#include "game.h"

QuestionsManager* Game::manager = nullptr;

map<unsigned int, User> Game::usersMap;

int Game::timeForQuestion = 10;

void Game::init() {
    Game::manager = new QuestionsManager();
}