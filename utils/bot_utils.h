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

    /**
     * @brief remove the command prefix from the message
     * 
     * @param message 
     * @param commandLen 
     * 
     * @return std::string 
     */
    std::string removeCommand(std::string& message, int commandLen);

    /**
     * @brief return the number of arguments in the command
     * 
     * @param command 
     * @param message 
     * @return int 
     */
    int countArguments(const std::string command, const std::string message);

    /**
     * @brief Return one of the two given emojis based on a condition
     * 
     * @param s a string where the condition should appear
     * 
     * @param condition the condition that the string has to respect
     * 
     * @param emoji the two emoji
     * 
     */
    std::string getEmoji(const std::string s, const std::string condition, const std::pair<std::string, std::string> emoji);
};

#endif