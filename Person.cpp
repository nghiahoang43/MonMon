#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <limits>
#include <thread>
#include <chrono>
#include "Monster.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include "Attribute.h"
#include "Species.h"
#include "Item_list.h"
#include "Item.h"
using namespace std;

//Validate input, making sure it is a valid integer in given range
extern int validate_input(int lower, int upper, string text);

//Validate input for yes no question
extern char validate_yn_input(string question);

//Function use switch to set number
extern int number_three_case(int number, int number_case[3]);

//Return a random_number in the given range
extern int random_number(int lower, int upper);

//Get monster stats advantage after compare attribute
void after_attribute_stats(int *atk, int *def, int numb)
{
    switch (numb)
    {
        //fire, metal
        case 1: 
            cout << "\nYour monster's attack has increased.\n";
            *atk *= 2;
            break;

        //water, earth
        case 2: 
            cout << "\nYour monster's defense has increased.\n";
            *def *= 2;
            break;
        
        //nature
        case 3: 
            cout << "\nYour monster's attack and defense have increased.\n";
            *atk *= 2;
            *def *= 2;
            break;
    }
}

//Constructor of person
Person::Person()
{
    //Set values
    //Start with 100 golds, level 1, 0 exp, unknown name, 3 monster balls
    gold = 100;
    level = 1;
    exp = 0;
    name = "Unknown";

    //Initialize inventory
    //Allocate 12 spaces for inventory
    inventory = new Item * [12];
    //Initialize potions
    for (int i = 0; i < 9; i++)
    {
        int grade = (i+1) % 3;
        if (grade == 0)
        {
            grade = 3;
        }
        int potion_type = ((i+1)/3) + 1;
        if ((i+1)%3 == 0)
        {
            potion_type--;
        }
        inventory[i] = new Potion(grade, potion_type);

    }

    //Initialize monballs
    for (int i = 9; i < 12; i++)
    {
        int grade = (i+1) % 3;
        if (grade == 0)
        {
            grade = 3;
        }
        inventory[i] = new Monball(grade);
    }

    //Initialize items_name_list
    items_name_list = new string[12];

    for (int i = 0; i < 12; i++)
    {
        items_name_list[i] = inventory[i]->get_name();
    }
    
    //Initialize items_amount list
    items_amount = new int[12];
    for (int i = 0; i < 12; i++)
    {
        items_amount[i] = 0;
    }

    //Initialize medal list
    medal_list = new bool[3];
    medal_list[0] = false;
    medal_list[1] = false;
    medal_list[2] = false;

    //Set variable to keep track of avaiable slots
    capacity = 5;
    current_slots = 0;

    //Set Normal monball in items_list to 3
    items_amount[9] = 3;
    total_monball = items_amount[9] + items_amount[10] + items_amount[11];
    max_monster = 3;

    //Set current monster to 0 and create monster_list
    current_monster = 0;
    monster_list = new Monster*[max_monster];

    //Random rank of the monster
    int rank;
    // rank 1 = 70%
    // rank 2 = 25%
    // rank 3 = 5% (only need to create rank 1 & rank 2)
    double rank1_rate = 70;
    double rank2_rate = 25;

    //Initialize gold_spend variable: amount of golds user spend to increase rank 3 monster
    int gold_spend;
    char ans;
    ans = validate_yn_input("\nDo you want to spend money to increase the rate of getting rank 3 monster? (y/n) ");

    //Answer (y/n)
    //If the answer is yes
    if (ans == 'y')
    {
        gold_spend = validate_input(0, 100, "\nHow many golds do you want to spend? (1 gold = +0.1%): ");
               
        //Subtract gold_spend from gold
        set_gold(-1*gold_spend);

        //Decrease rank1 and rank2 monster rate
        rank1_rate = rank1_rate - (gold_spend * 0.1)/2;
        rank2_rate = rank2_rate - (gold_spend * 0.1)/2;
    }
    
    cout << "rank 1: 0 - " << rank1_rate << endl;
    cout << "rank 2: " << rank1_rate << " - " << rank1_rate + rank2_rate << endl;
    cout << "rank 3: " << rank1_rate + rank2_rate << " - 100" << endl;

    //Random rate from 0 to 100
    int rank_rate = random_number(1, 100);
    
    //Base on rank rate, generate rank of the monster
    //Rank 1
    if (rank_rate <= rank1_rate) rank = 1;
    //Rank 2
    else if ((rank_rate > rank1_rate) && (rank_rate < (rank1_rate + rank2_rate))) rank = 2;
    //Rank 3
    else rank = 3;
    
    //Random number between 1,2 to give a random monster in a rank. Each rank only has 2 species
    int number = random_number(1,2);

    //Calculate species base on monster rank, and a random species in a rank
    int species = (rank * 2) + number - 2;

    //Create the monster base on species
    switch (species)
    {
        case 1:
            monster = new Slime;
            break;

        case 2:
            monster = new Eagle;
            break;

        case 3:
            monster = new Wolf;
            break;

        case 4:
            monster = new Bear;
            break;

        case 5:
            monster = new Chimera;
            break;

        case 6:
            monster = new Dragon;
            break;
    }
    cout << "\nCongratulations! You got a " << monster->get_species();

    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));

    //Show the stats of the monster
    cout << "\nYour monster's stats are:\n";
    monster->mon_info();

    //Add the monster to the list
    monster_list[current_monster] = monster;
    current_monster++;

    //Track inventory
    update_tracker();
}

