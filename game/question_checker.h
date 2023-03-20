#ifndef QUESTIONSCHECKER_H
#define QUESTIONSCHECKER_H

#include <string>
#include <list>
#include <iostream>
#include <utility>

#include "question.h"

using namespace std;

class QuestionsChecker{
private:
    static char keyUp(const char chr);
    static bool checkC(const char chr);
    static bool checkCombinations(const string tmp);
    
public:
    static pair<list<Question>, unsigned int> getPhrases(const string ph);
};

#endif