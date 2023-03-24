#include "bot_messages.h"

void BotMessages::startMessage(TgBot::Bot* bot, int64_t chatId, TgBot::ChatMember::Ptr user, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    bot->getApi().sendMessage(
        chatId,
        "⚙️ <b>Pannello Generale</b>" \
        "\n\n🛠️ <i>Ciao @</i>" + user->user->username + " <i>benvenuto nel pannello generale del bot</i>" \
        "\n\n⚠️ <b>Attenzione: </b> <i>Per essere configurato, il bot ha bisogno di essere avviato anche in chat privata</i>" \
        "\n\n✏️ <i>Una volta configurato il bot vai al pannello di avvio e premi il pulsante</i> ✅Avvia",
        false, 0, keyboard, "HTML"
    );      
}

void BotMessages::developersEdit(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    bot->getApi().editMessageText(
        "🧑‍💻 <b>Lista Sviluppatori</b>\n\n📮 @bScreen aka <b>Vinforte</b> \n\n🎩 @NonScopoMai aka <b>Mr.Visone</b> \n\n🐷 @stesapa4 aka <b>Stefi</b>",
        chatId,
        messageId,
        std::string(), "HTML", false, keyboard
    );
}

void BotMessages::editStartMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::ChatMember::Ptr user, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    bot->getApi().editMessageText(
        "⚙️ <b>Pannello Generale</b>" \
        "\n\n🛠️ <i>Ciao @</i>" + user->user->username + " <i>benvenuto nel pannello generale del bot</i>" \
        "\n\n⚠️ <b>Attenzione: </b> <i>Per essere configurato, il bot ha bisogno di essere avviato anche in chat privata</i>" \
        "\n\n✏️ <i>Una volta configurato il bot vai al pannello di avvio e premi il pulsante</i> ✅Avvia",
        chatId,
        messageId,
        std::string(), "HTML", false, keyboard
    );
}

void BotMessages::printToS(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    bot->getApi().editMessageText(
        "<b>✏️ Termini & Condizioni </b> \
        \n\n⛑️ <i>Gli sviluppatori non sono responsabili di eventuali patologie legate all'utilizzo di questo bot</i> \
        \n\n✅ Lo staff di @Sir_QuizBot ti augura buon divertimento :)",
        chatId,
        messageId,
        std::string(), "HTML", false, keyboard
    );
}

void BotMessages::printConfigPanel(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Configurazione Domande</b> " \
        "\n\n🔖 Utilizza il comando /configQuestions per configurare le domande" \
        "\n\n⚠️ <b>Attenzione: </b> ogni volta che configurerai nuove domande, le precedenti verranno dimenticate" \
        "\n\n✅ <b>Configurazione Domande Corretta</b>" \
        "\n\n🔹 Le oche sono belle;V" \
        "\n🔹 Gli uccelli volano;V" \
        "\n🔹 Le mucche miagolano;F" \
        "\n\n⛑️ Gli svilupattori di @Sir_QuizBot ti invitano a creare domande divertenti per migliorare l'esperienza di gioco!!",
        false, 0, keyboard, "HTML"
    );
}

void BotMessages::editConfigPanel(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyBoard) {
    bot->getApi().editMessageText(
        "🤖 <b>Configurazione Domande</b> " \
        "\n\n🔖 Utilizza il comando /configQuestions per configurare le domande" \
        "\n\n⚠️ <b>Attenzione: </b> ogni volta che configurerai nuove domande, le precedenti verranno dimenticate" \
        "\n\n✅ <b>Configurazione Domande Corretta</b>" \
        "\n\n🔹 Le oche sono belle;V" \
        "\n🔹 Gli uccelli volano;V" \
        "\n🔹 Le mucche miagolano;F" \
        "\n\n⛑️ Gli svilupattori di @Sir_QuizBot ti invitano a creare domande divertenti per migliorare l'esperienza di gioco!!",
        chatId,
        messageId,
        std::string(), "HTML", false, keyBoard
    );
}

void BotMessages::badCommandArgs(TgBot::Bot* bot, int64_t chatId) {
    bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Comando Non Valido</b> " \
        "\n\n⛔<b>Argomenti non idonei per il tipo di comando digitato.</b>",
        false, 0, std::make_shared<TgBot::GenericReply>(), "HTML"
    );
}

void BotMessages::phraseHasErrors(TgBot::Bot* bot, int64_t chatId, int errors) {
    bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Domande Non Valide</b>" \
        "\n\n⛔ " + std::to_string(errors) + " delle domande inserite non rispettano la formattazione.",
        false, 0, std::make_shared<TgBot::GenericReply>(), "HTML"
    );
}

