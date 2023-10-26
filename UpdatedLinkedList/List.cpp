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

template <class listdata>
int List<listdata>::getIndex() const{
  assert(!offEnd());
  assert(size != 0);
  Node *temp = head;
  int index = 1;
  while(temp != iterator){
    index++;
    temp = temp->next;
  }
  return index;
}

template <class listdata>
int List<listdata>::linearSearch(listdata data) const{
  assert(!isEmpty());
  Node *it = head;
  int index = 1;
  while(it != NULL){
    if(it->data == data){
      return index;
    }else{
      index++;
      it = it->next;
    }
  }
  return -1;
}

template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const{
  assert(!isEmpty());
  while(low<=high){
    int mid = low + (high-low) / 2;
    Node *it = head;
    for (int i = 1; i < mid; i++){
      it = it->next;
    }
    if(it->data == data){
      return mid;
    }else if(data < temp->data){
      return binarySearch(low, mid - 1, data);
    }else{
      return binarySearch(mid + 1, high, data);
    }
  }
  return -1;
}

template <class listdata>
int List<listdata>::binarySearch(listdata data) const{
  assert(!isEmpty());
  if(!isSorted()){
    return -1;
  }else{
    return binarySearch(head->data, tail->data, data);
  }
}

template <class listdata>
void List<listdata>::removeFirst(){
  assert(!isEmpty());
  if(size==1){
    delete (head);
    head = tail = iterator = NULL;
  }else{
    Node *it = head;
    if(iterator == head){
      iterator = NULL;
    }
    head = head->next;
    head->next->prev = NULL;
    delete (it);
  }
  size--;
}

template <class listdata>
void List<listdata>::removeLast(){
  assert(!isEmpty());
  if(size==1){
    delete (head);
    head = tail = iterator = NULL;
  }else{
    Node *it = tail;
    if(iterator==tail){
      iterator = NULL;
    }
    tail = tail->prev;
    tail->next = NULL;
    delete (it);
  }
  size--;
}

template <class listdata>
void List<listdata>::insertLast(listdata data){
  Node *newNode = new Node(data);
  if(isEmpty()){
    head = tail  = newNode;
  }else{
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

template <class listdata>
void List<listdata>::insertFirst(listdata data){
  Node *newNode = new Node(data);
  if(isEmpty()){
    head = tail = newNode;
  }else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  size++;
}

template <class listdata>
void List<listdata>::startIterator(){
  assert(!isEmpty());
  iterator = head;
}

template <class listdata>
void List<listdata>::advanceIterator(){
  assert(iterator != NULL);
  iterator = iterator->next;
}

template <class listdata>
void List<listdata>::reverseIterator(){
  assert(iterator != NULL);
  iterator = iterator->prev;
}

template <class listdata>
void List<listdata>::removeIterator(){
  assert(iterator != NULL);
  if(iterator == first){
    removeFirst();
  }else if(iterator == last){
    removeLast();
  }else{
    iterator->prev->next = iterator->next;
    iterator->next->prev = iterator->prev;
    delete (iterator);
    iterator = NULL;
  }
  size--;
}

template <class listdata>
void List<listdata>::insertIterator(listdata data){
  assert(iterator != NULL);
  if(iterator == last){
    insertLast(data);
  }else{
    Node *newNode = new Node(data);
    newNode->next = iterator->next;
    iterator->next->prev = newNode;
    newNode->prev = iterator;
    iterator->next = newNode;
  }
  size++;
}

template <class listdata>
void List<listdata>::advanceToIndex(int index){
  assert(!isEmpty());
  assert(index <= size);
  Node *it = head;
  for (int i = 1; i <= index; i++){
    iterator = it;
    it = it->next;
  }
}

template <class listdata>
void List<listdata>::printList() const{
  assert(!isEmpty());
  Node *it = head;
  while(it != NULL){
    cout << it->data << " ";
    it = it->next;
  }
  cout << endl;
}

template <class listdata>
void List<listdata>::reversePrint(Node *node) const{
  if(node){
    reversePrint(node->next);
    cout << node->data << " ";
  }
}

template <class listdata>
void List<listdata>::reversePrint() const{
  reversPrint(head);
}