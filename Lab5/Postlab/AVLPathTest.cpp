/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 24, 2021  
   CS2150 Lab 5 Post Lab AVLPathTest.cpp  
*/

// NOTE: The AVLPathTest.cpp file was downloaded from the PDR/source code for the Lab 5 Post Lab (didn't modify this file)

#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
