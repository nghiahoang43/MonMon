#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Attribute.h"
#include "Species.h"
#include "Zone.h"
using namespace std;

class Computer : public Player
{
private:
    //Computer state
    string name; //Name of comp
    Monster* monster; //Monster

public:
    //Computer behaviour
    //Computer constructor that take in monster parmeter
    Computer(Monster * cmonster);
    //Return current monster
    virtual Monster * get_monster(); 

    //Destructor
    ~Computer();
};

#endif