//Player buys items from shop
void Person::buy()
{
    //Print out player gold
    cout << "\nYour current gold: " << get_gold() << endl;

    while (true)
    {
        //Print items list
        for (int i = 0; i < 12; i++)
        {
            cout << i+1 << ". " << items_name_list[i];
            if ((i >=0) && (i < 9)) cout << "\t"; 
            else cout << "\t\t"; 
            cout << inventory[i]->get_price() << " golds" << endl;
        }
        
        //Use tracker to keep track of items in inventory and slots
        update_tracker();

        // initialize choice to let player choose an item to buy
        int choice;
        cout << "\nEnter 0 if you want to go back to menu.";
        choice = validate_input(0, 12, "\nPlease choose the item you want to buy by choosing the position number: ");
        
        //Player choose not to buy
        if (choice == 0) return;

        //Choose the selected items
        int index = choice - 1;
        Item * item = inventory[index];
        
        //Initialize amount of the item
        int amount;
        while (true)
        {
            //Ask the player to input the amount
            amount = validate_input(0, INT16_MAX, "\nPlease enter the amount of " + item->get_name() + " that you want to buy: ");

            //Not buying anything
            if (amount == 0) 
            {
                cout << "\nYou did not buy anything!\n";
                return;
            }       
            //Check enough gold
            else if (get_gold() < (amount * item->get_price()))
            {
                cout << "\nYou do not have enough gold. Search your pocket again?\n";
            }
            //Check capacity
            else if ((current_slots + amount) > capacity)
            {
                cout << "\nOut of slots!\n";
            }
            else break;
        }
        cout << "\nComplete purchase! You got " << amount << " " << item->get_name() << "!\n";

        //Set gold after purchasing
        int expense = amount * item->get_price() * (-1);
        set_gold(expense);
        cout << "\nYour current gold: " << get_gold() << endl;

        //Increase item in bag
        items_amount[index] += amount;      
    }   
}

//Player levels up
void Person::level_up()
{
    //Initialize exp to level up
    int exp_required = level * 20;
    int exp_diff = exp - exp_required;

    //Check if meet the required exp to level up
    if (exp_diff >= 0)
    {   
        //Stop for 500 millisecond
        this_thread::sleep_for(chrono::milliseconds(500));

        // increase level by 1
        level++;
        cout << "\nYou've leveled up! Your current level: " << level << endl;
        // set exp to exp_diff
        exp = exp_diff;
        // increase capacity by 5
        capacity+=5;
    }
}

