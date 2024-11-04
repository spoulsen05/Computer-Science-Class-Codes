/******************************************************************************

Name: Severin Poulsen
Project: Calculator
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: spoulsen@ramapo.edu
Date: 8 September 2023

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
unsigned short int inputNumber ();
unsigned short int computeSquare ( unsigned short number );

int main ()
{
    // Variable declarations
    unsigned short number;
    
    // Call to function for the user input of a number to be squared
    number = inputNumber ();

    cout << endl;
    
    // Call to function to compute the square of the entered number
    computeSquare ( number );

    // End of the main function
    return 0;
}

// Function to have user input a number to be squared
unsigned short int inputNumber ()
{
    // Variable declarations
    unsigned short number;
    
    // Number input
    cout << "Please enter a number to be squared!" << endl;
    do
    {
        //Prompt the user to input a number
        cin >> number;
    } while ( isnan ( number ) );
    
    // Return the number entered by the user
    return number;
}

// Function to calculate square of the number entered
unsigned short int computeSquare ( unsigned short number )
{
    // Variable declarations
    unsigned short square;
    
    // Compute the square of the number
    square = number * number;

    // Output the square of the number back to the user
    cout << number << "^2 = " << square << "!" << endl;
    
    // Return the squared number back to the user
    return square;
}