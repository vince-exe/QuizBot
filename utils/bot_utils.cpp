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

void BotUtils::swap(User& us1, User& us2) {
    User us3 = us1;

    us1 = us2;
    us2 = us3;
}

int BotUtils::partition(std::vector<User> &v, int start, int end) {
    int pivot = end;
	int j = start;

	for(int i = start; i < end; ++i){
		if(v[i].getPoints() > v[pivot].getPoints()){
			BotUtils::swap(v[i],v[j]);
			++j;
		}
	}

	BotUtils::swap(v[j],v[pivot]);

	return j;
}

void BotUtils::Quicksort(std::vector<User> &v, int start, int end ) {
	if(start < end){
		int p = BotUtils::partition(v,start,end);
		BotUtils::Quicksort(v,start,p-1);
		BotUtils::Quicksort(v,p+1,end);
	}
	
}