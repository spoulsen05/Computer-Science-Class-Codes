#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Name: Severin Poulsen
Project: Lab 6
Class: CMPS-148 / Computer Science II
Section: M/R 2:15 PM - 3:55 PM / 01
Email: spoulsen@ramapo.edu
Date: 28 March 2024

This program will create a linked list utilizing the Node and LinkedList classes
It will take input and add each element to the end of the list, and print the list back to the user
*/

// Node class representing each element of the linked list
class Node
{
    // Public variables
    public :
        int data;     // Data stored in the Node
        Node* next;   // Pointer to the next Node

        // Constructor to initialize a Node with given data and next pointer
        Node ( int value ) : data ( value ), next ( nullptr ) {}
};

// Linked list class to manage the list
class LinkedList
{
    // Public variables
    public :
        Node* head;   // Pointer to the first Node of the list
        // Constructor to initialize an empty linked list
        LinkedList () : head ( nullptr ) {}

        // Destructor to deallocate memory when the list is destroyed
        ~LinkedList ()
        {
            // Delete all Nodes in the list
            Node* current = head;
            while ( current != nullptr )
            {
                Node* next = current->next;
                delete current;
                current = next;
            }
            // The front of the list is empty
            head = nullptr;
        }

        // Function to insert a new Node at the beginning of the list
        void insertAfter ( int value )
        {
            // Create a new Node with the given value
            Node* newNode = new Node ( value );
    
            // Set the new Node to the end of the list
            newNode->next = nullptr;
            
            // If there are no Nodes already in the list
            if ( head == nullptr )
            {
                // The new Node is the first object in the list
                head = newNode;
            }
            // Otherwise
            else
            {
                // Create a Node to point to the end of the list
                Node* last = head;
                
                // While the next Node is not empty
                while ( last->next != nullptr )
                {
                    // Cycle to the end of the list
                    last = last->next;
                }
                
                // Update the last Node to point to the new Node
                last->next = newNode;
            }
        }

        // Function to print the elements of the list
        void display ()
        {
            // The current Node, defaulting at the front of the list
            Node* current = head;
    
            // While the current Node is not null
            while ( current != nullptr )
            {
                // Print out the current Node
                cout << current->data << " ";
                // The next Node becomes the current Node
                current = current->next;
            }
        }
};

// Main function
int main ()
{
    // Input variable
    int input;
    
    // Create a linked list
    LinkedList list;

    // Insert elements into the list at the beginning
    cin >> input;
    list.insertAfter ( input );
    cin >> input;
    list.insertAfter ( input );
    cin >> input;
    list.insertAfter ( input );
    cin >> input;
    list.insertAfter ( input );
    cin >> input;
    list.insertAfter ( input );

    // Display the elements of the list
    cout << "The list: ";
    list.display ();
    
    // Return 0 to end function
    return 0;
}