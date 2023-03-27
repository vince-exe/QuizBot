#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <vector>
#include <iostream>

#include "questions_manager.h"
#include "user.h"
#include "../utils/bot_utils.h"

using namespace std;

/**
 * @brief this class contains all the useful methods and properties for the correct esecution of the game
 * 
 */
class Game {
public:
    /* static QuestionManager pointer, used to handle the questions of the bot */
    static QuestionsManager* manager;

    /* mainly used to store the points of the Users during the game */
    static vector<User> usersVector;

    /* used to check if a user clicks more than once the button "true" or "false" */
    static vector<int64_t> checkVector;

    /* catche the current Bot question */
    static Question selectedQuestion;

    static int timeForQuestion;
    static int pointsCorrectQuestion;
    static int pointIncorrectQuestion;

    /* stores the index of the current question, used in combination with the QuestionManager* manager, to get the selectedQuestion */
    static int currentQuestion;

    static int numOfTrue;
    static int numOfFalse;
    
    /**
     * @brief init the Game properties 
     * 
     */
    static void init();
    
    /**
     * @brief search for a user in the usersVector
     * 
     * @param id user unique identifier
     * 
     * @return true if exists otherwise false
  
     */
    static bool userExist(int64_t id);

    /**
     * @brief increase the points of the given user
     * 
     * @param id user unique identifier
     * 
     * @param points points to increase 
     */
    static void increaseUsrPoints(int64_t id, int points);

    /**
     * @brief decrease the points of the given user
     * 
     * @param id user unique identifer
     * 
     * @param points points to decrease
     */
    static void decreaseUsrPoints(int64_t id, int points);

    /**
     * @brief iterate through the checkVector
     * 
     * @param id user unique identifier
     * 
     * @return true if the id is present otherwise false.
     */
    static bool checkVectorTest(int64_t id);
};


#endif