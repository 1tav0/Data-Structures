#include <iostream>
#include <ostream>
#include <iomanip>
#include "BST.h"
using namespace std;

int main(){
  BST<int> T1, T2, T3;
  cout << "We insert 0-10 to our T1." << endl;
  cout << "We insert 40,10,32,78,25 to our T2." << endl;
  for (int i = 0; i <= 10; i++){
    T1.insert(i);
  }
  T2.insert(40);
	T2.insert(10);
	T2.insert(32);
	T2.insert(78);
	T2.insert(25);

  cout << "\n***Testing the inOrderPrint() for our T1***\n";
  T1.inOrderPrint(cout);
  cout << "\n***Testing the inOrderPrint() for our T2***\n";
  T2.inOrderPrint(cout);
  cout << "\n***Testing the getRoot() for our T1***\n";
  cout << T1.getRoot();
  cout << "\n***Testing the getRoot() for our T2***\n";
  cout << T2.getRoot();
  cout << "\n***Testing the postOrderPrint() for our T1***\n";
  T1.postOrderPrint(cout);
  cout << "\n***Testing the postOrderPrint() for our T2***\n";
  T2.postOrderPrint(cout);
  cout << "\n***Testing the preOrderPrint() for our T1***\n";
  T1.preOrderPrint(cout);
  cout << "\n***Testing the preOrderPrint() for our T2***\n";
  T2.preOrderPrint(cout);
  
  cout << "\n***Testing getMinimum()***\n";
  cout << "What is our minimum element in T1: ";
  cout << T1.getMinimum() << endl;
  cout << "What is our minimum element in T2: ";
  cout << T2.getMinimum() << endl;

  cout << "\n***Testing getMaximum()***\n";
  cout << "What is our Maximum element in T1: ";
  cout << T1.getMaximum() << endl;
  cout << "What is our Maximum element in T2: ";
  cout << T2.getMaximum() << endl;

  cout << "\n***Testing the isEmpty()***\n";
  cout << "1 means yes, 0 means no" << endl;
  cout << "Is T1 empty? " << T1.isEmpty() << endl;
  cout << "Is T2 empty? " << T2.isEmpty() << endl;
  cout << "Is T3 empty? " << T3.isEmpty() << endl;

  cout << "\n***Testing the getSize()***\n";
  cout << "Size of T1? " << T1.getSize() << endl;
  cout << "Size of T2? " << T2.getSize() << endl;
  cout << "Size of T3? " << T3.getSize() << endl;

  cout << "\n***Testing the getHeight()***\n";
  cout << "Height of T1? " << T1.getHeight() << endl;
  cout << "Height of T2? " << T2.getHeight() << endl;
  cout << "Height of T3? " << T3.getHeight() << endl;

  cout << "\n***Testing the search()***\n";
  cout << "1 means is in the tree, 0 means is not in the tree" << endl;
  cout << "Search for 7 in T1? " << T1.search(7) << endl;
  cout << "Height for 7 in T2? " << T2.search(7) << endl;

  cout << "\n***Testing the remove()***\n";
  cout << "Original inOrderPrint of T1: ";
  T1.inOrderPrint(cout);
  cout << "Original inOrderPrint of T2: ";
  T2.inOrderPrint(cout);
  T1.remove(5);
  T2.remove(40);
  cout << "Removing 5 from T1? what is the inOrderPrint: ";
  T1.inOrderPrint(cout);
  cout << "Removing 40 from T2? what is the inOrderPrint: ";
  T2.inOrderPrint(cout);

  cout << "\n***Testing the copy constructor***\n";
  cout << "Is T1 empty? " << T2.isEmpty() << endl;
  cout << "Is T3 empty? " << T3.isEmpty() << endl;
  BST<int> T4(T1);
  cout << "We copy T2 as a new tree T3" << endl;
  cout << "What is our T1: ";
  T1.inOrderPrint(cout);
  cout << "What is our T3: ";
  T4.inOrderPrint(cout);
}