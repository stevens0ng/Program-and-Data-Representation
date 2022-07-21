/*Name: Steven Song
  UVA ID: sqs5hrn
  Date: April 26, 2021    
  CS2150 Lab 10 Pre Lab HuffNode.h
*/

// NOTE: This file is similar in format to the BinaryNode.h file from the source code in the PDR/lab instructions from the Lab 5 In Lab (all I did was add the frequency variable)

#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>

using namespace std;

class HuffNode {
  public:
  HuffNode();
  ~HuffNode();

  int freq; // Newly added for Lab 10 Pre Lab 
  char value; 
  HuffNode* left;
  HuffNode* right;
};

#endif
