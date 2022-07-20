// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 21, 2021   
   CS2150 Lab 5 Pre Lab TreeCalc.cpp 
*/

// This is the only file besides the Makefile where we have to implement the given methods for the Pre Lab 

#include "TreeCalc.h" // Must include the header file for "TreeCalc.h" 
#include <iostream> // Necessary for cin/cout 
#include <stack> // Necessary for stack operations such as push/pop 
#include <cstdlib> // Necessary for the concatenations for stack operations like .top(), .pop(), and .push()  
#include <string> // Necessary for string conversions 

using namespace std; // Defines the scope of the class 

TreeNode *treenodeinastack; // A treeNode variable that we create in order to calculate the result of the expression in the expression tree 
stack<int> stackoperations; // The stackoperations variable is used so that we can use the built in functions for pop, top, push, etc. when performing the necessary stack operations/operators in the expression tree like add, subtract, multiply, and divide. The stack is used to help you read in a postfix expression into an expression tree.

// expressionStack is just a stack that holds all of the Tree Nodes

// Constructor
TreeCalc::TreeCalc() { // empty constructor (apparently we don't need to declare anything inside the constructor) 
  // treenodeinastack = new TreeNode(); 
  // expressionStack = new stack<TreeNode*>();
  // stackoperations = new stack<int>();
}

// Destructor - frees memory (allows you to deallocate whatever the left points to and whatever the right points to) 
TreeCalc::~TreeCalc() { // Destructor just calls cleanTree on the Tree Node  
  cleanTree(treenodeinastack); // Pretty easy, since we just use recursion to call the cleanTree method, which frees the memory from the tree for us
  // Since the cleanTree method is just a function to help your destructor do its job, you should call it from your destructor. For cleaning the tree, you need to put a Tree Node in the parameter to start. (You should delete all of the dynamically allocated memory (TreeNodes) in your stack by calling cleanTree() on them.  
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) { // Delete the tree and all subtrees
  if (tree != NULL) { // Recursive method to delete all of the Tree Nodes (if they exist) 
    cleanTree(tree -> left); // Calls cleanTree on the left subtree recursively 
    cleanTree(tree -> right); // Calls cleanTree on the right subtree recursively   
     
    delete(tree); // Calls delete on the node passed in 
  }
  // If it's null, then don't do anything 
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  // insert a value into the tree
  TreeNode *nodetobeinserted  = new TreeNode(val);
  
  /* Read well-formed postfix expressions into a stack, support the following input: 1) integers, both positive and negative, 2) addition, 3) subtraction, 4) multiplication, 5) integer division 
  Build an expression tree using the items in the stack    
  */
  
  if (val == "+" || val == "-" || val == "*" || val == "/") { // If the token read from the input is an operator, then pop off the two values and attach them as the children of the operator, and push them back onto the stack
    // The Tree slides Expression Trees section tells you which order to insert the Tree Nodes (6.6-6.15) (right goes first then left)   
    TreeNode *right = expressionStack.top(); // The order in which you declare the right and left TreeNodes does matter here
    // TreeNode* left = expressionStack.top(); 
    expressionStack.pop();

    TreeNode *left = expressionStack.top(); // The greater value in a tree is the one on the right
    // TreeNode* right = expressionStack.top(); 
    expressionStack.pop();
    
    nodetobeinserted -> right = right; // TreeNode* right 
    nodetobeinserted -> left = left; // TreeNode* left
    // nodetobeinserted -> left = left; 
    // nodetobeinserted -> right = right; 
  }
  expressionStack.push(nodetobeinserted); // If the token read from the input is a number or a variable, then just push it onto the stack 
}

// From the PDR: prints the resulting expression tree as a postfix, infix, and prefix expression, in the following format 

// Prints data in prefix form (Node first, then children) 
void TreeCalc::printPrefix(TreeNode* tree) const {
  // prints the tree in prefix format (A pre-order traversal processes the given node first and then processes its left and then right subtrees)   
  
  /*
  if(tree is not empty)
    print(tree token)
    prefix(tree left subtree)
    prefix(tree right subtree) 
  end if
  end prefix  
  */

  // Ex. + a * + b c d 
  string prefixlength = ""; 
  if (tree != NULL) {
    cout << tree -> value + " "; 
    if (tree -> left != NULL) {
      printPrefix(tree -> left); // From the PDR: you'll need to use recursion for many of the TreeCalc methods 
    }
    if (tree -> right != NULL) {
      printPrefix(tree -> right); 
    }
  }
  cout << prefixlength; // printing out the inverse of what you inputed 
}

