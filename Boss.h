#ifndef BOSS_H
#define BOSS_H
#include <string>
#include <cstdlib>
#include "Monster.h"
#include "Attribute.h"
using namespace std;

class Boss: public Monster
{   
    protected:
    //Protected state
    int boss_id;
    string attribute;
    string name_list[3] = {"Wind Wolf", "Thunder Bear", "Evil Dragon"};
    string species_list[3] = {"Wolf", "Bear", "Dragon"};
    string attribute_list[3] = {"wind", "thunder", "evil"};
    int level_list[3] = {9, 16, 666};
    int health_list[3] = {90, 125, 666};
    int attack_list[3] = {70, 85, 666};
    int defense_list[3] = {55, 90, 666};

    public:
    //Constructor with parameter
    Boss(int zone_id);

    //Method that return boss info
    virtual void mon_info();

    //Virtual method growl for boss
    virtual void growl();

    //Do not need virtual method eat for boss
    virtual void eat();

    //Destructor
    ~Boss();
};
#endif