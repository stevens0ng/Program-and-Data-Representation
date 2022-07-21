/*Name: Steven Song 
  UVA ID: sqs5hrn 
  Date: April 27, 2021 
  CS2150 Lab 10 In Lab HuffmanNode.h   
*/

// NOTE: We don't need to include the frequency variable in HuffmanNode class for the In Lab the way we did in HuffNode class in the Pre Lab

// NOTE: The HuffmanNode.h and HuffmanNode.cpp files are almost the same as the HuffNode.h and HuffNode.cpp files in the Pre Lab except for the HuffmanNode class does not use the frequency variable and it just stores data for left and right HuffmanNode pointers 

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>

using namespace std; // Like always, we need the namespace std to define the scope (the context of the file in which all of the names are declared) 

class HuffmanNode {
  public:
  HuffmanNode();
  ~HuffmanNode();

  string value; // Changed from char type to a string type because the file IO is read in as a string and not as a char 
  HuffmanNode* left;
  HuffmanNode* right;
};

#endif
