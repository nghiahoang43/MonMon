#include<iostream>
#include<string>
#include "Item_list.h"
#include "Item.h"
using namespace std;

int main()
{
    //Initialize
    Item *potion1, *potion2, *potion3, *ball1, *ball2, *ball3;
    int type1, grade1, type2, grade2, type3, grade3;
    double *effect1, *effect2, *effect3, *probability1, *probability2, *probability3;

    //Take in input
    cin >> type1 >> type2 >> type3;
    cin >> grade1 >> grade2 >> grade3;

    //Test potion
    potion1 = new Potion(grade1, type1);
    cout << potion1->get_name() << endl;
    effect1 = potion1->use_item();
    cout << effect1[0] << " " << effect1[1] << endl;

    potion2 = new Potion(grade2, type2);
    cout << potion2->get_name() << endl;
    effect2 = potion2->use_item();
    cout << effect2[0] << " " << effect2[1] << endl;

    potion3 = new Potion(grade3, type3);
    cout << potion3->get_name() << endl;
    effect3 = potion3->use_item();
    cout << effect3[0] << " " << effect3[1] << endl;

    //Test monball
    ball1 = new Monball(1);
    cout << ball1->get_name() << endl;

    probability1 = ball1->use_item();
    cout << probability1[0] << " " << probability1[1] << " " << probability1[2] << endl;

    ball2 = new Monball(2);
    cout << ball2->get_name() << endl;
    probability2 = ball2->use_item();
    cout << probability2[0] << " " << probability2[1] << " " << probability2[2] << endl;

    ball3 = new Monball(3);
    cout << ball3->get_name() << endl;
    probability3 = ball3->use_item();
    cout << probability3[0] << " " << probability3[1] << " " << probability3[2] << endl;

    return 0;
}