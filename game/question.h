#ifndef QUESTION_H
#define QUESTION_H

#include <string>

/**
 * @brief class to rappresent the Question object
 * 
 */
class Question {
private:

    /* body of the question */
    std::string body;

    /* result of the question */
    bool result;

public:
    Question()=default;

    /**
     * @brief base constructor
     * 
     * @param b body of the question
     * 
     * @param r result of the question
     * 
     */
    Question(std::string b, bool r);

    std::string getBody();

    bool getResult();

    void setBody(std::string& b);

    void setResult(bool& r);
};

#endif