// TreeNode.h: TreeNode class definition

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 21, 2021  
   CS2150 Lab 5 Pre Lab TreeNode.h  
*/

// NOTE: This file was downloaded from the PDR/lab instructions for Lab 5 (didn't modify this file for the Pre Lab) 

#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std; 

class TreeNode {
public:
    TreeNode();                  // Default Constructor
    TreeNode(const string& val); // Constructor

private:
    string value;
    TreeNode* left;
    TreeNode* right;
    friend class TreeCalc;       // gives TreeCalc access to private data
};

#endif
