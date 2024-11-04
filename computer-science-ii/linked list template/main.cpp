#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Node class representing each element of the linked list
class Node
{
    // Public data
    public :
        int data;     // Data stored in the Node
        Node* next;   // Pointer to the next Node

        // Node () : data ( 0 ), next ( nullptr ) {}
        // Constructor to initialize a Node with given data and next pointer
        Node ( int value ) : data ( value ), next ( nullptr ) {}
};

// Linked list class to manage the list
class LinkedList
{
    // Private data
    private :
        Node* head;   // Point to the first Node of the list
    
    // Public data
    public :
        // Constructor to initialize an empty linked list
        LinkedList () : head ( nullptr ) {}

        // Destructor to deallocate memory when the list is destroyed
        ~LinkedList ()
        {
            // Delete all Nodes in the list, starting at the front
            Node* current = head;
            
            // While the current Node isn't empty
            while ( current != nullptr )
            {
                // The next Node is after the current one
                Node* next = current->next;
                // Delete the current Node
                delete current;
                // The next Node is made the current one
                current = next;
            }
            // The head is set to be empty to clear the list
            head = nullptr;
        }

        // Function to insert a new Node at the beginning of the list
        void insertBefore ( int value )
        {
            // Create a new Node with the given value
            Node* newNode = new Node ( value );
    
            // Set the next pointer of the new Node to the current head
            newNode->next = head;
    
            // Update the head to point to the new Node
            head = newNode;
        }
        
        // Function to insert a new Node in the middle of the list 
        void insertInMid ( int value ) 
        {
            // Create a new Node with the given value
            Node* newNode = new Node ( value );
                    
            // If there are no Nodes already in the list
            if ( head == nullptr )
            {
                // The new Node is the first object in the list
                head = newNode;
            }
            // Otherwise
            else
            {
                // Create a Node and ints to cycle through the list and get the length
                Node* ptr = head; 
                int length = 0;
                int count = 0;
          
                // Calculate the length of the list
                while ( ptr != NULL )
                {
                    // Add to the length variable
                    length ++;
                    // Cycle to next Node
                    ptr = ptr->next; 
                } 
          
                // If the length can be split in half evenly 
                if ( ( length % 2 ) == 0 )
                {
                    // The Nodes after insertion are the length divided by 2
                    count = ( length / 2 );
                }
                // Otherwise
                else
                {
                    // The Nodes after insertion are the length plus 1 divided by 2
                    count = ( length - 1 ) / 2;
                }
                ptr = head; 
          
                // While the count - 1 is less than one 
                while ( count-- > 1 )
                {
                    // The Node after insertion is moved back
                    ptr = ptr->next;
                }
          
                // Insert the Node in the correct spot
                newNode->next = ptr->next; 
                ptr->next = newNode; 
            } 
        }
        
        // Function to insert a new Node at the end of the list
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
            // The current Node, starting with the first in the list
            Node* current = head;
    
            // While the current Node isn't empty
            while ( current != nullptr )
            {   
                // Print out the current Node's data
                cout << current->data << " ";
                // Update to the next Node
                current = current->next;
            }
            cout << endl;
        }
};

// Main function
int main ()
{
    // Create a linked list
    LinkedList list;
    
    // Return to end the program
    return 0;
}