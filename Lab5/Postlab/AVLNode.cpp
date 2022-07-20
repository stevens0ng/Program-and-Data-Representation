/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 24, 2021  
   CS2150 Lab 5 Post Lab AVLNode.cpp  
*/

// NOTE: The AVLNode.cpp file was downloaded from the PDR/source code for the Lab 5 Post Lab (didn't modify this file) 

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
