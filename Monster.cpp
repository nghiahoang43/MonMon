#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <thread>
#include <chrono>
#include "Monster.h"
#include "Attribute.h"
using namespace std;

//Default monster constructor
Monster::Monster()
{
    level = 1;
    EXP = 0;
    name = "???";
}

//Complex method 
//Set monster name
void Monster::set_name(string mon_name)
{
    name = mon_name;
}

//Generate monster info
void Monster::mon_info()
{
    //Get monster attribute
    int type = element.give_monster_attribute();
    string mon_type;

    //Using switch to compare
    switch(type)
    {
        case 1:
            mon_type = "fire";
            break;
        case 2:
            mon_type = "water";
            break;
        case 3:
            mon_type = "earth";
            break;
        case 4:
            mon_type = "nature";
            break;
        case 5:
            mon_type = "metal";
            break;
    }

    //Display monster info
    cout << name << endl;
    cout << "Species: " << species << endl;
    cout << "Level: " << level << endl;
    cout << "Attribute: " << mon_type << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack_stats << endl;
    cout << "Defense: " << defense_stats << endl;

    //Feed monster
    cout << "\nYou try to feed the monster out of kindness.\n";
    eat();

    //Stop for 200 millisecond
    this_thread::sleep_for(chrono::milliseconds(200));
}

//Calculate exp gain from battle
int Monster::exp_gain_battle(bool battle_result, Monster *opponent)
{
    //Initialize
    int exp_base_battle, exp_gain;
    int add_monster_rank, mul_opp_rank;

    //Get exp base
    if (battle_result) exp_base_battle = 5;
    else exp_base_battle = 2;

    //Get addition from monster rank
    switch (rank)
    {
        case 1:
            add_monster_rank = 4;
            break;
        case 2:
            add_monster_rank = 2;
            break;
        case 3:
            add_monster_rank = 1;
            break;
    }

    //Get multiplier from opponent rank
    switch (opponent->rank)
    {
        case 1:
            mul_opp_rank = 1;
            break;
        case 2:
            mul_opp_rank = 2;
            break;
        case 3:
            mul_opp_rank = 4;
            break;
        case 4:
            mul_opp_rank = 5;
    }

    //Calculate exp gain and add it to monster
    exp_gain = (exp_base_battle + add_monster_rank) * (mul_opp_rank + opponent->level);
    EXP += exp_gain;

    //Return exp_gain
    return exp_gain;
}

//Check if monster can level up
void Monster::level_up()
{
    //Initialize
    int exp_level_up, exp_need;

    //Calculate exp need to level up
    exp_level_up = (rank * 10) * level;
    exp_need = EXP - exp_level_up;
    
    //If monster level up
    if (exp_need >= 0)
    {   
        //Stop for 500 millisecond
        this_thread::sleep_for(chrono::milliseconds(500));

        //Set new exp
        EXP = exp_need;

        //Set level and output to notify user
        level += 1;
        cout << name << " grows stronger. It is now level " << level << endl;

        //Get upgrade points and output to notify user
        switch(rank)
        {
            case 1:
                points = 5;
                break;
            case 2:
                points = 11;
                break;
            case 3:
                points = 17;
                break;
        }
        cout << name << " gains " << points << " upgrade points!\n";
        
        //Enough exp to level up
        upgrade_stats();
        return;
    }
}

//Upgrade monster stats
void Monster::upgrade_stats()
{   
    //Initialize
    int up_health, up_attack, up_defense;

    cout << "You can now upgrade " << name << "'s stats.\n\n";

    //Ask input from user for upgrade
    //Output monster info
    cout << name << " stats:\n";
    mon_info();
    cout << "\nUpgrade points: " << points << endl;

    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));

    //Validate user input
    while (true)
    {   
        //Ask for input
        cout << "Please enter points spent on upgrading stats in the following format: health attack defense.\n";
        cin >> up_health >> up_attack >> up_defense;
        cout << endl;

        //Check string
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nInvalid inputs!\n";
        }
        //Check negative
        else if((up_health < 0)||(up_attack < 0)||(up_defense < 0))
        {
            cout << "\nInvalid inputs!\n";
        }
        //Check if use more points than what monster have
        else if ((up_health + up_attack + up_defense) > points)
        {
            cout << "\nInvalid inputs!\n";
            cout << name << " only has " << points << " upgrade points.\n";
        }
        //Check if use less points than what monster have
        else if ((up_health + up_attack + up_defense) < points)
        {
            cout << "\nInvalid inputs!\n";
            cout << "You need to spend all " << points << " upgrade points.\n";
        }
        else break;
    }    
        
    //Upgrade monster stats
    health += up_health;
    attack_stats += up_attack;
    defense_stats += up_defense;
    points = 0;

    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));

    //Ouput monster new stats
    cout << "\nUpgrade successfully!\n";
    cout << endl << name << " new stats:\n";
    mon_info();
        
}

//Change wild monster stats base on level
void Monster::wild_monster_stats(int new_level)
{   
    //Initialize 
    int add_stats;

    //Set level for the wild monster
    //Later the level of wild monster will depend on zone
    set_level(new_level);

    //Base on rank to decide additional stats per level
    switch (rank)
    {
        case 1: add_stats = 2;
                break;
        case 2: add_stats = 4;
                break;
        case 3: add_stats = 6;
                break;
    }

    //Add to wild monster stats
    health += level * (add_stats);
    attack_stats += level * (add_stats);
    defense_stats += level * (add_stats);
}

//Method that return monster stats
string Monster::get_name() {return name;}

//Return monster rank
int Monster::get_rank() {return rank;}

//Return monster health
int Monster::get_health() {return health;}

//Return monster attack
int Monster::get_attack() {return attack_stats;}

//Return monster defense
int Monster::get_defense() {return defense_stats;}

//Return monster species
string Monster::get_species() {return species;}

//Return monster level
int Monster::get_level() {return level;}

//Return monster experience
int Monster::get_exp() {return EXP;}

//Private method for testing purpose only
//Set monster level
void Monster::set_level(int new_level) {level = new_level;}

//Set monster exp
void Monster::set_EXP(int new_EXP) {EXP = new_EXP;}

//Destructor
Monster::~Monster(){}