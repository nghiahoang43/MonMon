#include "Monster.h"
#include "Species.h"
#include "Attribute.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    //Initialize
    Monster *mon1, *mon2, *mon3, *mon4, *mon5, *mon6;
    
    //Test for initialize, set name, eat and growl
    //Test Slime
    mon1 = new Slime();
    mon1->set_name("mon1");
    mon1->eat();
    mon1->growl();

    //Test Eagle
    mon2 = new Eagle();
    mon2->set_name("mon2");
    mon2->eat();
    mon2->growl();

    //Test Wolf
    mon3 = new Wolf();
    mon3->set_name("mon3");
    mon3->eat();
    mon3->growl();

    //Test Bear
    mon4 = new Bear();
    mon4->set_name("mon4");
    mon4->eat();
    mon4->growl();

    //Test Chimera
    mon5 = new Chimera();
    mon5->set_name("mon5");
    mon5->eat();
    mon5->growl();

    //Test Dragon
    mon6 = new Dragon();
    mon6->set_name("mon6");
    mon6->eat();
    mon6->growl();
    
    cout << endl;

    //Test for level up, exp gain and upgrade stats
    //int exp_gain_battle(bool battle_result, Monster *opponent);
    //bool level_up();
    //void upgrade_stats();
    //Initialize
    int lvl1, lvl2, lvl3, lvl4, lvl5, lvl6;
    int exp1, exp2, exp3, exp4, exp5, exp6;

    //Get level and exp for monster to test
    cin >> lvl1 >> lvl2 >> lvl3 >> lvl4 >> lvl5 >> lvl6;
    cin >> exp1 >> exp2 >> exp3 >> exp4 >> exp5 >> exp6;
    mon1->set_level(lvl1);
    mon1->set_EXP(exp1);
    mon2->set_level(lvl2);
    mon2->set_EXP(exp2);
    mon3->set_level(lvl3);
    mon3->set_EXP(exp3);
    mon4->set_level(lvl4);
    mon4->set_EXP(exp4);
    mon5->set_level(lvl5);
    mon5->set_EXP(exp5);
    mon6->set_level(lvl6);
    mon6->set_EXP(exp6);

    //Test exp gain from battle
    cout << mon1->exp_gain_battle(true, mon6) << " ";
    cout << mon2->exp_gain_battle(false, mon4) << " ";
    cout << mon3->exp_gain_battle(true, mon2) << " ";
    cout << mon4->exp_gain_battle(false, mon5) << " ";
    cout << mon5->exp_gain_battle(true, mon3) << " ";
    cout << mon6->exp_gain_battle(false, mon1) << "\n";

    //Get monster exp
    cout << mon1->get_exp() << " " << mon2->get_exp() << " " << mon3->get_exp() << " ";
    cout << mon4->get_exp() << " " << mon5->get_exp() << " " << mon6->get_exp() << endl;

    //Test for level up 
    mon1->level_up();
    mon2->level_up();
    mon3->level_up();
    mon4->level_up();
    mon5->level_up();
    mon6->level_up();

    //Get monster exp
    cout << mon1->get_exp() << " " << mon2->get_exp() << " " << mon3->get_exp() << " ";
    cout << mon4->get_exp() << " " << mon5->get_exp() << " " << mon6->get_exp() << endl;

    return 0;
}