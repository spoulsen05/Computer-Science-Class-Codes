#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Name: Shannon Poulsen
Project: Lab 4
Class: CMPS-148 / Computer Science II
Section: M/R 2:15 PM - 3:55 PM / 01
Email:
Date: 29 February 2024

This program is intended to take a student's information and print out the ID of the student receiving an award
It creates a Student class and stores the information, as well as calculate CGPA and generate a random number
*/

class Student {
private:
    string name;
    int age;
    double gpa;
    double calCGPA();

public:
    // Default Constructor
    Student() {
        name = "";
        age = 0;
        gpa = 0.0;
    }

    //Parameterized Constructor
    Student(string n, int a, double g) : name(n), age(a), gpa(g) {}

    // Member functions to set values
    void setName(string n);                         // Name setter
    void setAge(int a);                             // Age setter
    void setGPA(double g);                          // GPA setter
    
    // Member functions to retrieve/get values
    string getName();                               // Name getter
    int getAge();                                   // Age getter
    double getGPA();                                // GPA getter
    
    // Other functions here
    void displayInfo();                             // Display information
    void randNumber();                              // Generate random number
    
};

// Write other functions here

// Get the name of the Student
void Student::setName(string n) { name = n; }

// Get the age of the Student
void Student::setAge(int a) { age = a; }

// Get the GPA of the Student
void Student::setGPA(double g) { gpa = g; }

// Return the name of the Student
string Student::getName() { return name; }

// Return the age of the Student
int Student::getAge() { return age; }

// Return the GPA of the Student
double Student::getGPA() { return gpa; }

// Calculate the CGPA of the student
double Student::calCGPA() {
    // Return the square root of the square of GPA minus 1
    return sqrt((gpa * gpa) - 1);
} 

// Generate a random number between 5001 and 6000
void Student::randNumber() {
    cout << "The student with ID " << (rand() % 1000) + 5001) << " received the award for excellency.";
}

// Print the Student information back out to user
void Student::displayInfo() {
    cout << "Age: " << age << endl;
    cout << fixed << setprecision ( 2 ) << "GPA: " << gpa << endl;
    cout << fixed << setprecision ( 2 ) << "CGPA: " << calCGPA() << endl;
}

int main() {
    // Create student objects
    Student student1;

    student1.setName("John Doe");
    student1.setAge(19);
    student1.setGPA(3.8);

    //Student student2("Jane Smith", 20, 3.5);

    Student student2;

    student2.setName("Jane Smith");
    student2.setAge(20);
    student2.setGPA(3.5);

    // Display information
    cout << "Student 1 Information:" << endl;
    cout << "Name: " << student1.getName() << endl;
    student1.displayInfo();
    cout << endl;

    cout << "Student 2 Information:" << endl;
    cout << "Name: " << student2.getName() << endl;
    student2.displayInfo();
    cout << endl;

    student1.randNumber();

    return 0;
}
