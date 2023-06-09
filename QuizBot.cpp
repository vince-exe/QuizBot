#include <tgbot/tgbot.h>

#include "commands/bot_commands.h"

#include "game/question_checker.h"
#include "game/game.h"

using namespace std;

int main() {
    TgBot::Bot quizBot("");

    BotCommands botCommands(&quizBot);
    botCommands.init();

    Game::init();

    try {
        std::cout<<quizBot.getApi().getMe()->username << " started"; 
        quizBot.getApi().deleteWebhook();
        
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