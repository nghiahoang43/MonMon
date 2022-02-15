#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Species.h"
using namespace std;

//Return a random number in the given range
extern int random_number(int upper, int lower);

//Rank 1:
//Attack variety range: 9
//Defense variety range: 4 

//Slime constructor
Slime::Slime()
{   
    species = "Slime";
    rank = 1;
    health = random_number(30, 20);
    attack_stats = random_number(10, 1);
    defense_stats = random_number(7, 3);
    element = Attribute();
}

//Slime eat
void Slime::eat() {cout << name << " consume everything. It bounces happily!!!\n";}

//Slime growl
void Slime::growl() {cout << "Boink boink.\n";}

//Slime destructor
Slime::~Slime(){}

//Eagle constructor
Eagle::Eagle()
{
    species = "Eagle";
    rank = 1;
    health = random_number(20, 15);
    attack_stats = random_number(12, 3);
    defense_stats = random_number(5, 1);
    element = Attribute();
} 

//Eagle eat
void Eagle::eat() {cout << name << " eats meat. It soars its wings!!!\n";}

//Eagle growl
void Eagle::growl() {cout << "Screeching.\n";}

//Eagle destructor
Eagle::~Eagle(){}


//Rank2:
//Attack variety range: 14
//Defense variety range: 8 

//Wolf constructor
Wolf::Wolf()
{
    species = "Wolf";
    rank = 2;
    health = random_number(50, 35);
    attack_stats = random_number(28, 14);
    defense_stats = random_number(16, 8);
    element = Attribute();
}

//Wolf eat
void Wolf::eat() {cout << name << " devours preys. It stares down as a predator!!!\n";}

//Wolf growl
void Wolf::growl() {cout << "Howling.\n";}

//Wolf destructor
Wolf::~Wolf(){}

//Bear constructor
Bear::Bear()
{   
    species = "Bear";
    rank = 2;
    health = random_number(60, 40);
    attack_stats = random_number(22, 8);
    defense_stats = random_number(20, 12);
    element = Attribute();
}

//Bear eat
void Bear::eat() {cout << name << " tears down its prey lazily. It sleeps afterward!!!\n";}

//Bear growl
void Bear::growl() {cout << "Grumbles.\n";}

//Bear destructor
Bear::~Bear(){}


//Rank3:
//Attack variety range: 32
//Defense variety range: 20 

//Chimera constructor
Chimera::Chimera()
{
    species = "Chimera";
    rank = 3;
    health = random_number(90, 55);
    attack_stats = random_number(50, 18);
    defense_stats = random_number(40, 20);
    element = Attribute();
}

//Chimera eat
void Chimera::eat() {cout << name << " nibbles then throws away its meal. It smirks!!!\n";}

//Chimera growl
void Chimera::growl() {cout << "Roars.\n";}

//Chimera destructor
Chimera::~Chimera(){}

//Dragon constructor
Dragon::Dragon()
{
    species = "Dragon";
    rank = 3;
    health = random_number(130, 80);
    attack_stats = random_number(68, 36);
    defense_stats = random_number(60, 40);
    element = Attribute();
}

//Dragon eat
void Dragon::eat() {cout << name << " eats its prey with gratitude. It is a majestic creature on top of the food chain!!!\n";}

//Dragon growl
void Dragon::growl() {cout << "Growling.\n";}

//Dragon destructor
Dragon::~Dragon(){}