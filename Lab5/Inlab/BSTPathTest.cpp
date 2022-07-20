/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 22, 2021  
   CS2150 Lab 5 In Lab BSTPathTest.cpp 
*/

// NOTE: This file was downloaded from the source code in the PDR/lab instructions for the Lab 5 In Lab (didn't modify this file) 

#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
    BinarySearchTree bst;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            bst.insert(word);
        } else if (instr == "R") {
            bst.remove(word);
        } else if (instr == "L") {
            cout << "BST path: " << bst.pathTo(word) << endl;
        }
    }
    cout << "BST numNodes: " << bst.numNodes() << endl;
}
