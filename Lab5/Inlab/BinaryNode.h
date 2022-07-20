/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 22, 2021 
   CS2150 Lab 5 In Lab BinaryNode.h  
*/

// NOTE: This file was downloaded from the source code in the PDR/lab instructions for the Lab 5 In Lab (didn't modify this file)

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
