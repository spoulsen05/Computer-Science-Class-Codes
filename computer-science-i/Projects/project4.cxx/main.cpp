/******************************************************************************

Name: Severin Poulsen
Project: Project 4 / Tax Filing
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 3 October 2023

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
    const double F_TAX_MUL_LT = 00.22,           // Multiplier for lowest income amount
                 F_TAX_MUL_LR = 00.24,           // Multiplier for second lowest income amount
                 F_TAX_MUL_M = 00.32,            // Multiplier for middle income amount
                 F_TAX_MUL_HR = 00.35,           // Multiplier for second highest income amount
                 F_TAX_MUL_HT = 00.37,           // Multiplier for highest income amount
                 
                 S_SUB_LT = 6164.50,             // Subtractor for lowest single & married separate
                 S_SUB_LR = 19768.50,            // Subtractor for lower single & married separate
                 S_SUB_HR = 26247.00,            // Subtractor for higher single & married separate
                 
                 SIN_S_HT = 37045.00,           // Subtractor for single with highest income
                 MS_SUB_HT = 32725.50,          // Subtractor for married separate with highest income
                 
                 J_SUB_LT = 8766.00,            // Subtractor for married joint with lowest income
                 J_SUB_LR = 12329.00,           // Subtractor for married joint with lower income
                 J_SUB_M = 39537.00,            // Subtractor for married joint with middle income
                 J_SUB_HR = 52494.00,           // Subtractor for married joint with highest income
                 J_SUB_HT = 65451.00,           // Subtractor for married joint with highest income
                 
                 SS_TAX = 00.062,               // Social Security tax rate
                 MD_TAX = 00.0145;              // Medicare tax rate

    // Variable declarations
    double income, federalIncome, multiplier,
    subtractor, socialSecurity, medicare, takeHomePay;
    char inputStatus;
    string status;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Marital status input
    cout << "Please input your marital status for tax filing purposes" << endl;
    cout << "   A.) Single" << endl;
    cout << "   B.) Married, filing jointly" << endl;
    cout << "   C.) Married, filing separately" << endl;
    do
    {
        // Prompt the user to input marital status
        cin >> inputStatus;
        inputStatus = tolower ( inputStatus );
    } while ( !( inputStatus == 'a' || inputStatus == 'b' || inputStatus == 'c' ) );
    
    // Status assignment based on user input
    switch ( inputStatus )
    {
        // Input for single selection
        case 'a' :
            status = "Single";
        break;
            
        // Input for married filing jointly selection
        case 'b' :
            status = "Married, filing jointly";
        break;
            
        // Input for married filing separately selection
        case 'c' :
            status = "Married, filing separately";
        break;
    }
    
    cout << endl;
    
    // Annual income input
    cout << "Please enter your annual income below:" << endl;
    do
    {
        // Prompt the user to input annual income
        cin >> income;
    } while ( !( isnormal ( income ) ) );
    
    // Multiplier and subtractor assignments
    switch ( inputStatus )
    {
        // Declarations for single status
        case 'a' :
            // Single & highest income
            if ( income >= 539900 )
            {
                multiplier = F_TAX_MUL_HT;
                subtractor = SIN_S_HT;
            }
            else
            {
                // Single & higher income
                if ( income >= 215950 )
                {
                    multiplier = F_TAX_MUL_HR;
                    subtractor = S_SUB_HR;
                }
                else
                {
                    // Single & lower income
                    if ( income >= 170050 )
                    {
                        multiplier = F_TAX_MUL_M;
                        subtractor = S_SUB_LR;
                    }
                    else
                    {
                        // Single & lowest income
                        multiplier = F_TAX_MUL_LR;
                        subtractor = S_SUB_LT;
                    }
                }
            }
        break;
        
        // Declarations for married filing jointly status
        case 'b' :
            // Married filing jointly & highest income
            if ( income >= 647850 )
            {
                multiplier = F_TAX_MUL_HT;
                subtractor = J_SUB_HT;
            }
            else
            {
                // Married filing jointly & higher income
                if ( income >= 431900 )
                {
                    multiplier = F_TAX_MUL_HR;
                    subtractor = J_SUB_HR;
                }
                else
                {
                    // Married filing jointly & middle income
                    if ( income >= 340100 )
                    {
                        multiplier = F_TAX_MUL_M;
                        subtractor = J_SUB_M;
                    }
                    else
                    {
                        // Married filing jointly & lower income
                        if ( income >= 178150 )
                        {
                            multiplier = F_TAX_MUL_LR;
                            subtractor = J_SUB_LR;
                        }
                        else
                        {
                            // Married filing jointly & lowest income
                            multiplier = F_TAX_MUL_LT;
                            subtractor = J_SUB_LT;
                        }
                    }
                }
            }
        break;
        
        // Declarations for married filing separately status
        case 'c' :
            // Married filing separately & highest income
            if ( income >= 323925 )
            {
                multiplier = F_TAX_MUL_HT;
                subtractor = MS_SUB_HT;
            }
            else
            {
                // Married filing separately & higher income
                if ( income >= 215950 )
                {
                    multiplier = F_TAX_MUL_HR;
                    subtractor = S_SUB_HR;
                }
                else
                {
                    // Married filing separately & lower income
                    if ( income >= 170050 )
                    {
                        multiplier = F_TAX_MUL_M;
                        subtractor = S_SUB_LR;
                    }
                    else
                    {
                        // Married filing separately & lowest income
                        multiplier = F_TAX_MUL_LR;
                        subtractor = S_SUB_LT;
                    }
                }
            }
        break;
    }
    
    // Calculations for taxes
    federalIncome = ( income * multiplier ) - subtractor;    // Federal tax income formula
    socialSecurity = income * SS_TAX;                        // Social Security tax income formula
    medicare = income * MD_TAX;                              // Medicare tax income formula
    
    // Prevent social security from going over social security limit
    if ( socialSecurity > 9114.00 )
    {
        socialSecurity = 9114.00;
    }
    
    // Calculate the total sum of taxes and utilize to calculate take home pay
    takeHomePay = income - ( federalIncome + socialSecurity + medicare );
    
    cout << endl;
    
    // Output the calculations of taxes to user
    cout << "Here are your taxes:" << endl;
    cout << "   Status: " << status << endl;                         // Marital status
    cout << "   Income: $" << income << endl;                        // Annual income
    cout << "   Federal Tax: $" << federalIncome << endl;            // Federal tax
    cout << "   Social Security Tax: $" << socialSecurity << endl;   // Social security tax
    cout << "   Medicare Tax: $" << medicare << endl;                // Medicare tax
    cout << "   After-Tax Take Home Pay: $" << takeHomePay << endl;  //Take home pay
    return 0;
}