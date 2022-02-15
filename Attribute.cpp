#include <string>
#include <ctime>
#include "Attribute.h"
using namespace std;

//Generate a random number within the given range
extern int random_number(int lower, int upper);

//Default constructor that set type
Attribute::Attribute() {type = random_number(1, 5);}

//Methode that return type of attribute
int Attribute::give_monster_attribute() {return type;}

//Method that compare with opponent's attribute
int Attribute::compare_attribute(Attribute opponent)
{
    //Get opponent attribute
    int opp_type = opponent.give_monster_attribute();
    
    //Compare attribute using switch
    switch(type)
    {
        //Fire
        case 1:
            if (opp_type == 5) return 1;
            break;
        //Water
        case 2:
            if (opp_type == 1) return 2;
            break;
        //Earth
        case 3:
            if (opp_type == 2) return 2;
            break;
        //Nature
        case 4:
            if (opp_type == 3) return 3;
            break;
        //Metal
        case 5:
            if (opp_type == 4) return 1;
            break;
    }

    return 0;
}

//Method that compare with boss monster
int Attribute::compare_attribute_boss(int boss_id)
{
    //Use switch to split case
    switch (boss_id)
    {
        //Wind wolf is weak against metal
        case 0:
            if (type == 5) return 1;
            break;

        //Thunder bear is weak against earth
        case 1:
            if (type == 3) return 2;
            break;

        //Evil dragon is weak against nature
        case 2:
            if (type == 4) return 3;
    }

    //No advantage over attribute
    return 0;
}

//For testing purpose only
Attribute::Attribute(int element) {type = element;}

//Destructor
Attribute::~Attribute(){}