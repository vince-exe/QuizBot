#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>

class Question {
private:
    std::string body;
    bool result;

public:
    Question()=default;

    Question(std::string b, bool r);

    std::string getBody();

    bool getResult();

    void setBody(std::string& b);

    void setResult(bool& r);
};

#endif