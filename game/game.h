#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <list>
#include <map>

#include "questions_manager.h"
#include "user.h"

using namespace std;

class Game {
public:
    static QuestionsManager* manager;

    static map<unsigned int, User> usersMap;
    
    static int timeForQuestion;

    static void init();
};


#endif