#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Monster.h"
#include "Attribute.h"
#include "Species.h"
using namespace std;

class Player
{
private:
    //Player state
    string name;
    int max_monster;
    int current_monster;
    int gold;
    int level;
    int exp;
    Monster * monster; //Monster

public:
    //Player behaviour
    virtual Monster * get_monster()=0;
};

#endif