// Prints data in infix form (Left node first, then right self, then right node) 
void TreeCalc::printInfix(TreeNode* tree) const {
  // print tree in infix format with appropriate parentheses (In an in-order traversal, first the node's left subtree is processed, followed by the node itself, and finally its right subtree) 

  /* if (tree not empty)
       if(tree token is operator)
         print(open paranthesis)
       endif
       infix (tree left subtree)
       print (tree token)
       infix (tree right subtree)
       if(tree token is operator)
         print(close parenthesis)
       endif
     endif
     end infix
  */

  /* Pseudocode: In-order traversal 
  if (curNode != NULL) {
    print(curNode -> left); 
    cout << curNode -> element << endl; 
    print(curNode -> right); 
  }
  */

  // Ex. Infix notation: (a + ((b+c) * d))

  // The reason why we don't declare a string variable for the infixnotation like we did for the prefix and the postfix notation is because unlike the prefix/postfix notation, there are parantheses around every infix notation, regardless of operator precedence 
  if (tree != NULL) { 
    if (tree -> left != NULL) {
      cout << "("; 
      printInfix(tree -> left);
      cout << " ";
    }
    cout << tree -> value << "";
    if (tree -> right != NULL) {
      cout << " "; 
      printInfix(tree -> right);
      // nodes that don't have children are going to be numbers
      // nodes that have children are going to be operators 
      cout << ")"; // Notice how the order of the quotations and the paranthesis are opposite of one another now for the left and right children node 
    }
  }
}

//Prints data in postfix form (Children first, then node) 
void TreeCalc::printPostfix(TreeNode* tree) const {
  // print the tree in postfix form (A post-order traversal operates on the left subtree, followed by the subtree, and finally on the node itself) 

  /*
  if(tree not empty) 
     postfix(tree left subtree)
     postfix(tree right subtree)
     print(tree token)
     endif
  end postfix
  */

  /* Pseudocode: Post-order traversal  
  if (treenode == NULL) 
    return 0;
  else  
    sum = 0;
    for each child c of tnode 
      sum += numNodes(c); 
    return 1 + sum; 
  */
  
  // Ex. Postfix notation a b c + d * + 
  string postfixlength = ""; 
  if (tree != NULL) { // accessing memory that's not there 
    if (tree -> left != NULL) {
      printPostfix(tree -> left);
    }
    if (tree -> right != NULL) {
      printPostfix(tree -> right);
    }
    postfixlength += tree -> value + " "; // you're printing out one giant string with spaces (you're concatenating a string between each value 
    cout << postfixlength;
  } // postfix prints everything out in the exact order as you inputted it 
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// From the PDR: Read well-formed postfix expressions into a stack, support the following input: 
// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
  // Traverse the tree and calculates the result
  if (tree -> left != NULL) { // calls it recursively   
    calculate(tree-> left); 
  }

  if (tree -> right != NULL) {
    calculate(tree-> right);
  }
  
  // These stack operators are exactly like they were in the Lab 3 Pre Lab/Post Lab when we did the postfixCalculator.h/cpp files 

  if (tree -> value == "+") {
    int top = stackoperations.top();
    stackoperations.pop();
    int bottom = stackoperations.top(); 
    stackoperations.pop();
    
    stackoperations.push(top + bottom); 
  }
  else if (tree -> value == "-") {
    int top = stackoperations.top();
    stackoperations.pop();
    int bottom = stackoperations.top();
    stackoperations.pop();

    stackoperations.push(bottom - top); 
  }

  else if (tree -> value == "*") {
    int top = stackoperations.top();
    stackoperations.pop();
    int bottom = stackoperations.top();
    stackoperations.pop();

    stackoperations.push(top * bottom); 
  }
  else if (tree -> value == "/") {
    int top = stackoperations.top();
    stackoperations.pop();
    int bottom = stackoperations.top();
    stackoperations.pop();

    stackoperations.push(bottom/top); 
  }
  else {
    // If it's a number or a variable and not an operator, then just push the number/variable onto the stack 
    int number = stoi(tree -> value); // Stoi converts it from a string to an int 
    stackoperations.push(number); // You have to point it to a value so that it is a string so that we can then convert that string to an integer 
  }
  return stackoperations.top(); // Returns the top value in the stack 
}

// Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user

// From the PDR: Calculates the result of your expression using the expression tree  
int TreeCalc::calculate() { // This is a helper method for the calculate method 
  int resultofexpressiontree = calculate(expressionStack.top()); // Gets/calculates the result of your expression tree using the expression tree. Your public calculate method will call your private calculate method. This private calculate method will do the actual work to evaluate the expression passed in.    
  treenodeinastack = expressionStack.top(); // Since the expressionstack contains treenode objects, we just set the first/top element in the stack to be the treenode variable that we created at the beginning of this file, and we set that to the result of the expression tree 
  expressionStack.pop(); // You use top to get the first/top element in the stack and you use top to examine the top of the stack 
  return resultofexpressiontree; // Returns the result of your expression using the expression tree   
}
