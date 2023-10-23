#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

template<class queuedata>
class Queue{
  private:
    struct Node{
      queuedata data;
      Node *next;

      Node(queuedata d){
        data = d;
        next = NULL;
      }
    };
    Node *front;
    Node *end;
    int size;
  
  public:
  /**constructors and destructures**/
    Queue();
    //initializes an empty queue
    //postcondition: an empty queue created with default values for all fields
    ~Queue();
    //frees memory allcocated to the queue
    //postcondition: memory for queue has been freed
    Queue(const Queue &Q);
    // initializes a queue to have same elements as another queue
    // post : a deep copy of the queue

  /**manipulation procedures*/
    void dequeue();
    // removes an element from the front of the queue
    //pre: size != 0
    //post: an element is removed from the front of the queue
    void enqueue(queuedata data);
    // adds an element to the end of the queue
    // post: an element is added to end of the queue

  /**accessors*/
    bool operator==(const Queue &Q);
    // returns whether this queue is equal to another queue
    queuedata getFront() const;
    //returns the element in the front of the queue
    //pre: size!=0
    int getSize() const;
    //returns the size of the queue
    bool isEmpty() const;
    //returns wether the queue is empty or not 

  /**additional queue operations*/
    void printQueue() const;
    //prints the elements in the queue separated by a blank space to stdout
};

#endif

