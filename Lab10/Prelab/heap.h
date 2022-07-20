// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

/*Name: Steven Song
  UVA ID: sqs5hrn
  Date: April 26, 2021   
  CS2150 Lab 10 Pre Lab heap.h
*/

// NOTE: The heap.h file was downloaded from the PDR/source code for the Lab 10 Pre Lab (didn't modify this file) (all I did was change it from a binary heap to a heap and changed the vector of ints to a vector of HuffNode pointers)  

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HuffNode.h"

using namespace std;

class heap {
public:
  heap();
  // heap(vector<HuffNode*> vec); Don't need this 
  ~heap();

  void insert(HuffNode* x);
  HuffNode* findMin();
  HuffNode* deleteMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  void print();

  vector<HuffNode*> _heap;
  unsigned int heap_size;

  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
