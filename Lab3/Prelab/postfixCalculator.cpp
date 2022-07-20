/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 28, 2021  
   CS2150 Lab 3 Pre Lab postfixCalculator.cpp
*/

// Stack: LIFO (Last In, First Out)  

// Implementation of the postfix calculator 
#include <iostream> // Necessary for cin/cout  
#include <stack> // Must include stack in order to access all of its functions (i.e. push, pop, top) 
#include "postfixCalculator.h" // Takes everything in postfixCAlculator.h and copies it in your file 
using namespace std; // Defines the scope of the class 

postfixCalculator::postfixCalculator() { // Notice how the STL stack is dynamically allocated 
  stackcalculator = *(new stack<int>()); // Since you're calling a constructor method, you need to dynamically allocate your postfix stack calculator 
} // You need it to be a pointer or you need to dereference it (dereference a pointer) 

void postfixCalculator::add () {
  // push will put an element on a stack, pop will remove an element, peek lets you look at the top element 
  // You want to use peek if you want to look at the element (str class) 
  // Postfix notation (when you have ex. 2 and 3 and the operator is after that)
  // You already encounter those numbers: you're putting them onto the stack
  
  int firstelement = stackcalculator.top(); // look at what's already there
  stackcalculator.pop(); // this would remove the first element you looked at

  int secondelement = stackcalculator.top();
  stackcalculator.pop();

  stackcalculator.push(firstelement + secondelement); // Adds/puts the sum back onto thestack (put the sum of 1 and 2 back onto the stack
}

void postfixCalculator::subtract() {
  int firstelement = stackcalculator.top(); // Look at what's already there
  stackcalculator.pop(); // Remove the first element you looked at from the stack 

  int secondelement = stackcalculator.top();
  stackcalculator.pop();

  stackcalculator.push(secondelement - firstelement); // If you peek into 1 and 2, you would do left and right of the original numbers in the string (so it would reverse the order so you would do 2 first before you do 1)  
}

// In Lab methods 
void postfixCalculator::multiply() {
  int firstelement = stackcalculator.top(); // Looks at the element at the top of the stack 
  stackcalculator.pop(); // Removes the first element you looked at from the stack 

  int secondelement = stackcalculator.top();
  stackcalculator.pop();

  stackcalculator.push(firstelement*secondelement); // Pretty straightfoward here  
}

void postfixCalculator::divide() {
  int firstelement = stackcalculator.top(); // Looks at the element at the top of the stack
  stackcalculator.pop(); // Removes the first element you looked at from the stack 

  int secondelement = stackcalculator.top();
  stackcalculator.pop();
  
  stackcalculator.push(secondelement/firstelement); // This line is the only difference between the multiply() and divide() methods (the lines before it are the same for both methods) 
}

void postfixCalculator::negation() { // Multiplies by whatever's at the top of the stack by -1
  int firstelement = stackcalculator.top(); // Returns the element at the top of the stack 
  stackcalculator.pop(); // Removes the element at the top of the stack

  // We use the tilde as the unary negation operator - this negates the top element of the stack, and (unlike the other four operators) does NOT use a second number from the stack.

  // Negative numbers still use a regular minus sign (i.e. '-3') and just pushes the negative number on the stack 
  
  stackcalculator.push(firstelement * -1); // If you want to do negation (which involves popping the top value, negating it, and pushing that new value back onto the stack), then you would use the tilde 
}

/* void postfixCalculator::negativenumbers() { // You just need to be able to handle negative numbers in your input (you don't actually need to write a method for negative numbers) 

} */

void postfixCalculator::pushnumber(int num) { // Pushes a number onto the stack
  stackcalculator.push(num); // Adds the passed element to the top of the stack 
} // Just call the push method 

int postfixCalculator::gettopvalue() { // Returns the element at the top of the stack 
  return stackcalculator.top(); // Examines the top of the stack 
}



