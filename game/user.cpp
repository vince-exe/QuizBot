#include "user.h"

User::User(){
    this->name=std::string();
    this->id=0;
    this->points=0;
}

User::User(std::string name, int64_t id, int points){
    this->name=name;
    this->id=id;
    this->points=points;
}

User::User(int64_t id, int points) {
    this->id=id;
    this->points=points;
}

User& User::operator=(User& user){
    this->id = user.id;
    this->name = user.name;
    this->points = user.points;

    return *this;
}

void User::setName(std::string name){
    this->name=name;
}

void User::setId(int64_t id){
    this->id=id;
}

void User::setPoints(int points){
    this->points=points;
}

std::string User::getName(){
    return this->name;
}

int64_t User::getId(){
    return this->id;
}

int User::getPoints(){
    return this->points;
}

std::string User::toString(){
    return std::string("Name: "+this->getName()+"\nId: "+std::to_string(this->getId())+"\nPoints: "+std::to_string(this->getPoints()));
}