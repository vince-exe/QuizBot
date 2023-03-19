#ifndef BOT_UTILS_H
#define BOT_UTILS_H

#include <tgbot/tgbot.h>

namespace BotUtils {
        /**
     * @brief Set the TgBot::InlineKeyboardMarkup::Ptr object
     * 
     * @param keyboard the keyboard to set
     * @param vec a vector that contains all the buttons
    */
    void setKeyBoard(TgBot::InlineKeyboardMarkup::Ptr keyboard, const std::vector<std::pair<std::string, std::string>> vec);
};

#endif