#ifndef BOT_COMMANDS_H
#define BOT_COMMANDS_H

#include <tgbot/tgbot.h>
#include <iostream>

class BotCommands {
private:
    TgBot::Bot* bot;
    TgBot::EventBroadcaster* eventBroadCaster;
    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard;

public:
    /**
     * @brief Construct a new Bot Commands object
     * 
     * @param bot a pointer to an existing TgBot::Bot istance
     * 
     */
    BotCommands(TgBot::Bot* bot);

    ~BotCommands();

    /**
     * @brief Initialize the class commands
     * 
     */
    void init();

    void start();
};

#endif
