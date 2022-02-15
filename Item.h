#ifndef ITEM_LIST_H
#define ITEM_LIST_H
#include "Item.h"
#include<string>
#include<iostream>
#include<string>
using namespace std;

class Potion: public Item
{
    protected:
    //State
    int type;
    double effect_list[2] = {1, 1};
    string name_list[3] = {"ATTACK", "DEFENSE", "PREMIUM"};

    public:
    //Constructor that take in grade and type
    Potion(int potion_grade, int potion_type);

    //Behaviour
    //Use item and apply its effect
    virtual double* use_item();

    //Return index
    virtual int return_index();

    //Destructor
    ~Potion();
};

class Monball: public Item
{
    protected:
    //State
    double probability_list[3] = {80, 50, 20};
    string name_list[3] = {"NORMAL", "GREAT", "MASTER"};

    public:
    //Constructor that take in grade
    Monball(int ball_grade);

    //Behaviour
    //Use item and apply its effect
    virtual double* use_item();

    //Return index
    virtual int return_index();

    //Destructor
    ~Monball();
};
#endif