/******************************************************************************

Name: Shannon Poulsen
Project: Test 1
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 6 October 2023

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
    // Symbolic constant declarations
    const double PK_I = 595.95,         // Peak season Iberian rate
                 PK_S = 824.95,         // Peak season Scandinavian rate
                 PK_C = 679.95,         // Peak season continental rate
                 OFF_I = 545.95,        // Off season Iberian rate
                 OFF_S = 769.95,        // Off season Scandinavian rate
                 OFF_C = 634.95,        // Off season continental rate
                 NJ_TX = 0.06,          // New Jersey tax rate
                 FED_TX = 0.05;         // Federal tax rate
    
    // Variable delcarations
    unsigned short days, monthNum;
    double cost, totalCost, tax, taxRate, dailyRate;
    char typeMarker;
    string type, month, residence;
    bool inNJ;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Tour type input
    do
    {
        // Prompt the user to enter the type of tour
        cout << "Please enter the type of tour:" << endl;
        cout << "I.) Iberian" << endl;
        cout << "S.) Scandinavian" << endl;
        cout << "C.) continental" << endl;
        cin >> typeMarker;
        typeMarker = toupper ( typeMarker );
    } while ( !( typeMarker == 'I' || typeMarker == 'S' || typeMarker == 'C' ) );
    
    cout << endl;
    
    // Based on user input, assign the type of tour being attended
    switch ( typeMarker )
    {
        // Input for an Iberian tour
        case 'I' :
            type = "Iberian";
        break;
            
        // Input for a Scandinavian tour
        case 'S' :
            type = "Scandinavian";
        break;
        
        // Input for a continental tour
        case 'C' :
            type = "continental";
        break;
    }
    
    // Days spent input
    do
    {
        // Prompt the user to enter the number of days spent at tour
        cout << "Please enter the number of days of the tour" << endl;
        cin >> days;
    } while ( !( days >= 1 && days <= 31 ) );
    
    cout << endl;
    
    // Tour month input
    cout << "Please enter the month of the tour (1 for January - 12 for December)" << endl;
    do
    {
        // Prompt the user to enter the month of the tour
        cin >> monthNum;
    } while ( !( monthNum >= 1 || monthNum <= 12 ) );
    
    cout << endl;
    
    // Month assignments based on user input
    switch ( monthNum )
    {
        // January
        case 1 :
            month = "January";
        break;
        
        // February 
        case 2 :
            month = "February";
        break;
        
        // March        
        case 3 :
            month = "March";
        break;
        
        // April        
        case 4 :
            month = "April";
        break;
        
        // May        
        case 5 :
            month = "May";
        break;
        
        // June    
        case 6 :
            month = "June";
        break;
        
        // June    
        case 7 :
            month = "July";
        break;
        
        // August    
        case 8 :
            month = "August";
        break;
        
        // September        
        case 9 :
            month = "September";
        break;
        
        // October    
        case 10 :
            month = "October";
        break;
        
        // November    
        case 11 :
            month = "November";
        break;
        
        // December    
        case 12 :
            month = "December";
        break;
    }
    
    // If the month is in the peak season range
    if ( !( monthNum <= 5 || monthNum >= 9 ) )
    {
        // If it is an Iberian tour
        if ( typeMarker == 'I' )
        {
            // Daily rate for Iberian peak season
            dailyRate = PK_I;
        }
        // Otherwise
        else
        {
            // If it is a Scandinavian tour
            if ( typeMarker == 'S' )
            {
                // Daily rate for Scandinavian peak season
                dailyRate = PK_S;
            }
            // Otherwise
            else
            {
                // Daily rate for continental peak season
                dailyRate = PK_C;
            }
        }
    }
    // Otherwise
    else
    {
        // If it is an Iberian tour
        if ( typeMarker == 'I' )
        {
            // Daily rate for Iberian off season
            dailyRate = OFF_I;
        }
        // Otherwise
        else
        {
            // If it is a Scandinavian tour
            if ( typeMarker == 'S' )
            {
                // Daily rate for Scandinavian off season
                dailyRate = OFF_S;
            }
            // Otherwise
            else
            {
                // Daily rate for continental off season
                dailyRate = OFF_C;
            }
        }
    }
    
    // Residency input
    do
    {
        // Prompt the user to enter if they live in New Jersey for tax calculations
        cout << "Are you a New Jersey resideny?" << endl;
        cout << "1.) Yes" << endl;
        cout << "0.) No" << endl;
        cin >> inNJ;
    } while ( !( inNJ == 1 || inNJ == 0 ) );
    
    switch ( inNJ )
    {
        // Input for New Jersey resident
        case true :
            taxRate = NJ_TX;
            residence = "New Jersey";
        break;
        
        // Input for out-of-state resident
        case false :
            taxRate = FED_TX;
            residence = "federal";
        break;
    }
    
    cout << endl;
    
    //Calculations of cost and totalCost
    cost = dailyRate * days;
    tax = taxRate * cost;
    totalCost = cost + tax;
    
    // Output message and calculations back to user
    cout << "The cost of a " << days << "-day " << type << " tour in " << month << " is $" << totalCost << endl;
    cout << "This includes $" << tax << " in " << residence << " taxes" << endl;
    cout << "Thank you for booking with EuroTours, your saleperson today was Severin Poulsen" << endl;
    return 0;
}
