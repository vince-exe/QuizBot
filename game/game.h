#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <vector>
#include <iostream>

#include "questions_manager.h"
#include "user.h"
#include "../utils/bot_utils.h"

using namespace std;

class Game {
public:
    static QuestionsManager* manager;

    static vector<User> usersVector;
    static vector<int64_t> checkVector;

    static Question selectedQuestion;

    static int timeForQuestion;
    static int pointsCorrectQuestion;
    static int pointIncorrectQuestion;
    static int currentQuestion;
    static int numOfTrue;
    static int numOfFalse;
    
    static void init();

    static bool userExist(int64_t id);

    static void increaseUsrPoints(int64_t id, int points);

    static void decreaseUsrPoints(int64_t id, int points);

    static bool checkVectorTest(int64_t id);
};


#endif