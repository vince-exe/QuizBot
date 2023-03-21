#include "bot_commands.h"

#include "./utils/bot_messages.h"
#include "../utils/bot_utils.h"
#include "../game/question_checker.h"
#include "../game/game.h"

BotCommands::BotCommands(TgBot::Bot* bot) {
    this->bot = bot;
    this->eventBroadCaster = &this->bot->getEvents();

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->startKeyBoard = startKeyBoard;

    TgBot::InlineKeyboardMarkup::Ptr backToStartPanel(new TgBot::InlineKeyboardMarkup);
    this->backToStartPanel = backToStartPanel;

    TgBot::InlineKeyboardMarkup::Ptr configKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->configKeyBoard = configKeyBoard;
    
    TgBot::InlineKeyboardMarkup::Ptr backToSettingsPanel(new TgBot::InlineKeyboardMarkup);
    this->backToSettingsPanel = backToSettingsPanel;
}

BotCommands::~BotCommands() {
    delete this->eventBroadCaster;
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

    BotUtils::setKeyBoard((this->configKeyBoard), {{"🔖 Vedi Domande", "show_questions"}});

    BotUtils::setKeyBoard((this->backToSettingsPanel), {{"🛠️ Pannello Impostazioni", "back_config_panel"}});

    this->start();
    this->configQuestions();
    this->callBackQuery();  
}

void BotCommands::callBackQuery() {
    this->bot->getEvents().onCallbackQuery([this](TgBot::CallbackQuery::Ptr query) {
        TgBot::ChatMember::Ptr user = this->bot->getApi().getChatMember(query->message->chat->id, query->from->id);
        this->query = query;

        if(query->data == "show_questions") {
            if(!Game::manager->lenght()) {
                BotMessages::emptyQuestionsList(this->bot, user->user->id);
            }
            else {
                // todo
            }
            return;
        }

        if(query->data == "back_config_panel") {
            BotMessages::editConfigPanel(this->bot, user->user->id, query->message->messageId, this->configKeyBoard);
            return;
        }

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
            else if(query->data == "update_private" && !this->bot->getApi().blockedByUser(user->user->id)) {
                BotMessages::printConfigPanel(this->bot, user->user->id, this->configKeyBoard);
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

        BotMessages::startMessage(this->bot, message->chat->id, user, this->startKeyBoard);
    });
}

void BotCommands::configQuestions() {
    this->eventBroadCaster->onCommand("configQuestions", [this](TgBot::Message::Ptr message) {       
        if(message->chat->type != TgBot::Chat::Type::Private) { return; }
        
        if(BotUtils::countArguments("/configQuestions", message->text) <= 0) {
            BotMessages::badCommandArgs(this->bot, message->chat->id);
            return;
        }
        
        std::string checkString = BotUtils::removeCommand(message->text, 17);
        pair<list<Question>, unsigned int> check = QuestionsChecker::getPhrases(checkString);

        for(auto element : check.first) {
            std::cout<<"\nBody: " << element.getBody();
            std::cout<<"\nResult: " << element.getResult();
            std::cout<<"\n\n";
        }

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