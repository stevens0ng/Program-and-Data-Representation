/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 3, 2021  
   CS2150 Lab 3 Post Lab Stack.h 
*/

#ifndef STACK_H
#define STACK_H

#include <iostream> // Necessary for cin/cout 
#include <string> // Necessary for string conversions 
#include "List.h" // Includes the header file for the Stack class 

using namespace std; // Defines the scope of the class 

class Stack {
public:
  Stack(); // Constructor for our Stack
  ~Stack(); // Deconstructor for our Stack 
  
  void push(int e); // Inserts at the front of the stack 
  void pop(); // Removes the element at the front of the stack
  int top(); // Examines the element at the front of the stack
  bool empty(); // Checks for empty 

private:
  List* stackoperations; // Dynamically allocates the list 
  // call the list class, but not the stack class from itself 
 
}; 
#endif
