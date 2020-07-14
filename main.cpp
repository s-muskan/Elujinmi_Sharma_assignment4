#include <iostream>
#include <fstream>
#include <stdio.h>
#include "BinaryTree.cpp"
#include <cstdlib>
#include <sstream>
#include <string>




using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::cin;

int main( int argc, char * argv[]) {


    ifstream readFile(argv[1]); //takes in file from command line
    string input = "";
    ItemType item;

    BinaryTree list;
while(getline(readFile,input)) {
    std::istringstream iss(input); //reads input
    ItemType item;
    int num;

    while (iss >> num) { //adds ech number to list

      item.initialize(num); //creates item
      list.insert(item); //adds to list
    }
  }

    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), \n pre-order (p), post-order (o), getSameLevelNonsiblings (c),quit (q)"<<endl;

     while (true) { //loop to keep going
         cout << "Enter a command:  ";
         getline(cin, input); //gets in command entered by user
         if (input.compare("i") == 0) { //if insert
        cout << "Number to insert:  ";
        getline(cin, input); //gets number
        item.initialize(stoi(input)); //adds number to item
        list.insert(item); //adds item to list
        list.inOrder();
         } else if (input.compare("n") == 0) { //if insert
        list.inOrder();
         } else if (input.compare("p") == 0) { //if insert
        list.preOrder();
         } else if (input.compare("o") == 0) { //if insert
        list.postOrder();
         }
     }
}
