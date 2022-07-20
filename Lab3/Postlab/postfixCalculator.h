/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: March 3, 2021  
   CS2150 Lab 3 Post Lab postfixCalculator.h
*/

// Class declaration of the postfix calculator 
#ifndef POSTFIXCALCULATOR_H // As always we must have the preprocessors #ifndef, #define, and #endif in our .h file
#define POSTFIXCALCULATOR_H

#include <iostream> // Necessary for cin/cout 
// #include <stack>
#include "Stack.h" // Includes the Stack header file 

// All you need to include for your header
// That way you can access all the library functions. You could just do stack, but it wouldn't be able to do anything with it.

using namespace std; // Defines the scope of your class
 
class postfixCalculator {
 public:
  postfixCalculator(); // postfixCalculator default constructor (we only need one)

  // stack<int> stackcalculator; // Since the PDR states for the Post Lab, you have to implement your own stack rather than using the built in STL stack so we have to comment out the STL stack that we used in the Pre Lab and Post Lab  

  // Methods that must be implemented for the Pre Lab 
  
  void add();  // declaration for it and prototype

  void subtract();

  // Methods that must be implemented for the In Lab 

  void multiply();
    
  void divide();

  void negation(); // Multiplies by whatever's at the top of the stack by -1

  // NEWLY added for the Post Lab 

  Stack* stackcalculator; // Since we have to create our own stack instead of using the built in STL stack in the Pre Lab/In Lab, we create/define a new Stack variable here called stack calculator that is dynamically allocatted in order to prevent memory loss, and we modify our postfix calculator by using our stack to modify our postfix calculator 

  void pushnumber(int num); // Pushes a number onto a stack (will be used for calling in the testPostfixCalc.cpp file) 

  int gettopvalue(); // Returns the element at the top of the stack (Often, the top() and pop() functionality are joined as an int pop() function, but in this lab, it is beneficial to separate them, as that's what the STL stack does)
  
}; // Why do you need a semicolon after the closing brace: it's just C++ syntax 
#endif
