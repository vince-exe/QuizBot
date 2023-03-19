#include "bot_commands.h"

#include "./utils/bot_messages.h"
#include "../utils/bot_utils.h"

BotCommands::BotCommands(TgBot::Bot* bot) {
    this->bot = bot;
    this->eventBroadCaster = &this->bot->getEvents();

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->startKeyBoard = startKeyBoard;

    TgBot::InlineKeyboardMarkup::Ptr backToStartPanel(new TgBot::InlineKeyboardMarkup);
    this->backToStartPanel = backToStartPanel;
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

    this->callBackQuery();
    this->start();
}

void BotCommands::callBackQuery() {
    this->bot->getEvents().onCallbackQuery([this](TgBot::CallbackQuery::Ptr query) {
        TgBot::ChatMember::Ptr user = this->bot->getApi().getChatMember(query->message->chat->id, query->from->id);
        this->query = query;

        if(user->status != "creator") { return; }

        try {
            if(query->data == "developers") {
                BotMessages::developersEdit(this->bot, query->message->chat->id, query->message->messageId, this->backToStartPanel);
            }
            else if(query->data == "backToStartPanel") {
                BotMessages::editStartMessage(this->bot, query->message->chat->id, query->message->messageId, user, this->startKeyBoard);
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