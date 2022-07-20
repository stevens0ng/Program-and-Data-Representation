// Insert your header information here
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 21, 2021  
   CS2150 Lab 5 Pre Lab TreeNode.cpp  
*/

// NOTE: This file was downloaded from the PDR/lab instructions for Lab 5 (didn't modify this file for the Pre Lab)

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}

