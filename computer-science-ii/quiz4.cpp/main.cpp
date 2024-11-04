#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to utilize the Fibonacci sequence and return a value in the sequence
int Fibonacci ( int index )
{
    // When the index is at zero and finished recursion
    if ( index <= 1 )
    {
        // If the number is negative
        if ( index < 0 )
        {
            // Return -1 for negative numbers
            return -1;
        }
        // Otherwise
        else
        {
            // Return the number at the index in the sequence
            return index;
        }
    }
    // Otherwise
    else
    {
        // The number will call the function twice, with index - 1 & index - 2
        return Fibonacci ( index - 1 ) + Fibonacci ( index - 2 );
    }
}

// Main function
int main ()
{
    // The index variable declaration
    int index;
    
    // Take user input for the index
    cin >> index;
    
    // Print out the number at the indexed spot in the sequence
    cout << "Fibonacci(" << index << ") is " << Fibonacci ( index ) << endl;
    
    // Return 0 to end function
    return 0;
}