#include "Stack.h"
#include <assert.h>
#include <iostream>
using namespace std;

template<class stackdata>
Stack<stackdata>::Stack(){
  top = NULL;
  size = 0;
}

template<class stackdata>
Stack<stackdata>::~Stack(){
  Node *it = top;
  Node *temp = NULL;
  while(it != NULL){
    temp = it->next;
    delete (it);
    it = temp;
  }
  size = 0;
}

template<class stackdata>
Stack<stackdata>::Stack(const Stack &S){
  if(S.top == NULL){
    top = NULL;
  }else{
    top = new Node(S.top->data);
    Node *it = S.top;
    Node *copy = top;
    while(it->next != NULL){
      it = it->next;
      copy->next = new Node(it->data);
      copy = copy->next;
    }
    copy = NULL;
  }
  size = S.size;
};

template <class stackdata>
void Stack<stackdata>::push(stackdata data){
  Node *newNode = new Node(data);
  if(size==0){
    top = newNode;
  }else{
    newNode->next = top;
    top = newNode;
  }
  size++;
}

template<class stackdata>
void Stack<stackdata>::pop(){
  if(size==0){
    cout << "Stack is empty";
  }else if(size == 1){
    delete (top);
    top = NULL;
  }else{
    Node *it = top;
    top = top->next;
    delete (it);
  }
  size--;
}

template<class stackdata>
bool Stack<stackdata>::operator==(const Stack & S){
  if(S.size != size){
    return false;
  }else{
    Node *it = S.top;
    Node *copy = top;
    while(it!= NULL){
      if(it->data != copy->data){
        return false;
      }
      it = it->next;
      copy = copy->next;
    }
    return true;
  }
}

template<class stackdata>
stackdata Stack<stackdata>::peek() const{
  if(size==0){
    cout << "Stack is empty";
  }else{
    return top->data;
  }
}

template <class stackdata>
int Stack<stackdata>::getSize() const{
  assert(size != 0);
  return size;
}

template <class stackdata>
bool Stack<stackdata>::isEmpty() const{
  if(size==0){
    return true;
  }else{
    return false;
  }
} 

template<class stackdata>
void Stack<stackdata>::printStack() const{
  if(size==0){
    cout << "Stack is empty";
  }else{
    Node* it = top;
    while(it != NULL){
      cout << it->data << " ";
      it = it->next;
    }
    cout << endl;
  }
}
