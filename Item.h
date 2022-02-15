#ifndef ITEM_H
#define ITEM_H
#include<string>
#include<iostream>
using namespace std;

class Item
{
protected:
	//Basic state of item
	int grade;
	int price;
	string name;

public:
	//Behaviour
	//Use item and apply its effect
	virtual double* use_item()=0;

	// Return index
	virtual int return_index()=0;

	//Method that work with class state
	int get_grade();
	int get_price();
	string get_name();
};

#endif