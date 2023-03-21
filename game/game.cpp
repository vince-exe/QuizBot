#include "game.h"

QuestionsManager* Game::manager = nullptr;

void Game::init() {
    Game::manager = new QuestionsManager();
}