//Show player exp (format:LEVEL ?: ?/100)
void Person::show_exp()
{
    int exp_required = level * 20;
    cout << "LEVEL " << level << ": " << exp << "/" << exp_required << endl;
}

//Player choose monster to interact from the list
void Person::set_current_monster()
{
    // show monster list
    cout << "\nYour monster list:\n";
    print_monsters_list();

    // Ask to choose
    int monster_number;
    monster_number = validate_input(1, current_monster, "\nChoose the monster you want by enter the intial number: ");

    // set chosen monster to fight
    monster = monster_list[monster_number-1];
}

//Player catches monster
void Person::catch_monster(Monster * wild_monster)
{
    //Check player has monball
    if (total_monball <= 0)
    {
        cout << "\nYou don't have enough monster ball to catch this monster!\n";
        return;
    }
    //Check player has slots to catch monster
    else if (current_monster == max_monster) 
    {
        cout << "\nYou can only have 5 monsters at the same time. Release your old monster to catch new one.\n";
        return;
    }
    //Catch monster using monball
    else
    {
        //Print out list of Monball
        cout << "\nMonball list\n";      
        for (int i = 0; i < 3; i++)
        {
            cout << i+1 << ". " << items_name_list[9+i] << ": " << items_amount[9+i] << endl;
        }
        
        //Get choice
        int choice;
        cout << "\nEnter 0 if you do not want to catch.";
        while (true)
        {
            //Choose what kind of mon balls
            choice = validate_input(0, 3, "\nChoose the type of monball do you want to use by enter the inital number: ");
            if (choice == 0)
            {
                cout << "\nYou choose not to catch the monster.\nYou seem to be a pacific with all the battle you are doing!\n";
                return;
            }
            //Check if you have this monball
            else if (items_amount[9+choice-1] == 0)
            {
                cout << "\nYou don't have this kind of monball!\n";
            }
            else break;
        }

        //Random rate to catch monster
        int probability_list[3]= {70, 50, 20};
        int initial_success_rate;
        initial_success_rate = number_three_case(wild_monster->get_rank(), probability_list);
        int rate = random_number(1, 100);

        //Initialize success rate by type of balls
        int increased_success_rate;
        increased_success_rate = (choice-1) * 10;
        int success_rate = initial_success_rate + increased_success_rate;

        //Stop for 500 millisecond
        this_thread::sleep_for(chrono::milliseconds(500));

        //Random from 1 to 100, if the return nmber is smaller than sucess rate then catch monster
        if (rate < success_rate)
        {
            //Change monster name and add monster to the list
            wild_monster->set_name("New Monster");
            monster_list[current_monster] = wild_monster;

            //Player earns 5 golds and 3 exp 
            cout << "\nYou've catched a monster!\n";
            cout << "\nYou got 5 golds and 3 exp!\n";
            set_gold(5);
            exp += 3;
            
            //Increase current_monster by 1
            current_monster++;

            //Decrease the chosen item amount by 1
            items_amount[9+choice-1]--;

            //Print new monster's stats
            cout << "\nNew monster's stats are: " << endl;
            wild_monster->mon_info();
        }
        else
        {
            //The monster flees
            cout << "\nYou've failed to catch this monter!\n";
            cout << "\nIt fleed away!\n";

            //Decrease the chosen item amount by 1
            items_amount[9+choice-1]--;
        }
        return;
    }
}

//Player releases monster
void Person::release_monster()
{
    //Show the monster list
    cout << "\nYour monster list:\n";
    print_monsters_list();

    //If there is only one monster in the list
    if (current_monster == 1)
    {
        cout << "\nYou can't release any monster because you only have one monster!\n";
        return;
    }

    //Ask to choose
    int monster_number;
    monster_number = validate_input(1 ,current_monster ,"\nChoose the monster you want by enter the intial number: ");
    cout << "\nYou give " << monster_list[monster_number-1]->get_name() << " freedom! It stares at you and then leaves\n";
    cout << "What was that stare?\n";
    
    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));

    //Change the list
    for (int i = monster_number-1; i < current_monster; i++)
    {
        monster_list[i] = monster_list[i+1];
    }
    current_monster--;
}

