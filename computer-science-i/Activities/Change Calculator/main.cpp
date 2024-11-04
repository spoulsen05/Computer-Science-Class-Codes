/******************************************************************************

Name: Severin Poulsen
Project: Change Calculator
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 12 September 2023

*******************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

int main ()
{
    // Variable declarations
    unsigned short change, originalChange,
    numQuarters, numDimes, numNickels, numPennies;
  
    // Change input
    do
    {
        // Prompt the user to input an amount of change
        cout << "Please enter the change to return (1-99)" << endl;
        cin >> change;
    } while ( !( change >= 1 && change <= 99 ) );
    originalChange = change;
    
    // Calcuations
    numQuarters = change / 25;      // Quarters is change divided by 25
    change = change % 25;           // Take remainder to calculate other change

    numDimes = change / 10;         // Dimes is change divided by 10
    change = change % 10;           // Take remainder to calculate other change

    numNickels = change / 5;        // Nickels is change divided by 5
    change = change % 5;            // Take remainder to calculate other change

    numPennies = change / 1;        // Pennies is change divided by 1
    change = change % 1;            // Take remainder to calculate other change
    
    cout << endl;
    
    // Output number of quarters, dimes, nickels, and pennies to user
    cout << originalChange << "¢ = " << endl;
    
    // Quarters output
    if ( numQuarters > 0 )
    {
        cout << "   " << numQuarters;
        switch ( numQuarters == 1 )
        {
            // In the case of one quarter, use singular case
            case true :
                cout << " quarter" << endl;
            break;
            
            // Otherwise, use plural case
            default :
                cout << " quarters" << endl;
        }
    }
    
    // Dimes output
    if ( numDimes > 0 )
    {
        cout << "   " << numDimes;
        switch ( numDimes == 1 )
        {
            // In the case of one dime, use singular case
            case true :
                cout << " dime" << endl;
            break;
            
            // Otherwise, use plural case
            default :
                cout << " dimes" << endl;
        }
    }
    
    // Nickels output
    if ( numNickels > 0 )
    {
        cout << "   " << numNickels;
        switch ( numNickels == 1 )
        {
            // In the case of one nickel, use singular case
            case true :
                cout << " nickel" << endl;
            break;
            
            // Otherwise, use plural case
            default :
                cout << " nickels" << endl;
        }
    }
    
    // Pennies output
    if ( numPennies > 0 )
    {
        cout << "   " << numPennies;
        switch ( numPennies == 1 )
        {
            // In the case of one penny, use singular case
            case true :
                cout << " penny" << endl;
            break;
            
            // Otherwise, use plural case
            default :
                cout << " pennies" << endl;
        }
    }
    
    return 0;
}