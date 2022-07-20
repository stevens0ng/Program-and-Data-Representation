/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: February 28, 2021   
   CS2150 Lab 3 Pre Lab postfixCalculator.h
*/

// Class declaration of the postfix calculator 
#ifndef POSTFIXCALCULATOR_H // As always we must have the preprocessors #ifndef, #define, and #endif in our .h file
#define POSTFIXCALCULATOR_H

#include <iostream> // Necessary for cin/cout
#include <stack> // Since we're using a pre-existing stack class from C++'s standard library (STL stack), we must include stack to access its built in methods (i.e. push, pop, top)

using namespace std; // Defines the scope of your class 

class postfixCalculator {
 public:
  postfixCalculator(); // postfixCalculator default constructor (we only need one)

  stack<int> stackcalculator; // As the PDR/instructions state: for Lab 3, you will be using a stack of int values. We have to dynamically allocate it  

  // Methods that must be implemented for the Pre Lab 
  
  void add();  

  void subtract(); 

  // Methods that must be implemented for the In Lab 

  void multiply();
    
  void divide();

  void negation(); // Multiplies by whatever's at the top of the stack by -1 
  
  // void negativenumbers(); // Don't need this method: apparently our In Lab just has to be able to handle negative numbers from user input

  void pushnumber(int num); // Pushes a number onto a stack (will be used for calling in the testPostfixCalc.cpp file) 

  int gettopvalue(); // Returns the element at the top of the stack (Often, the top() and pop() functionality are joined as an int pop() function, but in this lab, it is beneficial to separate them, as that's what the STL stack does)

  // I don't think we need to implement a method for bool empty() like it states under the PDR under the "stacks" section in the Pre Lab  
  
}; // Why do you need a semicolon after the closing brace: it's just C++ syntax 
#endif
