// Add your header information here
// TreeCalc.h: Tree Calculator class definition
// CS 2150: Lab 5
// You must submit ALL code to make your project build correctly

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 21, 2021  
   CS2150 Lab 5 Pre Lab TreeCalc.h  
*/

// NOTE: This file was downloaded from the PDR/lab instructions for Lab 5 (didn't modify this file for the Pre Lab) 

#ifndef TREECALC_H
#define TREECALC_H

#include <stack> 

#include "TreeNode.h"
using namespace std;

class TreeCalc {
public:
    TreeCalc();                     // Constructor
    ~TreeCalc();                    // Destructor

    void cleanTree(TreeNode* tree); // Deletes tree/frees memory
    void readInput();               // Gets data from user
    void insert(const string& val); // Puts value in tree

    // print methods
    void printPrefix(TreeNode* tree) const;  // Prints data in prefix form
    void printInfix(TreeNode* tree) const;   // Prints data in infix form
    void printPostfix(TreeNode* tree) const; // Prints data in postfix form
    void printOutput() const;                // Prints in post, in, pre form
    int calculate();                         // Calls private calculate method

private:
    stack<TreeNode*> expressionStack;   // Stack to hold the expression

    int calculate(TreeNode* tree) const; // Evaluates tree, returns value

};

#endif
