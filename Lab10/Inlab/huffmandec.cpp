/*Name: Steven Song 
  UVA ID: sqs5hrn 
  Date: April 27, 2021 
  CS2150 Lab 10 In Lab huffmandec.cpp 
*/

// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
  
#include <iostream> // Used for input/output such as cin/cout (necessary to print stuff out)
#include <fstream> // Used for opening a file to both read and write from/to files
#include <sstream> // Used for the string stream (necessary for reading in strings and writing data into these strings)
#include <stdlib.h> // Header for standard library for the C++ language, which includes functions like memory allocation and conversion among others
#include <cstdlib> // Header used for dynamic memory management, integer arithmetics, searching, sorting, and converting 

// We have to include our HuffmanNode file in order to have access to the huffmanNode variables anytime we want to create a new huffmanNode in any of our methods 
#include "HuffmanNode.h"

using namespace std; // Like always, we need the namespace std to define the scope (the context of the file in which all of the names are declared) 

/* 
The basic steps for decomposition are: 
1) Read in the prefix code structure from the encoded file 
2) Re-create the Huffman tree from the code structure read in from the file
3) Read in one bit at a time from the encoded file and move through the prefix code tree until a leaf node is reached
4) Output the character stored at the leaf node 
5) Repeat the last 2 steps until the encoded file has been entirely encoded 
*/

// recreate the huffman tree from the character and the prefix code (very similar to the code in Lecture 33)  
void create_path(HuffmanNode* node, string c, string prefix) {
  // how recursion stops  
  if (prefix == "") {
    node->value = c;
    return;
  }
  // make the problem simpler (i.e., the actual recursion)   
  if (prefix[0] == '0') {
    // go to the left 
    if (node->left == NULL) { // ensure_there_is_a_left_child_of_node();
      node->left = new HuffmanNode();
    }
    create_path(node->left, c, prefix.substr(1));
  }
  else { // first character is a '1'
    // go to the right 
    if (node->right == NULL) { // ensure_there_is_a_right_child_of_node();
      node->right = new HuffmanNode();
    }
    create_path(node->right, c, prefix.substr(1));
  }
}

// The decode method and the create_path method are the two main methods that we have to implement in our huffmandec.cpp file 
void decode(HuffmanNode* node, string message) { // Traverses a Huffman Tree (if you find the leaf node, then you're at the character so you can just print the character value)  
  HuffmanNode* temp = node;
  for (int i = 0; i < message.length(); i++) {
    if (message[i] == '0') { // go to the left 
      temp = temp-> left;
    }
    else if (message[i] == '1') { // go to the right  
      temp = temp-> right;
    }
    if (temp->left == NULL && temp->right == NULL) {
      cout << temp-> value;
      temp = node; // until you reach the leaf node 
    }
  }
  cout << endl;
}

// NOTE: Most of the main method was already provided to us in the source code in the PDR for Lab 10 In Lab (in the inlab-skeleton.cpp file) and also in the live lectures, specifically Lectures 32-33 

// main(): we want to use parameters
int main (int argc, char** argv) {
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  // must be opened in binary mode as otherwise trailing whitespace is discarded

  // 1. Read in the prefix code structure from the encoded file 
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  // read in the first section of the file: the prefix codes
  HuffmanNode* root = new HuffmanNode();
  while (true) {
    string character, prefix;
    // read in the first token on the line
    file >> character;

    // did we hit the separator?
    if (character[0] == '-' && character.length() > 1) {
      break;
    }

    // check for space
    if (character == "space") {
      character = " ";
    }

    // read in the prefix code
    file >> prefix;
    // do something with the prefix code
    
    // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl; ONLY used for debugging 
    
    // 2. Re-create the Huffman tree from the code structure read in from the file
    create_path(root, character, prefix);
  }  
  string path = "";

  // Read in one bit at a time from the encoded file and move through the prefix code tree until a leaf node is reached
  // Output the character stored at the leaf node
  // Repeat the last two steps until the encoded file has been entirely decoded
  // Lastly, read in the second part of the file and traverse your Huffman tree and output a character whenever you reach a leaf node
    
  // read in the second section of the file: the encoded message
  stringstream sstm;
  while (true) {
    string bits;
    // read in the next set of 1's and 0's
    file >> bits;
    // check for the separator
    if (bits[0] == '-') {
      break;
    }
    // add it to the stringstream
    sstm << bits;
  }
  string allbits = sstm.str();

  // at this point, all the bits are in the 'allbits' string
  
  // cout << "All the bits: " << allbits << endl; ONLY used for debugging 

  // close the file before exiting
  file.close();
  decode(root, allbits); // For this lab, you must only print out the decoded message and nothing else 
  return 0; // As always, we must return 0 at the end of each main method for insurance 
}
