/******************************************************************************

Name: Shannon Poulsen
Project: Project 2 / Conversion Calculator
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email:
Date: 19 September 2023

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
    const double CHF = 00.8960,    // Switzerland
                 RUS = 96.7529,    // Russia
                 ARG = 349.9784,   // Argentina
                 CL = 884.9809,    // Chile
                 BOT = 13.6923,    // Botswana
                 LBYA = 04.8600,   // Libya
                 IN = 83.1265,     // India
                 SING = 01.3630;   // Singapore
    
    // Variable declarations
    double change,
    currencySwiss, currencyRussian,
    currencyArgentine, currencyChilean,
    currencyBotswanan, currencyLibyan,
    currencyIndian, currencySingaporan;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Menu creation and introduction of currency conversions
    cout << "Welcome to Severin Poulsen's Currency Converter." << endl;
    cout << "You can convert to the following currencies:" << endl;
    
    // Each country currencies printed out to user in order
    cout << "   Swiss Franc      (about " << CHF << " per US Dollar)" << endl;    // Switzerland
    cout << "   Russian Ruble    (about " << RUS << " per US Dollar)" << endl;    // Russia
    cout << "   Argentine Peso   (about " << ARG << " per US Dollar)" << endl;    // Argentina
    cout << "   Chilean Peso     (about " << CL << " per US Dollar)" << endl;     // Chile
    cout << "   Botswanan Pula   (about " << BOT << " per US Dollar)" << endl;    // Botswana
    cout << "   Libyan Dinar     (about " << LBYA << " per US Dollar)" << endl;  // Libya
    cout << "   Indian Rupee     (about " << IN << " per US Dollar)" << endl;     // India
    cout << "   Singapore Dollar (about " << SING << " per US Dollar)" << endl;  // Singapore

    cout << endl;
    
    // User input of US dollars
    cout << "Please enter the money amount that you wish to convert in US Dollars:" << endl;
    do
    {
        // US Dollar input
        cin >> change;
    } while ( !( change > 0 ) );
    
    cout << endl;
    
    // Countries currency conversion based on user input
    currencySwiss = change * CHF;          // Switzerland
    currencyRussian = change * RUS;        // Russia
    currencyArgentine = change * ARG;      // Argentina
    currencyChilean = change * CL;         // Chile
    currencyBotswanan = change * BOT;      // Botswana
    currencyLibyan = change * LBYA;        // Libya
    currencyIndian = change * IN;          // India
    currencySingaporan = change * SING;    // Singapore
    
    // Conversions printed to screen in order as they are initially listed
    cout << "On 19 September 2023:" << endl;
    cout << change;
    switch ( ( int ) change == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " US Dollar" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " US Dollars" << endl;
    }
    
    // Swiss currency printed to user
    cout << "       = " << currencySwiss << " Swiss";
    switch ( ( int ) currencySwiss == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Franc" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Francs" << endl;
    }

    // Russian currency printed to user
    cout << "       = " << currencyRussian << " Russian";
    switch ( ( int ) currencyRussian == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Ruble" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Rubles" << endl;
    }
    
    // Argentine currency printed to user
    cout << "       = " << currencyArgentine << " Argentine";
    switch ( ( int ) currencyArgentine == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Peso" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Pesos" << endl;
    }
    
    // Chilean currency printed to user
    cout << "       = " << currencyChilean << " Chilean";
    switch ( ( int ) currencyChilean == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Peso" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Pesos" << endl;
    }
    
    // Botswanan currency printed to user
    cout << "       = " << currencyBotswanan << " Botswanan";
    switch ( ( int ) currencyBotswanan == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Pula" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Pulas" << endl;
    }
    
    // Libyan currency printed to user
    cout << "       = " << currencyLibyan << " Libyan";
    switch ( ( int ) currencyLibyan == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Dinar" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Dinars" << endl;
    }
    
    // Indian currency printed to user
    cout << "       = " << currencyIndian << " Indian";
    switch ( ( int ) currencyIndian == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Rupee" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Rupees" << endl;
    }
    
    // Singapore currency printed to user
    cout << "       = " << currencySingaporan << " Singapore";  // Singapore
    switch ( ( int ) currencySingaporan == 1 )
    {
        // In the case of a single output, use singular
        case true :
            cout << " Dollar" << endl;
        break;
            
        // Any other time, use plural
        default :
            cout << " Dollars" << endl;
    }
        
    cout << endl;
    
    // Exit message of currency converter
    cout << "Thank you for using Severin Poulsen's Currency Converter." << endl;
    return 0;
}
