#ifndef SPECIES_H
#define SPECIES_H
#include <string>
#include <cstdlib>
#include "Attribute.h"
#include "Monster.h"
using namespace std;

//Rank 1 monster
class Slime: public Monster
{
public:
    //Default constructor
    Slime();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Slime();
};

//Rank 1 monster
class Eagle: public Monster
{
public:
    //Default constructor
    Eagle();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Eagle();
};

//Rank 2 monster
class Wolf: public Monster
{
public:
    //Default constructor
    Wolf();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Wolf();    
};

//Rank 2 monster
class Bear: public Monster
{
public:
    //Default constructor
    Bear();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Bear();
};

//Rank 3 monster
class Chimera: public Monster
{
public:
    //Default constructor
    Chimera();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Chimera();
};

//Rank 3 monster
class Dragon: public Monster
{
public:
    //Default constructor
    Dragon();

    //Method:
    //Monster eat food
    virtual void eat();

    //Monster growl
    virtual void growl();

    //Destructor
    ~Dragon();
};
#endif