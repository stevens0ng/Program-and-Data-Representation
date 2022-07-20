// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

/*Name: Steven Song
  UVA ID: sqs5hrn
  Date: April 26, 2021   
  CS2150 Lab 10 Pre Lab heap.cpp
*/

// NOTE: The heap.cpp file was downloaded from the PDR/source code for the Lab 10 Pre Lab (didn't modify this file) (all I did was change it from a binary heap to a heap and changed the vector of ints to a vector of HuffNode pointers) 

#include <iostream>
#include "heap.h"
#include "HuffNode.h"

using namespace std;

// default constructor
heap::heap() : heap_size(0) {
  _heap.push_back(new HuffNode());
}

/* builds a heap from an unsorted vector
//heap::heap(vector<int> vec) : heap_size(vec.size()) { Don't need this 
//    heap = vec;
//    heap.push_back(heap[0]);
//    heap[0] = 0;
//    for (int i = heap_size/2; i > 0; i--) {
//        percolateDown(i);
//    }
//} */

// the destructor doesn't need to do much
heap::~heap() {
  
}

void heap::insert(HuffNode* x) {
  // a vector push_back will resize as necessary
  _heap.push_back(x);
  // move it up into the right position
  percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
  // get the value just inserted
  HuffNode* x = _heap[hole];
  // while we haven't run off the top and while the
  // value is less than the parent...
  for ( ; (hole > 1) && (x->freq < _heap[hole/2]->freq); hole /= 2) {
    _heap[hole] = _heap[hole/2]; // move the parent down
  }
  // correct position found!  insert at that spot
  _heap[hole] = x;
}

HuffNode* heap::deleteMin() {
  // make sure the heap is not empty
  if (heap_size == 0) {
    throw "deleteMin() called on empty heap";
  }

  // save the value to be returned
  HuffNode* ret = _heap[1];
  // move the last inserted position into the root
  _heap[1] = _heap[heap_size--];
  // make sure the vector knows that there is one less element
  _heap.pop_back();
  // percolate the root down to the proper position
  if (!isEmpty()) {
    percolateDown(1);
  }
  // return the old root node
  return ret;
}

void heap::percolateDown(int hole) {
  // get the value to percolate down
  HuffNode* x = _heap[hole];
  // while there is a left child...
  while (hole*2 <= heap_size) {
    int child = hole*2; // the left child
    // is there a right child?  if so, is it lesser?
    if ((child+1 <= heap_size) && (_heap[child+1]->freq < _heap[child]->freq)) {
      child++;
    }
    // if the child is greater than the node...
    if (x->freq > _heap[child]->freq) {
      _heap[hole] = _heap[child]; // move child up
      hole = child;             // move hole down
    } else {
      break;
    }
  }
  // correct position found!  insert at that spot
  _heap[hole] = x;
}

HuffNode* heap::findMin() {
  if (heap_size == 0) {
    throw "findMin() called on empty heap";
  }
  return _heap[1];
}

unsigned int heap::size() {
  return heap_size;
}

void heap::makeEmpty() {
  heap_size = 0;
  _heap.resize(1);
}

bool heap::isEmpty() {
  return heap_size == 0;
}

void heap::print() {
  cout << "(" << _heap[0]->freq << ") ";
  for (int i = 1; i <= heap_size; i++) {
    cout << _heap[i]->value << " " << _heap[i]->freq << " ";
    // next line from http://tinyurl.com/mf9tbgm
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if (isPow2) {
      cout << endl << "\t";
    }
  }
  cout << endl;
}
