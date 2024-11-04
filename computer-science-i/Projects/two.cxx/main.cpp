/******************************************************************************

Name: Shannon Poulsen
Project: Test 2
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email:
Date: 10 November 2023

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
void printGreeting ();
char anotherOrder ();

void inputOrder ( char & typeChar, int & sizeNum, int & quantityNum );
char inputType ();
int inputSize ();
int inputQuantity ();

double computeCost ( char typeChar, int sizeNum, int quantityNum );
string computeTypeName ( char typeChar );

int main ()
{
    // Symbolic constant declarations
    unsigned short S = 40, M = 80, L = 120;
    
    // Variable declarations
    int sizeNum, sizeSmall, sizeMed, sizeLarge, quantityNum, totalQuantity;
    double totalCost;
    char typeChar, newOrder;
    
    // Initial declarations of accumulator variables to prevent code breaking
    sizeSmall = 0;
    sizeMed = 0;
    sizeLarge = 0;
    totalQuantity = 0;
    totalCost = 0.00;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Prompt the user asking if they would like to place an order
    newOrder = anotherOrder ();
    while ( !( newOrder == 'n' ) )
    {
        // Take the user input of order details
        inputOrder ( typeChar, sizeNum, quantityNum );
        
        // If the order is of 40-gallon barrels
        if ( sizeNum == S )
        {
            // Add the quantity to the total of 40-gallon barrels
            sizeSmall += quantityNum;
        }
        // Otherwise
        else
        {
            // If the order is of 80-gallon barrels
            if ( sizeNum == M )
            {
                // Add the quantity to the total of 80-gallon barrels
                sizeMed += quantityNum;
            }
            // Otherwise
            else
            {
                // Add the quantity to the total of 120-gallon barrels
                sizeLarge += quantityNum;
            }
        }
        
        // Add quantity of order to the total quantity
        totalQuantity += quantityNum;
        
        // Compute the cost of the order and add to the total cost
        totalCost += computeCost ( typeChar, sizeNum, quantityNum );
        
        // Ask the user if they would like to process another order
        newOrder = anotherOrder ();
    }
    
    //Output results to user
    cout << totalQuantity << " rain";
    // Case based on number of barrels
    switch ( totalQuantity == 1 )
    {
        // In the case of a singular barrel, use singular
        case true :
            cout << " barrel was ";
        break;
        
        // Any other time, user plural
        default :
            cout << " barrels were ";
        break;
    }
    cout << "sold today." << endl;
    
    // Output barrel sizes to user
    cout << "Of this, " << sizeSmall;
    // Case based on number of 40-gallon barrels
    switch ( sizeSmall == 1 )
    {
        // In the case of a singular 40-gallon barrel, use singular
        case true :
            cout << " was a 40-gallon barrel, ";
        break;
        
        // Any other time, user plural
        default :
            cout << " were 40-gallon barrels, ";
        break;
    }
    cout << sizeMed;
    // Case based on number of 80-gallon barrels
    switch ( sizeMed == 1 )
    {
        // In the case of a singular 80-gallon barrel, use singular
        case true :
            cout << " was an 80-gallon barrel, ";
        break;
        
        // Any other time, user plural
        default :
            cout << " were 80-gallon barrels, ";
        break;
    }
    cout << "and " << sizeLarge;
    // Case based on number of 120-gallon barrels
    switch ( sizeLarge == 1 )
    {
        // In the case of a singular 120-gallon barrel, use singular
        case true :
            cout << " was a 120-gallon barrel." << endl;
        break;
        
        // Any other time, user plural
        default :
            cout << " were 120-gallon barrels." << endl;
        break;
    }
    
    // Output total revenue to user
    cout << "The total cost of these orders is $" << totalCost << "." << endl;
    cout << "Thank you for using EnviroCare. Your sales assistant today was Severin Poulsen." << endl;
    
    return 0;
}

// Function to print print greeting
void printGreeting ()
{
    // Greeting printed out to the user
    cout << "-------------------------------------------------------" << endl;
    cout << "Welcome to EnviroCare Rain Barrels!" << endl;
    
    // Barrel sizes printed
    cout << "We offer rain barrels in three different sizes:" << endl;
    cout << "   40, 80, or 120 gallons" << endl;
    cout << endl;
    
    // Plastic barrel prices printed
    cout << "The prices for plastic barrels are as follows:" << endl;
    cout << "   40-gallon:      $49.95" << endl;
    cout << "   80-gallon:      $75.95" << endl;
    cout << "   120-gallon:     $89.95" << endl;
    cout << endl;
    
    // Steel barrel prices printed
    cout << "The prices for steel barrels are as follows:" << endl;
    cout << "   40-gallon:      $95.95" << endl;
    cout << "   80-gallon:      $119.95" << endl;
    cout << "   120-gallon:     $135.95" << endl;
    cout << endl;
    
    // Shipping costs printed
    cout << "Shipping costs are as follows:" << endl;
    cout << "   $19.95 for orders under $200.00" << endl;
    cout << "   and 10\% of the cost otherwise." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;
    
    // Return to end function
    return;
}

// Function to determine if user wishes to process another order
char anotherOrder ()
{
    // Variable declarations
    char newOrder;
    
    // Call to printGreeting
    printGreeting ();
    
    // Order input
    cout << "Would you like to process an order?" << endl;
    cout << "Y.) Yes" << endl;
    cout << "N.) No" << endl;
    do
    {
        // Take the user input on whether they want to process another order
        cin >> newOrder;
        newOrder = tolower ( newOrder );
        cout << endl;
    } while ( !( newOrder == 'y' || newOrder == 'n' ) );
    
    // Return the decision for another order
    return newOrder;
}

// Function to input full order of rain barrels
void inputOrder ( char & typeChar, int & sizeNum, int & quantityNum )
{
    // Calls to input functions for each variable
    typeChar = inputType ();
    sizeNum = inputSize ();
    quantityNum = inputQuantity ();
    
    // Return to end function
    return;
}

// Function to input type of rain barrels
char inputType ()
{
    // Variable declarations
    char typeChar;
    
    // Type input
    cout << "Please enter the type of rain barrels to purchase:" << endl;
    cout << "P.) Plastic" << endl;
    cout << "S.) Steel" << endl;
    do
    {
        // Take the user input on whether they want plastic or steel
        cin >> typeChar;
        typeChar = tolower ( typeChar );
        cout << endl;
    } while ( !( typeChar == 'p' || typeChar == 's' ) );
    
    // Return the type of rain barrels
    return typeChar;
}

// Function to input size of rain barrels
int inputSize ()
{
    // Symbolic constant declarations
    const unsigned short S = 40, M = 80, L = 120;
    
    // Variable declarations
    unsigned short sizeNum;
    
    // Size input
    cout << "Please enter the size of rain barrels to purchase:" << endl;
    cout << "40, 80, or 120" << endl;
    do
    {
        // Take the user input on whether they 40, 80, or 120
        cin >> sizeNum;
        cout << endl;
    } while ( !( sizeNum == S || sizeNum == M || sizeNum == L ) );
    
    // Return the size of rain barrels
    return sizeNum;
}

// Function to input quantity of rain barrels
int inputQuantity ()
{
    // Symbolic constant declarations
    const unsigned short MIN = 1;
    
    // Variable declarations
    unsigned short quantityNum;
    
    // Quantity input
    cout << "Please enter the number of rain barrels to purchase:" << endl;
    do
    {
        // Take the user input on how many rain barrels to purchase
        cin >> quantityNum;
        cout << endl;
    } while ( !( quantityNum >= MIN ) );
    
    // Return the quantity of rain barrels
    return quantityNum;
}

// Function to compute the cost of the order
double computeCost ( char typeChar, int sizeNum, int quantityNum )
{
    // Symbolic constant declarations
    const double PS = 49.95, PM = 75.95, PL = 89.95,        // Plastic prices for 40, 80, and 120
                 SS = 95.95, SM = 119.95, SL = 135.95,      // Steel prices for 40, 80, and 120
                 SPU = 19.95, SPR = 0.10,                   // Shipping price under $200 and the regular rate
                 SPL = 200.00;                              // Shipping price threshold
    
    // Variable declarations
    double cost, price, shipping;
    string typeName;
    
    // Call to compute type name
    typeName = computeTypeName ( typeChar );
    
    // Switch to compute the price based on user input
    switch ( typeChar )
    {
        // For plastic rain barrels
        case 'p' :
            // Switch for sizes
            switch ( sizeNum )
            {
                // For a 40-gallon barrel
                case 40 :
                    // Price is for a 40-gallon barrel
                    price = PS;
                break;
                
                // For an 80-gallon barrel
                case 80 :
                    // Price is for an 80-gallon barrel
                    price = PM;
                break;
                
                // For a 120-gallon barrel
                case 120 :
                    // Price is for a 120-gallon barrel
                    price = PL;
                break;
            }
        break;
        
        // For steel rain barrels
        case 's' :
            // Switch for sizes
            switch ( sizeNum )
            {
                // For a 40-gallon barrel
                case 40 :
                    // Price is for a 40-gallon barrel
                    price = SS;
                break;
                
                // For an 80-gallon barrel
                case 80 :
                    // Price is for an 80-gallon barrel
                    price = SM;
                break;
                
                // For a 120-gallon barrel
                case 120 :
                    // Price is for a 120-gallon barrel
                    price = SL;
                break;
            }
        break;
    }
    
    // Equation to calculate order cost
    cost = price * quantityNum;
    
    // If the cost is under 200
    if ( cost < 200 )
    {
        // Shipping rate is the flat rate
        shipping = SPU;
        // Shipping amount is added to cost
        cost += SPU;
    }
    // Otherwise
    else
    {
        // Shipping is the regular rate
        shipping = SPR;
        // Shipping rate is multiplied by cost and added on
        cost += cost * shipping;
    }
    
    // Output the cost and inputs of order to user
    cout << "The cost of " << quantityNum << " " << sizeNum << "-gallon " << typeName << " rain";
    // Case based on number of barrels
    switch ( quantityNum == 1 )
    {
        // In the case of a singular order, use singular
        case true :
            cout << " barrel ";
        break;
        
        // Any other time, user plural
        default :
            cout << " barrels ";
        break;
    }
    cout << "is $" << cost << "." << endl;
    cout << endl;
    
    // Return the cost of the rain barrel order
    return cost;
}

// Function to compute name of rain barrel type
string computeTypeName ( char typeChar )
{
    // Variable declarations
    string typeName;
    
    // Compute the name of the type based on the character for the type
    switch ( typeChar )
    {
        // Case for plastic rain barrel
        case 'p' :
            typeName = "plastic";
        break;
        
        // Case for steel rain barrel
        case 's' :
            typeName = "steel";
        break;
    }
    
    // Return the name of the rain barrel type
    return typeName;
}
