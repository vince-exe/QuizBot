#ifndef USER_H
#define USER_H

#include <iostream>

class User{
private:
    std::string name;
    int64_t id;
    unsigned int points;

public:
    User();
    User(std::string name, int64_t id, unsigned int points);
    User(User &user);
    User& operator=(User& user);
    void setName(std::string name);
    void setId(int64_t id);
    void setPoints(unsigned int points);
    std::string getName();
    int64_t getId();
    unsigned int getPoints();
    std::string toString();
};

#endif