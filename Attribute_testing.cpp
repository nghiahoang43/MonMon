#include "Attribute.h"
#include <iostream>
using namespace std;

int main()
{
    //Initialize
    int input1, input2;
    cin >> input1 >> input2;
    Attribute *element1, *element2;
    element1 = new Attribute(input1);
    element2 = new Attribute(input2);

    //Test method
    cout << element1->give_monster_attribute() << endl;
    cout << element2->give_monster_attribute() << endl;

    cout << element1->compare_attribute(*element2) << endl;

    cout << element1->compare_attribute_boss(0) << endl;
    cout << element1->compare_attribute_boss(1) << endl;
    cout << element1->compare_attribute_boss(2) << endl;

    cout << element2->compare_attribute_boss(0) << endl;
    cout << element2->compare_attribute_boss(1) << endl;
    cout << element2->compare_attribute_boss(2) << endl;
}