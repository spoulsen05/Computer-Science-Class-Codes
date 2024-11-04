/******************************************************************************

Name: Shannon Poulsen
Project: Project 6 / Tuition Processor
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: 
Date: 17 October 2023

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
    const double IS_RATE = 499.30,        // In-state rate for under 12 credits
                 IS_FLAT = 7988.80,       // In-state flat amount for 12-18 credits
                 OS_RATE = 824.64,        // Out-of-state rate for under 12 credits
                 OS_FLAT = 13194.24,      // Out-of-state flat amount for 12-18 credits
                 G_RATE = 661.94,         // Graduate rate for under 12 credits
                 G_FLAT = 10591.04;       // Graduate flat amount for 12-18 credits

    const unsigned int MIN_VAL = 1,       // Minimum credit value
                       MAX_VAL = 20;      // Maximum credit value
    
    // Variable declarations
    unsigned int studentNum, credits, totalCredits;
    double rateAmount, flatAmount, tuition, totalTuition;
    string status;
    char inputStudent, inputStatus;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Initialize accumulator variables to 0
    studentNum = 0;
    
    // Begin to prompt user for inputs
    cout << "Welcome to the tuition processing program" << endl;
    cout << endl;
    
        // Ask if the user would like to process a student's tuition
        do
        {
            cout << "Would you like to process a student's tuition? (Y/N):" << endl;
            cin >> inputStudent;
            inputStudent = tolower ( inputStudent );
        } while ( !( inputStudent == 'y' || inputStudent == 'n' ) );
        
        // While the user continues to answer with yes, continue to take user inputs
        while ( inputStudent == 'y' )
        {
            studentNum ++;
            
            // Status input
            do
            {
                // Take user input of student status
                cout << "Please enter whether this student is in-state (I), out-of-state (O), or a qualified graduate (G):" << endl;
                cin >> inputStatus;
                inputStatus = tolower ( inputStatus );
            } while ( !( inputStatus == 'i' || inputStatus == 'o' || inputStatus == 'g' ) );
                
            // Assign specific rates and flats based on student status
            switch ( inputStatus )
            {
                // Assignments of in-state student
                case 'i' :
                    status = "in-state";
                    rateAmount = IS_RATE;
                    flatAmount = IS_FLAT;
                break;
                        
                // Assignments of out-of-state student
                case 'o' :
                    status = "out-of-state";
                    rateAmount = OS_RATE;
                    flatAmount = OS_FLAT;
                break;
                        
                // Assignments of graduate student
                case 'g' :
                    status = "qualified RCC graduate rate";
                    rateAmount = G_RATE;
                    flatAmount = G_FLAT;
                break;
            }
                
            // Credits input
            do
            {
                // Take user input of credits entered
                cout << "Please enter the number of credits for which the student is registering (1-20):" << endl;
                cin >> credits;
            } while ( !( credits >= MIN_VAL && credits <= MAX_VAL ) );
                
            // Tuition calculations based on credits entered
            // If over/equal to 12 credits...
            if ( credits >= 12 )
            {
                // If under/equal to 18 credits: the tuition is the flat amount
                if  ( credits <= 18 )
                {
                    tuition = flatAmount; 
                }
                // If over 18 credits: take away 18 from the credits, multiply by the rate, and add to the flat
                else
                {
                    tuition = flatAmount + rateAmount * ( credits - 18 );
                }
            }
            // If under 12 credits: multiply credits by rate
            else
            {
                tuition = rateAmount * credits;
            }
                
            // Add credits to total credits and tuition to total tuition
            totalCredits += credits;
            totalTuition += tuition;
                
            // Outprint the tuition to user
            cout << "The tuition for " << credits;
            switch ( credits )
            {
                // In the case of a singular credit, use singular
                case 1 :
                    cout << " credit";
                break;
                            
                // Any other time, use plural
                default :
                    cout << " credits";
            }
            cout << " at the " << status << " rate is $" << tuition << endl;
            
            cout << endl;
            
            // Prompt the user for another student's tuition
            do
            {
                cout << "Would you like to process another student's tuition? (Y/N):" << endl;
                cin >> inputStudent;
                inputStudent = tolower ( inputStudent );
            } while ( !( inputStudent == 'y' || inputStudent == 'n' ) );
        }
             
        cout << endl;
        
        // Print out total number of students to user
        cout << studentNum;
        switch ( studentNum == 1 )
        {
            // In the case of a singular student, use singular
            case true :
                cout << " student was";
            break;
            
            // Any other time, use plural
            default :
                cout << " students were";
        }
        cout << " processed today" << endl;   
                
        // Print out total number of credits to user
        cout << "A total of " << totalCredits;
        switch ( totalCredits == 1 )
        {
            // In the case of a singular credit, use singular
            case true :
                cout << " credit was";
            break;
            
            // Any other time, use plural
            default :
                cout << " credits were";
        }
        cout << " processed today" << endl;
    
        // Print tuition amount to user
        cout << "The total tuition processed was $" << totalTuition << endl;
        return 0;
}
