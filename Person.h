#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Player.h"
#include "Computer.h"
#include "Monster.h"
#include "Attribute.h"
#include "Species.h"
#include "Item.h"
#include "Item_list.h"

using namespace std;

class Person : public Player
{
private:
    //Basic state of player
    string name;
    int max_monster; // max monsters player can have
    int current_monster; // current number of monsters
    int gold; // current gold
    int level; // current level
    int exp; // current exp
    bool* medal_list; // medal list

    Monster * monster; // first monster
    Monster ** monster_list; // monsters list
    
    Item ** inventory; //Inverntory list
    int capacity; //Inventory capacity
    int current_slots;
    string * items_name_list; // items_list
    int * items_amount; // items amount
    int total_monball; // total amount of monball

public:
    //Complex method
    Person(); //Person constructor
    void buy(); //Player buy from shop
    void level_up(); //Level up player
    void show_exp(); //Show player current exp (exp/100)
    void set_current_monster(); //Set monster to specific monster in a list
    void catch_monster(Monster * wild_monster); //Catch wild monster
    void release_monster(); //Release monster
    bool battle(Monster * comp_monster, bool check_boss, int zone_id); //Battle with other monsters
    void update_tracker(); //Update trackers after an action
    void print_monsters_info();  //Print current monster info
    void print_monsters_list();  //Print monsters list
    void print_inventory(); //Print player's inventory
    
    //Method that get player state
    virtual Monster * get_monster(); //Return current monster
    string get_name(); //Get player's name
    void set_name(string pname); //Set name to player
    int get_level(); //Return player's level
    bool * get_medal_list(); //Return medal list
    int get_current_monster(); //Return current monster
    int get_gold(); //Get current gold
    void set_gold(int income); //Set new gold
    
    //Testing purpose only
    Person(Monster ** new_monster_list, int number); //Person constructor with parameter

    //Destructor
    ~Person();
};

#endif