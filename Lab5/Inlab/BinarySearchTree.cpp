/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 22, 2021 
   CS2150 Lab 5 In Lab BinarySearchTree.cpp 
*/

// These are all of the necessary header files that we need to include in this cpp file
#include "BinaryNode.h"
#include "BinarySearchTree.h"  
#include <iostream> // Necessary for cin/cout 
#include <string> // You need this for the string data type. You also need "using namespace std" to make the short name string visible 

using namespace std; // Defines the scope of the class 

// constructor 
BinarySearchTree::BinarySearchTree() {
   root = NULL;
}
// destructor 
BinarySearchTree::~BinarySearchTree() {
   delete root;
   root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if (root == NULL) {
    BinaryNode* newtreenode = new BinaryNode();
    root = newtreenode;
    root -> value = x; 
    // newtreenode -> value = x; // Pointer to the value and sets it equal to x. 
    // root = newtreenode; 
  }
  else {
    insert2(root, x);
  }
}

// Helper method for insert()  
// BinaryNode* BinarySearchTree::insert2(BinaryNode*& n, const string& x) {
void BinarySearchTree::insert2(BinaryNode*& n, const string& x) {
  // The insert method code here is very similar to the one used in the slides for Lab 5 (Trees) in the Binary Search Tree section (5.11)  
  if (n == NULL) {
    n = new BinaryNode(); // You have to dynamically allocate it and instantiate it as an empty node 
    n -> value = x;
  }   
  else if (x < n -> value) { // The arrow means to follow the pointer. n is the pointer and n* is the object (n -> value is the same as (*n).method())  
    insert2(n -> left, x); 
  }
  else if (x > n -> value) {
    insert2(n -> right, x); 
  }
 
  /*
  else {
    cout << "Duplicate! Do nothing!" << endl;
  } 
  */  
}

// NOTE: The remove method was already provided to us in the source code/PDR for the BinarySearchTree.cpp file for the In Lab (didn't modify them in any way) 

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
  root = remove(root, x);
   // count up how many nodes you are: 
}

// NOTE: This helper method for remove was given to us in the PDR/source code in the BinarySearchTree.cpp file: 

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.

// From the PDR: pathTo() must return a string representing the nodes encountered when finding an element 
string BinarySearchTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if (find(x) == false) { // As long as when you call find, it's false (meaning you didn't find x) then you just have to return an empty string for the path. Otherwise, you have to call the recursive method for pathTo below 
    return ""; // As the PDR states, calling pathTo() on an element that doesn't exist would result in an empty string "" 
  }
  return pathTo2(root, x); 
}

// Helper method for pathTo() 
string BinarySearchTree::pathTo2(BinaryNode* n, const string& x) const {
  // do it iteratively: you can keep track of a string that stores all of your previous results and explore one child node at a time:
  // We compare the values of the Binary Nodes to the string and if it's equal to 0, we return that string, if it's less than, then we recursively call this method: traversing to the left BinaryNode if the value is less than 0, and traversing to the right BinaryNode if the value is greater than 0. In testfile1.txt, the "We" and the "we" are different and the second "we" shouldn't be added. 
  if (x == n -> value) { // Strings have overloaded <, >, and == operators, so you can simply compare with those, no need for any conversions. 
    return x;
  }
  else if (x < n -> value) {
    return " " + n -> value + " " + pathTo2(n -> left, x);
  }
  else { // else if (x > n -> value) 
    return " " + n -> value + " " + pathTo2(n -> right, x); 
  }
}

// Find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find2(root, x); 
}

// Helper method for find() method  
bool BinarySearchTree::find2(BinaryNode* n, const string& x) const {
  // Similar to the insert method, the find method code here is very similar to the one used in the slides for Lab 5 (Trees) in the Binary Search Tree section (5.10) 
  if (n == NULL) { // If you hit a NULL pointer, then you have "run off" the bottom of the tree, and the value is NOT in the tree 
    return false;
  }
  // If not equal, recurse depending on which half of the tree the value should be in if it is in the tree 
  else if (x < n -> value) {
    return find2(n -> left, x);
  }
  else if (x > n -> value) { // The arrow just means that n points to the value 
    return find2(n -> right, x);
  }
  else { // If x = n -> value, that means you found the value for the node 
    return true;
  }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return numNodes2(root); // Similar to all of the helper methods used in the BinarySearchTree.cpp file, we call the helper method for numNodes recursively. (The helper method takes in Binary Nodes as parameters which allows them to recurse over a subtree)   
}

// Helper method for numNodes() 
int BinarySearchTree::numNodes2(BinaryNode* n) const {
  int totalnumberofnodes = 0;
  if (n != NULL) {
    totalnumberofnodes += 1;
    if (n -> left != NULL) {
      totalnumberofnodes += numNodes2(n -> left);
    }
    if (n -> right != NULL) {
      totalnumberofnodes += numNodes2(n -> right);
    }
  }
  return totalnumberofnodes; 
}

// NOTE: All of these methods below were already provided to us in the source code/PDR for the BinarySearchTree.cpp file for the In Lab (didn't modify these methods in any way for the In Lab) 

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node -> left == NULL) {
    return node -> value;
  }
  return min(node -> left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}


