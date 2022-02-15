#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <string>
using namespace std;

//1: fire
//2: water
//3: eartch
//4: nature
//5: metal  

class Attribute
{
protected:
    //Attribute type
    int type;
    int type_boss[2] = {0,0};
    bool boss_check = false;

public:
    //Default constructor
    Attribute();
   
    //Method that return type
    int give_monster_attribute();

    //Method to compare attribute
    int compare_attribute(Attribute opponent);

    //Mehod to compare attribute with boss
    int compare_attribute_boss(int boss_id);

    //For testing purpose only
    Attribute(int element);

    //Destructor
    ~Attribute();
};
#endif