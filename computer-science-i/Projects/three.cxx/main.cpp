/******************************************************************************

Name: Severin Poulsen
Project: Test 3
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 15 December 2023

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
int inputChoice ();

char inputRoomType ();
int inputMonth ();
int inputDays ();

void inputTransaction (  char & roomChar, int & monthNum, int & dayNum );

double computeCost ( char roomChar, int monthNum, int dayNum );
string computeRoomName ( char roomChar );
string computeMonthName ( int monthNum );

void printTransaction ( char roomChar, int monthNum, int dayNum, double cost );
void printAllTransactions ( char roomTypeLog [], int monthLog [], int daysLog [], double costLog [], int total );
double computeRevenueByType ( char roomChar, char roomTypeLog [], double costLog [], int total );

// Main function
int main ()
{
    // Symbolic constant declarations
    const unsigned short MAX = 100,     // Max number of transactions the arrats can process
                         QUIT = 4;      // Quits the menu
    
    // Arrays to hold transaction details
    char roomTypeLog [ MAX ];          // Room type details
    int monthLog [ MAX ];              // Month details
    int daysLog [ MAX ];               // Day details
    double costLog [ MAX ];            // Cost details
    
    // Variable declarations
    int choice, total, totalDays;
    double totalCost, totalE, totalF, totalL, highestRev;
    string highestName;
    
    // Initial declarations of accumulator variables
    total = 0;
    totalDays = 0;
    totalCost = 0;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Take the initial menu input from the user
    choice = inputChoice ();
    
    // While the user has not quit the menu
    while ( !( choice == QUIT ) )
    {
        // Menu choice based on user input
        switch ( choice )
        {
            // Case to enter a new transaction
            case 1 :
                // Take the input of the transaction details
                inputTransaction ( roomTypeLog [ total ], monthLog [ total ], daysLog [ total ] );
                
                // Assign cost of transaction based on details given
                costLog [ total ] = computeCost ( roomTypeLog [ total ], monthLog [ total ], daysLog [ total ] );
                
                // Add dayNum onto the total days
                totalDays += daysLog [ total ];
                
                // Add cost onto the total cost
                totalCost += costLog [ total ];
                
                // Increment the number of transactions
                total += 1;
                
                // Print out the details of the transaction
                printTransaction ( roomTypeLog [ total ], monthLog [ total ], daysLog [ total ], costLog [ total ] );
            break;
            
            // Case to print out all transactions
            case 2 :
                // Call to function to print out all transactions
                printAllTransactions ( roomTypeLog, monthLog, daysLog, costLog, total );
            break;
            
            // Case to find room type with highest revenue
            case 3 :
                // Compute the revenue for all three room types
                totalE = computeRevenueByType ( 'e', roomTypeLog, costLog, total );
                totalF = computeRevenueByType ( 'f', roomTypeLog, costLog, total );
                totalL = computeRevenueByType ( 'l', roomTypeLog, costLog, total );
                
                // If the economy rooms have higher revenue than the family or luxury rooms
                if ( totalE > totalF && totalE > totalL )
                {
                    // the highest revenue is economy
                    highestName = "Economy";
                    highestRev = totalE;
                }
                //Otherwise
                else
                {
                    // If the family rooms have higher revenue than the economy or luxury rooms
                    if ( totalF > totalE && totalF > totalL )
                    {
                        // the highest revenue is family
                        highestName = "Family";
                        highestRev = totalF;
                    }
                    // Otherwise
                    else
                    {
                        // If the luxury rooms have higher revenue than the economy or family rooms
                        if ( totalL > totalE && totalL > totalF )
                        {
                            // the highest revenue is luxury
                            highestName = "Luxury";
                            highestRev = totalL;
                        }
                    }
                }
                // Output the highest revenue room type
                cout << highestName << " rooms were the most popular with revenue of $" << highestRev << "." << endl;
            break;
        }
        
        // Prompt the user for another menu choice
        choice = inputChoice ();
    }
    
    // Output the total number of transactions processed
    cout << total;
    switch ( total == 1 )
    {
        // In the case of one transaction processed, use singular
        case true :
            cout << " transaction was ";
        break;
        
        // Otherwise, use plural
        default :
            cout << " transactions were ";
        break;
    }
    cout << "processed today." << endl;
    
    // Ouput the total number of rooms booked
    cout << "Rooms were booked for a total of " << totalDays;
    switch ( totalDays == 1 )
    {
        // In the case of one room booked, use singular
        case true :
            cout << " day.";
        break;
        
        // Otherwise, use plural
        default :
            cout << " days.";
        break;
    }
    cout << endl;
    
    // Output the total transaction costs to the user
    cout << "The cost all the transactions is $" << totalCost << "." << endl;
    
    // End of the program
    cout << "Your cashier today was Severin Poulsen." << endl;
    
    // End of the main function
    return 0;
}

// Function to print menu options out to the user
void printMenu ()
{
    // Print the menu out to the user
    cout << "--------------------------------------------" << endl;
    cout << "Welcome to Darlington Ski Resort" << endl;
    cout << "You can book an economy, family, or luxury room:" << endl;
    
    // Room costs printed out in the menu
    cout << "The rooms cost as follows:" << endl;
    cout << "             Off-peak          Peak" << endl;
    cout << "Economy      $89.95          $115.95" << endl;
    cout << "Family      $129.95          $175.95" << endl;
    cout << "Luxury      $189.95          $255.95" << endl;
    
    // Menu options printed out to the user
    cout << "Please select:" << endl;
    cout << "  1.) Enter a new transaction" << endl;
    cout << "  2.) Print all transactions" << endl;
    cout << "  3.) Print the room type with the most revenue" << endl;
    cout << "  4.) Quit" << endl;
    
    // Return to end function
    return;
}

// Function to receive user input of menu choice
int inputChoice ()
{
    // Variable declarations
    int choice;
    
    // Call to display menu options to user
    printMenu ();
    
    // Choice input
    do
    {
        // Take the user input of the menu choice selected
        cout << "Please select a menu option (1-4):" << endl;
        cin >> choice;
    } while ( !( choice >= 1 || choice <= 4 ) );
    
    // Return the selected menu choice
    return choice;
}

// Function to receive user input on the type of room
char inputRoomType ()
{
    // Variable declarations
    char roomChar;
    
    // Room type input
    do
    {
        // Take the user input of the room type selected
        cout << "Please enter the type of room: e/E for economy, f/F for family, and l/L for luxury" << endl;
        cin >> roomChar;
        roomChar = tolower ( roomChar );
    } while ( !( roomChar == 'e' || roomChar == 'f' || roomChar == 'l' ) );
    
    // Return the selected room type
    return roomChar;
}

// Function to receive user input on rental month
int inputMonth ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 1, MAX = 12,         // Keeps input from going below month 1 or above month 12
                         OCT = 10, APR = 4;         // Prevent months from going before October and after April
    
    // Variable declarations
    int monthNum;
    
    // Rental month input
    do
    {
        // Take the user input of the rental month
        cout << "Please enter the month: October (10) - April (4)" << endl;
        cin >> monthNum;
    } while ( !( monthNum >= MIN || monthNum <= MAX ) || !( monthNum >= OCT || monthNum <= APR ) );
    
    // Return the selected rental month
    return monthNum;
}

// Function to receive user input on number of rental days
int inputDays ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 1, MAX = 7;
    
    // Variable declarations
    int dayNum;
    
    // Rental days input
    do
    {
        // Take the user input of the rental days
        cout << "Please enter the number of days (1-7)" << endl; 
        cin >> dayNum;
    } while ( !( dayNum >= MIN || dayNum <= MAX ) );
    
    // Return the number of rental days
    return dayNum;
}

// Function to receive the details of the transaction
void inputTransaction ( char & roomChar, int & monthNum, int & dayNum )
{
    cout << "For the transaction, please enter the following information:" << endl;
    
    // Call to functions to assign values for transaction
    roomChar = inputRoomType ();
    monthNum = inputMonth ();
    dayNum = inputDays ();
    
    // Return to end function
    return;
}

// Function to compute the cost of the transaction
double computeCost ( char roomChar, int monthNum, int dayNum )
{
    // Symbolic constant declarations
    const double E_OFF = 89.95,         // Economy room off season
                 F_OFF = 129.95,        // Family room off season
                 L_OFF = 189.95,        // Luxury room off season
                 E_PEAK = 115.95,       // Economy room peak season
                 F_PEAK = 175.95,       // Family room peak season
                 L_PEAK = 255.95;       // Luxury room peak season
    
    // Variable declarations
    double pricing, cost;
    
    // Assign the room pricing based on room type and month of stay
    switch ( monthNum )
    {
        // Months Dec-Feb are the peak season prices
        case 1 :
        case 2 :
        case 12 :
            // Assign pricing based on room type
            switch ( roomChar )
            {
                // Assign the peak season economy room pricing
                case 'e' :
                    pricing = E_PEAK;
                break;
                
                // Assign the peak season family room pricing
                case 'f' :
                    pricing = F_PEAK;
                break;
                
                // Assign the peak season luxury room pricing
                case 'l' :
                    pricing = L_PEAK;
                break;
            }
        break;
        
        // Otherwise, the prices are for the off-season
        default :
            // Assign pricing based on room type
            switch ( roomChar )
            {
                // Assign the off season economy room pricing
                case 'e' :
                    pricing = E_OFF;
                break;
                
                // Assign the off season family room pricing
                case 'f' :
                    pricing = F_OFF;
                break;
                
                // Assign the off season luxury room pricing
                case 'l' :
                    pricing = L_OFF;
                break;
            }
        break;
    }
    
    // The cost of the room is based on the room pricing and the number of days spent
    cost = pricing * dayNum;
    
    // Return the cost of the transaction
    return cost;
}

// Function to return the designated room name
string computeRoomName ( char roomChar )
{
    // Variable declarations
    string roomStr;
    
    // Determine the room type name based on character input
    switch ( roomChar )
    {
        // Economy room name assignment
        case 'e' :
            roomStr = "n economy";
        break;
        
        // Family room name assignment
        case 'f' :
            roomStr = " family";
        break;
        
        // Luxury room name assignment
        case 'l' :
            roomStr = " luxury";
        break;
    }
    
    // Return the calculated room name to the user
    return roomStr;
}

// Function to return the designated month name
string computeMonthName ( int monthNum )
{
    // Variable declarations
    string monthStr;
    
    // Determine the rental month name based on number input
    switch ( monthNum )
    {
        // January month name assignment
        case 1 :
            monthStr = "January";
        break;
        
        // February month name assignment
        case 2 :
            monthStr = "February";
        break;
        
        // April month name assignment
        case 3 :
            monthStr = "March";
        break;
        
        // April month name assignment
        case 4 :
            monthStr = "April";
        break;
        
        // October month name assignment
        case 10 :
            monthStr = "October";
        break;
        
        // November month name assignment
        case 11 :
            monthStr = "November";
        break;
        
        // December month name assignment
        case 12 :
            monthStr = "December";
        break;
    }
    
    // Return the calculated room name to the user
    return monthStr;
}

// Function to print out the details of the transaction
void printTransaction ( char roomChar, int monthNum, int dayNum, double cost )
{
    // Variable declarations
    string roomStr, monthStr;
    
    // Compute the transaction details and assign them to variables
    roomStr = computeRoomName ( roomChar );
    monthStr = computeMonthName ( monthNum );
    
    // Output transaction details to the user
    cout << "The cost of booking a" << roomStr << " room for " << dayNum;
    switch ( dayNum == 1 )
    {
        // In the case of one day booked, use singular
        case true :
            cout << " day";
        break;
        
        // Otherwise, use plural
        default :
            cout << " days";
        break;
    }
    cout << " in " << monthStr << " is $" << cost << "." << endl;
    cout << endl;
    
    // Return to end function
    return;
}

// Function to print out all transactions to the user
void printAllTransactions ( char roomTypeLog [], int monthLog [], int daysLog [], double costLog [], int total )
{
    // Check through all of the transactions
    for ( int i = 1; i <= total; i ++ )
    {
        // Print out the details of each transaction to the user
        cout << i << ".) ";
        printTransaction ( roomTypeLog [ i - 1 ], monthLog [ i - 1 ], daysLog [ i - 1 ], costLog [ i - 1 ] );
    }
    
    // Return to end function
    return;
}

// Function to compute the revenue of all of the rooms of a certain type
double computeRevenueByType ( char roomChar, char roomTypeLog [], double costLog [], int total )
{
    // Variable declarations
    double totalRevenue = 0;
    
    // Check through all of the transactions
    for ( int i = 1; i <= total; i ++ )
    {
        // If the current transaction found is of the room type passed
        if ( roomTypeLog [ i - 1 ] == roomChar )
        {
            // Add the cost of the transaction to the total revenue
            totalRevenue += costLog [ i - 1 ];
        }
    }
    
    // Return the total revenue of all of the rooms of a certain type
    return totalRevenue;
}