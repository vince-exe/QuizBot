#ifndef USER_H
#define USER_H

#include <iostream>

class User{
private:
    std::string name;

    int64_t id;

    int points;

public:
    User();

    User(std::string name, int64_t id, int points);
    
    User(int64_t id, int points);

    User& operator=(User& user);

    void setName(std::string name);

    void setId(int64_t id);

    void setPoints(int points);

    std::string getName();

    int64_t getId();

    int getPoints();
    
    std::string toString();
};

#endif