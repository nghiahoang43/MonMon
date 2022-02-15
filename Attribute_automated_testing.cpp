#include "Attribute.h"
#include <iostream>
using namespace std;

int main()
{
    //Initialize
    int input1, input2, input3, input4, input5;
    cin >> input1 >> input2 >> input3 >> input4 >> input5;
    Attribute *element1, *element2, *element3, *element4, *element5;
    element1 = new Attribute(input1);
    element2 = new Attribute(input2);
    element3 = new Attribute(input3);
    element4 = new Attribute(input4);
    element5 = new Attribute(input5);

    //Test method
    cout << element1->give_monster_attribute() << " ";
    cout << element2->give_monster_attribute() << " ";
    cout << element3->give_monster_attribute() << " ";
    cout << element4->give_monster_attribute() << " ";
    cout << element5->give_monster_attribute() << endl;

    cout << element2->compare_attribute(*element5) << " ";
    cout << element4->compare_attribute(*element3) << " ";
    cout << element5->compare_attribute(*element1) << " ";
    cout << element3->compare_attribute(*element2) << " ";
    cout << element1->compare_attribute(*element4) << endl;

    cout << element1->compare_attribute_boss(0) << " ";
    cout << element1->compare_attribute_boss(1) << " ";
    cout << element1->compare_attribute_boss(2) << endl;

    cout << element2->compare_attribute_boss(0) << " ";
    cout << element2->compare_attribute_boss(1) << " ";
    cout << element2->compare_attribute_boss(2) << endl;
    
    cout << element3->compare_attribute_boss(0) << " ";
    cout << element3->compare_attribute_boss(1) << " ";
    cout << element3->compare_attribute_boss(2) << endl;
    
    cout << element4->compare_attribute_boss(0) << " ";
    cout << element4->compare_attribute_boss(1) << " ";
    cout << element4->compare_attribute_boss(2) << endl;
    
    cout << element5->compare_attribute_boss(0) << " ";
    cout << element5->compare_attribute_boss(1) << " ";
    cout << element5->compare_attribute_boss(2) << endl;
    
}