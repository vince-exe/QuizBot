#include "bot_commands.h"

BotCommands::BotCommands(TgBot::Bot* bot) {
    this->bot = bot;
    
    this->creatorId = 0;
    this->groupChat = 0;
    this->currentSetting = -1;

    this->gameRunning = false;
    this->botStarted = false;
    this->gameStarted = false;

    this->eventBroadCaster = &this->bot->getEvents();

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->startKeyBoard = startKeyBoard;

    TgBot::InlineKeyboardMarkup::Ptr backToStartPanel(new TgBot::InlineKeyboardMarkup);
    this->backToStartPanel = backToStartPanel;

    TgBot::InlineKeyboardMarkup::Ptr configKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->configKeyBoard = configKeyBoard;
    
    TgBot::InlineKeyboardMarkup::Ptr backToSettingsPanel(new TgBot::InlineKeyboardMarkup);
    this->backToSettingsPanel = backToSettingsPanel;

    TgBot::InlineKeyboardMarkup::Ptr playKeyboard(new TgBot::InlineKeyboardMarkup);
    this->playKeyboard = playKeyboard;

    TgBot::InlineKeyboardMarkup::Ptr nextQuestionKeyboard(new TgBot::InlineKeyboardMarkup);
    this->nextQuestionKeyboard = nextQuestionKeyboard;

    TgBot::InlineKeyboardMarkup::Ptr newGameKeyboard(new TgBot::InlineKeyboardMarkup);
    this->newGameKeyboard = newGameKeyboard;

    TgBot::InlineKeyboardMarkup::Ptr changeSettingsKeyboard(new TgBot::InlineKeyboardMarkup);
    this->changeSettingsKeyboard = changeSettingsKeyboard;
}

BotCommands::~BotCommands() {
    delete this->eventBroadCaster;
}

void* BotCommands::countThread(void* arg) {
    BotCommands* data = (BotCommands *) arg;
    
    TgBot::Message::Ptr msg = BotMessages::secondsLeftMessage(data->bot, data->groupChat, Game::timeForQuestion);
    int changeTime = Game::timeForQuestion / 2;

    for(int i = 0; i < Game::timeForQuestion; i++) {
        try {
            if(i == changeTime) {
                BotMessages::editSecondsLeftMessage(data->bot, data->groupChat, msg->messageId, changeTime);
            }

            sleep(1);
        }
        catch(std::exception& e) {
            std::cout<<"\nThread Count Exception: " + (std::string)e.what();
        }

    }
    std::cout<<"\nCount Thread Finished.";

    data->timeFinishedMsg = BotMessages::timeFinishedEditMessage(data->bot, data->groupChat, msg->messageId);
    BotMessages::editDisplayQuestion(data->bot, data->groupChat, data->questionMsg->messageId, data->nextQuestionKeyboard);

    pthread_exit(NULL);
}

void BotCommands::init() {
    BotUtils::setKeyBoard((this->startKeyBoard), 
    {
        {"🔐 Configura (DM)", "update_private"},
        {"© Sviluppatori", "developers"}
    }
    );
    BotUtils::setKeyBoard((this->startKeyBoard),
    {
        {"📖 Termini & Condizioni", "ToS"},
        {"✅ Avvia", "startGame"}
    }
    );

    BotUtils::setKeyBoard((this->backToStartPanel), {{"🔙 Back", "backToStartPanel"}});

    BotUtils::setKeyBoard((this->configKeyBoard), {{"🔖 Vedi Domande", "show_questions"}, {"⚙️ Modifica Impostazioni", "change_game_settings"}});

    BotUtils::setKeyBoard((this->backToSettingsPanel), {{"🛠️ Pannello Impostazioni", "back_config_panel"}});

    BotUtils::setKeyBoard((this->playKeyboard), {{"✅ Vero", "true_response"}, {"❌ Falso", "false_response"}});
    
    BotUtils::setKeyBoard((this->nextQuestionKeyboard), {{"🔖 Prossima Domanda", "next_question"}});

    BotUtils::setKeyBoard((this->newGameKeyboard), {{"✅ Nuova Partita", "new_game"}});

    BotUtils::setKeyBoard((this->changeSettingsKeyboard), {
        {"⏳", "change_time_question"},
        {"❌", "change_points_invalid_question"},
        {"✅", "change_points_valid_question"}
    });
    BotUtils::setKeyBoard((this->changeSettingsKeyboard), {{"🛠️ Pannello Impostazioni", "back_config_panel"}});

    this->start();
    this->configQuestions();
    this->configQuestion();
    this->callBackQuery();  
}

