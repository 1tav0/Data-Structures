#include "Queue.h"
#include <iostream>
using namespace std;

template<class queuedata>
Queue<queuedata>::Queue(){
  front = end = NULL;
  size = 0;
}

template<class queuedata>
Queue<queuedata>::~Queue(){
  Node *it = front;
  Node *temp = NULL;
  while(it != NULL){
    temp = it->next;
    delete (it);
    it = temp;
  }
}

template<class queuedata>
Queue<queuedata>::Queue(const Queue &Q){
  if(Q.front == NULL){
    front = end = NULL;
  }else{
    front = new Node(Q.front->data);
    Node *it = Q.front;
    Node *copyit = front;
    while(it->next != NULL){
      it = it->next;
      copyit->next = new Node(it->data);
      copyit = copyit->next;
    }
    end = copyit;
    copyit = NULL;
  }
  size = Q.size;
}

template<class queuedata>
void Queue<queuedata>::enqueue(queuedata data){
  Node *newNode = new Node(data);
  if(size==0){
    front = end = newNode;
    size++;
  }else{
    end->next = newNode;
    end = newNode;
    size++;
  }
}

template<class queuedata>
void Queue<queuedata>::dequeue(){
  if(size==0){
    cout << "Queue is empty" << endl;
    return;
  }else if(size==1){
    delete (front);
    front = end = NULL;
  }else{
    Node *temp = front;
    front = front->next;
    delete (temp);
  }
  size--;
}

template<class queuedata>
bool Queue<queuedata>::operator == (const Queue &Q){
  if(size != Q.size){
    return false;
  }else{
    Node *it = Q.front;
    Node *copy = front;
    while(it != NULL){
      if(it->data != copy->data){
        return false;
      }
      it = it->next;
      copy = copy->next;
    }
  }
  return true;
}

template<class queuedata>
queuedata Queue<queuedata>::getFront() const{
  assert(size != 0);
  return front->data;
}

template<class queuedata>
int Queue<queuedata>::getSize() const{
  assert(size != 0);
  return size;
}

template<class queuedata>
bool Queue<queuedata>::isEmpty() const{
  return size != 0;
}

template<class queuedata>
void Queue<queuedata>::printQueue() const{
  assert(size != 0);
  Node *it = front;
  while(it != NULL){
    cout << it->data << " ";
    it = it->next;
  }
  cout << endl;
}