//Player battle using their monster
//Return true: win, false: lose
bool Person::battle(Monster * comp_monster, bool check_boss, int zone_id)
{
    //Show opponent's info
    cout << "\nOpponent's info:" << endl;
    comp_monster->mon_info();
    //Let the player choose what monster will fight
    //Show the list of current monsters
    cout << "\nYour monster list:" << endl;
    print_monsters_list();

    //Ask to choose
    int monster_number;
    monster_number = validate_input(1, current_monster, "\nChoose the monster will fight for you: ");

    //Set chosen monster to fight
    monster = monster_list[monster_number-1];
    
    //Initialize effect stats from potion
    double *stats_add = new double[2];
    stats_add[1] = 1;
    stats_add[2] = 1;

    //Ask the player if they want to use potions
    char potion_choice;
    potion_choice = validate_yn_input("\nDo you want to use potion? (y/n): ");

    //If player want to use potion
    if (potion_choice == 'y')
    {
        //Display potion list
        cout << "\nPotions list:\n";
        for (int i = 0; i < 9; i++)
        {
            cout << i+1 << ". " << inventory[i]->get_name() << "\t" << items_amount[i] << endl;
        }

        //Ask the player to enter option of potion
        //Validate and get input
        int potion_num;
        cout << "\nEnter 0 if you don't want to use any potion.";
        
        //Check if user has the potion
        while (true)
        {
            potion_num = validate_input(0, 9, "\nChoose the type of potion you want to use: ");
            if (potion_num == 0) break;
            else if ((items_amount[potion_num-1] == 0)&&(potion_num != 0))
            {
                cout << "\nYou don't have this kind of potion.\n";
            }
            else break;
        }
        //Amount of used potion minus 1
        if (potion_num != 0)
        {
            stats_add = inventory[potion_num - 1]->use_item();
            items_amount[potion_num-1]--;
        }
    }  

    //Get player monster stat
    int m_hp = monster->get_health();
    int m_atk = monster->get_attack() * stats_add[1];
    int m_def = monster->get_defense() * stats_add[2];
    
    //Get computer monster stat
    int c_hp = comp_monster->get_health();
    int c_atk = comp_monster->get_attack();
    int c_def = comp_monster->get_defense();

    //Get compare to multiply stat (0,1,2,3) base on attribute
    int compare_m_to_c;

    //If battle with boss
    //Compare player to boss
    if (check_boss) compare_m_to_c = monster->element.compare_attribute_boss(zone_id-1);
    //Compare player to opponent
    else
    {
        //Compare player to boss
        compare_m_to_c = monster->element.compare_attribute(comp_monster->element);

        //Compare player to opponent
        int compare_c_to_m;
        compare_c_to_m = comp_monster->element.compare_attribute(monster->element);
        if (compare_c_to_m != 0) cout << "\nYour opponent gains attribute advantage.\n";
        
        //Change opponent stat
        after_attribute_stats(&c_atk, &c_def, compare_c_to_m);
    }
    if (compare_m_to_c != 0) cout << "\nYour monster gains attribute advantage.\n";

    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));
    
    //Change player's monster stat
    after_attribute_stats(&m_atk, &m_def, compare_m_to_c);
   
    //Get rank to calculate stats multiplier from rank
    if (comp_monster->get_rank() < 4)
    {
        //Calculate rank gap
        int rank_gap = monster->get_rank() - comp_monster->get_rank();

        //Change monster's stat by rank gap
        if (rank_gap < 0)
        {
            //comp_rank.rank - monster.rank = 1
            if (rank_gap == -1)
            {
                c_atk *= 1.25;
                c_def *= 1.25;
            }
            //comp_rank.rank - monster.rank = 2
            else if (rank_gap == -2)
            {
                c_atk *= 1.5;
                c_def *= 1.5;
            }
            
        }
        else if (rank_gap > 0)
        {
            //monster.rank - comp.rank = 1
            if (rank_gap == 1)
            {
                m_atk *= 1.25;
                m_def *= 1.25;
            }
            //monster.rank - comp.rank = 2
            else if (rank_gap == 2)
            {
                m_atk *= 1.5;
                m_def *= 1.5;
            }
        }
    }
    
   
    //Random turn between 1,2 to get whose turn first
    //Turn: 1: player monster attack first, 2: opponent monster attack first
    int turn = random_number(1, 2);

    //Initialize count to check tie result
    int count = 0;
    int damage;

    //Battle
    while ((m_hp > 0)&&(c_hp > 0)&&(count <= 20))
    {
        //Player monster attacks
        if (turn == 1)
        {
            cout << "\nYour Monster's turn!\n";
            damage = m_atk - c_def;

            // if damage is not postive, count it as ineffective attacked
            if (damage <= 0)
            {
                damage = 0;
                cout << "\nIneffective attacked!\n";
            }
            // if damage is positive, subtract opponent's monster hp by damage
            else
            {
                c_hp = c_hp - damage;
                cout << "Your Monster dealed " << damage << " to opponent Monster.\n";
            }
            cout << "Your Monster's HEALTH: " << m_hp << endl;
            cout << "Opponent Monster's HEALTH: " << c_hp << endl;
            turn = 2;
        }
        //Opponent monster attacks
        else if (turn == 2)
        {
            cout << "\nOpponent Monster's turn!\n";
            double damage = c_atk - m_def;

            // if damage is not postive, count it as ineffective attacked
            if (damage <= 0)
            {
                damage = 0;
                cout << "\nIneffective attacked!\n";
            }
            // if damage is positive, subtract opponent's monster hp by damage
            else
            {
                m_hp = m_hp - damage;
                cout << "Opponent Monster dealed " << damage << " to your Monster.\n";
            }
            cout << "Your Monster's HEALTH: " << m_hp << endl;
            cout << "Opponent Monster's HEALTH: " << c_hp << endl;
            turn = 1;
        }

        //Update count
        count++;

        //Stop for 500 millisecond
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    //Result
    //If both monster still have HP
    if ((m_hp > 0)&&(c_hp > 0))
    {
        cout << "\nTie! Both monsters are tired, just stop here!\n";
        return false;
    }
    //If one of them is out of HP
    else
    {   //Your monster lost
        if (m_hp <= 0)
        {
            cout << "\nYour monster HP is 0. DEFEAT!\n";
            
            //Calculate exp and check if can level up
            monster->exp_gain_battle(false, comp_monster);
            monster->level_up();
            return false;
        }
        //Your monster win
        else if (c_hp <= 0)
        {
            cout << "\nOpponent monster HP is 0. VICTORY!\n";
            cout << "\nYour monster goes ";
            monster->growl();

            //Calculate exp and check if can level up
            monster->exp_gain_battle(true, comp_monster);
            monster->level_up();

            //Player earn 5exp and 3 golds
            cout << "\nYou earn 3 golds and 5 exp!\n";
            exp+=5;
            set_gold(3);
            return true;
        }
    }
    //Stop for 500 millisecond
    this_thread::sleep_for(chrono::milliseconds(500));

    return false;
}

