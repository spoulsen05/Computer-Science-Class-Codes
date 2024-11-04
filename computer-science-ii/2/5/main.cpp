#include <iostream>
using namespace std;

int main ()
{
    int min, max, min2, max2, rows = 2, cols = 4;
    int myNumbers [ 5 ] = { 5, 7, 8, 11, 15 };
    int size = sizeof ( myNumbers ) / sizeof ( myNumbers [ 0 ] );
    
    /*
    FOR LOOP EXAMPLE
    */
    
    for ( int i = 0; i < size; i ++ )
    {
        cout << myNumbers [ i ] << endl;
    }
    
    /*
    FOR-IT LOOP EXAMPLE
    */
    
    for ( int i : myNumbers )
    {
        cout << i << endl;
    }
    
    /*
    PROBLEM: FINDING THE MINIMUM AND MAXIMUM ELEMENT IN AN ARRAY
    */
    
    min = myNumbers [ 0 ];
    max = myNumbers [ 0 ];
    
    for ( int i = 0; i < size; i ++ )
    {
        if ( myNumbers [ i ] < min )
        {
            min = myNumbers [ i ];
        }
        else if ( myNumbers [ i ] > max )
        {
            max = myNumbers [ i ];
        }
    }
    
    /*
    2D ARRAY EXAMPLE
    */
    
    int numbers [ rows ] [ cols ] = {
        { 5, 9, 7, 16 },
        { 3, 21, 15, 8 }            };
        
        
    /*
    NESTED FOR LOOP EXAMPLE
    */
    
    for ( int i = 0; i < rows; i ++ )
    {
        for ( int j = 0; i < cols; i ++ )
        {
            cout << numbers [ i ] [ j ] << " ";
        }
        cout << endl;
    }
    
    /*
    PROBLEM: FINDING THE MINIMUM AND MAXIMUM ELEMENT IN A 2D ARRAY
    */
    
    for ( int i = 0; i < rows; i ++ )
    {
        for ( int j = 0; i < cols; i ++ )
        {
           if ( numbers [ i ] [ j ] < min2 )
            {
                min2 = numbers [ i ] [ j ];
            }
            else if ( numbers [ i ] [ j ] > max2 )
            {
                max2 = numbers [ i ] [ j ];
            } 
        }
    }

    return 0;
}
