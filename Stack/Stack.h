#ifndef MY_STACK_H
#define MY_STACK_H
#include <cstddef>
using namespace std;

template<class stackdata>
class Stack{
  private:
    struct Node{
      stackdata data;
      Node *next;

      Node(stackdata newData){
        data = newData;
        next = NULL;
      }
    };
    Node *top;
    int size;
  public:
  /**constructors and destructors*/
    Stack();
    //initializes an empty stack
    //post: an empty stack created with all fields assigned default values
    ~Stack();
    //frees memory allocated to the stack
    //post: memory for stack has been freed
    Stack(const Stack &S);
    //initializes this stack to have same elements as S
    //post: a deep copy of the stack S
  /**manipulation procedures*/
    void push(stackdata data);
    void pop();
  /**accessors*/
    bool operator==(const Stack &S);
    //returns whether this stack is equal to another stack S
    stackdata peek() const;
    //returns the element at the top of the stack
    //pre: size != 0
    int getSize() const;
    //returns the size of the stack
    bool isEmpty() const;
    //returns whether the stack is empty
  /**additional operations*/
    void printStack() const;
    //prints the elements in the stack each element separate by a blank space to stdout
};

#endif