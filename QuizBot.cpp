#include <tgbot/tgbot.h>
#include "commands/bot_commands.h"

int main() {
    TgBot::Bot quizBot("6265358048:AAFGQVuqhsZ_C5Hdf85t7x5yw0rYZLfDmNs");

    BotCommands botCommands(&quizBot);
    botCommands.init();

    try {
        std::cout<<quizBot.getApi().getMe()->username << " started"; 
        TgBot::TgLongPoll longPoll(quizBot);

        while (true) {
            std::cout<<"\n.";
            longPoll.start();
        }
    } 
    catch (TgBot::TgException& e) {
        std::cout<<"\nerror: " << e.what();
    }
    
    return EXIT_SUCCESS;
}