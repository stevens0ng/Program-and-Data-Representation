/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 22, 2021  
   CS2150 Lab 5 In Lab BinaryNode.cpp  
*/

// NOTE: This file was downloaded from the source code in the PDR/lab instructions for the Lab 5 In Lab (didn't modify this file)

#include "BinaryNode.h"
#include <string>

using namespace std;  

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
