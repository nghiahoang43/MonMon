#include "Zone.h"
#include "Monster.h"
#include "Species.h"
#include "Boss.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Get input for test cases
    //Initalize
    int player_level;
    int medal;
    bool medal_list[3] = {false, false, false};
    Zone *zone1, *zone2, *zone3;
    Monster *boss1, *boss2, *boss3;

    //Take in input for zone 1 testing
    cin >> player_level;
    for (int i = 0; i < 3; i++)
    {
        cin >> medal;
        if (medal != 0) medal_list[i] = true;
        else medal_list[i] = false;
    }

    //Testing for zone_permission(int player_level, bool* medal_list) and spawn_zone_boss()    
    //Zone 1 testing
    zone1 = new Zone(1);
    cout << "Permission zone 1: " << zone1->zone_permission(player_level, medal_list) << endl;
    boss1 = new Boss(1);
    cout << "Boss zone 1: " << boss1->get_name() << endl;

    //Take in input for zone 2 testing
    cin >> player_level;
    for (int i = 0; i < 3; i++)
    {
        cin >> medal;
        if (medal != 0) medal_list[i] = true;
        else medal_list[i] = false;
    }

    //Zone 2 testing
    zone2 = new Zone(2);
    cout << "Permission zone 2: " << zone2->zone_permission(player_level, medal_list) << endl;
    boss2 = new Boss(2);
    cout << "Boss zone 1: " << boss2->get_name() << endl;

    //Take in input for zone 3 testing
    cin >> player_level;
    for (int i = 0; i < 3; i++)
    {
        cin >> medal;
        if (medal != 0) medal_list[i] = true;
        else medal_list[i] = false;
    }

    //Zone 3 testing
    zone3 = new Zone(3);
    cout << "Permission zone 3: " << zone3->zone_permission(player_level, medal_list) << endl;
    boss3 = new Boss(3);
    cout << "Boss zone 1: " << boss3->get_name() << endl;
    return 0;
}