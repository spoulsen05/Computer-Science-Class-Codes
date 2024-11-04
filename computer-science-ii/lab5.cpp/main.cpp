#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Name: Severin Poulsen
Project: Lab 5
Class: CMPS-148 / Computer Science II
Section: M/R 2:15 PM - 3:55 PM / 01
Email: spoulsen@ramapo.edu
Date: 14 March 2024

This program will demonstrate various skills in C++ concerning pointers
This will include utilizing pointers with arrays, memory allocation, other pointers, etc.
*/

// Main function
int main ()
{
    // Declaration of pointer Object
    int* ptr;
    
    /*** PART ONE ***/
    
    // The input variable declaration and assigned value
    int num;
    cin >> num;
    
    // Assign the pointer to the input's address
    ptr = &num;
    
    // Print out the value of the input and pointer
    cout << "Value of num: " << num << endl;
    cout << "Value of ptr: " << *ptr << endl;
    
    /*** PART TWO ***/
    
    // Variable declaration to run for loop, and array declaration
    int i, array [ 5 ];
    
    // Assign the pointer to i's address
    ptr = &i;
    
    // Assign and print out each element in array using for loop
    for ( i = 0; i < 5; i ++ )
    {
        // Assign elements in array
        cin >> array [ *ptr ];
        
        // Print out each element using the pointer
        cout << "Element " << *ptr << ": " << array [ *ptr ] << endl;
    }
    
    /*** PART THREE ***/
    
    // Create a new integer and take input to allocate memory
    int intVal;
    cin >> intVal;
    
    // Allocate the memory to a new integer
    int* newInt = new int;
    *newInt = intVal;
    
    // Output the value stored in the allocated memory pointer
    cout << "Value at dynamically allocated memory: " << *newInt << endl;
    
    // Delete the new pointer
    delete newInt;
    
    /*** PART FOUR ***/
    
    // New pointer for pointer-to-pointer, take input and assign pointer to pointer
    int* ptr2;
    int* ptr3;
    
    cin >> intVal;
    
    ptr2 = &intVal;
    ptr3 = ptr2;
    
    // Output the value stored in the allocated memory pointer
    cout << "Value pointed by pointer to pointer: " << *ptr3 << endl;
    
    // Return to end main function
    return 0;
}