/*
    Kelley, Hayden

    CS A250
    Project (Part C)

    Project (Part D)
    
    1. SELECTION NAME: Print Three Random Cookies
    2. PURPOSE: This option will print out three random cookies
    with their name, serving size, calorie amount, and recipe.
    Duplicate cookies may be printed out and that is intentional 
    as it is not selecting for unique cookies.
    3. EXPECTED OUTPUT:

    --------------------------------------------------------------
        SELECTED COOKIES
    --------------------------------------------------------------

    Three Selected Cookies:

        Cookie 1:
        (Name)
            (Calories)
            (Servings)
            (Ingredients)

        Cookie 2:
        (Name)
            (Calories)
            (Servings)
            (Ingredients)

        Cookie 3:
        (Name)
            (Calories)
            (Servings)
            (Ingredients)


    4. TEST CASES:
        Executed then exiting the program
        Executed then reselecting the random option
        Executed then choosing a different option.
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

// Definition function displayMenu
void displayMenu()
{
    cout << string(62, '*') << '\n'
        << string(24, ' ') << "COOKIE RECIPES" << '\n'
        << string(62, '*') << '\n' << '\n'
        << "Select one of the following:" << '\n' << '\n'
        << "    a. Print all recipes" << '\n'
        << "    b. Print cookie recipe" << '\n'
        << "    c. Print cookie calories" << '\n'
        << "    d. Print limited calories" << '\n'
        << "    e. Print three random cookies" << '\n'
        << "    f. To exit" << endl;
}

// Definition function processChoice
void processChoice(CookieList& cookieList)
{
    char in = '\n';
    size_t sel = 0;
    
    while (in == '\n') 
    {
        
        cout << '\n' << "Enter your choice: ";
        cin >> in;
        cout << endl;
        switch (in)
        {
        case 'a': // Print all cookies
            cout << string(62, '-') << '\n'
                << string(4, ' ') << "COOKIE RECIPES" << '\n'
                << string(62, '-') << '\n' << endl;
            cookieList.printAllCookies();
            cout << endl;
            break;
        case 'b': // Individual Recipes
            cout << string(62, '-') << '\n'
                << string(4, ' ') << "COOKIE RECIPE" << '\n'
                << string(62, '-') << '\n' << '\n'
                << "Choose a cookie to view the recipe" << '\n'
                << endl;
            cookieList.printCookieSelection();
            cout << '\n'
                << "Your choice: ";
            cin >> sel;
            cout << endl;
            cookieList.printRecipe(sel);
            cout << endl;
            break;
        case 'c': // Print calories
            cout << string(62, '-') << '\n'
                << string(4, ' ') << "COOKIE CALORIES" << '\n'
                << string(62, '-') << '\n'
                << '\n'
                << "Choose a cookie # to view number of calories."
                << '\n' << endl;
            cookieList.printCookieSelection();
            cout << '\n'
                << "Your choice: ";
            cin >> sel;
            cout << endl;
            cookieList.printCalories(sel);
            cout << endl;
            break;
        case 'd': // Print Cookies Within A Calorie Range
            cout << string(62, '-') << '\n'
                << string(4, ' ') << "MAXIMUM CALORIES" << '\n'
                << string(62, '-') << '\n' << '\n'
                << "What is the maximum # of calories (100-200)? ";
            cin >> sel;
            cout << endl;
            cookieList.printLimitedCalories(sel);
            cout << endl;
            break;
        case 'e': // Print 3 Random Cookies
            cout << string(62, '-') << '\n'
                << string(4, ' ') << "SELECTED COOKIES" << '\n'
                << string(62, '-') << '\n' << endl;
            cookieList.rollThreeCookies();
            break;
        case 'f':
            cout << "Thank you for using our software. Good bye!" 
                << '\n' << endl;
            break;
        default:
            cout << '\n'
                << "  => Sorry. That is not a selection. " 
                << '\n' << endl;
            break;
        }
        if (in == 'f') {
            break;
        }
        else if ((in == 'a') || (in == 'b') || (in == 'c')
            || (in == 'd') || ( in == 'e'))
        {
            cout << string(62, '=') << '\n' 
                << '\n' << "Would you like to continue (y/n)? ";
            cin >> in;
            if (in == 'n')
            {
                cout << '\n'
                    << "Thank you for using our software. Good bye!"
                    << '\n' << endl;
                break;
            }
            else
            {
                cout << endl;
                displayMenu();
                in = '\n';
            }
        }
        else
        {
            cout << string(62, '=') << '\n' << '\n' 
                << "Would you like to try again (y/n)? ";
            cin >> in;
            if (in == 'n')
            {
                cout << '\n'
                    << "Thank you for using our software. Good bye!"
                    << '\n' << endl;
                break;
            }
            else
            {
                cout << endl;
                displayMenu();
                in = '\n';
            }
        }
    }
}