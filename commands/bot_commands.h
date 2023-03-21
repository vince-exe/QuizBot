#ifndef BOT_COMMANDS_H
#define BOT_COMMANDS_H

#include <tgbot/tgbot.h>
#include <iostream>

class BotCommands {
private:
    TgBot::Bot* bot;
    TgBot::EventBroadcaster* eventBroadCaster;

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard;
    TgBot::InlineKeyboardMarkup::Ptr backToStartPanel;
    TgBot::InlineKeyboardMarkup::Ptr configKeyBoard;
    TgBot::InlineKeyboardMarkup::Ptr backToSettingsPanel;
    
    TgBot::CallbackQuery::Ptr query;

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

    void callBackQuery();

    void start();

    void configQuestions();
};

#endif