//Update trackers after an action
void Person::update_tracker()
{
    //Set current_slots to 0
    current_slots = 0;
    //Update current slots
    for (int i = 0; i < 12; i++)
    {
        current_slots += items_amount[i];
    }

    //Update total_monball
    total_monball = items_amount[9] + items_amount[10] + items_amount[11];
    
}

//Print monster info list
void Person::print_monsters_info()
{   
    //Print the monster list
    print_monsters_list();

    //Initalize
    int monster_choice;
            
    cout << "\nEnter 0 to return to main menu.\n";
    monster_choice = validate_input(0, current_monster,"\nChoose the monster you want to see stats: ");

    //Choose not to see mon info 
    if(monster_choice == 0) return;

    //Show selected monster info
    monster_list[monster_choice-1]->mon_info();
}

//Print monster list
void Person::print_monsters_list()
{
    for (int i = 0; i < current_monster; i++)
    {
        cout << "(" << i+1 << ") " << monster_list[i]->get_name() << endl;
    }  
}

//Print invertory list
void Person::print_inventory()
{
    for (int i = 0; i < 12; i++)
    {
        cout << i+1 << ". " << items_name_list[i];
        if ((i >=0) && (i < 9)) cout << "\t"; 
        else cout << "\t\t"; 
        cout << items_amount[i] << endl;
    }
    cout << "Slots: " << current_slots << "/" << capacity << endl;   
}

