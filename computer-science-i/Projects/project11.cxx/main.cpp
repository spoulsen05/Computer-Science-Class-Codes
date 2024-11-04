/******************************************************************************

Name: Severin Poulsen
Project: Project 11 / Car Sharing Club
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 12 December 2023

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

// Prototype declarations
void printMenu ();
int inputMenuChoice ();

void registerMember ( string & name, double & balance );
string inputName ();
double inputDeposit ( string name );

int inputDay ();
void printCurrentMembers ();
int selectMember ();

void findReservation ( int member );
void reserveCar ( int day, int member, double balances [] );
void cancelReservation ( int day, int member, double balances [] );
double addToBalance ( int member, double balances [], string names [] );

void printAvailable ();
void printMembership ();

int main ()
{
    // Symbolic constant declarations
    const unsigned short QUIT = 8,      // Value to quit program
                         MAX = 100,     // Max value for membership arrays
                         DAYS = 30;     // Max number of days for reservations array
    
    // Variable declarations
    
    
    // Membership names stored in a string array
    string names [ MAX ];
    
    // Membership balances stored in a double array
    double balances [ MAX ];
    
    // Membership reservations stored in two-dimensional array
    short reservations [ DAYS ];
    
    // Initial declarations of accumulator variables
    
    // Prompt the user to enter a member's infotmation
    balances += registerMember ( balances, names );
    choice = inputMenuChoice ();
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // As long as the use does not quit the menu
    while ( !( choice == QUIT ) )
    {
        switch ( choice )
        {
            // Call to register a new member
            case 1 :
            
            break;
            
            // Call to schedule a reservation
            case 2:
            
            break;
            
            // Call to schedule a reservation
            case 3:
            
            break;
            
            // Call to add to balance
            case 4:
                balances += addToBalance ( balances, names );
            break;
            
            // Case to show all reservations for specific member
            case 5:
            
            break;
            
            // Case to list all days the car has not been rented
            case 6:
                printAvailable ();
            break;
            
            // Case to print all available member names
            case 7:
                printCurrentMembers ();
            break;
        }
    }
    
    // Output the results to user
    
    
    // End of the main function
    return 0;
}

// Function to print menu options to user
void printMenu ()
{
    // Print menu to user
    cout << "Here are the options available to you:" << endl;
    cout << "1.) Register a new member" << endl;
    cout << "2.) Schedule a reservation" << endl;
    cout << "3.) Cancel reservation" << endl;
    cout << "4.) Add to balance" << endl;
    cout << "5.) Search member reservations" << endl;
    cout << "6.) Search car availability" << endl;
    cout << "7.) Show all members" << endl;
    cout << "8.) Quit" << endl;
    
    // Return to end function
    return;
}

// Function to input choice for the menu options
int inputMenuChoice ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 1, MAX = 8;
    
    // Variable declarations
    unsigned short choice;
    
    // Print menu options to user
    printMenu ();
    
    // Menu choice input
    cout << "Please select an option:" << endl;
    do
    {
        // Prompt user to input a choice for the menu options
        cin >> choice;
    } while ( !( choice >= MIN && choice <= MAX ) );
    
    // Return the choice input
    return choice;
}

// Function to register a new member
void registerMember ( string & name [], double & balance [] )
{
    // Symbolic constant declarations
    const double MIN = 250.00;
    
    // Call to functions for variable values
    name [] = inputName ();
    
    // Initial balance input
    do
    {
        // Initial balance cannot be less than declared minimum
        deposit = inputDeposit ( name );
    } while ( !( balance >= MIN ) );
    
    balance [] = deposit;
    
    // Return to end function
    return;
}

// Function to input the new member name
string inputName ()
{
    // Variable declarations
    string name;
    
    // Member name input
    cout << "Please input the name of the member you would like to register:" << endl;
    do
    {
        // Prompt user to input a name for member registration
        cin >> name; 
    } while ( );
    
    // Return the name input
    return name;
}

// Function to input the new member balance
double inputDeposit ( string name )
{
    // Symbolic constant declarations
    const double MIN = 0.00;
    
    // Variable declarations
    double deposit;
    
    // Deposit input
    cout << "Please input a deposit for " << name << ":" << endl;
    do
    {
        // Prompt user to input a deposit amount
        cin >> deposit;
    } while ( !( deposit >= MIN ) );
    
    // Return the balance input
    return deposit;
}

// Function to input the day of reservation/reservation cancellation
int inputDay ()
{
    // Variable declarations
    int day;
    
    // Day input
    cout << "Please input a day to reserve/cancel (1-30):" << endl;
    do
    {
        // Prompt user to input a day to reserve/cancel
        cin >> day; 
    } while ( !( day >= 1 && day <= 30 ) );
    
    // Return the day input
    return day;
}

// Function to print out all current members
void printCurrentMembers ( string names [] )
{
    // For all of the members registered
    for (int i = 0; i < ; i ++ )
    {
        // Print out all members present in list
        cout << i + 1 << ".) " << names [ i ] << endl;
    }
    
    // Return to end function
    return; 
}

// Function to select a member from the list
int selectMember ( string names [] )
{
    // Variable declarations
    int member;
    
    // Print all current members to user
    printCurrentMembers ();
    
    // Member input
    cout << "Please input the number of the member you wish to select:" << endl;
    do
    {
        // Take user input of the selected member
        cin >> member;
    } while ( !( member  >= 1 && member <= 100 ) );
    member --;
    
    // Return the member input
    return member;
}

// Function to find a member's reservation
void findReservation ( int member, short reservations [] )
{
    // Symbolic constant declarations
    const unsigned short DAYS = 30;
    
    // Call to functions for variable values
    member = selectMember ();
    
    for ( int i = 0; i <= DAYS; i ++ )
    {
        if ( reservations [ i ] == member )
        {
            cout << "This member has the car rented on day " reservations [ i ] << "." << endl;
        }
    }
    
    // Return to end function
    return;
}

// Function to reserve a car
void reserveCar ( int member, int day, double balance )
{
    // Symbolic constant declarations
    const double COST = 80.00;
    
    // Call to functions for variable values
    day = inputDay ();
    member = selectMember ();
    
    // Assign member subscript to reservations array
    reservations [ day - 1 ] = member;
    
    // Subtract the cost from the member's balance
    balance -= COST;
    
    // Return to end function
    return;
}

// Function to cancel an existing reservation
void cancelReservation ( int member, int day, double balance )
{
    // Symbolic constant declarations
    const double COST = 80.00, FEE = 9.95;
    
    // Call to functions for variable values
    day = inputDay ();
    member = selectMember ();
    
    // Remove member subscript from reservations array
    reservations [ day - 1 ] = 0;
    
    // Refund the money to the member's balance minus transaction fee
    balance += ( COST - FEE );
    
    // Return to end function
    return;
}

// Function to add more to existing balance
double addToBalance ( int member, double balances [], string names [] )
{
    // Call to functions for variable values
    member = selectMember ();
    balances [ member ] += inputDeposit ( names [ member ] );
    
    // Return updated balance
    return balances [ member ];
}

// Function to print all of the days the car can be reserved
void printAvailable ()
{
    // Symbolic constant declarations
    
    
    // Variable declarations
    
    
    // Return to end function
    return;
}

// Function to print all of the members and their deposits
void printMembership ()
{
    // Symbolic constant declarations
    
    
    // Variable declarations
    
    
    // Return to end function
    return;
}