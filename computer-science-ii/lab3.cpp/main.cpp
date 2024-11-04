#include <iostream>
using namespace std;

/*
Lab 3
This program is intended to create the Triangle class and take the base and height from input
It will compare two Triangles and determine which area is smaller, and output the smaller Triangle's data
*/

// The Triangle class and its relevant functions and data
class Triangle
{
    // Public data
    public :
        // Function to set the base and height of the Triangle
        void SetBaseAndHeight ( double userBase, double userHeight )
        {
            // Set the base and height to the input
            base = userBase;
            height = userHeight;
        }
        
        // Function to return the area of the Triangle
        double GetArea ()
        {   // Return the area of the Triangle
            return 0.5 * base * height;
        }
        
        // Function to print out the Triangle's data to the user
        void PrintInfo ()
        {   // Print out the data of the Triangle back to the user
            cout.setf ( ios :: fixed );
            cout.precision ( 2 );
            cout << "Triangle with smaller area:" << endl;
            cout << "Base: " << base << endl;
            cout << "Height: " << height << endl;
            cout << "Area: " << GetArea () << endl;
        }
        
    // Private data
    private :
        // Base and height variables of the Triangle class
        double base, height;
};

// The main function of the program
int main ()
{
    // Declaration of Triangle objects and double variables
    Triangle triangle1, triangle2;
    double userBase, userHeight;
    
    // Take the input base and height for triangle1
    cin >> userBase >> userHeight;
    
    // Set the base and height of triangle1
    triangle1.SetBaseAndHeight ( userBase, userHeight );
    
    // Take the input base and height for triangle2
    cin >> userBase >> userHeight;
    
    // Set the base and height of triangle2
    triangle2.SetBaseAndHeight ( userBase, userHeight );
    
    // If triangle1's area is smaller than triangle2's area
    if ( triangle1.GetArea () < triangle2.GetArea () )
    {   // Print out triangle1's data
        triangle1.PrintInfo ();
    }
    
    // Otherwise
    else
    {   // Print out triangle2's data
        triangle2.PrintInfo ();
    }
    
    // Return to end main function
    return 0;
}