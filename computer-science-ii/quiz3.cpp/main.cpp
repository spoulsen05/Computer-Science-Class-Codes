#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Node class representing each element of the linked list
class Node
{
    public :
        int data;     // Data stored in the node
        Node* next;   // Pointer to the next node

        //Node () : data ( 0 ), next ( nullptr ) {}
        // Constructor to initialize a node with given data and next pointer
        Node ( int value ) : data ( value ), next ( nullptr ) {}
};

// Linked list class to manage the list
class LinkedList
{
    private :
        Node* head;   // Pointer to the first node of the list

    public :
        // Constructor to initialize an empty linked list
        LinkedList () : head ( nullptr ) {}

        // Destructor to deallocate memory when the list is destroyed
        ~LinkedList ()
        {
            // Delete all nodes in the list
            Node* current = head;
            while ( current != nullptr )
            {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

        // Function to insert a new node at the beginning of the list
        void insert ( int value )
        {
            // Create a new node with the given value
            Node* newNode = new Node ( value );
    
            // Set the next pointer of the new node to the current head
            newNode->next = head;
    
            // Update the head to point to the new node
            head = newNode;
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
            // Create a node and ints to cycle through the list and get the length
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
            {   // The nodes after insertion are the length divided by 2
                count = ( length / 2 );
            }
            // Otherwise
            else
            {   // The nodes after insertion are the length plus 1 divided by 2
                count = ( length - 1 ) / 2;
            }
            ptr = head; 
      
            // While the count - 1 is less than one 
            while ( count-- > 1 )
            {   // The Node after insertion is moved back
                ptr = ptr->next;
            }
      
            // Insert the Node in the correct spot
            newNode->next = ptr->next; 
            ptr->next = newNode; 
        } 
    } 

        // Function to print the elements of the list
        void display ()
        {
            Node* current = head;
    
            while ( current != nullptr )
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main ()
{
    // Create the array of input variables
    int input [5];
    
    // Create a linked list
    LinkedList list;
    
    // Initialize the linked list with 10, 15, and 20
    list.insert ( 20 );
    list.insert ( 15 );
    list.insert ( 10 );
    
    // Print the initial list to the user
    cout << "Initial List: ";
    list.display ();
    
    // Take the inputs from the user and store them in the input array
    for ( int i = 0; i < 5; i ++ )
    {
        cin >> input [i];
    }
    
    // Insert the first two numbers at the front of the list
    list.insert ( input [0] );
    list.insert ( input [1] );
    
    // Print the list to the user after adding two numbers to the front
    cout << "List after adding two numbers at the beginning: ";
    list.display ();
    
    // Insert the next two numbers at the end of the list
    list.insertAfter ( input [2] );
    list.insertAfter ( input [3] );
    
    // Print the list to the user after adding two numbers to the end
    cout << "List after adding two numbers at the end: ";
    list.display ();
    
    // Insert the last number in the middle of the list
    list.insertInMid ( input [4] );
    
    // Print the list to the user after adding the last number in the middle
    cout << "List after adding " << input [4] << " in the middle: ";
    list.display ();

    return 0;
}