#include "List.h"
#include "List.cpp"
#include <iostream>
using namespace std;

int main(){
  List<int> L1, L2;

  cout << "Testing printList when the list is empty: \n";
  L1.printList();
  cout << endl;
  cout << "***Testing insertFirst***: " << endl;
  cout << "Testing Out insertFirst to L1 from 0-10\n";
  for (int i = 0; i <= 10; i++){
    L1.insertFirst(i);
  }
  L1.printList();

  cout << "\n***Testing out insertLast with 11 to L1***: \n";
  L1.insertLast(11);
  L1.printList();
  cout << "***Testing out removeFirst from L1***: \n";
  L1.removeFirst();
  L1.printList();
  cout << "***Testing out removeLast from L1***: \n";
  L1.removeLast();
  L1.printList();
  cout << "***Testing out isEmpty with List1 && List2***\n";
  cout << "0 means false, 1 means true" << endl;
  cout << "L1 is empty: " << L1.isEmpty() << endl;
  cout << "L2 is empty: " << L2.isEmpty() << endl;
  cout << "Inserting 1 to L2 : \n";
  L2.insertFirst(1);
  L2.printList();

  cout << "***Testing out getLength***:\n";
  cout << "size of L1: " << L1.getLength() << endl;
  cout << "size of L2: " << L2.getLength() << endl;
  cout << "\n***Testing out getFirst:***\n";
  cout << "First element in L1 is: " << L1.getFirst();
  cout << "\n***Testing out getLast:***\n";
  cout << "Last element in L1 is: " << L1.getLast() << endl;


  cout << "\n***Testing out startItertor() advanceIterator() & getIterator()***\n";
  cout << "We start the iterator at head of the L1 list: \n";
  L1.startIterator();
  L1.printList();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  cout << "We advance the iterator one place from where it is:\n";
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;


  cout << "\n***Testing the offEnd() in L2***\n" ;
  L2.insertFirst(2);
  cout << "What is our L2: \n";
  L2.printList();
  cout << "We advance the iterator in L2: \n";
  L2.startIterator();
  L2.advanceIterator();
  cout << "what element is our iterator pointing to: " << L2.getIterator() << endl;
  cout << "Iterator should NOT be off the end of the list\n";
  if (L2.offEnd())
    cout << "Iterator is off the end of the list" << endl;
  else
    cout << "Iterator is not off the end of the list\n\n";

  cout << "We advance the iterator now it should be offEnd()\n";
  L2.advanceIterator();
  if (L2.offEnd())
    cout << "Iterator is off the end of the list\n";
  else
    cout << "Iterator is not off the end of the list\n\n";


  cout << "\n***Testing the removeIterator()***\n";
  L1.printList();
  cout << "what element is our iterator pointing to in L1: ";
  L1.advanceIterator();
  cout << L1.getIterator();
  cout << "\nThe element pointed to by iterator is removed: \n";
  L1.removeIterator();
  L1.printList();
  // cout << "The iterator should be NULL: " << endl;
  // cout << L1.getIterator();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator 2x: " << endl;
  L1.advanceIterator();
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  L1.printList();
  cout << "We remove element pointed to by iterator: ";
  L1.removeIterator();
  L1.printList();
  cout << "We insert a new element at beginning: " << endl;
  L1.insertFirst(7);
  L1.printList();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator: " << endl;
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe remove element pointed to by iterator: ";
  L1.removeIterator();
  L1.printList();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator: " << endl;
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe remove element pointed to by iterator: ";
  L1.removeIterator();
  L1.printList();
  // cout << "The iterator should be NULL: " << endl;
  // cout << L1.getIterator();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator 5 times: " << endl;
  L1.advanceIterator();
  L1.advanceIterator();
  L1.advanceIterator();
  L1.advanceIterator();
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe remove element pointed to by iterator: ";
  L1.removeIterator();
  L1.printList();


  cout << "\n\n***Testing the insertIterator***\n";
  L1.printList();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator twice: \n";
  L1.advanceIterator();
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  cout << "We insert a new element 8 using insertIterator :\n";
  L1.insertIterator(8);
  L1.printList();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  cout << "We insert a new element 2 using insertIterator :\n";
  L1.insertIterator(2);
  L1.printList();
  cout << "new size: " << L1.getLength();


  cout << "\n\n***Testing the reverseIterator()****\n";
  L1.printList();
  cout << "Start the iterator again: " << endl;
  L1.startIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();
  cout << "\nWe advance our iterator 4x: \n";
  L1.advanceIterator();
  L1.advanceIterator();
  L1.advanceIterator();
  L1.advanceIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  cout << "We reverse our iterator once: ";
  L1.reverseIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator() << endl;
  cout << "We reverse our iterator twice: ";
  L1.reverseIterator();
  L1.reverseIterator();
  cout << "what element is our iterator pointing to in L1: ";
  cout << L1.getIterator();

  cout << "\n\n***Testing the operator == & copy constructor***\n";
  cout << "what is our L1 list: ";
  L1.printList();
  cout << "what is our L2 list: ";
  L2.printList();
  cout << "Testing if the lists are equal: \n";
  if(L1 == L2){
    cout << "L1 & L2 are the same\n";
  }else{
    cout << "L1 & L2 are not the same\n";
  }
  cout << "We make a copy of L1: " << endl;
  List<int> L3(L1);
  cout << "what is our L1 list: ";
  L1.printList();
  cout << "what is our L2 list: ";
  L2.printList();
  cout << "what is our copied L3 list: ";
  L3.printList();
  cout << "Testing if the lists L1 & L3 are the equal: \n";
  if(L1 == L3){
    cout << "L1 & L3 are the same\n";
  }else{
    cout << "L1 & L3 are not the same\n";
  }

  cout << "\n***Testing reversePrint()***\n";
  cout << "We make new list L4" << endl;
  List<int> L4;
  for (int i = 0; i <= 10; i++){
    L4.insertFirst(i);
  }
  cout << "what is our L4 list: ";
  L4.printList();
  cout << "We print the list in reverse using reversePrint(): \n";
  cout << "what is our L4 list in reverse: ";
  L4.reversePrint();

  cout << "\n***Testing the isSorted()***\n";
  if(L4.isSorted()){
    cout << "L4 is sorted" << endl;
  }else{
    cout << "L4 is not sorted" << endl;
  }
  cout << "We make a new sorted list L5: \n";
  List<int> L5;
  for (int i = 10; i >= 0; i--){
    L5.insertFirst(i);
  }
  cout << "what is our L5 list: ";
  L5.printList();
  cout << "***Testing the isSorted()***\n";
  if(L5.isSorted()){
    cout << "L5 is sorted" << endl;
  }else{
    cout << "L5 is not sorted" << endl;
  }

  cout << "\n***Testing the getIndex***\n";
  cout << "Indicates the index (starting from 1) of the Node where the iterator is currently pointing to.\n";
  cout << "We start the iterator at head of the L5 list: \n";
  L5.startIterator();
  L5.printList();
  cout << "what element is our iterator pointing to in L5: ";
  cout << L5.getIterator() << endl;
  cout << "We advance the iterator one place from where it is:\n";
  L5.advanceIterator();
  cout << "what element is our iterator pointing to in L5: ";
  cout << L5.getIterator() << endl;
  cout << "What is the index of our iterator: ";
  cout << L5.getIndex();

  cout << "\n\n***Testing the advanceToIndex()***\n";
  cout << "The current index of iterator in L5 is: ";
  cout << L5.getIndex() << endl;
  cout << "We move to index 7";
  L5.advanceToIndex(7);
  cout << "\nThe iterator is now at index: ";
  cout << L5.getIndex() << endl;
  cout << "what is the value at index 7 (1-based indexing) that the iterator is pointing to now: ";
  cout << L5.getIterator() << endl;

  cout << "\n***Testing linearSearch***\n";
  cout << "Returns the index of the element, if it is found in the List else -1" << endl;
  L5.printList();
  cout << "Searching for element 9 in L5: ";
  cout << "is at index " << L5.linearSearch(9) << endl;
  cout << "Searching for element 10 in L5: ";
  cout << "is at index " << L5.linearSearch(10) << endl;
  cout << "Searching for element 12 in L5: ";
  cout << "is at index " << L5.linearSearch(12) << endl;

  cout << "\n***Testing binarySearch***\n";
  cout << "Returns the index of the element, if it is found in the List else -1" << endl;
  cout << "Searching for element 2 in L5: ";
  cout << "is at index " << L5.linearSearch(2) << endl;
  cout << "Searching for element 0 in L5: ";
  cout << "is at index " << L5.linearSearch(0) << endl;
  cout << "Searching for element 12 in L5: ";
  cout << "is at index " << L5.linearSearch(12) << endl;

  return 0;
}