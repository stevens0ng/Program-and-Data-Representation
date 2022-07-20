/* Name: Steven Song  
   UVA ID: sqs5hrn 
   Date: March 24, 2021  
   CS2150 Lab 5 Post Lab AVLNode.h 
*/

// NOTE: The AVLNode.h file was downloaded from the PDR/source code for the Lab 5 Post Lab (didn't modify this file)

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif
