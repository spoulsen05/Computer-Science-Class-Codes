/******************************************************************************

Name: Shannon Poulsen
Project: Project 10 / Stock Broker Program: Extended
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: 
Date: 28 November 2023

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

void printCompanies ( string company [] );
int inputCompanyChoice ( string company [] );

int inputStartPrice ();

int inputCashInvestment ();
int inputBuyQuantity ( string company, double price, double cash );
int inputSellQuantity ( string company, short shares );

void printHoldings ( string company [], short shares [], double price [], double cash, bool isQuit );
double updateSharePrice ( string company, double price );

int main ()
{
    // Symbolic constant declarations
    const unsigned short QUIT = 5,      // Value to quit program
                         MAX = 10;      // Max value for company arrays
                         
    // Company names stored in a string array
    const string companyName [ MAX ] =
    { "Apple Inc.", "American Express Co.", "Cisco Systems Inc.", "Dow Inc.", "Home Depot Inc.",
      "Intel Co.", "Microsoft Co.", "Visa Inc.", "Verizon Communications Inc.", "Walmart Inc." };
    
    // Company stock prices stored in a double array
    double companyPrice [ MAX ] =
    { 190.52, 165.29, 48.08, 51.35, 313.15,
      44.21, 381.48, 252.52, 37.43, 158.23 };
    
    // Company stocks owned stored in an integer array
    double companyShares [ MAX ] =
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
    // Variable declarations
    unsigned short choice, select,
    sharesBought, sharesSold;
    double shares = 0, cash, newPrice,
    buyCost, sellCost;
    bool isQuit = false;
    
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
    
    // Print the menu out to the user
    choice = inputMenuChoice ();
    
    // Menu options will be available until the user quits the menu
    while ( !( choice == QUIT ) )
    {
        // What is printed to the user depending on the choice input
        switch ( choice )
        {
            // Call to buy shares
            case 1 :
                cout << endl;
                
                // Take company choice from user
                select = inputCompanyChoice ( companyName );
                
                // Input the amount of shares bought
                sharesBought = inputBuyQuantity ( companyName [ select ], companyPrice [ select ],
                                                                                           cash );
                // The shares are updated with the updater variable
                companyShares[ select ] += sharesBought;
                
                // Cost is calculated based on share amount times share price
                buyCost = sharesBought * companyPrice [ select ];
                
                // Cash is updated based on cost
                cash -= buyCost;
                
                // Output purchase details to user
                cout << "You bought " << sharesBought;
                switch ( sharesBought == 1 )
                {
                    // In the case of a singular share being processed, use singular
                    case true :
                        cout << " share";
                    break;
                                                                        
                    // Any other time, user plural
                    default :
                        cout << " shares";
                }
                cout << " from " << companyName [ select ] << endl;
                cout << "The cost of your purchase is $" << buyCost << "." << endl;
            break;
                    
            // Call to sell shares
            case 2 :
                cout << endl;
                
                // Take company choice from user
                select = inputCompanyChoice ( companyName );
                
                // Input the amount of shares sold
                sharesSold = inputSellQuantity ( companyName [ select ], companyShares [ select ],
                                                                                           cash );
                // The shares are updated with the updater variable
                companyShares[ select ] -= sharesSold;
                            
                // Cost is calculated based on share amount times share price
                sellCost = sharesSold * companyPrice [ select ];
                            
                // Cash is updated based on cost
                cash += sellCost;
                
                // Output sale details to user
                cout << "You sold " << sharesSold;
                switch ( sharesSold == 1 )
                {
                    // In the case of a singular share being processed, use singular
                    case true :
                        cout << " share";
                    break;
                                                                        
                    // Any other time, user plural
                    default :
                        cout << " shares";
                }
                cout << " from " << companyName [ select ] << endl;
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
                
                // Print holdings for chosen company back to user
                printHoldings ( companyName, companyShares, companyPrice, cash, isQuit );
            break;
        }
        
        cout << endl;
        
        // For each company available to the user
        for ( int i = 0; i < 10; i ++ )
        {
            // Update the share price for each company
            newPrice = updateSharePrice ( companyName [ i ], companyPrice [ i ] );
            companyPrice [ i ] = newPrice;
        }
        cout << endl;
                
        // Print the menu out to the user again
        choice = inputMenuChoice ();
    }
    
    // The user has quit the menu
    isQuit = true;
    
    // Print holdings once more
    printHoldings ( companyName, companyShares, companyPrice, cash, isQuit );
    
    // Return to end main function
    return 0;
}

// Function to print menu options to user
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
    cout << "Please select an option:" << endl;
    do
    {
        // Prompt user to input a choice for the menu options
        cin >> choice;
    } while ( !( choice >= MIN && choice <= MAX ) );
    
    // Return the choice input
    return choice;
}

// Function to print company options to user
void printCompanies ( string company, short size )
{
    // For all of the companies available
    for ( int i = 0; i < size; i ++ )
    {
        // Print companies out to user
        cout << i + 1 << ".) " << company [ i ] << endl;
    }
    
    // Return to end function
    return;
}

// Function to input choice for the company options
int inputCompanyChoice ( string company [] )
{
    // Symbolic constant declarations
    const unsigned short MIN = 1, MAX = 10;
    
    // Variable declarations
    unsigned short select;
    
    // Print company options to user
    cout << "Here are your options:" << endl;
    printCompanies ( company, MAX );
    
    // Company choice input
    cout << "Please select a company:" << endl;
    do
    {
        // Prompt user to input a choice for the company options
        cin >> select;
    } while ( !( select >= MIN && select <= MAX ) );
    select -= 1;
    
    // Return the company input
    return select;
}

// Function to input a cash investment
int inputCashInvestment ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 100;
    
    // Variable declarations
    int investment;
    
    // Investment input
    cout << "Please enter your cash investment:" << endl;
    do
    {
        // Prompt the user to enter a cash investment
        cin >> investment;
    } while ( !( investment >= MIN ) );
    
    // Return the cash amount
    return investment;
}

// Function for inputting bought shares
int inputBuyQuantity ( string company, double price, double cash )
{
    // Symbolic constant declarations
    const unsigned short MIN = 0;
    
    // Variable declarations
    unsigned short bought;
    double buyCost;
    
    // Share purchase input
    do
    {
        // Prompt the user to input the amount of shares they wish to purchase
        cout << "How many shares from " << company << " would you like to buy?" << endl;
        cin >> bought;
        
        // If the cost of the shares to buy are not less than or equal to the cash on hand
        if ( !( price * bought <= cash ) )
        {
            cout << "Sorry, you do not have enough cash to buy " << bought;
            switch ( bought == 1 )
            {
                // In the case of a singular share being processed, use singular
                case true :
                    cout << " share";
                break;
                                                            
                // Any other time, user plural
                default :
                    cout << " shares";
                break;
            }
            cout << "." << endl;
        }
    } while ( !( bought > MIN && price * bought <= cash ) );
    
    // Returns the updater variable
    return bought;
}

// Function for inputting sold shares
int inputSellQuantity ( string company, short shares )
{
    // Symbolic constant declarations
    const unsigned short MIN = 0;
    
    // Variable declarations
    unsigned short sold;
    double sellCost;
    
    // Share selling input
    do
    {
        // Prompt the user to input the amount of shares they wish to sell
        cout << "How many shares from " << company << " would you like to sell?" << endl;
        cin >> sold;
        
        // If the shares to sell are not less than or equal to the shares owned
        if ( !( sold <= shares ) )
        {
            cout << "Sorry, you do not have " << sold;
            switch ( sold == 1 )
            {
                // In the case of a singular share being processed, use singular
                case true :
                    cout << " share";
                break;
                                                            
                // Any other time, user plural
                default :
                    cout << " shares";
                break;
            } 
            cout << " to sell." << endl;
        }
    } while ( !( sold > MIN && sold <= shares ) );
    
    // Returns the updater variable
    return sold;
}

// Function to print current holdings to user
void printHoldings ( string company [], short shares [], double price [], double cash, bool isQuit )
{
    // Variable declarations
    double totalPrice, totalWorth;
    
    for ( int i = 0; i < 10; i ++ )
    {
        // Total price is shares times price
        totalPrice = shares [ i ] * price [ i ];
        
        // Portfolio worth is the total price plus current cash amount
        totalWorth = totalPrice + cash;
        
        cout << endl;
        
        // Print holdings out to user
        cout << "You have " << shares [ i ];
        switch ( shares [ i ] == 1 )
        {
            // In the case of a singular share, use singular
            case true :
                cout << " share from " << company [ i ] << endl;
                cout << "It is worth $";
            break;
            
            // Any other time, user plural
            default :
                cout <<" shares from " << company [ i ] << endl;
                cout << "They are worth $";
        }
        cout << totalPrice << "." << endl;
        
        // If the user quits the menu
        if ( isQuit )
        {
            // Print out the portfolio value of each company
            cout << "The total worth of your portfolio is $" << totalWorth << "." << endl;
        }
        // Otherwise
        else
        {
            // Print the cash amount back to the user
            cout << "You have $" << cash << " cash." << endl;
        }
    }
    
    // Return to end function
    return;
}

// Function to update share price
double updateSharePrice ( string company, double price )
{
    // Symbolic constant declarations
    const unsigned short LB = 0, UB = 4;
    
    // Variable declarations
    unsigned short random, direction;
    
    // Calculate a random number between 1 and 5 as the percentage amount
    random = rand () % ( UB - LB );
    
    // Direction will either be 1 or 0
    direction = rand () % ( 1 );
    
    
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
    cout << "The new price of a share for " << company << " is $" << price << "." << endl;
    
    // Returns the updated share price
    return price;
}
