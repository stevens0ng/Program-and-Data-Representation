/*Name: Steven Song
  UVA ID: sqs5hrn
  Date: April 26, 2021    
  CS2150 Lab 10 Pre Lab HuffNode.cpp 
*/

// NOTE: This file is similar in format to the BinaryNode.cpp file from the source code in the PDR/lab instructions from the Lab 5 In Lab (all I did was add the frequency variable)

#include "HuffNode.h"

using namespace std; 

HuffNode::HuffNode() {
  // value = '?';
    freq = 0;
    left = NULL;
    right = NULL;
}

HuffNode::~HuffNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
