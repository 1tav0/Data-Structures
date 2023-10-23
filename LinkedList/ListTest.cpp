#include <iostream>
#include "List.h"
using namespace std;

int main(){

  List L1;
  List L2;

  L1.insertFirst(0);
  L1.insertLast(1);
  L1.insertLast(2);
  L1.insertLast(3);
  L1.insertLast(4);
  cout << "Is the list empty? " << (L1.isEmpty() ? "Yes" : "No") << endl;
  cout << "Length of the list: " << L1.getLength() << endl;
  cout << "First element in the list: " << L1.getFirst() << endl;
  cout << "Last element in the list: " << L1.getLast() << endl;
  L1.isEmpty();
  L1.printList(); // To print the entire list
  return 0;
}