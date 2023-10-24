#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
using namespace std;

int main(){

  Stack<int> st1;
  cout << "Testing the push function" << endl;
  st1.push(1);
  st1.push(2);
  st1.push(3);
  st1.push(4);
  st1.push(5);
  st1.push(6);
  st1.push(7);
  st1.printStack();
  cout << "Testing the isEmpty():" << endl;
  cout << st1.isEmpty() << endl;
  cout << "Testing the copy constructor:" << endl;
  Stack<int> st2(st1);
  cout << "stack 1:" << endl;
  st1.printStack();
  cout << "Copied stack 2:" << endl;
  st2.printStack();
  cout << "Testing the overloaded == operator" << endl;
  if(st1 == st2){
    cout << "stacks are the same" << endl;
  }else{
    cout << "stacks are not the same" << endl;
  }
  cout << "Testing the pop function" << endl;
  st1.pop();
  cout << "Popping from Stack 1:" << endl;
  st1.printStack();
  cout << "Testing the overloaded == operator" << endl;
  if(st1 == st2){
    cout << "stacks are the same" << endl;
  }else{
    cout << "stacks are not the same" << endl;
  }
  cout << "Testing the size function" << endl;
  cout << "stack 1 size: "<< st1.getSize() << endl;
  cout << "stack 2 size: "<< st2.getSize() << endl;
  cout << "Testing the peek function" << endl;
  cout << "Top element in stack 1: "<<st1.peek() << endl;
  cout << "Top element in stack 2: "<< st2.peek() << endl;
  cout << "*******************************************\n";
  Stack<string> S1;
  cout << "Testing the push function" << endl;
  S1.push("a stack");
  S1.push("is");
  S1.push("this");
  S1.push("world");
  S1.push("hello");
  S1.printStack();
  cout << "Testing the isEmpty():" << endl;
  cout << S1.isEmpty() << endl;
  cout << "Testing the copy constructor:" << endl;
  Stack<string> S2(S1);
  cout << "stack 1:" << endl;
  S1.printStack();
  cout << "Copied stack 2:" << endl;
  S2.printStack();
  cout << "Testing the overloaded == operator" << endl;
  if(S1 == S2){
    cout << "stacks are the same" << endl;
  }else{
    cout << "stacks are not the same" << endl;
  }
  cout << "Testing the pop function" << endl;
  S1.pop();
  cout << "Popping from Stack 1:" << endl;
  S1.printStack();
  cout << "Testing the overloaded == operator" << endl;
  if(S1 == S2){
    cout << "stacks are the same" << endl;
  }else{
    cout << "stacks are not the same" << endl;
  }
  cout << "Testing the size function" << endl;
  cout << "stack 1 size: "<< S1.getSize() << endl;
  cout << "stack 2 size: "<< S2.getSize() << endl;
  cout << "Testing the peek function" << endl;
  cout << "Top element in stack 1: "<<S1.peek() << endl;
  cout << "Top element in stack 2: "<< S2.peek() << endl;
}