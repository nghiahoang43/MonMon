#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Computer.h"
#include "Attribute.h"
#include "Species.h"
using namespace std;

//Constructor of Computer
Computer::Computer(Monster * cmonster)
{
    // set name (format: COMP NO.1)
    name = "COMP NO.???";
    // random species
    monster = cmonster;
}

//Return current monster
Monster * Computer::get_monster(){return monster;}

//Destructor
Computer::~Computer(){}