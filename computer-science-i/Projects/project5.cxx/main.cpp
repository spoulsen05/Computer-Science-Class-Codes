/******************************************************************************

Name: Shannon Poulsen
Project: Project 5 / Fortune Teller
Class: CMPS-147 / Computer Science I
Section: T/F 9:55 AM - 11:35 AM / 01
Email: 
Date: 10 October 2023

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
    const string ARIES = "\"Perhaps a major opportunity for change is knocking on your door.\"",
                 TAURUS = "\"Major changes are a large piece of the puzzle.\"",
                 GEMINI = "\"Be on the lookout for opportunities and invitations.\"",
                 CANCER = "\"There's great opportunity at hand, and you shouldn't ignore it.\"",
                 LEO = "\"Realize the potential of instigating a significant change in your life.\"",
                 VIRGO = "\"Take charge of your life right now.\"",
                 LIBRA = "\"Don't change  just to change, but examine what needs to shift.\"",
                 SCORPIO = "\"Remedy the things you can change and leave the rest.\"",
                 SAGITTARIUS = "\"Heed the subtleties of this wave of energy.\"",
                 CAPRICORN = "\"Stand back and get a better perspective on your direction.\"",
                 AQUARIUS = "\"Realize that change is a key ingredient for growth.\"",
                 PISCES = "\"Focus and see where you need to make some changes.\"";
    
    // Variable declarations
    unsigned int day, monthNum, zodiacNum, luckyNum;
    string suffix, month, zodiac, fortune;

    cout << "Welcome to Severin Poulsen's Fortune Teller." << endl;
    
    // Birth day input
    cout << "Please enter your birth day (1-31):" << endl;
    do
    {
        // Prompt the user to enter their birth day
        cin >> day;
    } while ( !( day >= 1 && day <= 31 ) );
    
    cout << endl;
    
    // Calculate the suffix based on the first digit of the day
    switch ( day % 10 )
    {
        // If first digit is 1
        case 1 :
            // If it is not 10-19, add "st"
            if ( !( day / 10 == 1 ) )
            {
               suffix = "st"; 
            }
            // Otherwise, add "th"
            else
            {
               suffix = "th"; 
            }
        break;
        
        // If the first digit is 2
        case 2 :
            // If it is not 10-19, add "nd"
            if ( !( day / 10 == 1 ) )
            {
               suffix = "nd"; 
            }
            // Otherwise, add "th"
            else
            {
               suffix = "th"; 
            }
        break;
        
        // If the first digit is 3
        case 3 :
            // If it is not 10-19, add "rd"
            if ( !( day / 10 == 1 ) )
            {
               suffix = "rd"; 
            }
            // Otherwise, add "th"
            else
            {
               suffix = "th"; 
            }
        break;

        // Any other cases, add "th"
        default :
            suffix = "th";
    }

    // Birth month input
    cout << "Please enter your birth month (1-12):" << endl;
    do
    {
        // Prompt the user to enter their birth month
        cin >> monthNum;
    } while ( !( monthNum >= 1 && monthNum <= 12 ) );
    
    cout << endl;
    
    // Month and zodiac assignments based on user input
    switch ( monthNum )
    {
        // January
        case 1 :
            month = "January";
            // Zodiac calculated based on the day within the month
            if ( day <= 19 )
            {
                // Capricorn up to day 19
                zodiacNum = 12;
            }
            else
            {
                // Aquarius elsewise
                zodiacNum = 1;
            }
        break;
        
        // February
        case 2 :
            month = "February";
            // Zodiac calculated based on the day within the month
            if ( day <= 18 )
            {
                // Aquarius up to day 18
                zodiacNum = 1;
            }
            else
            {
                // Pisces elsewise
                zodiacNum = 2;
            }
        break;
        
        // March 
        case 3 :
            month = "March";
            // Zodiac calculated based on the day within the month
            if ( day <= 20 )
            {
                // Pisces up to day 20
                zodiacNum = 2;
            }
            else
            {
                // Aries elsewise
                zodiacNum = 3;
            }
        break;
        
        // April   
        case 4 :
            month = "April";
            // Zodiac calculated based on the day within the month
            if ( day <= 19 )
            {
                // Aries up to day 19
                zodiacNum = 3;
            }
            else
            {
                // Taurus elsewise
                zodiacNum = 4;
            }
        break;
        
        // May  
        case 5 :
            month = "May";
            // Zodiac calculated based on the day within the month
            if ( day <= 20 )
            {
                // Taurus up to day 20
                zodiacNum = 4;
            }
            else
            {
                // Gemini elsewise
                zodiacNum = 5;
            }
        break;
        
        // June
        case 6 :
            month = "June";
            // Zodiac calculated based on the day within the month
            if ( day <= 21 )
            {
                // Gemini up to day 21
                zodiacNum = 5;
            }
            else
            {
                // Cancer elsewise
                zodiacNum = 6;
            }
        break;
        
        // July
        case 7 :
            month = "July";
            // Zodiac calculated based on the day within the month
            if ( day <= 22 )
            {
                // Cancer up to day 22
                zodiacNum = 6;
            }
            else
            {
                // Leo elsewise
                zodiacNum = 7;
            }
        break;
        
        // August
        case 8 :
            month = "August";
            // Zodiac calculated based on the day within the month
            if ( day <= 22 )
            {
                // Leo up to day 22
                zodiacNum = 7;
            }
            else
            {
                // Virgo elsewise
                zodiacNum = 8;
            }
        break;
        
        // September 
        case 9 :
            month = "September";
            // Zodiac calculated based on the day within the month
            if ( day <= 22 )
            {
                // Virgo up to day 22
                zodiacNum = 8;
            }
            else
            {
                // Libra elsewise
                zodiacNum = 9;
            }
        break;
        
        // October
        case 10 :
            month = "October";
            // Zodiac calculated based on the day within the month
            if ( day <= 22 )
            {
                // Libra up to day 22
                zodiacNum = 9;
            }
            else
            {
                // Scorpio elsewise
                zodiacNum = 10;
            }
        break;
        
        // November
        case 11 :
            month = "November";
            // Zodiac calculated based on the day within the month
            if ( day <= 21 )
            {
                // Scorpio up to day 21
                zodiacNum = 10;
            }
            else
            {
                // Sagittarius elsewise
                zodiacNum = 11;
            }
        break;
        
        // December
        case 12 :
            month = "December";
            // Zodiac calculated based on the day within the month
            if ( day <= 21 )
            {
                // Sagittarius up to day 21
                zodiacNum = 11;
            }
            else
            {
                // Capricorn elsewise
                zodiacNum = 12;
            }
        break;
    }
    
    // Fortune based on zodiac sign calculated
    switch ( zodiacNum )
    {
        // Aquarius & corresponding fortune
        case 1 :
            zodiac = "Aquarius";
            fortune = AQUARIUS;
        break;
        
        // Pisces & corresponding fortune
        case 2 :
            zodiac = "Pisces";
            fortune = PISCES;
        break;
        
        // Aries & corresponding fortune
        case 3 :
            zodiac = "Aries";
            fortune = ARIES;
        break;
        
        // Taurus & corresponding fortune
        case 4 :
            zodiac = "Taurus";
            fortune = TAURUS;
        break;
        
        // Gemini & corresponding fortune
        case 5 :
            zodiac = "Gemini";
            fortune = GEMINI;
        break;
        
        // Cancer & corresponding fortune
        case 6 :
            zodiac = "Cancer";
            fortune = CANCER;
        break;
        
        // Leo & corresponding fortune
        case 7 :
            zodiac = "Leo";
            fortune = LEO;
        break;
        
        // Virgo & corresponding fortune
        case 8 :
            zodiac = "Virgo";
            fortune = VIRGO;
        break;
        
        // Libra  & corresponding fortune
        case 9 :
            zodiac = "Libra";
            fortune = LIBRA;
        break;
        
        // Scorpio & corresponding fortune
        case 10 :
            zodiac = "Scorpio";
            fortune = SCORPIO;
        break;
        
        // Sagittarius & corresponding fortune
        case 11 :
            zodiac = "Sagittarius";
            fortune = SAGITTARIUS;
        break;
        
        // Capricorn & corresponding fortune
        case 12 :
            zodiac = "Capricorn";
            fortune = CAPRICORN;
        break;
    }
    
    // Calculations based on the user input
    luckyNum = ( day / 10 ) + ( day % 10 );
    
    // Output to user
    cout << "You were born on the " << day << suffix << " of " << month << "." << endl;
    cout << "Your zodiac sign is " << zodiac << "." << endl;
    cout << "Your fortune for the day:" << endl;
    cout << "   " << fortune << endl;
    cout << "Your lucky number: " << luckyNum << endl;
    cout << "Thank you for using Shannon Poulsen's Fortune Teller." << endl;
    return 0;
}
