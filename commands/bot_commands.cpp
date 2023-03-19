#include "bot_commands.h"

BotCommands::BotCommands(TgBot::Bot* bot) {
    this->bot = bot;
    this->eventBroadCaster = &this->bot->getEvents();

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard(new TgBot::InlineKeyboardMarkup);
    this->startKeyBoard = startKeyBoard;

    TgBot::CallbackQuery::Ptr query;
}

BotCommands::~BotCommands() {
    delete this->eventBroadCaster;
}

void BotCommands::init() {

}

void BotCommands::start() {
    this->eventBroadCaster->onCommand("start", [this](TgBot::Message::Ptr message) {
        TgBot::ChatMember::Ptr user = this->bot->getApi().getChatMember(message->chat->id, message->from->id);
        if(user->user->isBot || !user) { return; }

        std::cout<<"\nStart Command";
    });
}