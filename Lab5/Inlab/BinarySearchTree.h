/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 22, 2021  
   CS2150 Lab 5 In Lab BinarySearchTree.h  
*/

// A Binary Search Tree is a binary tree that imposes an ordering on its nodes. A node's left child has a lesser value, while its right child has a greater value. Binary Search Trees are useful for efficient insertion, deletion, and lookup of items with a certain key

// All nodes have at most 2 children.

#ifndef BST_H
#define BST_H

#include <string> // Necessary for string conversions 
#include "BinaryNode.h" // Must include the BinaryNode header file 

using namespace std; // Defines the scope of the class 

// You do not need to know how Trunk works. (This part was already provided to us in the PDR/lab instructions) 
struct Trunk {
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    // insert finds a position for x in the tree and places it there.
    void insert(const string& x);
    // remove finds x's position in the tree and removes it.
    void remove(const string& x);
    // printTree pretty-prints the tree to aid debugging.
    void printTree();

    // pathTo finds x in the tree and returns a string representing the path it
    // took to get there.
    string pathTo(const string& x) const;
    // find determines whether or not x exists in the tree.
    bool find(const string& x) const;
    // numNodes returns the total number of nodes in the tree.
    int numNodes() const;

private:
    // Declare a root node
    BinaryNode* root;
  
    // private helper for remove to allow recursion over different nodes. returns
    // A BinaryNode* that is assigned to the original node.
    BinaryNode* remove(BinaryNode*& n, const string& x);
    // min finds the string with the smallest value in a subtree.
    string min(BinaryNode* node) const;

    // private helper for printTree to allow recursion over different nodes.
    void printTree(BinaryNode* root, Trunk* prev, bool isRight);

    // Any other methods you need...

    // These are the helper methods that I used for my BinarySearchTree.cpp
    // The PDR recommends that you create private helper methods for BinarySearchTree. The private methods takes BinaryNodes as parameters which allow them to recurse over a subtree, a common implementation technique. 

    // BinaryNode* insert2(BinaryNode*& n, const string&x); 

    void insert2(BinaryNode*& n, const string& x); // helper method for insert() 

    bool find2(BinaryNode* n, const string& x) const; // helper method for find()

    string pathTo2(BinaryNode* n, const string& x) const; // helper method for pathTo()  

    int numNodes2(BinaryNode* n) const; // helper method for numNodes()  
};

#endif
