#include <iostream>
#include <fstream>
#include "List.h"
#include "List.cpp"
#include <string>
#include <locale>

using namespace std;

List<string> L;

int main(){
  int sourceLine;
  int destinationLine;
  bool flag = true;
  string directionLineLower = "";
  string directionLine;
  string Line;
  string textFile;
  string title;
  string temp;

  cout << "Welcome to the poetry re-arranger!\n\n";
  cout << "Enter the name of a file containing a poem: \n";
  cin >> textFile;
  int linenumber = 0;
  ifstream myFile(textFile);
  while(myFile.fail()){
    cout << "Wrong textFile" << endl;
    cout << "Please re enter the textFile." << endl;
    cin >> textFile;
    myFile.open(textFile);
  }

  getline(myFile, title);
  // getline(myFile, temp);

  while(!myFile.eof()){
    getline(myFile, Line);
    // L.getLength();
    // cout << Line << endl;
    L.insertLast(Line);
  }

  cout << endl;

  string author = L.getLast();
  L.removeFirst();
  L.removeLast(); //removing the last two line of txt file
  L.removeLast();

  cout << "There are " << L.getLength() << " lines in your poem " << endl;
  cout << "The poem is: ";
  cout << title << " ";
  cout << author << endl << endl;
  L.printNumberedList();

  // L.startIterator();
  // for (int i = 1; i < sourceLine; i++, L.advanceIterator()){
  //   string storeData = L.getIterator();
  //   L.removeIterator();

  //   if(destinationLine>sourceLine){
  //     destinationLine--;
  //   }

  //   L.startIterator();
  //   for (int i = 1; i < destinationLine; i++, L.advanceIterator());

  //   L.insertIterator(storeData);
  // }

  while(flag){
    cout << "How would you like to rearrange this poem? \n\n";
    cout << "Please enter the line number of the poem: ";
    cin >> sourceLine;

    L.startIterator();
    for (int i = 0; i < sourceLine-1; i++){
      L.advanceIterator();
    }
    string poemLine = L.getIterator();
    if(poemLine == ""){
      cout << "The line is blank" << endl;
    }else{
      cout << "The line is: " << poemLine << endl;
    }
    cout << endl;
    cout << "Do you want to move this line up or down:";
    cin >> directionLine;
    cout << "How many lines do you want to move it: ";
    cin >> destinationLine;
    if(directionLine == "up"){
      for (int i = 0; i < destinationLine + 1; i++){
        L.reverseIterator();
      }
      L.insertIterator(poemLine);
      for (int i = 0; i < destinationLine + 2; i++){
        L.advanceIterator();
      }
      L.removeIterator();
    }else if(directionLine == "down"){
      for (int i = 0; i < destinationLine; i++){
        L.advanceIterator();
      }
      L.insertIterator(poemLine);
      for (int i = 0; i < destinationLine; i++){
        L.reverseIterator();
      }
      L.removeIterator();
    }

    cout << "The new poem is: " << endl;
    cout << endl;
    L.printNumberedList();

    cout << "Would you like to rearrange this poem further: ";
    cin >> directionLineLower;
    if(directionLineLower.compare("no") == 0){
      flag = false;
      cout << "Goodbye!" << endl;
    }
  }
}