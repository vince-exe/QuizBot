#ifndef QUESTIONS_MANAGER_H
#define QUESTIONS_MANAGER_H

#include <map>
#include <list>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>

#include "question.h"

using namespace std;

class QuestionsManager{
private:
    map<unsigned short, Question> ptr;
    unsigned short size;

public:
    QuestionsManager();
    QuestionsManager(pair<list<Question>, unsigned int> questions);
    QuestionsManager(list<Question> questions);
    QuestionsManager(Question question);
    QuestionsManager(QuestionsManager &that);
    QuestionsManager& operator=(QuestionsManager &that);
    Question operator[](unsigned short index);
    Question at(unsigned short index);
    unsigned short lenght();
    void setQuestions(pair<list<Question>, unsigned int> questions);
    void setQuestions(list<Question> questions);
    void setQuestions(Question question);
    void add(pair<list<Question>, unsigned int> questions);
    void add(list<Question> questions);
    void add(Question question);
    bool remove(unsigned short index);
    void clear();
    void randomize();
    void randomize(unsigned int randomKey);
};

#endif