#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

//Complete the class here. You may use Visual Studio to write the code, and then copy/paste here.
class NumberFilter
{
    public :        // Access is public
        // Variable declarations
        int upperThreshold;                 // Threshold
        vector<int> values;                 // Vector for values
        
        // Function declarations
        void GetUserValues ( int numValues );
        void SetThreshold ();
        void FilterAndPrintValues ();
};

// The function to take the input value from the user
void NumberFilter::GetUserValues ( int numValues )
{
    try {
        // If numValues is less or equal to zero
        if ( numValues < 1 )
        {   // The code will throw an error
            throw runtime_error ( "Invalid number of values." );
        }
    }
    // Exception handler
    catch ( runtime_error& excpt )
    {
        // Print out the error and terminate the program
        cout << excpt.what () << endl;
        terminate ();
    }
    
    // The size of the vector is numValues
    values.resize ( numValues );
    
    // Assign values into vector
    for ( int i = 0; i < numValues ; i ++ )
    {
        cin >> values.at ( i );
    };
}

// The function to set the threshold of the filter
void NumberFilter::SetThreshold ()
{
    // Input the threshold value for the vector
    cout << "Enter a threshold value:" << endl;
    cin >> this->upperThreshold;
}

// The function to filter and print the values under the threshold
void NumberFilter::FilterAndPrintValues ()
{
    // Declare a new vector of the filtered values
    vector<int> newValues;
    
    // Cycle through the values vector
    for ( int i = 0; i < values.size (); i ++ )
    {   // If a value at i is less or equal to the threshold
        if ( values.at ( i ) <= upperThreshold )
        {   // Push it back onto the new vector
            newValues.push_back ( values.at ( i ) );
        }
    }
    
    // Print out the filtered values
    cout << "Output (values <= " << upperThreshold << "): ";
    // Cycle through the new vector
    for ( int i = 0; i < newValues.size (); i ++ )
    {   // Print out the value at i
        cout << newValues.at (i) << " ";
    }
    cout << endl;
}

int main ()
{
    int numValues;

    cout << "Enter the number of values: ";
    cin >> numValues;

    // Create an object of NumberFilter
    NumberFilter filter;

    // Retrieve user inputs and filter values
    filter.GetUserValues ( numValues );// Based on 'numValues', receive inputs and add in a vector
    filter.SetThreshold ();            // Input the threshold
    filter.FilterAndPrintValues ();    // Add the values that passed the threshold to a new vector and print

    return 0;
}