/*Name: Steven Song 
  UVA ID: sqs5hrn 
  Date: April 26, 2021   
  CS2150 Lab 10 Pre Lab huffmanenc.cpp
*/

// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.
#include "heap.h" // We have to include heap.h in order to access of all of its functions and members such as the find, insert, make the heap tree, read the prefix method, etc.  
#include "HuffNode.h"

// included so we can use cout
#include <iostream> // Used for cin/cout
// file I/O
#include <fstream> // Used for file/IO and reading in files
// cstdlib is where exit() lives
#include <cstdlib> // Used for exit()

using namespace std; // Used to define the scope of the file

// For the pre-lab, you will implement, in huffmanenc.cpp, the Huffman encoding algorithm using a binary heap that you implement in heap.cpp/h.

// This encode method builds a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character from a Binary heap 
HuffNode* encode(heap binaryheap) {  
  if (binaryheap.size() == 0) {
    return NULL;
  }
  
  if (binaryheap.size() == 1) {
    return binaryheap._heap[1];
  }
  
  HuffNode* root;
  while (binaryheap.size() > 1) {
    HuffNode* left = binaryheap.deleteMin();
    HuffNode* right = binaryheap.deleteMin();
    root = new HuffNode();
    root -> freq = left -> freq + right -> freq;
    root -> left = left;
    root -> right = right;
    binaryheap.insert(root);
  }
  return root;
}

// This method prints out the ASCII characters that are encoded, followed by their bit encoding. (Section 1 of the output format) 
void printPrefix(HuffNode* node, string path) {
  if (node->left == NULL && node->right == NULL) {
    cout << node->value << " " << path << endl;
  }
  else {
    printPrefix(node->left, path + "0");
    printPrefix(node->right, path + "1");
  }
}

// For each character c, prints out the character code. (Section 2 of the output format) 
void printPrefix(HuffNode* node, char c, string path) {
  if (node->left == NULL && node->right == NULL) {
    if (node->value == c) {
      cout << path << " ";
    }
    else {
      cout << "";
    }
  }
  else {
    printPrefix(node->left, c, path + "0");
    printPrefix(node->right, c, path + "1");
  }
}

int HuffmanBits[256]; // This method builds a map of ASCII characters with the number of bits for each character (Part of Section 3 of the output format)  
void getBitsMap(HuffNode* node, string path) {
  if (node->left == NULL && node->right == NULL) {
    HuffmanBits[node->value] = path.length();
  }
  else {
    getBitsMap(node->left, path + "0");
    getBitsMap(node->right, path + "1");
  }
}

// NOTE: The beginning of the main method is similar to the fileio.cpp file that was provided to us in the repo for the Lab 10 Pre Lab

// we want to use parameters
int main(int argc, char** argv) {
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  // ifstream stands for "input file stream"
  ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit
  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  // read in characters one by one, until reading fails (we hit the end of the file)
  // 1) Read the source file and determine the frequencies of the characters in the file
  int freq[256];
  for (int i = 0; i < 256; i++) {
    freq[i] = 0;
  }
    
  char g;
  int totalsymbols = 0; // total number of symbols that are encoded 
  while (file.get(g)) { // From the main method in the fileio.cpp 
    // cout << g << endl;
    if ((g < ' ') || (g > '~')) {
      continue;
    }
    freq[g]++;
    totalsymbols++;
  }
  
  // 2) Store the character frequencies in a heap (priority queue)
  heap binaryheap; // creates a heap variable  
  int distinctsymbols = 0; // total number of distinct/unique symbols that are encoded
  for (unsigned int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      distinctsymbols++;
      HuffNode* node = new HuffNode();
      node->freq = freq[i];
      node->value = i;
      binaryheap.insert(node);
    }
  }

  // once we hit the end of the file we are marked as "failed", so clear that
  // then "seek" to the beginning of the file to start again
  file.clear(); // Clears the _state_ of the file, not its contents!
  file.seekg(0); // From the main method in the fileio.cpp

  // binaryheap.print();

  // 3) Build a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character
  HuffNode* root = encode(binaryheap);

  // 4) Re-read the source file and for each character read, write its prefix code to the output
  string path = "";
  printPrefix(root, path); // This is Section 1 of the output: the ASCII characters that are encoded, followed by their bit encoding. Only one such encoding per line, with no blank lines allowed. The format for a line is the ASCII character, a single space, and then the 1 and 0 characters that are the encoding for that character, followed by a newline.   

  // a nice pretty separator
  cout << "----------------------------------------" << endl;

  int numofbits = 0; // the number of bits in the compressed file  
  for (int i = 0; i < 256; i++) {
    HuffmanBits[i] = 0;
  }
  
  getBitsMap(root, path); // Helper for section 3 of the output (Mapped ASCII characters for the number of bits)  

  // Read the file again, and print to the screen
  while (file.get(g)) {
    if ((g < ' ') || (g > '~')) {
      continue;
    }
    printPrefix(root, g, path); // Section 2 of the output: The encoded message, using the characters 0 and 1.  
    numofbits += HuffmanBits[g];   
  }

  // Section 3: The last section of the file displays several stats about the compression. You should output the total number of symbols encoded, how many unique symbols are used, the number of bits in the original and compressed files, the compression ratio to five decimal places, and the cost of the huffman tree to five decimal places.
  
  double compressionratio = (double)totalsymbols*8/(double)numofbits; // From the Huffman coding slides in Lab 10 (In Normal ASCII, the encoding is 8 bits per character)
  double costofthetree = (double)numofbits/(double)totalsymbols; // The cost of a file encoded via a Huffman tree containing n symbols is equal to C(T) = p1 * r1 + p2 * r2 + p3 * r3 + ... + pn * rn where p is the frequency that the symbol occurs and r is the length of the path from the root to the node (from the Huffman coding slides) 

  cout << endl;
  cout << "----------------------------------------" << endl;

  cout << "There are a total of " << totalsymbols << " symbols that are encoded." << endl; // Outputs the total number of symbols encoded
  cout << "There are " << distinctsymbols << " distinct symbols used." << endl; // Outputs how many distinct/unique symbols are used

  // cout << "The size of the heap is " << binaryheap.size() << endl;
  cout << "There were " << totalsymbols*8 << " bits in the original file." << endl; // Outputs the number of bits in the original file 
  cout << "There were " << numofbits << " bits in the compressed file." << endl; // Outputs the number of bits in the compressed file 
  cout << "This gives a compression ratio of " << compressionratio << "." << endl; // Outputs the compressionratio to 5 decimal places 
  cout << "The cost of the Huffman tree is " <<  costofthetree << " bits per character." << endl; // Outputs the cost of the Huffman tree to 5 decimal places 

  // close the file
  file.close();
  return 0; // We need to return 0 at the end of our file for insurance
}
