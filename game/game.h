#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <list>

#include "questions_manager.h"

using namespace std;

class Game {
public:
    static QuestionsManager* manager;

    static void init();
};


#endif