#include "List.h"
#include <iostream>

using namespace std;

//constructor
List::List(){
  first = NULL;
  last = NULL;
  length = 0;
}

//Destructor
List::~List(){
  Node *it = first;
  Node *temp = NULL;
  while(it != NULL){
    temp = it->next;
    delete (it);
    it = temp;
  }
}

void List::printList() const {
  Node *it = first;
  while(it != NULL){
    cout << it->data << " ";
    it = it->next;
  }
  cout << endl;
}

void List::insertFirst(int data){
  Node *newNode = new Node(data);
  if(length==0){
    first = newNode;
    last = newNode;
  }else{
    newNode->next = first;
    first = newNode;
  }
  length++;
}

void List::insertLast(int data){
  Node *newNode = new Node(data);
  if (length==0){
    first = newNode;
    last = newNode;
  }else{
    last->next = newNode;
    newNode->next = NULL;
    last = newNode;
  }
  length++;
}

void List::removeFirst(){
  if(length==0){
    cout << "List is empty";
    return;
  }else if(length==1){
    delete (first);
    first = NULL;
    last = NULL;
  }else{
    Node *temp = first;
    first = first->next;
    delete (temp);
  }
  length--;
}

void List::removeLast(){
  Node *it = first;
  if(length==0){
    cout << "List is empty";
    return;
  }else if(length==1){
    delete (first);
    first = NULL;
    last = NULL;
  }else{
    while(it->next!=last){
      it = it->next;
    }
    delete (last);
    last = it;
    last->next = NULL;
  }
  length--;
}

bool List::isEmpty() const{
  return length == 0;
}

int List::getLength() const{
  return length;
}

int List::getLast() const{
  return last->data;
}

int List::getFirst() const{
  return first->data;
}