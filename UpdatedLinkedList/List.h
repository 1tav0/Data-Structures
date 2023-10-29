#ifndef MY_LIST_H
#define MY_LIST_H

#include <cstddef> //for NULL
using namespace std;

template<class listdata>
class List{
  private:
    struct Node{
      listdata data;
      Node *next;
      Node *prev;

      Node(listdata newData){
        data = newData;
        next = prev = NULL;
      }
    };
    Node *head;
    Node *tail;
    Node *iterator;
    int size;

    void reversePrint(Node *node) const;
    //Helper function for the public reversePrint() function.
    //Recursively prints the data in a List in reverse.
    bool isSorted(Node *node) const;
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.
    int binarySearch(int low, int high, listdata data) const;
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Post: The iterator location has not been changed
  public:
  /**Constructors and Destructors*/
    List();
    //Default constructor; initializes and empty list
    //Constructs a new linked list object.
    //Postcondition: An empty list was created.
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Freeing memory by deleting the linked list.
    List(const List &L);
    //Makes a copy of the list object

  /**Accessors*/

    listdata getFirst() const;
    //Returns the first data in the list
    //Precondition: The list must not be empty
    listdata getLast() const;
    //Returns the last data in the list
    //pre: The list must not be empty
    bool isEmpty() const;
    //Determines if the list is empty
    int getLength() const;
    //Returns the length of the list
    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator
    bool offEnd() const;
    //Returns whether the iterator is off the end of the list, ie NULL
    bool operator==(const List &L);
    //compares if two lists are the same
    bool isSorted() const;
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function
    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: !offEnd()
    int linearSearch(listdata data) const;
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Does not call the indexing functions in the implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed
    int binarySearch(listdata data) const;
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed

   /**Manipulation Procedures*/

    void removeFirst();
    //Removes the value stored in first node in the list
    //Precondition: The list must not be empty
    //Postcondition: The first data is removed
    void removeLast();
    //Removes the value stored in the last node in the list
    //Precondition: The list must not be empty
    //Postcondition: The last data is removed
    void insertFirst(listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the front of the list
    void insertLast(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: The new data added to the end of the list
    void startIterator();
    //Moves the iterator to the start of the list
    void advanceIterator();
    //Moves the iterator up by one node
    void reverseIterator();
    //Moves the iterator down by one node
    void removeIterator();
    // Removes the element currently pointed to by the iterator. Iterator then points to NULL.
    void insertIterator(listdata data);
    //inserts an element after the node currently pointed to by the iterator
    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
   	//Nodes are numbered starting at 1 through the size of the List
   	//Pre: size != 0
   	//Pre: index <= size
    void move(int sourceLine, int destinationLine);
    // moves data from sourceLine to destinationLine

    /**Additional List Operations*/

    void printList() const;
    //Prints to the console the value of each data in the list sequentially
    //Prints a empty newline character if it's empty..
    void reversePrint() const;
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty
    void printNumberedList();
};

#endif