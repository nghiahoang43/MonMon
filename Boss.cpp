#include <iostream>
#include <string>
#include "Boss.h"
#include "Monster.h"
#include "Attribute.h"
using namespace std;

//Boss constructor take in zone id
Boss::Boss(int zone_id)
{   
    //Get boss id from zone id
    boss_id = zone_id - 1;

    //Set information for boss
    name = name_list[boss_id];
    species = species_list[boss_id];
    health = health_list[boss_id];
    attack_stats = attack_list[boss_id];
    defense_stats = defense_list[boss_id];
    attribute = attribute_list[boss_id];
    
    //Set rank and level for boss
    rank = 4;
    level =  level_list[boss_id];
}

//Method that return boss info
void Boss::mon_info()
{
    cout << endl;
    cout << name << endl;
    cout << "Rank: 4\n";
    cout << "Level: " << level << endl;
    cout << "Attribute: " << attribute << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack_stats << endl;
    cout << "Defense: " << defense_stats << endl;
} 

//Virtual method growl for boss
void Boss::growl()
{   
    //Each boss has different growl
    switch (boss_id)
    {
        //Wind wolf
        case 0: cout << "\nThe royal white wolf look at with deepest compassion. It told you to stop!\n";
                break;

        //Thunder bear
        case 1: cout << "\nThe almighty bear using its force to push you back. It is dangerous to go any further!\n";
                break;

        //Evil dragon
        case 2: cout << "\nThe dragon has an awful corruption aura. It has done so many bad things and no one can stop it!\n";
                break;
    }
}

//Virtual method eat for boss
void Boss::eat()
{   
    cout << "\nMythical mutated monster absorb energy from the environment!!!\n";
}

//Destructor
Boss::~Boss()
{}