void BotCommands::callBackQuery() {
    this->bot->getEvents().onCallbackQuery([this](TgBot::CallbackQuery::Ptr query) {
        TgBot::ChatMember::Ptr user = this->bot->getApi().getChatMember(query->message->chat->id, query->from->id);
        this->query = query;

        if(query->data == "show_questions") {

            if(!Game::manager->lenght()) {
                this->bot->getApi().answerCallbackQuery(
                    query->id,
                    "⛔ La lista di quesiti è vuota. ⛔ \
                    \n\n🔖 Utilizza il comando /configQuestions per configurare dei quesiti.",
                    true
                );
            }
            else {
                BotMessages::showQuestions(this->bot, user->user->id, query->message->messageId, this->backToSettingsPanel);
            }
            return;
        }

        if(query->data == "back_config_panel") {
            BotMessages::editConfigPanel(this->bot, user->user->id, query->message->messageId, this->configKeyBoard);

            return;
        }

        else if(query->data == "change_game_settings") {
            BotMessages::showConfigOptionPanel(this->bot, user->user->id, query->message->messageId, this->changeSettingsKeyboard);
            return;
        }

        /* Config Settings */
        else if(query->data == "change_time_question") {
            this->currentSetting = BotUtils::config::TimeForQuestion;
        }
        else if(query->data == "change_points_invalid_question") {
            this->currentSetting = BotUtils::config::PointsInvalidQuestion;
        }
        else if(query->data == "change_points_valid_question") {
            this->currentSetting = BotUtils::config::PointsValidQuestion;
        }

        else if(query->data == "true_response" || query->data == "false_response") {
            try {
                /* if the user already clicked */
                if(Game::checkVectorTest(user->user->id)) { return; }
                Game::checkVector.push_back(user->user->id);
                    
                if(Game::userExist(user->user->id)) { 
                    if(query->data == "true_response" && Game::selectedQuestion.getResult() || 
                        query->data == "false_response" && !Game::selectedQuestion.getResult()) {

                        if(query->data == "true_response") { Game::numOfTrue++; }
                        else { Game::numOfFalse++; }

                        Game::increaseUsrPoints(user->user->id, Game::pointsCorrectQuestion);
                    }
                    else {
                        if(query->data == "true_response") { Game::numOfTrue++; }
                        else { Game::numOfFalse++; }

                        Game::decreaseUsrPoints(user->user->id, Game::pointIncorrectQuestion);
                    }       
                }
                /* if it's the first time */
                else {
                    if(query->data == "true_response" && Game::selectedQuestion.getResult() || 
                        query->data == "false_response" && !Game::selectedQuestion.getResult()) {

                        if(query->data == "true_response") { Game::numOfTrue++; }
                        else { Game::numOfFalse++; }

                        Game::usersVector.push_back(User(user->user->username, user->user->id, Game::pointsCorrectQuestion));
                    }
                    else {
                        if(query->data == "true_response") { Game::numOfTrue++; }
                        else { Game::numOfFalse++; }

                        Game::usersVector.push_back(User(user->user->username, user->user->id, 0 - Game::pointIncorrectQuestion));
                    }   
                }
            }
            catch(std::exception& e) {
                return;
            }
        }            

        /* Buttons For Creator */
        if(user->status != "creator") { return; }

        try {
            if(query->data == "developers") {
                BotMessages::developersEdit(this->bot, query->message->chat->id, query->message->messageId, this->backToStartPanel);
            }
            else if(query->data == "backToStartPanel") {
                BotMessages::editStartMessage(this->bot, query->message->chat->id, query->message->messageId, user, this->startKeyBoard);
            }
            else if(query->data == "ToS") {
                BotMessages::printToS(this->bot, query->message->chat->id, query->message->messageId, this->backToStartPanel);
            }
            else if(query->data == "update_private" && !this->bot->getApi().blockedByUser(user->user->id) && this->botStarted) {
                BotMessages::printConfigPanel(this->bot, user->user->id, this->configKeyBoard);
            } 

            if(!BotCommands::botStarted) { return; }

            else if(query->data == "startGame" || query->data == "new_game") {
                /* check if the questions list is empty */
                if(!Game::manager->lenght()) {
                    this->bot->getApi().answerCallbackQuery(
                        query->id,
                        "⛔ La lista di quesiti è vuota. ⛔ \
                        \n\n🔖 Utilizza il comando /configQuestions per configurare dei quesiti.",
                        true
                    );
                    return;
                }

                if(this->gameRunning) { 
                    this->bot->getApi().answerCallbackQuery(query->id, "⚠️ Una partita è ancora in corso... ⚠️", true);
                    return;
                }

                if(query->data == "new_game") {
                    this->bot->getApi().deleteMessage(this->groupChat, this->questionMsg->messageId);
                    return;
                }
                
                pthread_t ptid;
                pthread_create(&ptid, NULL, &BotCommands::countThread, (void *)this);

                Game::usersVector.clear();
                Game::currentQuestion = 0;
                Game::selectedQuestion = Game::manager->at(Game::currentQuestion);
                Game::checkVector.clear();
                Game::numOfTrue = 0;
                Game::numOfFalse = 0;

                this->gameStarted = true;
                this->gameRunning = true;
                
                this->questionMsg = BotMessages::displayQuestion(this->bot, query->message->chat->id, this->playKeyboard);
            }

            if(!this->gameStarted) { return; }

            else if(query->data == "next_question" && user->status == "creator") {
                Game::currentQuestion++;

                /* finished */
                if(Game::currentQuestion >= Game::manager->lenght()) {
                    this->bot->getApi().deleteMessage(this->groupChat, this->timeFinishedMsg->messageId);
                    BotMessages::editGameFinished(this->bot, query->message->chat->id, this->questionMsg->messageId, this->newGameKeyboard);
                    this->gameRunning = false;

                    return;
                }

                Game::selectedQuestion = Game::manager->at(Game::currentQuestion);
                Game::checkVector.clear();
                Game::numOfTrue = 0;
                Game::numOfFalse = 0;
                this->gameStarted = true;

                this->bot->getApi().deleteMessage(this->groupChat, this->timeFinishedMsg->messageId);
                this->bot->getApi().deleteMessage(this->groupChat, this->questionMsg->messageId);

                pthread_t ptid;
                pthread_create(&ptid, NULL, &BotCommands::countThread, (void *)this);

                this->questionMsg = BotMessages::displayQuestion(this->bot, query->message->chat->id, this->playKeyboard);
            }
        }
        catch(std::exception& e) {
            return;
        }
    });
}

