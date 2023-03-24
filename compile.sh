#!/bin/bash
clear
g++ QuizBot.cpp game/user.cpp game/questions_manager.cpp game/question.cpp game/game.cpp game/question_checker.cpp commands/bot_commands.cpp commands/utils/bot_messages.cpp utils/bot_utils.cpp -o QuizBot --std=c++14 -I/usr/local/include -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn -lTgBot -lboost_system -lssl -lcrypto -lpthread
./QuizBot