//Return monster
Monster * Person::get_monster() {return monster;}

//Get player's name
string Person::get_name() {return name;}

//Set user's name
void Person::set_name(string pname) {name = pname;}

//Return player's level
int Person::get_level() {return level;}

//Return medal list
bool* Person::get_medal_list() {return medal_list;}

//Get player's current monster
int Person::get_current_monster() {return current_monster;}

//Get gold
int Person::get_gold() {return gold;}

//Set gold
void Person::set_gold(int income) {gold += income;}

//For testing only
Person::Person(Monster ** new_monster_list, int number_of_monster)
{
    // Set values
    // Start with 100 golds, level 1, 0 exp, unknown name, 3 monster balls
    cout << "Welcome to MonMon." << endl;
    cout << "The Adventure starts now!" << endl;
    cout << "You have 100 golds and 3 Normal Monballs at start." << endl;
    gold = 100;
    level = 1;
    exp = 0;
    name = "unknown";
    // initialize inventory
    // allocate 12 spaces for inventory
    inventory = new Item * [12];
    // initialize potions
    for (int i = 0; i < 9; i++)
    {
        int grade = (i+1) % 3;
        if (grade == 0)
        {
            grade = 3;
        }
        int potion_type = ((i+1)/3) + 1;
        if ((i+1)%3 == 0)
        {
            potion_type--;
        }
        inventory[i] = new Potion(grade, potion_type);

    }

    // initialize monballs
    for (int i = 9; i < 12; i++)
    {
        int grade = (i+1) % 3;
        if (grade == 0)
        {
            grade = 3;
        }
        inventory[i] = new Monball(grade);
    }

    // initialize items_name_list
    items_name_list = new string[12];

    for (int i = 0; i < 12; i++)
    {
        items_name_list[i] = inventory[i]->get_name();
    }
    
    // initialize medal list
    medal_list = new bool[3];
    medal_list[0] = true;
    medal_list[1] = false;
    medal_list[2] = false;
    items_amount = new int[12];
    for (int i = 0; i < 12; i++)
    {
        items_amount[i] = 0;
    }
    
    capacity = 5;
    current_slots = 0;
    // set Normal monball in items_list to 3
    items_amount[9] = 3;
    total_monball = items_amount[9] + items_amount[10] + items_amount[11];
    max_monster = 3;

    // set current monster to 0 and create monster_list
    current_monster = 0;
    monster_list = new Monster*[max_monster];

    cout << "\nCongratulations! You got a ";

    // create the monster
    monster = new_monster_list[0];

    // show the stats of the monster
    cout << monster->get_species() << endl;

    // add the monster to the list
    for (int i = 0; i < max_monster; i++)
    {
        monster_list[i] = new_monster_list[i];
    }
    current_monster = number_of_monster;
}

// destructo
Person::~Person()
{
    //Deallocate
    delete [] monster_list; 
    delete [] inventory;
    delete [] items_amount;
    delete [] items_name_list;
    delete [] medal_list;
}