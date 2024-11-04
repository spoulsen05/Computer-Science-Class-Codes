#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> numElements ( 3, 5 );
    
    numElements.at ( 1 ) = 15;
    
    /* REGULAR PRINT */
    //cout << numElements.at ( 1 ) << endl;
    
    /* FOR LOOP */
    //for ( int i = 0; i < numElements.size (); i ++ )
    //{
    //    cout << numElements.at ( i ) << endl;
    //}
    
    /* FOR-EACH LOOP */
    //for ( int i : numElements )
    //{
    //    cout << i << endl;
    //}
    
    /* RESIZE LARGER VECTOR */
    //numElements.resize ( 5 );
    //
    //numElements.at ( 3 ) = 20;
    //numElements.at ( 4 ) = 25;
    //
    //cout << "After size grew: " << endl;
    //for ( int i : numElements )
    //{
    //    cout << i << endl;
    //}
    
    /* RESIZE SMALLER VECTOR */
    //numElements.resize ( 2 );
    //
    //cout << "After size shrunk: " << endl;
    //for ( int i : numElements )
    //{
    //    cout << i << endl;
    //}
    
    /* PUSH_BACK OPERATOR */
    //numElements.push_back ( 50 );
    //
    //cout << "After appending using push_back: " << endl;
    //for ( int i : numElements )
    //{
    //    cout << i << endl;
    //}
    
    /* BACK OPERATOR */
    //int n = numElements.back ();
    //cout << "The last element: " << numElements.back () << endl;
    
    /* POP_BACK OPERATOR */
    //numElements.pop_back ();
    //
    //cout << "After deleting: " << endl;
    //for ( int i : numElements )
    //{
    //    cout << i << endl;
    //}
    //
    //cout << "The last element: " << numElements.back () << endl;
    
    /* COPY VECTOR */
    //vector<int> numElements2 ( 3, 5 );
    //
    //cout << "Before copying: " << endl;
    //for ( int i : numElements2 )
    //{
    //    cout << i << endl;
    //}
    //
    //numElements2 = numElements;
    //
    //cout << "After copying: " << endl;
    //for ( int i : numElements2 )
    //{
    //    cout << i << endl;
    //}
    
    /* COMPARE VECTORS */
    //numElements2.push_back ( 100 );
    //
    //if ( numElements == numElements2 )
    //{
    //    cout << "Both vectors are the same." << endl;
    //}
    //else
    //{
    //    cout << "The vectors are differenct." << endl;
    //}
    
    return 0;
}