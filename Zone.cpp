#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Zone.h"
#include "Monster.h"
#include "Species.h"
#include "Boss.h"
using namespace std;

//Generate a random number in the given range
extern int random_number(int lower, int upper);

//Constuctor that take id
Zone::Zone(int id) {zone_id = id;}

//Check condition to enter zone
bool Zone::zone_permission(int player_level, bool* medal_list)
{
    //Initialize a copy
    int zone = get_zone_id();

    //Check zone 1
    if (zone == 1) return true;

    //Set requirement list base on zone 2 and 3
    //Initialize
    int level_required;
    int medal_index = zone - 2;

    //Using switch to set level required
    switch (zone)
    {
        //Zone 2: level 5
        case 2: 
            level_required = 5;
            break;
        //Zone 3: level 12
        case 3: 
            level_required = 12;
            break;
    }

    //Check requirements adn return to main
    if ((player_level < level_required) || (medal_list[medal_index] == false)) return false;
    else return true;
}

//Generate monster in zone
Monster* Zone::spawn_monster_zone(int player_level)
{
    //Initalize
    int zone = get_zone_id();
    int spawned_monster_level;
    int probability;
    Monster* wild_monster;

    //Probability for each monster
    probability = random_number(1, 100);

    //Species in each zone
    //Zone 1: Slime, Eagle and Wolf
    if (zone == 1)
    {
        //Generate monster based on probability
        if (probability < 46) wild_monster = new Slime();
        else if (probability < 81) wild_monster = new Eagle();
        else wild_monster = new Wolf();
    }
    //Zone 2: Eagle, Wolf and Bear
    else if (zone == 2)
    {
        //Generate monster based on probability
        if (probability < 21) wild_monster = new Eagle();
        else if (probability < 66) wild_monster = new Wolf();
        else wild_monster = new Bear();
    }
    //Zone 3: Bear, Chimera and Dragon
    else if (zone == 3)
    {
        //Generate monster based on probability
        if (probability < 31) wild_monster = new Bear();
        else if (probability < 81) wild_monster = new Chimera();
        else wild_monster = new Dragon();
    }

    //Set spawned monster level
    if (wild_monster->get_rank() == 3)
    {
        if (player_level < 16) spawned_monster_level = random_number(1, 8);
        else spawned_monster_level = random_number(9, 12);
    }
    else if (player_level < 3) spawned_monster_level = random_number(1, 4);
    else if (player_level < 5) spawned_monster_level = random_number(5, 7);
    else if (player_level < 8) spawned_monster_level = random_number(8, 11);
    else if (player_level < 12) spawned_monster_level = random_number(12, 14);
    else if (player_level < 16) spawned_monster_level = random_number(15, 17);
    else spawned_monster_level = random_number(18, 20);

    //Set spawned monster stats based on level
    wild_monster->wild_monster_stats(spawned_monster_level);

    //Return wild monster
    return wild_monster;
}
    
//Get zone id
int Zone::get_zone_id(){return zone_id;}

//Destructor
Zone::~Zone(){}