void BotMessages::emptyQuestionsList(TgBot::Bot* bot, int64_t chatId) {
    bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Avviso Bot</b> " \
        "\n\n⛔ La lista di quesiti è vuota." \
        "\n\n🔖 Utilizza il comando /configQuestions per configurare dei quesiti.",
        false, 0, std::make_shared<TgBot::GenericReply>(), "HTML"
    );
}

 void BotMessages::pharasesSuccess(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyBoard) {
    bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Domande Aggiunte</b>" \
        "\n\n✅ Le domande sono state correttamente aggiunte." \
        "\n\n🔖 Utilizza l'apposito pulsante per stamparle." \
        "\n\n⛑️ Gli svilupattori di @Sir_QuizBot ti invitano a creare domande divertenti per migliorare l'esperienza di gioco!!",
        false, 0, keyBoard, "HTML"
    );
}

void BotMessages::showQuestions(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    std::string msg;
    Question question;

    for(int i = 0; i < Game::manager->lenght(); i++) {
        question = Game::manager->at(i);

        msg += "<b>" + std::to_string(i + 1) + ") </b>" + question.getBody();
        if(!question.getResult()) {
            msg += " ❌";
        }
        else {
            msg += " ✅";
        }
        msg+="\n\n";
    }

    bot->getApi().editMessageText(
        "🤖 <b>Lista Domande</b>" \
        "\n\n🔖 Ecco le domande salvate nel bot\n" \
        "\n" + msg \
        + "\n⛑️ Gli svilupattori di @Sir_QuizBot ti invitano a creare domande divertenti per migliorare l'esperienza di gioco!!",
        chatId,
        messageId,
        std::string(), "HTML", false, keyboard
    );
}

TgBot::Message::Ptr BotMessages::secondsLeftMessage(TgBot::Bot* bot, int64_t chatId, int secondsLeft) {
    return bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Tempistica Domanda</b>" \
        "\n\n🔖 Rispondi alla domanda nel minor tempo possibile!!" \
        "\n\n📮 <b>Secondi Rimanenti: </b>" + std::to_string(secondsLeft),
        false, 0, std::make_shared<TgBot::GenericReply>(), "HTML"
    );
}

void BotMessages::editSecondsLeftMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId, int secondsLeft) {
    bot->getApi().editMessageText(
        "🤖 <b>Tempistica Domanda</b>" \
        "\n\n🔖 Rispondi alla domanda nel minor tempo possibile!!" \
        "\n\n📮 <b>Secondi Rimanenti: </b>" + std::to_string(secondsLeft),
        chatId,
        messageId,
        std::string(), "HTML", false
    );
}

TgBot::Message::Ptr BotMessages::timeFinishedEditMessage(TgBot::Bot* bot, int64_t chatId, int64_t messageId) {
    return bot->getApi().editMessageText(
        "🤖 <b>Tempistica Domanda</b>" \
        "\n\n📛<b> Tempo Scaduto </b>",
        chatId,
        messageId,
        std::string(), "HTML", false
    );
}

TgBot::Message::Ptr BotMessages::displayQuestion(TgBot::Bot* bot, int64_t chatId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    Question q = Game::manager->at(Game::currentQuestion);

    return bot->getApi().sendMessage(
        chatId,
        "🤖 <b>Domanda n: " + std::to_string(Game::currentQuestion + 1) + " / " + std::to_string(Game::manager->lenght()) + "</b>" \
        "\n\n✅ <b>Vero</b>   o   ❌ <b>Falso</b> 🤨" \
        "\n\n📮 " + q.getBody(),
        false, 0, keyboard, "HTML"
    );
}

TgBot::Message::Ptr BotMessages::editDisplayQuestion(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    std::string s = (Game::selectedQuestion.getResult() == true) ? "true" : "false";

    return bot->getApi().editMessageText(
        "🤖 <b>Risultati Domanda</b>" \
        "\n\n✏️ <b> Domanda: </b> " + Game::selectedQuestion.getBody() + \
        "\n\n📮<b> Soluzione: </b> " + BotUtils::getEmoji(s, "true", {"✅", "❌"}) + \
        "\n\n📛 <i>Risposte degli utenti...</i>" \
        "\n\n✅: <b>" + std::to_string(Game::numOfTrue) + "</b>" \
        "\n\n❌: <b>" + std::to_string(Game::numOfFalse) + "</b>" \
        "\n\n🔱 Attendere il creator del gruppo per passare alla prossima domanda.",
        chatId,
        messageId,
        std::string(), "HTML", false, keyboard
    );
}

void BotMessages::editGameFinished(TgBot::Bot* bot, int64_t chatId, int64_t messageId, TgBot::InlineKeyboardMarkup::Ptr keyboard) {
    std::string top;
    BotUtils::selectionSort(Game::usersVector);

    for(auto& el : Game::usersVector) {
        top += "\n\n💰 <b>Punteggio: </b>" + std::to_string(el.getPoints()) + "  🔸 @" + el.getName();
    } 

    bot->getApi().editMessageText(
        "🤖 <b>Risultati Domanda</b>" \
        "\n\n👑 <b> Classifica Giocatori </b>" \
        + top + \
        "\n\n📮 Gli svilupattori di @Sir_QuizBot vi augurano un buon proseguimento!!",
        chatId, messageId, std::string(), "HTML", false, keyboard
    );
}
