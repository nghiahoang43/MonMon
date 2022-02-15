#include "Item_list.h"
#include "Item.h"
#include<string>
#include<iostream>
using namespace std;

//Function use switch to set name
extern string string_three_case(int number, string string_case[3]);

//Potion
//Potion type 1: attack potion
//Potion type 2: defense potion
//Potion type 3: premium potion

//Potion constructor
Potion::Potion(int potion_grade, int potion_type)
{
    grade = potion_grade;
    type = potion_type;

    //Set price for potion
    price = grade * 5;
    
    //If potion is type 3
    if (type == 3) price *= 2;

    //Set name for potion
    name = string_three_case(type, name_list) + " Potion" + " grade " + to_string(grade);
}

//Return potion index
int Potion::return_index()
{
    int index = type * 3 + grade -4;

    return index;
}

//Use potion
double* Potion::use_item()
{
    cout << "You've used " << name << ".\n";
    //Initialize
    double multiplier = 1;
    int stats_index = type - 1;

    //Get multiplier base on grade
    multiplier += grade * 0.25;

    //Multiply to the effect list
    if (type == 3)
    {
        effect_list[0] *= multiplier;
        effect_list[1] *= multiplier;
    }
    else effect_list[stats_index] *= multiplier;

    //Return effect list
    return effect_list;
}

//Potion destructor
Potion::~Potion(){}


//Monball
//Monball constructor
Monball::Monball(int ball_grade)
{
    grade = ball_grade;

    //Set price base on grade
    price = 10 * grade;

    //Set name
    name = string_three_case(grade, name_list) + " monball";
}

// Return ball index
int Monball::return_index()
{
    int index = 8 + grade;
    return index;
}

//Use monball 
double* Monball::use_item()
{
    cout << "You've used " << name << ".\n";
    //If grade 1 ball
    if (grade == 1) return probability_list;

    //Initialize
    double add_probability;

    //Get increase probability base on grade base on grade
    add_probability = 10 * (grade - 1);

    //Addition to the probability
    for (int i = 0; i < 3; i++)
    {
        probability_list[i] += add_probability;
    }

    //Return probability list
    return probability_list;
}

//Monball destructor
Monball::~Monball(){}