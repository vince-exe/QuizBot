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
        "\n\n🔖 Utilizza il pulsante \"🛠️ Configura Domande\" per configurare le domande" \
        "\n\n⚠️ <b>Attenzione: </b> ogni volta che configurerai nuove domande, le precedenti verranno dimenticate" \
        "\n\n✅ <b>Configurazione Domande Corretta</b>" \
        "\n\n🔹 Le oche sono belle;V" \
        "\n🔹 Gli uccelli volano;V" \
        "\n🔹 Le mucche miagolano;F" \
        "\n\n⛑️ Gli svilupattori di @Sir_QuizBot ti invitato a creare domande divertenti per migliorare l'esperienza di gioco!!",
        false, 0, keyboard, "HTML"
    );
}