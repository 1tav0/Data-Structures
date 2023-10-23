#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
using namespace std;

int main(){
  Queue<int> q1, q2;
  cout << "Testing enqueue" << endl;
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);
  q1.enqueue(4);
  q1.printQueue();
  cout << "Testing Dequeue" << endl;
  q1.dequeue();
  q1.printQueue();
  q2.enqueue(10);
  q2.enqueue(2);
  q2.enqueue(6);
  q2.enqueue(4);
  //Testing operator==
	cout << "\n** Testing operator== **\n\n";
	if(q1==q2)
		cout << "Queues are the same.\n";
	else
		cout << "Those two Queues are not the same.\n";

  cout << "\n** Testing getFront() **\n\n";
	cout << q2.getFront() << endl;

  //Testing getSize()
	cout << "\n** Testing getSize() **\n\n";
	cout << q1.getSize() << endl;

  // **TEsting copy constructor
  cout << "\nTesting copy constructor\n\n";

  Queue<int> q3(q2);
  cout << "this is q2" << endl;
  q2.printQueue();
  cout << "this is q3" << endl;
  q3.printQueue();

  return 0;
}