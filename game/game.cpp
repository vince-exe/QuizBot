#include "game.h"

QuestionsManager* Game::manager = nullptr;

vector<User> Game::usersVector;
vector<int64_t> Game::checkVector;

int Game::timeForQuestion = 10;

int Game::currentQuestion = 0;

int Game::pointsCorrectQuestion = 300;

int Game::pointIncorrectQuestion = 400;

int Game::numOfTrue = 0;
int Game::numOfFalse = 0;

Question Game::selectedQuestion;

void Game::init() {
    Game::manager = new QuestionsManager();
}

bool Game::userExist(int64_t id) {
    for(auto& el : Game::usersVector) {
        if(el.getId() == id) { 
            return true;
        }
    }

    return false;
}

void Game::increaseUsrPoints(int64_t id, int points) {
    for(auto& el : Game::usersVector) {
        if(el.getId() == id) {
            el.setPoints(el.getPoints() + points);
        }
    }
}

void Game::decreaseUsrPoints(int64_t id, int points) {
    for(auto& el : Game::usersVector) {
        if(el.getId() == id) {
            el.setPoints(el.getPoints() - points);
        }
    }
}

bool Game::checkVectorTest(int64_t id) {
    for(auto& el : Game::checkVector) {
        if(el == id) {
            return true;
        }
    }
    
    return false;
}
