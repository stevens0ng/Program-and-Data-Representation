/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 3, 2021   
   CS2150 Lab 3 Post Lab Stack.cpp 
*/

#include <iostream> // Used for cin/cout (printing out stuff) 
#include <string> // Necessary for string variables and conversions, etc 
#include "Stack.h" // Must include Stack header file 
// Takes everything in Stack.h and copies it in your file 
using namespace std; // Defines the scope of the class  

Stack::Stack () { // List class stays the same, but you need to make sure that whatever stack operations you're doing translates to list operations
  stackoperations = new List();  
}
Stack:: ~Stack() {
  delete(stackoperations); 
}

// Push, pop, and top are built in Stack functions from the STL stack class so we have to implement the push, pop, and top methods from our own Stack class and then call these methods in our postfixCalculator.cpp class like the PDR states for the Post Lab 

void Stack::push(int e) {
  stackoperations -> insertAtTail(e); // It's a pointer and not statically allocated 
} 

int Stack::top() { // Returns the value of the top of the stack
// last method to get the iterator 
  return stackoperations -> last().retrieve(); // last returns a ListItr type 
} // tail is the front of the stack, not head 

void Stack::pop() { // pop: remove removes the first instance on a list 
  stackoperations -> remove(stackoperations -> tail -> previous -> value); // you have to change the remove method in the List.cpp  // call remove on the top element of stack (since tail does not exist in the stack cpp except for in the 
} // You don't have to change the remove method, but you do have to change the find method since the remove method is calling find since you're removing from the tail now instead of the head (you're popping and pushing from the reverse order was it was before in Lab 2) 

bool Stack::empty() {
  if (stackoperations -> size() == 0) { // If the linked list's size is equal to 0, then it's empty which means it's true; otherwise, it's false 
    return true;
  }
  else {
    return false;
  }
  /*   
  return stackoperations -> isEmpty(); 
  */
  // don't need this part apparently 
}
