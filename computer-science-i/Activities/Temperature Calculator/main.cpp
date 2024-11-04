/******************************************************************************

Name: Shannon Poulsen
Project: Temperature Calculator
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

// Prototype declarations
double inputTemp ();

void computeTemp ( double fahrenheit, double & celsius, double & kelvin, double & rankine,
                   double sbtrhnd, double dvdnd, double dvsr, double fWater, double fBrine );
                              
double computeCelsius ( double fahrenheit, double sbtrhnd, double dvdnd, double dvsr );
double computeKelvin ( double fahrenheit, double fWater, double sbtrhnd, double dvdnd, double dvsr );
double computeRankine ( double fahrenheit, double fBrine );

int main ()
{
    // Symbolic constant declarations
    const double SBTRHND = 32.00,       // Subtrahend
                 DVDND = 5.00,          // Dividend
                 DVSR = 9.00,           // Divisor
                 
                 KELVIN = 273.15,       // Freezing point of water in Kelvin
                 RANKINE = 459.67;      // Freezing point of brine in Rankine
             
    // Variable declarations
    double fahrenheit, celsius, kelvin, rankine;
    
    // Two fixed decimal spaces for float amounts
    cout.setf ( ios::fixed );
    cout.precision ( 2 );
    
    cout << "Welcome to Severin Poulsen's Temperature Converter!" << endl;
    
    // Call to inputTemp
    fahrenheit = inputTemp ();
    
    cout << endl;
  
    // Call to computeTemp to calculate conversions
    computeTemp ( fahrenheit, celsius, kelvin, rankine, SBTRHND, DVDND, DVSR, KELVIN, RANKINE );
  
    // Output various temperature conversions
    cout << fahrenheit << " °F would be about:" << endl;
    cout << "   " << celsius << " °C" << endl;     // Celsius
    cout << "   " << kelvin << " °K" << endl;      // Kelvin
    cout << "   " << rankine << " °Ra" << endl;      // Rankine
    
    // Output end message to user
    cout << endl;
    cout << "Thank you for using Severin Poulsen's Temperature Converter!" << endl;
    
    // Return to end function
    return 0;
}

// Function to input the temperature
double inputTemp ()
{
    // Variable declarations
    double fahrenheit;
    
    // Temperature input
    do
    {
        // Prompt user to enter a temperature amount
        cout << "Please enter a temperature in Fahrenheit:" << endl;
        cin >> fahrenheit;
    } while ( isnan ( fahrenheit ) );
    
    // Return the Fahrenheit temperature input
    return fahrenheit;
}

// Function to compute temperature conversions
void computeTemp ( double fahrenheit, double & celsius, double & kelvin, double & rankine,
                   double sbtrhnd, double dvdnd, double dvsr, double fWater, double fBrine )
{
    // Calls to compute functions for each variable
    celsius = computeCelsius ( fahrenheit, sbtrhnd, dvdnd, dvsr );
    kelvin = computeKelvin ( fahrenheit, fWater, sbtrhnd, dvdnd, dvsr );
    rankine = computeRankine ( fahrenheit, fBrine );
    
    // Return to end function
    return;
}

// Function to compute Celsius conversion
double computeCelsius ( double fahrenheit, double sbtrhnd, double dvdnd, double dvsr )
{
    // Variable declarations
    double celsius;
  
    // Calculate Celsius based on Fahrenheit input
    celsius = ( fahrenheit - sbtrhnd ) * ( dvdnd / dvsr );
  
    // Output Celsius conversion to user
    return celsius;
}

// Function to compute Kelvin conversion
double computeKelvin ( double fahrenheit, double fWater, double sbtrhnd, double dvdnd, double dvsr )
{
    // Variable declarations
    double kelvin;
  
    // Calculate Kelvin based on Fahrenheit input
    kelvin = ( fahrenheit - sbtrhnd ) * ( dvdnd / dvsr ) + fWater;
  
    // Output Kelvin conversion to user
    return kelvin;
}

// Function to compute Rankine conversion
double computeRankine ( double fahrenheit, double fBrine )
{
    // Variable declarations
    double rankine;
  
    // Calculate Rankine based on Fahrenheit input
    rankine = fahrenheit + fBrine;
  
    // Output Rankine conversion to user
    return rankine;
}
