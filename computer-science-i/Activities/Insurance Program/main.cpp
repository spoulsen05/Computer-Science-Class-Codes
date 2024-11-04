/******************************************************************************

Name: Shannon Poulsen
Project: Insurance Program
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: 
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
    // Declare symbolic constants
    const double NJ_M_25_UN = 125.00, OOS_M_25_UN = 150.00,
                 NJ_M_25_OV = 95.00, OOS_M_25_OV = 125.00,
                 NJ_F_25_UN = 105.00, OOS_F_25_UN = 135.00,
                 NJ_F_25_OV = 80.00, OOS_F_25_OV = 110.00,
                 NJ_X_25_UN = 115.00, OOS_X_25_UN = 145.00,
                 NJ_X_25_OV = 87.50, OOS_X_25_OV = 117.50;
    
    // Declare variables
    unsigned short age, months;
    double premiumPerMonth, totalPremium;
    string gender;
    char inputGender;
    bool isNJ;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios::fixed );
    cout.precision ( 2 );
    
    // Prompt the user to input their age
    cout << "Enter your current age (16-99):" << endl;
    do
    {
        // Age input
        cin >> age;
    } while ( !( age >= 16 && age <= 99 ) );
    
    cout << endl;
    
    // Prompt the user to input their gender
    cout << "Enter your gender" << endl;
    cout << "M.) Male" << endl;
    cout << "F.) Female" << endl;
    cout << "X.) Other" << endl;
    do
    {
        // Gender input
        cin >> inputGender;
        inputGender = tolower ( inputGender );
    } while ( !( inputGender == 'm' || inputGender == 'f' || inputGender == 'x' ) );
    
    // Assign gender based on user input
    switch ( inputGender )
    {
        // Input for male
        case 'm' :
            gender = "male";
        break;
            
        // Input for female
        case 'f' :
            gender = "female";
        break;
            
        // Input for other
        case 'x' :
            gender = "neither";
        break;
    }
    
    cout << endl;
    
    // Prompt the user to enter their months of coverage
    cout << "Enter the months of coverage (3-24):" << endl;
    do
    {
        // Months of coverage input
        cin >> months;
    } while ( !( months >= 3 && months <= 24 ) );
    
    cout << endl;
    
    // Ask the user if they live in New Jersey
    cout << "Do you live in New Jersey?" << endl;
    cout << "1.) Yes" << endl;
    cout << "0.) No" << endl;
    do
    {
        // State residency input
        cin >> isNJ;
    } while ( !( isNJ == 1 || isNJ == 0 ) );
    
    cout << endl;
    
    // Assignments based on user input
    switch ( isNJ )
    {
        // NJ premium calculations
        case true :
            switch ( inputGender )
            {
                // Male premium calculation
                case 'm' :
                    if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = NJ_M_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = NJ_M_25_OV;
                    }
                break;
                
                // Female premium calculation
                case 'f' :
                   if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = NJ_F_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = NJ_F_25_OV;
                    }
                break;
                
                // Other premium calculation
                case 'x' :
                    if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = NJ_X_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = NJ_X_25_OV;
                    }
                break;
            }
        break;
        
        // Out-of-state calculations
        case false :
            switch ( inputGender )
            {
                // Male premium calculation
                case 'm' :
                    if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = OOS_M_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = OOS_M_25_OV;
                    }
                break;
                
                // Female premium calculation
                case 'f' :
                   if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = OOS_F_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = OOS_F_25_OV;
                    }
                break;
                
                // Other premium calculation
                case 'x' :
                    if ( age <= 25 )
                    {
                        // Under age 25
                        premiumPerMonth = OOS_X_25_UN;
                    }
                    else
                    {
                        // Over age 25
                        premiumPerMonth = OOS_X_25_OV;
                    }
                break;
            }
        break;
    }
    
    // Compute total premium
    totalPremium = months * premiumPerMonth;
    
    //Output total premium
    cout << "The premium cost for a driver that is " << gender
    << ", " << age << " years of age, and a";
    
    // Depending on if the user is a New Jersey resident, change case
    switch ( isNJ )
    {
        // If an NJ resident
        case true :
            cout << " New Jersey ";
        break;
        
        // If an out-of-state resident
        case false :
            cout << "n out-of-state ";
        break;
    }
    cout << "resident is $" << totalPremium << " for " << months << " months." << endl;
    return 0;
}
