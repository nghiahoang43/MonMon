#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <limits>
#include "Monster.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Attribute.h"
#include "Species.h"
#include "Item_list.h"
#include "Item.h"
using namespace std;

int main()
{
    // create monster list
    Monster ** monster_list;
    monster_list = new Monster*[3];
    monster_list[0] = new Bear;
    monster_list[1] = new Chimera;
    monster_list[2] = new Slime;
    Person Person1(monster_list, 3);

    // testing function get_monster()
    string mname1 = "Testing_Monster_1";
    string mname2 = "Testing_Monster_2";
    string mname3 = "Testing_Monster_3";

    Person1.get_monster()->set_name(mname1);

    Person1.set_current_monster();
    Person1.get_monster()->set_name(mname2);

    Person1.set_current_monster();
    Person1.get_monster()->set_name(mname3);

    
    // testing print_monsters_list()
    cout << "Monsters List: " << endl;
    Person1.print_monsters_list();

    // testing print_monster_info()
    cout << "\nTest print_monsters_info: " << endl;
    Person1.print_monsters_info();
    Person1.print_monsters_info();

    // testing get_current_monster()
    int current_monster = Person1.get_current_monster();
    cout << "\nNumber of current monster: " << current_monster << endl;
    
    // testing set_name function
    string pname = "Testing_Person";
    Person1.set_name(pname);

    // testing get_name function
    string name = Person1.get_name();
    cout << "Name: " << name << endl;

    // testing release_monster()
    cout << "\nTest release all monster: " << endl;
    Person1.release_monster();
    Person1.release_monster();
    Person1.release_monster();

    // testing get_gold
    int gold = Person1.get_gold();
    cout << "Current gold: " << gold << endl;

    // testing set_gold function
    int pgold = 5;
    Person1.set_gold(pgold);
    gold = Person1.get_gold();
    cout << "Current gold: " << gold << endl;
    
    // testing update_tracker() function
    Person1.update_tracker();

    // testing buy()
    Person1.buy();
    Person1.buy();

    // testing print_monster_list function
    Person1.print_monsters_list();

    // testing print_inventory()
    Person1.print_inventory();

    // testing buy()
    Person1.buy();

    // testing get_level() function
    int level = Person1.get_level();
    cout << "Current level: " << level << endl;

    // testing show_exp()
    Person1.show_exp();

    Monster * comp_monster = new Bear();
    Computer Computer(comp_monster);

    cout << "Computer testing" << endl;

    // testing get_monster()
    Computer.get_monster();

    delete [] monster_list;
    delete comp_monster;

    return 0;
}