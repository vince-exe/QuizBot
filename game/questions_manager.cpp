#include "questions_manager.h"

QuestionsManager::QuestionsManager() {
    this->size = 0;
}

QuestionsManager::QuestionsManager(pair<list<Question>, unsigned int> questions){
    this->size = 0;
    for(auto i : questions.first) this->ptr[this->size++] = i;
}

QuestionsManager::QuestionsManager(list<Question> questions){
    this->size = 0;
    for(auto i : questions) this->ptr[this->size++] = i;
}

QuestionsManager::QuestionsManager(Question question){
    this->size = 0;
    this->ptr[this->size++] = question;
}

QuestionsManager::QuestionsManager(QuestionsManager& that){
    this->ptr = that.ptr;
    this->size = that.lenght();
}

QuestionsManager& QuestionsManager::operator=(QuestionsManager &that){
    *this = that;
    return *this;
}

Question QuestionsManager::operator[](unsigned short index){
    return this->ptr[index];
}

Question QuestionsManager::at(unsigned short index){
    return this->ptr[index];
}

unsigned short QuestionsManager::lenght(){
    return this->size;
}

void QuestionsManager::setQuestions(pair<list<Question>, unsigned int> questions){
    this->size = 0;
    this->ptr.clear();
    for(auto i : questions.first) this->ptr[this->size++] = i;
}

void QuestionsManager::setQuestions(list<Question> questions){
    this->size = 0;
    this->ptr.clear();
    for(auto i : questions) this->ptr[this->size++] = i;
}

void QuestionsManager::setQuestions(Question question){
    this->size = 0;
    this->ptr.clear();
    this->ptr[this->size++] = question;
}

void QuestionsManager::add(pair<list<Question>, unsigned int> questions){
    for(auto i : questions.first) this->ptr[this->size++] = i;
}

void QuestionsManager::add(list<Question> questions){
    for(auto i : questions) this->ptr[this->size++] = i;
}

void QuestionsManager::add(Question question){
    this->ptr[this->size++] = question;
}

bool QuestionsManager::remove(unsigned short index){
    return this->ptr.erase(index);
}

void QuestionsManager::clear() {
    if(!this->size) { return; }
    
    this->ptr.clear();
    this->size = 0;
}

void QuestionsManager::randomize(){
    srand(getpid() + time(NULL)); 
    map<unsigned short, Question> questionsTwo;
    for(int i = 0; i < this->lenght(); i++){
        int n = rand()%(this->lenght());
        while(this->ptr[n].getBody() == string()) if(n++ >= this->lenght()) n = 0;
        questionsTwo[i] = this->ptr[n];
        this->ptr.erase(n);
    }
    this->ptr = questionsTwo;
}

void QuestionsManager::randomize(unsigned int randomKey){
    srand(randomKey);
    map<unsigned short, Question> questionsTwo;

    for(int i = 0; i < this->lenght(); i++){
        int n = rand()%(this->lenght());
        while(this->ptr[n].getBody() == string()) if(n++ >= this->lenght()) n = 0;
        questionsTwo[i] = this->ptr[n];
        this->ptr.erase(n);
    }
    
    this->ptr = questionsTwo;
}

