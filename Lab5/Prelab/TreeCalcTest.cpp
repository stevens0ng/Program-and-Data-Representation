// TreeCalcTest.cpp
// CS 2150: Tree calculator test program
// Your code MUST work with an UNMODIFIED version of this test program
// We will be using this program to test your implementations

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 21, 2021  
   CS2150 Lab 5 Pre Lab TreeCalcTest.cpp  
*/

// NOTE: This file was downloaded from the PDR/lab instructions for Lab 5 (didn't modify this file for the Pre Lab)

#include <iostream>
#include "TreeCalc.h"

using namespace std;

int main() {
    TreeCalc tester;
    // read expression input from the user
    tester.readInput();
    // print out the output in postorder, in order, preorder forms
    tester.printOutput();
    // calculate the result of the expression tree
    cout << "The result of the expression tree is " << tester.calculate() << endl;
    return 0;
}
