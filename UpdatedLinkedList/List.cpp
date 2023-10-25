#include "List.h"
#include <cstddef> //for NULL
#include <cassert> 
#include <iostream>
#include <string>
using namespace std;

template <class listdata>
List<listdata>::List(){
  head = tail = iterator = NULL;
  length = 0;
}

template <class listdata>
List<listdata>::~List(){
  Node *it = head;
  Node *temp = NULL;
  while(it != NULL){
    temp = it->next;
    delete (it);
    it = temp;
  }
  size = 0;
}

template <class listdata>
List<listdata>::List(const List &L){
  if(L.head==NULL){
    head = tail = iterator = NULL;
  }else{
    head = new Node(L.head->data);
    Node *it = L.head;
    iterator = head;
    while(it->next != NULL){
      it = it->next;
      iterator->next = new Node(it->data);
      iterator->next->prev = iterator;
      iterator = iterator->next;
    }
    tail = iterator;
    iterator = NULL;
  }
  size = L.size;
}

template <class listdata>
listdata List<listdata>::getFirst() const{
  assert(size != 0);
  return head->data;
}

template <class listdata>
listdata List<listdata>::getLast() const{
  assert(size != 0);
  return tail->data;
}

template <class listdata>
bool List<listdata>::isEmpty() const{
  if(size==0){
    return true;
  }else{
    return false;
  }
}

template <class listdata>
int List<listdata>::getLength() const{
  return size;
}

template <class listdata>
listdata List<listdata>::getIterator() const{
  assert(iterator != NULL);
  return iterator->data;
}

template <class listdata>
bool List<listdata>::offEnd() const{
  if(iterator == NULL){
    return true;
  }else{
    return false;
  }
}

template<class listdata>
bool List<listdata>::operator==(const List &L){
  if(L.size != size){
    return false;
  }else{
    Node *it = L.head;
    iterator = head;
    while(it->next != NULL){
      if(it->data != iterator->data){
        return false;
      }
      it = it->next;
      iterator = iterator->next;
    }
    return true;
  }
  size = L.size;
}

template <class listdata>
bool List<listdata>::isSorted(Node *node) const{
  if(node->next == NULL){
    return true;
  }else if(node->data > node->next->data){
    return false;
  }else{
    return isSorted(node->next);
  }
}

template <class listdata>
bool List<listdata>::isSorted() const{
  if(isEmpty()){
    return true;
  }else{
    return isSorted(head);
  }
}