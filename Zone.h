#ifndef ZONE_H
#define ZONE_H
#include <string>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Species.h"
#include "Attribute.h"
#include "Boss.h"
using namespace std;

class Zone
{
    protected:
    //Protected state of zone
    int zone_id;
    
    public:
    //Default constructor
    Zone(int id);

    //Method
    //Check condition to enter zone
    bool zone_permission(int player_level, bool* medal_list);

    //Generate monster in zone
    Monster* spawn_monster_zone(int player_level);
    
    //Get zone id
    int get_zone_id();  

    //Destructor
    ~Zone();
};
#endif