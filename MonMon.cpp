#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <limits>
#include <thread>
#include <chrono>
#include <fstream>
#include "Monster.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Attribute.h"
#include "Species.h"
#include "Item.h"
#include "Item_list.h"
#include "Zone.h"
#include "Boss.h"
using namespace std;

//Use function to reduce duplicate code
//Validate input, making sure it is a valid integer in given range
extern int validate_input(int lower, int upper, string text);

//Validate input for yes no question
extern char validate_yn_input(string question);

//Return a random number in the given range
extern int random_number(int lower, int upper);

int main()
{   
    //Ask user if they want to read rule
    char answear = validate_yn_input("Do you want to read rule? (y/n) ");
    
    //Load rule into the screen 
    if (answear == 'y') 
    {
        cout << ifstream("MonMon_rule.txt").rdbuf();
        this_thread::sleep_for(chrono::milliseconds(5000));
    }

    //Random seed
    srand(time(NULL));

    //Initiaize win variable
    bool win;

    //Start game and initialize player
    cout << "Welcome to MonMon." << endl;
    cout << "The Adventure starts now!" << endl;
    cout << "You have 100 golds and 3 Normal Monballs at start." << endl;
    
    //Get Player name and initialize player object
    //Set name
    cout << "Please set your name: ";
    string pname;
    cin >> pname;
    
    //Inititalize Player object, the game start is incorporate into the initalize of person
    Person User;
    User.set_name(pname);

    //You get a monster at the start. The details are included in the design documentation 
    cout << "Please set your new monster name: ";
    string mon_name;
    cin >> mon_name;
    User.get_monster()->set_name(mon_name);
    cout << endl;

    //Initialize variable
    Zone *zone;
    Monster *wild_monster, *boss;
    int level;

    //Get medal list to check for zone permission
    bool* medal_list;
    bool permission;

    //The main game. This is run in a while loop until player choose to quit
    while (true)
    {
        //Stop for 500 milisecond
        this_thread::sleep_for(chrono::milliseconds(500));
        //Game menu
        cout << "\nHi, " << User.get_name() << endl;
        cout << "\nMain Menu:\n";
        cout << "0. Clear screen\n";
        cout << "1. Enter Zone\n";
        cout << "2. Buy items\n";
        cout << "3. Show your monster list\n";
        cout << "4. Show your current gold\n";
        cout << "5. Show your inventory\n";
        cout << "6. Set your monster name\n";
        cout << "7. Release your monster\n";
        cout << "8. Check your level\n";
        cout << "9. Quit game\n";

        //Get choice from player
        int choice;
        choice = validate_input(0, 9, "\nPlease choose what to do next: ");

        //Choide 0: Clear terminal
        if (choice == 0)
        {
            system("clear");
        }

        //Choice 1: Enter zone
        else if (choice == 1)
        {
            while (true)
            {
                //Stop for 500 milisecond
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "\nZone Menu\n";
                cout << "1. Zone 1\n";
                cout << "2. Zone 2\n";
                cout << "3. Zone 3\n";
                cout << "4. Quit Zone menu\n";   
                
                //Ask for user input
                int zone_id;
                zone_id = validate_input(1,4,"\nPlease choose zone to enter: ");

                //Go back to main menu
                if (zone_id == 4)
                {
                    break;
                }
                
                //Initialize variable

                zone = new Zone(zone_id);
                level = User.get_level();

                //Get medal list to check for zone permission
                medal_list = User.get_medal_list();
                permission = zone->zone_permission(level, medal_list);

                //Check if user can enter the zone
                if (permission == false) cout << "You don't meet the requirements. You suck\n";
                else
                {   
                    int zone_choice;
                    while (true)
                    {   
                        //Stop for 500 milisecond
                        this_thread::sleep_for(chrono::milliseconds(500));
                        cout << "\nZone " << zone->get_zone_id() << ":\n";
                        cout << "1. Find NPC\n";
                        cout << "2. Catch Wild Monster\n";
                        cout << "3. Fight zone BOSS\n";
                        cout << "4. Return to Zone menu\n";

                        //Ask fo user choice
                        zone_choice = validate_input(1,4,"\nPlease choose what to do next: ");

                        //Zone choice 1: Find NPC
                        if (zone_choice == 1)
                        {
                            cout << "You've encoutered a NPC\n";
                            // Initialize monster by zone id
                            wild_monster = zone->spawn_monster_zone(level);

                            //Initializze computer as NPC
                            Computer NPC(wild_monster);
                            
                            //Battle with NPC and get results
                            win = User.battle(NPC.get_monster(), false, zone_id);
                            
                            //Win against the monster and you can check if player level up
                            if (win) User.level_up();
                        }
                        //Zone choice 2: Catch Wild Monster
                        else if (zone_choice == 2)
                        {
                            cout << "You've encoutered a wild monster\n";
                            //Initialize new wild monster by zone id
                            wild_monster = zone->spawn_monster_zone(level);
                            win = User.battle(wild_monster, false, zone_id);

                            //Win against the monster and you can catch
                            if (win)
                            {
                                User.catch_monster(wild_monster);
                                User.level_up();
                            }
                            //Lose and you can not catch the monster
                            else cout << "\nIt fleed away!\n";
                        }
                        //Zone choice 3: Fight zone BOSS
                        else if (zone_choice == 3)
                        {
                            //Check if user has defeate zone BOSS already
                            if (medal_list[zone_id-1]) cout << "\nYou have already defeated the zone BOSS!\n";
                            //Check if user has enough money to challenge BOSS
                            else if (User.get_gold() < 10) cout << "\nYou do not have 10 golds to fight zone BOSS.\n";
                            else
                            {
                                User.set_gold(-10);
                                cout << "\nYou have paid entry fee. You can now fight zone BOSS.\n";
                                cout << "You've encountered the BOSS of this zone\n";
                                
                                //Initialize boss
                                boss = new Boss(zone_id);
                                boss->growl();
                                
                                //Stop for 500 milisecond
                                this_thread::sleep_for(chrono::milliseconds(500));
                                win = User.battle(boss, true, zone_id);
                                
                                //If win against boss
                                if (win)
                                {   
                                    User.level_up();
                                    //If not zone 3 boss
                                    if (zone_id != 3) 
                                    {
                                        cout << endl;
                                        cout << boss->get_name() << " gives up. It warns you about the corruption aura!\n";
                                        //Update medal for defeating boss
                                        medal_list[zone_id-1] = true;
                                    }

                                }
                                //Lost against boss
                                else 
                                {
                                    //If lost against zone 3 BOSS, Easter egg
                                    if (zone_id == 3)
                                    {
                                        cout << "\nYou should have listen to them, foolish human!\n";
                                        cout << "\nGame is glitched by corruption aura. Terminate program!\n";
                                        
                                        return 0;
                                    }
                                }
                            }
                        }
                        //Zone choice 4: Return to zone menu
                        else if (zone_choice == 4)
                        {
                            cout << "Quit zone!\n";
                            //Deallocate zone
                            delete zone;
                            break;
                        }
                    }
                } 
            }
        }

        //Choice 2: Buy items
        else if (choice == 2)
        {
            if (User.get_gold() > 0) User.buy();
            else cout << "\nYou are broke. What do you want to buy? Free air???\n";
        }
        
        //Choice 3: Show your monster list
        else if (choice == 3) User.print_monsters_info();

        //Choice 4: Show your current gold
        else if (choice == 4) cout << "\nYour current gold is: " << User.get_gold() << endl;
        
        //Choice 5: Show your inventory
        else if (choice == 5)
        {
            cout << "\nYour inventory: \n";
            User.print_inventory();
        }

        //Choice 6: Set your monster name
        else if (choice == 6)
        {
            User.set_current_monster();

            //Set monster anme
            string mon_name;
            cout << "\nPlease set your new monster name: ";
            cin >> mon_name;
            User.get_monster()->set_name(mon_name);
        }
        //Choice 7: Release monster
        else if (choice == 7) User.release_monster();
        
        //Choice 8: Show player exp
        else if (choice == 8) User.show_exp();
        
        //Choice 9: Quit game
        else if (choice == 9)
        {
            cout << "\nThank you for playing!\n";
            return 0;
        }
        //Update trackers
        User.update_tracker();
    }
    return 0;
}