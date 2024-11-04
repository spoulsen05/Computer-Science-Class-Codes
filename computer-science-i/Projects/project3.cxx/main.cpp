/******************************************************************************

Name: Severin Poulsen
Project: Project 3 / Stock Broker
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 26 September 2023

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
    const double AMZN = 128.03,     // Amazon
                 AAPL = 173.46,     // Apple
                 TSLA = 244.43,     // Tesla
                 NVDA = 418.14,     // NVIDIA
                 GOOGL = 128.56,    // Google
                 NFLX = 380.22,     // Netflix
                 META = 297.24,     // Meta
                 MSFT = 313.51;     // Microsoft
    
    // Variable declarations
    double investAmount, shareAmount, companyRate;
    string company;
    char input;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Menu creation and introduction of currency conversions
    cout << "Welcome to Severin Poulsen's Stock Broker program." << endl;
    cout << "You can buy shares of the following companies:" << endl;
    
    // Each company shares printed out to user in order
    cout << "   Amazon      (about $" << AMZN << " per share)" << endl;     // Amazon
    cout << "   Apple       (about $" << AAPL << " per share)" << endl;     // Apple
    cout << "   Tesla       (about $" << TSLA << " per share)" << endl;     // Tesla
    cout << "   NVIDIA      (about $" << NVDA << " per share)" << endl;     // NVIDIA
    cout << "   Google      (about $" << GOOGL << " per share)" << endl;    // Google
    cout << "   Netflix     (about $" << NFLX << " per share)" << endl;     // Netflix
    cout << "   Meta        (about $" << META << " per share)" << endl;     // Meta
    cout << "   Microsoft   (about $" << MSFT << " per share)" << endl;     // Microsoft

    cout << endl;
    
    // Investment amount input
    cout << "Please enter the amount you want to invest:" << endl;
    do
    {
        // User input of US dollars to invest
        cin >> investAmount;
    } while ( !( investAmount > 0 ) );
        
    cout << endl;
    
    // Company investment input
    cout << "Please select the company whose shares you wish to purchase:" << endl;
    cout << "   A.) Amazon" << endl;     // Amazon
    cout << "   B.) Apple" << endl;      // Apple
    cout << "   C.) Tesla" << endl;      // Tesla
    cout << "   D.) NVIDIA" << endl;     // NVIDIA
    cout << "   E.) Google" << endl;     // Google
    cout << "   F.) Netflix" << endl;    // Netflix
    cout << "   G.) Meta" << endl;       // Meta
    cout << "   H.) Microsoft" << endl;  // Microsoft  
    do
    {
        // Prompt the user to input which company they would like to invest in
        cin >> input;
        input = tolower ( input );
    } while ( !( input == 'a' || input == 'b' || input == 'c' || input == 'd' ||
                 input == 'e' || input == 'f' || input == 'g' || input == 'h' ) );
                 
    // Company selection based on user input
    switch ( input )
    {
        // Input for Amazon
        case 'a' :
            company = "Amazon";
            companyRate = AMZN;
        break;
            
        // Input for Apple
        case 'b' :
            company = "Apple";
            companyRate = AAPL;
        break;
            
        // Input for Tesla
        case 'c' :
            company = "Tesla";
            companyRate = TSLA;
        break;
            
        // Input for NVIDIA
        case 'd' :
            company = "NVIDIA";
            companyRate = NVDA;
        break;
            
        // Input for Google
        case 'e' :
            company = "Google";
            companyRate = GOOGL;
        break;
            
        // Input for Netflix
        case 'f' :
            company = "Netflix";
            companyRate = NFLX;
        break;
            
        // Input for Meta
        case 'g' :
            company = "Meta";
            companyRate = META;
        break;
            
        // Input for Microsoft
        case 'h' :
            company = "Microsoft";
            companyRate = MSFT;
        break;
    }
    
    cout << endl;
    
    // Calculate the shares based on the investment and company share rate
    shareAmount = investAmount / companyRate;

    // Conversions printed to screen
    cout << "With $" << investAmount << ", you can purchase " << shareAmount;
    switch ( ( int ) shareAmount == 1 )
    {
        // In the case of a single share, use singular
        case true :
            cout << " share from ";
        break;
            
        // Any other time, use plural
        default :
            cout << " shares from ";
    }
    cout << company << " at $" << companyRate << " per share.";
    
    cout << endl;
    
    // Exit message of currency converter
    cout << "Thank you for using Severin Poulsen's Stock Broker program." << endl;
    return 0;
}