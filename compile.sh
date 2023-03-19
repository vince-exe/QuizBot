#!/bin/bash
clear
g++ QuizBot.cpp commands/bot_commands.cpp -o QuizBot --std=c++14 -I/usr/local/include -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn -lTgBot -lboost_system -lssl -lcrypto -lpthread
./QuizBot