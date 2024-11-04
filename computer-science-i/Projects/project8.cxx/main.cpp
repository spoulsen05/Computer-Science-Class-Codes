/******************************************************************************

Name: Shannon Poulsen
Project: Project 8 / Stock Broker Program
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email:
Date: 3 November 2023

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
int inputCashInvestment ();
int inputStartPrice ();
int inputBuyQuantity ( double price, double cash );
int inputSellQuantity ( short shares );
void printHoldings ( short shares, double price, double cash, bool isQuit );
double updateSharePrice ( double price );

int main ()
{
    // Variable declarations
    unsigned short choice, shares = 0,
    sharesBought, sharesSold;
    double cash, buyCost, sellCost,
    sharePrice, lowestPrice, highestPrice;
    bool isQuit;
    
    // Set seed for the random functions
    srand ( time ( NULL ) );
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Initial message printed out to the user
    cout << "Welcome to Severin Poulsen's Stockbroker program!" << endl;
    
    cout << endl;
    
    // Prompt the user to input the initial cash investment
    cash = inputCashInvestment ();
    
    cout << endl;
    
    // Prompt the user to input the starting price
    highestPrice = lowestPrice = sharePrice = inputStartPrice ();
    
    cout << endl;
    
    // Print the menu out to the user
    choice = inputMenuChoice ();
    
    // Menu options will be available until the user quits the menu
    while ( !( choice == 5 ) )
    {
        // The user has not yet quit the menu
        isQuit = false;
        
        // What is printed to the user depending on the choice input
        switch ( choice )
        {
            // Call to buy shares
            case 1 :
                // Input the amount of shares bought
                sharesBought = inputBuyQuantity ( sharePrice, cash );
                // The shares are updated with the updater variable
                shares += sharesBought;
                // Cost is calculated based on share amount times share price
                buyCost = sharesBought * sharePrice;
                // cash is updated based on cost
                cash -= buyCost;
                // Output cost to user
                cout << "The cost of your purchase is $" << buyCost << "." << endl;
            break;
                    
            // Call to sell shares
            case 2 :
                // Input the amount of shares sold
                sharesSold = inputSellQuantity ( shares );
                // The shares are updated with the updater variable
                shares -= sharesSold;
                // Cost is calculated based on share amount times share price
                sellCost = sharesSold * sharePrice;
                // cash is updated based on cost
                cash += sellCost;
                // Output cost to user
                cout << "The proceeds of your sale are $" << sellCost << "." << endl;
            break;
                    
            // Call to add more cash to current balance
            case 3 :
                cout << endl;
                cash += inputCashInvestment ();
            break;
                    
            // Call to only print out the current holdings
            case 4 :
                cout << endl;
            break;
        }
        
        // Print out the holdings and update the share price after each run
        printHoldings ( shares, sharePrice, cash, isQuit );
        sharePrice = updateSharePrice ( sharePrice );
                
        // If the calculated share price is lower than the current lowest price
        if ( sharePrice < lowestPrice )
        {
            // Update the lowest price to the calculated share price
            lowestPrice = sharePrice;
        }
        // Otherwise
        else
        {
            // If the calculated share price is higher than the current highest price
            if ( sharePrice > highestPrice )
            {
                // Update the highest price to the calculated share price
                highestPrice = sharePrice;
            }
        }
                
        // Print the menu out to the user again
        choice = inputMenuChoice ();
    }
    
    // The user has quit the menu
    isQuit = true;

    cout << endl;

    // Exiting the program prints the holdings out to the user
    printHoldings ( shares, sharePrice, cash, isQuit );
 
    cout << endl;

    // Lowest price calculations
    cout << "The lowest price of a share was $" << lowestPrice << "." << endl;
    cout << "At this price:" << endl;
    // Prints out the lowest price portfolio values
    printHoldings ( shares, lowestPrice, cash, isQuit );

    cout << endl;

    // Highest price calculations
    cout << "The highest price of a share was $" << highestPrice << "." << endl;
    cout << "At this price:" << endl;
    // Prints out the highest price portfolio values
    printHoldings ( shares, highestPrice, cash, isQuit );
    
    return 0;
}

// Function to print out different options based on menu input
void printMenu ()
{
    // Print menu to user
    cout << "Here are your options:" << endl;
    cout << "1.) Buy shares" << endl;
    cout << "2.) Sell shares" << endl;
    cout << "3.) Add cash to your balance" << endl;
    cout << "4.) Print current holdings" << endl;
    cout << "5.) Quit" << endl;
    
    // Return to end function
    return;
}

// Function to input choice for the menu options
int inputMenuChoice ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 1, MAX = 5;
    
    // Variable declarations
    unsigned short choice;
    
    // Print menu options to user
    printMenu ();
    
    // Menu choice input
    do
    {
        // Prompt user to input a choice for the menu options
        cout << "Please select an option:" << endl;
        cin >> choice;
    } while ( !( choice >= MIN && choice <= MAX ) );
    
    // Return the choice input
    return choice;
}

// Function to input a cash investment
int inputCashInvestment ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 100;
    
    // Variable declarations
    int investment;
    
    // Investment input
    do
    {
        // Prompt the user to enter a cash investment
        cout << "Please enter your cash investment:" << endl;
        cin >> investment;
    } while ( !( investment >= MIN ) );
    
    // Return the cash amount
    return investment;
}

// Function to input starting share price
int inputStartPrice ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 0;
    
    // Variable declarations
    double price;
    
    // Starting price input
    do
    {
        // Prompt the user to enter a starting share price
        cout << "Please enter the starting price of Citigroup shares:" << endl;
        cin >> price;
    } while ( !( price > MIN ) );
    
    // Return the starting share price
    return price;
}

// Function for inputting bought shares
int inputBuyQuantity ( double price, double cash )
{
    // Symbolic constant declarations
    const unsigned short MIN = 0;
    
    // Variable declarations
    unsigned short bought;
    
    // Share purchase input
    do
    {
        // Prompt the user to input the amount of shares they wish to purchase
        cout << "How many shares from Citigroup would you like to buy?" << endl;
        cin >> bought;
        
        // If the cost of the shares to buy are not less than or equal to the cash on hand
        if ( !( price * bought <= cash ) )
        {
            switch ( bought == 1 )
            {
                // In the case of a singular share being processed, use singular
                case true :
                    cout << "Sorry, you do not have enough cash to buy " << bought << " share." << endl;
                break;
                                                            
                // Any other time, user plural
                default :
                    cout << "Sorry, you do not have enough cash to buy " << bought << " shares." << endl;
            }
        }
    } while ( !( bought > MIN && price * bought <= cash ) );
    
    // Returns the updater variable
    return bought;
}

// Function for inputting sold shares
int inputSellQuantity ( short shares )
{
    // Symbolic constant declarations
    const unsigned short MIN = 0;
    
    // Variable declarations
    unsigned short sold;
    
    // Share selling input
    do
    {
        // Prompt the user to input the amount of shares they wish to sell
        cout << "How many shares from Citigroup would you like to sell?" << endl;
        cin >> sold;
        
        // If the shares to sell are not less than or equal to the shares owned
        if ( !( sold <= shares ) )
        {
            switch ( sold == 1 )
            {
                // In the case of a singular share being processed, use singular
                case true :
                    cout << "Sorry, you do not have " << sold << " share to sell." << endl;
                break;
                                                            
                // Any other time, user plural
                default :
                    cout << "Sorry, you do not have " << sold << " shares to sell." << endl;
            } 
        }
    } while ( !( sold > MIN && sold <= shares ) );
    
    // Returns the updater variable
    return sold;
}

// Function to print current holdings to user
void printHoldings ( short shares, double price, double cash, bool isQuit )
{
    // Variable declarations
    double totalPrice, totalWorth;
            
    // Total price is shares times price
    totalPrice = shares * price;
    
    // Portfolio worth is the total price plus current cash amount
    totalWorth = totalPrice + cash;
    
    // Print holdings out to user
    switch ( shares == 1 )
    {
        // In the case of a singular share, use singular
        case true :
            cout << "You have " << shares << " share from Citigroup." << endl;
            cout << "It is worth $" << totalPrice << "." << endl;
        break;
        
        // Any other time, user plural
        default :
            cout << "You have " << shares << " shares from Citigroup." << endl;
            cout << "They are worth $" << totalPrice << "." << endl;
    }
    cout << "You have $" << cash << " cash." << endl;
    
    // If the user quits the menu, print out the portfolio value as well
    if ( isQuit )
    {
        cout << "The total worth of your portfolio is $" << totalWorth << "." << endl;
    }
    
    // Return to end function
    return;
}

// Function to update share price
double updateSharePrice ( double price )
{
    // Symbolic constant declarations
    const unsigned short UB = 5, LB = 1;
    
    // Variable declarations
    unsigned short random, direction;
    
    cout << endl;
    cout << "Re-calculating the cost of a Citigroup share..." << endl;
    
    // Calculate a random number between 1 and 5 as the percentage amount
    random = LB + rand () % ( UB + 1 );
    
    // Direction will either be 1 or 0
    direction = rand () % ( 2 );
    
    // Depending on whether direction is 1 or 0, add or subtract accordingly
    switch ( direction )
    {
        // Add the percentage to price
        case 1 :
            price += price * ( ( double ) random / 100 ); 
        break;
        
        // Subtract the percentage from price
        case 0 :
            price -= price * ( ( double ) random / 100 );
        break;
    }
    
    // Print the calculated share price to the screen
    cout << "The new price of a share for Citigroup is $" << price << "." << endl;
    cout << endl;
    
    // Returns the updated share price
    return price;
}
