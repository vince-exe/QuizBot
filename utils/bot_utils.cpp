#include "bot_utils.h"

void BotUtils::setKeyBoard(TgBot::InlineKeyboardMarkup::Ptr keyboard, const std::vector<std::pair<std::string, std::string>> vec) {
    std::vector<TgBot::InlineKeyboardButton::Ptr> row;

    for(auto it : vec) {
        TgBot::InlineKeyboardButton::Ptr button(new TgBot::InlineKeyboardButton);

        button->text = it.first;
        button->callbackData = it.second;

        row.push_back(button);
    }

    keyboard->inlineKeyboard.push_back(row);
}

std::string BotUtils::removeCommand(std::string& message, int commandLen) {
    return message.substr(commandLen, message.length() - 1);
}

int BotUtils::countArguments(const std::string command, const std::string message) {
    int countArguments = 0;
    bool in = false;

    for(int i = command.length(); i < message.length(); i++) {
        while(message[i] != ' ' && i < message.length()) {
            in = true;
            i++;
        }
        if(in) { countArguments++; }
        in = false;
    }

    return countArguments;
}

std::string BotUtils::getEmoji(const std::string s, const std::string condition, const std::pair<std::string, std::string> emoji) {
    return (s == condition ) ? emoji.first : emoji.second;
}

void BotUtils::selectionSort(std::vector<User>& vector) {
    int min;
    User temp;
    
    for(int i = 0; i < vector.size() - 1; i++) {
	    min = i;
        for(int j = i + 1; j < vector.size(); j++) {
        	if (vector[j].getPoints() < vector[min].getPoints()) {
        	    min = j;
            }
        }
        temp = vector[min];
        vector[min] = vector[i];
        vector[i] = temp;
    }
}