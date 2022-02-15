#include<string>
#include<iostream>
#include<limits>
#include<cctype>

using namespace std;

//Validate input
int validate_input(int lower, int upper, string text)
{
    //Initialize input
    double input;

    //Use while loop to validate
    while (true)
    {
        //Take in input
        cout << text;
        cin >> input;

        //Check string
        if (!cin) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nInvalid input!\n";
        }
        //Check double
        else if (abs(input - int(input)) != 0)
        {
            cout << "\nInvalid input!\n";
        }
        //Check negative
        else if (input < 0)
        {
            cout << "\nInvalid input!\n";
        }
        //Check in range
        else if ((input < lower) || (input > upper))
        {
            cout << "\nInvalid input!\n";
        }
        //Pass
        else break;
    }

    //Return to main
    return input;
}

//Validate input for yes no question
char validate_yn_input(string question)
{   
    //Initialize
    char lower_case_choice;
    string choice;
    
    //Use while loop to validate
    while (true)
    {
        cout << question;
        cin >> choice;
        lower_case_choice = tolower(choice[0]);

        //Check if input is not char
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\nInvalid input!\n";
        }
        //Check length
        else if (choice.length() != 1)
        {
            cout << "Too long! Invalid input!" << endl;
        }
        //Check y/n answear
        else if ((lower_case_choice != 'y') && (lower_case_choice != 'n'))
        {
            cout << "Invalid input!" << endl;
        }
        else break;
    }
    return lower_case_choice;
}

//Function use switch to set name
string string_three_case(int number, string string_case[3])
{
    //Use switch to set string as one of the three case
    switch (number)
    {
        case 1: return string_case[0];
        case 2: return string_case[1];
        case 3: return string_case[2];
    }
    return "NULL";
}

//Function use switch to set number
int number_three_case(int number, int number_case[3])
{
    //Use switch to set number as one of the three case
    switch (number)
    {
        case 1: return number_case[0];
        case 2: return number_case[1];
        case 3: return number_case[2];
    }
    return 0;
}

//Generate a random number within the given range
int random_number(int lower, int upper)
{  
    int rand_numb = rand() % (upper + 1 - lower) + lower;
    return rand_numb;
}