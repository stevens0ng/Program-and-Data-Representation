/* Name: Steven Song  
   UVA ID: sqs5hrn 
   Date: March 24, 2021   
   CS2150 Lab 5 Post Lab AVLTree.cpp  
*/

#include "AVLNode.h" // These are all of the header files that we must include 
#include "AVLTree.h" // We must include the header file for "AVLTree.h" since it contains the necessary functions/members/methods for the AVLTree.cpp file to function properly 
#include <iostream> // Necessary for cin/cout
#include <string> // Necessary for string variables/conversions

using namespace std; // Defines the scope of the class

// The structure of the provided AVL starter code is analogous to that of the BST

// Keep tree balanced after each operation

// For every node in the tree, the height of the left and right subtrees differs at most by 1 

// Constructor (provided to us in the source code)  
AVLTree::AVLTree() {
    root = NULL;
}

// Destructor (provided to us in the source code)  
AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  insert2(root, x); // Calls the insert2 method recursively (similar to the In Lab)
}

// Helper method for insert()

// According to the Tree slides (for the AVL Trees section 7.10), the insert method for AVL Trees is the same as the insert method for BST except might need to "fix" the AVL Tree after the insert (via rotations)

// Let x be the deepest node where imbalance occurs

/* Four cases where the insert happened:
   1. In the left subtree of the left child of x (Perform a single rotation) 
   2. In the right subtree of the left child of x (Perform a double rotation) 
   3. In the left subtree of the right child of x (Perform a double rotation) 
   4. In the right subtree of the right child of x (Perform a single rotation)  
*/

// AVLNode* AVLTree::insert2(AVLNode*& n, const string& x) {
void AVLTree::insert2(AVLNode*& n, const string& x) {
    if (n == NULL) {
      n = new AVLNode();
      n -> value = x;
      // return n; 
    }
    
    else {
      if (x < n -> value) { // Less than means the left subtree is one longer than the right subtree 
	insert2(n -> left, x); // n -> left = insert2(n -> left, x); 
      }
      else if (x > n -> value) { // Greater than means the right subtree is one longer than the left subtree 
	insert2(n -> right, x); // n -> right = insert2(n -> right, x); 
      }
    }
    
    n -> height = max(height(n -> left), height(n -> right)) + 1;
    balance(n); // Call balance
    // return n; 
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    if (find(x) == false) {
        return "";
    }
    return pathTo2(root, x);
}

// Helper method for pathTo() (This method is almost the exact same as the recursive method for pathTo() in the In Lab for the BinarySearchTree.cpp file except the formatting with the " " is slightly different) 
string AVLTree::pathTo2(AVLNode* n, const string& x) const {
    if (x == n -> value) {
        return x;
    }
    else if (x < n -> value) {
        return n -> value + " " + pathTo2(n -> left, x);
    }
    else { // else if (x > n -> value) 
        return n -> value + " " + pathTo2(n -> right, x);
    }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return find2(root, x);
}

// Helper method for find() (Similar to pathTo(), this method is almost the exact same as the recursive method for find() in the In Lab)

// According to the Tree slides (for the AVL Trees section 7.10), the find method for AVL Trees is the same as the find method for BST in the In Lab for the BinarySearchTree.cpp file  
bool AVLTree::find2(AVLNode* n, const string& x) const {
    if (n == NULL) {
        return false;
    }
    else if (x < n -> value) {
        return find2(n -> left, x);
    }
    else if (x > n -> value) {
        return find2(n -> right, x);
    }
    else { // if (x = n -> value) 
        return true;
    }
}
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes2(root);
}

// Helper method for numNodes() (Similar to pathTo() and find(), this method is the exact same as the recursive method for numNodes() in the In Lab for the BinarySearchTree.cpp file) 
int AVLTree::numNodes2(AVLNode* n) const {
  int totalnumberofnodes = 0;
  if (n!= NULL) {
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

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.

// NOTE: The balance method is very similar to the pseudocode provided in the PDR for Lab 5 Post Lab 
void AVLTree::balance(AVLNode*& n) {
  if (height(n -> right) - height(n -> left) == 2) { // A balance factor of 2 or -2 means that the tree is unbalanced 
    AVLNode* rightchild = n -> right;
    if (height(rightchild -> right) - height(rightchild -> left) < 0) { // The height of the right subtree minus the height of the left subtree 
      n -> right = rotateRight(rightchild); // double rotation (In the right subtree of the right child of x, perform a single rotation)
      rotateLeft(n); 
    }
    else {
      rotateLeft(n); 
    }
  }
    
  else if (height(n -> right) - height(n -> left) == -2) {
    AVLNode* leftchild = n -> left;
    if (height(leftchild -> right) - height(leftchild -> left) > 0) {
      n -> left = rotateLeft(leftchild); // Without setting n -> left, n left doesn't change
      rotateRight(n);
    }
    else {
      rotateRight(n);
    }
  }

  // Balance method pseudocode: (balance(AVLNode*& node) is crucial for both insert and remove 

  /* 
  // Note that balance factor here is assumed to be (height of right subtree - height of left subtree) 
  balance(node): 
    if balance factor of node is 2 we will need to rotate left:
      first, see if we should also rotate right (i.e., double rotation) 
      if balance factor of left is positive: 
        rotate left on the left child 
      endif 
      rotate right on node 
    endif
  */
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode* rightchild = n -> right;
  n -> right = rightchild -> left;
  rightchild -> left = n;

  n -> height = max(height(n -> left), height(n -> right)) + 1; // This line is exactly the same as it was in the insert method  
  rightchild -> height = max(height(rightchild -> left), height(rightchild -> right)) + 1;
  n = rightchild; // this is must
  return rightchild;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) { // rotateRight is almost the same as rotateLeft except everything is flipped 
  AVLNode* leftchild = n -> left;
  n -> left = leftchild -> right;
  leftchild -> right = n;
  
  n -> height = max(height(n -> left), height(n -> right)) + 1; // This line is exactly the same as it was in the insert method 
  leftchild -> height = max(height(leftchild -> left), height(leftchild -> right)) + 1;
  n = leftchild; // this is must
  return leftchild;
}

// NOTE: Every method below this line: starting from remove(), all the way to printTree() was provided to us in the source code for the AVLTree.cpp for the Post Lab (didn't modify any of the methods in any way)

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node -> left == NULL) {
        return node -> value;
    }
    return min(node -> left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}  

