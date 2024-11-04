/******************************************************************************

Name: Shannon Poulsen
Project: Project 9 / Card Game Parlor
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: 
Date: 10 November 2023

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

// Prototype declarations of functions
char inputGame ();

void dealCard ( unsigned short & faceNum, unsigned short & suitNum );
unsigned short int dealFace ();
unsigned short int dealSuit ();

void printCard ( unsigned short faceNum, unsigned short suitNum );
string computeFaceName ( unsigned short faceNum );
string computeSuitName ( unsigned short suitNum );

unsigned short int computeEquivalent ( unsigned short faceNum );

char playAgain ();
char wantAnotherCard ();

bool blackjack ();
bool ohNo99 ();

int main ()
{
    // Variable declarations
    unsigned short bjWin, on99Win;
    char newGame, selectGame;

    // Set seed for the random functions
    srand ( time ( NULL ) );

    // Two fixed decimal spaces for float amounts
    cout.setf ( ios :: fixed );
    cout.precision ( 2 );
    
    // Initial declarations of accumulator variables
    bjWin = 0;
    on99Win = 0;

    // Introduction message printed to user
    cout << "Welcome to Severin Poulsen's Card Game Parlor!" << endl;

    // Initial prompt for the user to play a game
    newGame = playAgain ();

    // While the user wants to keep playing
    while ( !( newGame == 'n' ) )
    {
        // Take the game input
        selectGame = inputGame ();

        // Game is determined based on user input
        switch ( selectGame )
        {
            // Blackjack input
            case 'b' :
                // If the user wins a game of blackjack
                if ( blackjack () )
                {
                    // Add to total blackjack wins
                    bjWin ++;
                }
            break;

            // OhNo99 input
            case 'o' :
                // if the user wins a game of OhNo99
                if ( ohNo99 () )
                {
                    // Add to total OhNo99 wins
                    on99Win ++;
                }
            break;
        }
        // Prompt the user to play a game once again
        newGame = playAgain ();
    }

    cout << endl;
    // Output final game results to user
    cout << "You won " << bjWin;
    // Blackjack results based on number of wins
    switch ( bjWin == 1 )
    {
        // In case of a singular game won, used singular
        case true :
            cout << " game";
        break;

        // Any other time, user plural
        default:
            cout << " games";
        break;
    }
    cout << " of Blackjack and " << on99Win;
    // OhNo99 results based on number of wins
    switch ( on99Win == 1 )
    {
        // In case of a singular game won, used singular
        case true :
            cout << " game";
        break;

        // Any other time, user plural
        default:
            cout << " games";
        break;
    }
    cout << " of OhNo99." << endl;

    // Ending message printed to user
    cout << "Thank you for playing at Shannon Poulsen's Card Game Parlor." << endl;
    return 0;
}

// Function to take user input 
char playAgain ()
{
    // Variable declarations
    char choice;

    cout << endl;

    // New game prompt
    cout << "Would you like to play a game?" << endl;
    cout << "Y.) Yes" << endl;
    cout << "N.) No" << endl;
    do
    {
        // Take user input to determine if user wishes to keep playing
        cin >> choice;
        choice = tolower ( choice );
    } while ( !( choice == 'y' || choice == 'n' ) );

    // Return the variable based on user input
    return choice;
}

// Function to input game choice
char inputGame ()
{
    // Variable declarations
    char choice;

    cout << endl;

    // Game type prompt
    cout << "What would you like to play?" << endl;
    cout << "B.) Blackjack" << endl;
    cout << "O.) OhNo99" << endl;
    do
    {
        // Take user input to determine what game the user wishes to play
        cin >> choice;
        choice = tolower ( choice );
    } while ( !( choice == 'b' || choice == 'o' ) );

    // Return the game choice based on user input
    return choice;
}

// Function to deal a new card
void dealCard ( unsigned short & faceNum, unsigned short & suitNum )
{
    // Call to functions for variable values
    faceNum = dealFace ();
    suitNum = dealSuit ();

    // Print the card details back to the user
    printCard ( faceNum, suitNum );

    // Return to end function
    return;
}

// Function to deal face value
unsigned short int dealFace ()
{
    // Symbolic constant declarations
    const unsigned short UB = 13;

    // Variable declarations
    unsigned short faceNum;

    // Random generation of face value
    faceNum = rand () % UB;

    // return face value
    return faceNum;
}

// Function to deal suit value
unsigned short int dealSuit ()
{
    // Symbolic constant declarations
    const unsigned short UB = 4;

    // Variable declarations
    unsigned short suitNum;

    // Random generation of suit value
    suitNum = rand () % UB;

    // Return suit value
    return suitNum;
}

// Function to print card dealt to user
void printCard ( unsigned short faceNum, unsigned short suitNum )
{
    // Variable declarations
    string faceName, suitName;

    // Compute face and suit names
    faceName = computeFaceName ( faceNum );
    suitName = computeSuitName ( suitNum );

    // Output of card values to user
    cout << faceName << " of " << suitName << "." << endl;

    // Return to end function
    return;
}

// Function to compute face name
string computeFaceName ( unsigned short faceNum )
{
    // Symbolic constant declarations
    const unsigned short MAX = 13;
    const string FACE [ MAX ] =
    { "ace", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten", "jack", "queen", "king" };

    // Return face name based on face number
    return FACE [ faceNum ];
}

// Function to compute suit name
string computeSuitName ( unsigned short suitNum )
{
    // Symbolic constant declarations
    const unsigned short MAX = 4;
    const string SUIT [ MAX ] =
    { "clubs", "spades", "diamonds", "hearts" };

    // Return suit name based on suit number
    return SUIT [ suitNum ];
}

// Function to compute card points
unsigned short int computeEquivalent ( unsigned short faceNum )
{
    // Variable declarations
    unsigned short points;

    // Assign point values based on face value
    switch ( faceNum >= 9 )
    {
        // If the face value is greater than/equal to 10
        case true :
            // Set the point value to 10
            points = 10;
        break;

        // Any other time
        default :
            // Set the point value to the face value number + 1
            points = faceNum + 1;
    }

    // Return points
    return points;
}

// Function to prompt if user would like another card
char wantAnotherCard ()
{
    // Variable declarations
    char choice;

    cout << endl;

    // New game prompt
    cout << "Would you like another card? (Y/N)" << endl;
    do
    {
        // Take user input to determine if user wants another card
        cin >> choice;
        choice = tolower ( choice );
    } while ( !( choice == 'y' || choice == 'n' ) );

    // Return the variable based on user input
    return choice;
}

// Function to simulate Blackjack
bool blackjack ()
{
    // Variable declarations
    unsigned short totalPoints, faceNum, suitNum, hypValue;
    bool isWon;
    char newCard;

    // Set accumulator variable for the total points
    totalPoints = 0;

    cout << endl;

    // Draw two cards and add the value to the total points
    for ( int i = 0; i < 2; i ++ )
    {
        // Deal card to user and print it out
        cout << "You were dealt ";
        dealCard ( faceNum, suitNum );

        // Add card value to the total points
        totalPoints += computeEquivalent ( faceNum );
    }
    // Output total points to user after dealing cards
    cout << "The total points is now " << totalPoints << "." << endl;

    // While the total points is under 21 and the user wishes to draw more cards
    do
    {
        // Prompt the user for another card
        newCard = wantAnotherCard ();

        // If the total points is under 21 and the user wishes to draw more cards
        if ( !( totalPoints >= 21 || newCard == 'n' ) )
        {
            cout << endl;

            // Deal card to user and print it out
            cout << "You were dealt ";
            dealCard ( faceNum, suitNum );
  
            // Add card value to the total points
            totalPoints += computeEquivalent ( faceNum );

            // Output total points to user after dealing cards
            cout << "The total points is now " << totalPoints << "." << endl;
        }
    } while ( !( totalPoints >= 21 || newCard == 'n' ) );

    // If the total points is equal to 21
    if ( totalPoints == 21 )
    {
        // The user wins
        isWon = true;
    }
    // Otherwise
    else
    {
        // If the total points is over 21
        if ( totalPoints > 21 )
        {
            // The user loses
            isWon = false;
        }
        // Otherwise
        else
        {
            // If the total points is under 21
            if ( totalPoints < 21 )
            {
                // Deal a hypothetical card to the user
                cout << "You would have been dealt ";
                dealCard ( faceNum, suitNum );
                hypValue = computeEquivalent ( faceNum );
                
                // If the next card drawn would cause the total points to exceed 21
                if ( ( totalPoints + hypValue ) > 21 )
                {
                    // The user wins
                    isWon = true;
                }
                // Otherwise
                else
                {
                    // The user loses
                    isWon = false;
                }
            }
        }
    }

    // Different messages printed based on if user won or lost
    switch ( isWon )
    {
        // If the user won
        case true :
            // Output win message to user
            cout << "Congratulations! You won this game of Blackjack." << endl;
        break;

        // If the user lost
        case false :
            // Output lose message to user
            cout << "Sorry, you lost this game of Blackjack." << endl;
        break;
    }

    // Return whether or not user won
    return isWon;
}

// Function to simulate OhNo99
bool ohNo99 ()
{
    // Variable declarations
    unsigned short totalPoints, faceNum, suitNum;
    string playerStr;
    char playerChar;
    bool isWon;

    // Set accumulator variable for the total points
    totalPoints = 0;

    // The first player will always be the computer in OhNo99
    playerChar = 'c';

    cout << endl;

    // While the total points are under 99
    while ( totalPoints <= 99 )
    {
        // Set the player name based on character value
        switch ( playerChar )
        {
            // For case 'c'
            case 'c' :
                // Set the player to the computer
                playerStr = "computer";
            break;

            // For case 'u'
            case 'u' :
                // Set the player to the user
                playerStr = "user";
            break;
        }

        // Deal card to user and print it out
        cout << "The " << playerStr << " played ";
        dealCard ( faceNum, suitNum );
        
        // When the current player is the computer
        if ( playerChar == 'c' )
        {
            // Change the next player to the user
            playerChar = 'u';
        }
        // Otherwise
        else
        {
            // Change the next player to the computer
            playerChar = 'c';
        }

        // Add card value to the total points
        totalPoints += computeEquivalent ( faceNum );

        // Output total points to user
        cout << "The sum of the pile is now " << totalPoints << "." << endl;
        cout << endl;
    }

    // If the next player is not the computer
    if ( !( playerChar == 'c' ) )
    {
        // The user wins
        isWon = true;
    }
    // Otherwise
    else
    {
        // The user loses
        isWon = false;
    }
    
    // Different messages printed based on if user won or lost
    switch ( isWon )
    {
        // If the user won
        case true :
            // Output win message to user
            cout << "Congratulations! You won this game of OhNo99." << endl;
        break;

        // If the user lost
        case false :
            // Output lose message to user
            cout << "Sorry, you lost this game of OhNo99." << endl;
        break;
    }

    // Return whether or not user won
    return isWon;
}
