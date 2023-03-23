#ifndef BOT_COMMANDS_H
#define BOT_COMMANDS_H

#include <tgbot/tgbot.h>
#include <iostream>
#include <unistd.h>

#include "./utils/bot_messages.h"
#include "../utils/bot_utils.h"
#include "../game/question_checker.h"
#include "../game/game.h"

class BotCommands {
private:
    TgBot::Bot* bot;
    TgBot::EventBroadcaster* eventBroadCaster;

    TgBot::InlineKeyboardMarkup::Ptr startKeyBoard;
    TgBot::InlineKeyboardMarkup::Ptr backToStartPanel;
    TgBot::InlineKeyboardMarkup::Ptr configKeyBoard;
    TgBot::InlineKeyboardMarkup::Ptr backToSettingsPanel;
    
    TgBot::CallbackQuery::Ptr query;

    int64_t creatorId;

    bool botStarted;

private:
    /* this function has to be static because the normal class method has an hide paramater "this", that the "pthread_create()"" doesn't understand */
    static void* countThread(void* arg);

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
