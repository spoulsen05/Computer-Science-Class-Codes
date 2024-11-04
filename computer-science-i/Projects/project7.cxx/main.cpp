/******************************************************************************

Name: Severin Poulsen
Project: Project 7 / Interest Rate
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 24 October 2023

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
    const unsigned int MIN_B = 0,             // Minimum amount for balance
                       MIN_R = 0,             // Minimum amount for annual rate
                       MAX_R = 100,           // Maximum amount allowed for annual rate
                       MIN_P = 0;             // Minimum amount for payments
    
    // Variable declarations
    double balance, interest, totalInterest,
    rateAnnual, rateDaily, minPayment, totalPayments;
    unsigned short months;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Initialize accumulator variables to 0 to prevent code breaking
    totalInterest = 0;
    totalPayments = 0;
    months = 0;
    
    // Credit card input
    do
    {
        // Prompt user to input balance on credit card
        cout << "Please enter the current balance on your credit card:" << endl;
        cin >> balance;
    } while ( !( balance > MIN_B ) );
    
    // Annual interest rate input
    do
    {
        // Prompt user to input annual interest rate
        cout << "Please enter the annual interest rate:" << endl;
        cin >> rateAnnual;
    } while ( !( rateAnnual > MIN_R && rateAnnual < MAX_R ) );
    
    // Minimum payment input
    do
    {
        // Prompt user to input the minimum payment
        cout << "Enter the minimum payment due:" << endl;
        cin >> minPayment;
    } while ( !( minPayment > MIN_P && ( int ) minPayment % 10 == 0 ) );
    
    // Calculation of daily rate
    rateDaily = ( rateAnnual / 365 ) / 100;    // Annual rate divided by 365, and divided by 100
    
    cout << endl;
    
    // While there is still a loan to pay off, continue to run the loop
    while ( !( balance <= MIN_B ) )
    {
        // Add to months until payment is complete
        months ++;
        
        // Calculation of monthly rate based on daily compounded interest
        for ( int i = 1; i <= 30; i ++ )
        {
            interest = balance * rateDaily;     // Balance times daily rate
            balance += interest;                // Add interest onto the balance
            totalInterest += interest;          // Accumulate the total interest
        }
        
        // Output balance with monthly interest
        cout << "Balance with interest at the end of month " << months << " is $" << balance << endl;  
        
        // Prevent balance from going below 0
        if ( balance < minPayment )
        {
            // Minimum payment will be the remaining balance
            totalPayments += balance;
            balance = 0;
        }
        // Otherwise, calculate like normal
        else
        {
            // Calculate balance after minimum payment
            balance -= minPayment;                  // Subtract minimum payment
            totalPayments += minPayment;            // Accumulate the total payments
        }
        
        // Output balance after minimum payment
        cout << "Balance after the minimum payment is $" << balance << endl;
    }
    
    cout << endl;
    
    // Output results to user
    cout << "The total months taken for you to pay off the loan is " << months << endl;         // Total months output
    cout << "The total payments you made were $" << totalPayments << endl;                      // Total payments output
    cout << "The total interest you paid was $" << totalInterest << endl;                       // Total interest output
    return 0;
}