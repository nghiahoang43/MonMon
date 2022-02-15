#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Attribute.h"
using namespace std;

class Monster
{
protected:
    // Basic state that restricted access
    string species;
    int health;
    int attack_stats;
    int defense_stats;
    int level;
    int EXP;
    int rank;
    int points;

public:
    //Basic state that can be accessed
    Attribute element;
    string name;
        
    //Behaviour
    //Virtual Behaviour
    //Monster eat
    virtual void eat()=0;
    //Monster growl 
    virtual void growl()=0;
    //Give monster info
    virtual void mon_info();

    //Behaviours that are complex
    //Default monster constructor
    Monster();
    //Set monster name
    void set_name(string mon_name);
    //Calculate exp gain from battle
    int exp_gain_battle(bool battle_result, Monster *opponent);
    //Check if monster can level up
    void level_up();
    //Upgrade monster stats
    void upgrade_stats();
    //Change wild monster stats base on level
    void wild_monster_stats(int new_level);
    
    //Behaviours that return monster stats
    string get_name();
    int get_rank();
    int get_health();
    int get_attack();
    int get_defense();
    string get_species();
    int get_level();
    int get_exp();

    //Only use for test ting
    void set_level(int new_level);
    void set_EXP(int new_EXP);

    //Destructor
    virtual ~Monster();
};
#endif