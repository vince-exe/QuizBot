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
    //A map consisting of the index and the question
    map<unsigned short, Question> ptr;

    //An unsigned short that has how many elements the map has
    unsigned short size;

public:
    /**
     * @brief Construct a new QuestionsManager object
     * 
     * 
     */
    QuestionsManager();

    /**
     * @brief Construct a new QuestionsManager object
     * 
     * @param questions A pair consisting of the list of questions and how many questions have not been entered
     * 
     */
    QuestionsManager(pair<list<Question>, unsigned int> questions);

    /**
     * @brief Construct a new QuestionsManager object
     * 
     * @param questions A list of questions
     * 
     */
    QuestionsManager(list<Question> questions);

    /**
     * @brief Construct a new QuestionsManager object
     * 
     * @param question One question
     * 
     */
    QuestionsManager(Question question);

    /**
     * @brief The Copy Builder
     * 
     * @param that The second questionsmanager object
     * 
     */
    QuestionsManager(QuestionsManager &that);

    /**
     * @brief Address copy operator
     * 
     * @param that The second questionsmanager object
     * 
     * @return Returns QuestionsManager object after changing address
     */
    QuestionsManager& operator=(QuestionsManager &that);

     /**
     * @brief Square bracket operator that if it receives index returns the question
     * 
     * @param index Index that matches the question object you need
     * 
     * @return Returns the question that matches the received index
     */
    Question operator[](unsigned short index);

    /**
     * @brief Take index to return the question
     * 
     * @param index Index that matches the question object you need
     * 
     * @return Returns the question that matches the received index
     */
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

    /**
     * @brief Reorder the map randomly
     * 
     * 
     */
    void randomize();

    /**
     * @brief Reorder the map randomly
     * 
     * @param randomKey the random seed that can be set
     * 
     */
    void randomize(unsigned int randomKey);
};

#endif