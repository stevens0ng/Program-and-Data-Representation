/* Name: Steven Song 
   UVA ID: sqs5hrn  
   Date: March 3, 2021  
   CS2150 Lab 3 Post Lab postfixCalculator.cpp
*/

#include <iostream> // Necessary for cin/cout 
// #include <stack> 
#include <string> // Necessary for string variables and conversions, etc 
#include "postfixCalculator.h" // Takes everything in postfixCalculator.h and copies it in your file
#include "Stack.h" // Takes everything in Stack.h and copies it in your file

using namespace std; // Defines the scope of the class 

postfixCalculator::postfixCalculator() {
  stackcalculator = new Stack(); // Since you're calling a constructor method (dynamically allocatted)
   
} // you need it to be a pointer or you need to dereference it a pointer
// dynamic allocation: using the word "new" (on the right side) 
// static allocation: not using a key word (above is using a static allocation to store an object)

// add, subtract, multiply, and divide methods are the same as they were in the Pre Lab 

void postfixCalculator::add() {
  // push will put an element on a stack, pop will remove an element, peek lets you look at the top element 
  // you want to use peek if you want to look at the element (str class) 
  // postfix notation (when you have ex. 2 and 3 and the operator is after that)
  // you already encounter those numbers:
  // you're putting them onto the stack 

  int firstelement = stackcalculator -> top(); // look at what's already there
  stackcalculator -> pop(); // this would remove the first element you looked at
  int secondelement = stackcalculator -> top();
  stackcalculator -> pop();

  stackcalculator -> push(firstelement + secondelement); // puts the sum back onto thestack (put the sum of 1 and 2 back onto the stack
  // you can leave it as it is since it's all laid on the stack 
  // add the sum back onto the stack   
}

void postfixCalculator::subtract() {
  int firstelement = stackcalculator -> top(); // look at what's already there
  stackcalculator -> pop(); // this would remove the first element you looked at
  int secondelement = stackcalculator -> top();
  stackcalculator -> pop();

  stackcalculator -> push(secondelement - firstelement); // if you peek into 1 and 2, you would do left and right of the original numbers in the string (so it would reverse the order so you would do 2 first before you do 1)  
}

void postfixCalculator::multiply() {
  int firstelement = stackcalculator -> top(); // look at what's already there
  stackcalculator -> pop(); // this would remove the first element you looked at
  int secondelement = stackcalculator -> top();
  stackcalculator -> pop();

  stackcalculator-> push(firstelement*secondelement); 
}

void postfixCalculator::divide() {
  int firstelement = stackcalculator -> top(); // look at what's already there
  stackcalculator -> pop(); // this would remove the first element you looked at
  int secondelement = stackcalculator -> top();
  stackcalculator -> pop();
  
  stackcalculator -> push(secondelement/firstelement); 
}

// push method 
void postfixCalculator::pushnumber(int num) { // pushes a number onto the stack
  stackcalculator -> push(num); // You have to use -> instead of . 
}

// gets the top value in the stack 
int postfixCalculator::gettopvalue() {
  return stackcalculator -> top(); // You have to use -> instead of .
}

void postfixCalculator::negation() { // Multiplies by whatever's at the top of the stack by - 1 
  int firstelement = stackcalculator -> top();
  stackcalculator -> pop();

  stackcalculator -> push(firstelement * -1);
}