void BotCommands::start() {
    this->eventBroadCaster->onCommand("start", [this](TgBot::Message::Ptr message) {
        TgBot::ChatMember::Ptr user = this->bot->getApi().getChatMember(message->chat->id, message->from->id);
        if(user->user->isBot || !user || user->status != "creator") { return; }

        this->creatorId = user->user->id;
        this->groupChat = message->chat->id;
        this->botStarted = true;

        BotMessages::startMessage(this->bot, message->chat->id, user, this->startKeyBoard);
    });
}

void BotCommands::configQuestions() {
    this->eventBroadCaster->onCommand("configQuestions", [this](TgBot::Message::Ptr message) {       
        if(message->chat->type != TgBot::Chat::Type::Private || !this->botStarted || message->from->id != this->creatorId) { return; }
        
        if(BotUtils::countArguments("/configQuestions", message->text) <= 0) {
            BotMessages::badCommandArgs(this->bot, message->chat->id);
            return;
        }

        std::string checkString = BotUtils::removeCommand(message->text, 17);
        pair<list<Question>, unsigned int> check = QuestionsChecker::getPhrases(checkString);

        Game::manager->clear();

        /* if the phrase has one or multiples errors */
        if(check.second) {
            BotMessages::phraseHasErrors(this->bot, message->chat->id, check.second);
        }
        else {
            /* add to the QuestionsManager the QuestionsList */
            Game::manager->add(check.first);
            BotMessages::pharasesSuccess(this->bot, message->chat->id, this->backToSettingsPanel);
        }
    });
}

void BotCommands::configQuestion() {
    this->eventBroadCaster->onCommand("configSetting", [this](TgBot::Message::Ptr message) {
        if(message->chat->type != TgBot::Chat::Type::Private || !this->botStarted || message->from->id != this->creatorId) { return; }

        if(BotUtils::countArguments("/configSetting", message->text) <= 0) {
            BotMessages::badCommandArgs(this->bot, message->chat->id);
            return;
        }

        std::string body = BotUtils::removeCommand(message->text, 15);
        int value = std::atoi(body.c_str());

        switch (this->currentSetting) {
            case BotUtils::config::PointsInvalidQuestion:
                if(value < Game::MIN_POINTS_INCORRECT_QUEST || value > Game::MAX_POINTS_INCORRECT_QUEST) { return; }
                Game::pointIncorrectQuestion = value;
                break;

            case BotUtils::config::PointsValidQuestion:
                if(value < Game::MIN_POINTS_CORRECT_QUEST || value > Game::MAX_POINTS_CORRECT_QUEST) { return; }
                Game::pointsCorrectQuestion = value;
                break;

            case BotUtils::config::TimeForQuestion:
                if(value < Game::MIN_TIME_QUEST || value > Game::MAX_TIME_QUEST) { return; }
                Game::timeForQuestion = value;
                break;

            default:
                return;
        }

        BotMessages::sendConfigOptionPanel(this->bot, message->chat->id, this->changeSettingsKeyboard);
        this->currentSetting = -1;

    });
}
