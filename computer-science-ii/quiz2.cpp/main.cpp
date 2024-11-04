#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

public:
    int GetHours() {
        return hours;
    }

    int GetMinutes() {
        return minutes;
    }

    int GetSeconds() {
        return seconds;
    }    
    
    void ReadTime() {
       cin >> hours >> minutes >> seconds;
    }

    void TimeDifference(Time end, Time start) {
       hours = end.GetHours() - start.GetHours();
       minutes = end.GetMinutes() - start.GetMinutes();
       seconds = end.GetSeconds() - start.GetSeconds();
       
        if (seconds < 0) {
            minutes -= 1;
            seconds += 60;
        }
        
        if (minutes < 0) {
            hours -= 1;
            minutes += 60;
        }
    }

    void PrintTime() {
       if (hours < 10) {
           cout << setfill('0') << setw(2);
       }
       cout << hours << ":";
       
       if (minutes < 10) {
           cout << setfill('0') << setw(2);
       }
       cout << minutes << ":";
       
       if (seconds < 10) {
           cout << setfill('0') << setw(2);
       }
       cout << seconds << endl;
    }
};

//DO NOT change main
int main() {
    Time start;
    Time end;
    Time difference;

    start.ReadTime();
    end.ReadTime();
    difference.TimeDifference(end, start);

    cout << "Start:\t";
    start.PrintTime();
    cout << "End:\t";
    end.PrintTime();
    cout << "Difference: ";
    difference.PrintTime();

    return 0;
}