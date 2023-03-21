#include <tgbot/tgbot.h>
#include "commands/bot_commands.h"

#include "game/question_checker.h"
using namespace std;

int main() {
    /*
    pair<list<Question>, unsigned int> domande = QuestionsChecker::getPhrases("") ;
    auto list = domande.first;
    std::cout<<"\nerrori: " << domande.second;

    for(auto element : list) {
        std::cout<<"\nBody: " << element.getBody();
        std::cout<<"\nResult: " << element.getResult();
        std::cout<<"\n\n";
    }
    */
    
    TgBot::Bot quizBot("");

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