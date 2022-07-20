/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 28, 2021   
   CS2150 Lab 3 Pre Lab testPostfixCalc.cpp
*/

#include <iostream> // Necessary for cin/cout 
#include <stack> // Necessary for stack operations such as push/pop 
#include <string> // Everything is space separated
#include "postfixCalculator.h"

using namespace std; // Defines the scope of the class 

// stoi: converts string to integers 

// C++ API/Documentation (ex. code 1 space 2 line 2 something to read everything in) (once you have all your tokens, you just need to decide if there are an operators , then you just need to call the methods that we called in the post operator"

// The testPostfixCalc.cpp accepts user input and evaluates that expression accordingly with the stack class that you created 

int main () {
  postfixCalculator n; // Since we created/instantiated the stack calculator in the constructor in our postfixCalculator class 
  string token; // reads from the standard input 
  while (cin >> token) { // run your program and then input a postfix expression and once you enter that in, the cin will take the string that you justenred and splits it once it up with token (white space) // separated by space the >> separates the characters from the space

    // int firstelement = stoi(token);
    if (token == "+") {
      n.add();
    }
    
    else if (token == "-") {
      // you don't have to separate negative numbers from the subtraction sign
      // it will read in the next word once it stops at a white space 
      /* 
      int i; // i is arbitrary (i will take a new string from the standard input)
      // it takes words separated by white space 
      
      if (atoi(token) >> i) { // If the "-" precedes an integer, push in a number   
	n.pushnumber(i); // If the "-" does NOT precede an integer, perform subtraction on the top two numbers in stack 
      }
      else { 
      */
      n.subtract();
    }

    else if (token == "*") {
      n.multiply(); 
    }

    else if (token == "/") {
      n.divide(); 
    }

    else if (token == "~") { // the symbol for negation is just the "tilde" sign 
      n.negation(); 
    }
    
    else {
      int firstelement = stoi(token); // converts it from a string to an int (store the int into your calculator)  
      n.pushnumber(firstelement); // If you don't call any of the stack class's functions (the arithmetic operations), then just push the first element that you entered on your keyboard 
    }

    // store the int into your calculator
   
    // check if it's a number of if it's a '-' or a '+'  
    // Do stuff with `token`!
    // For example, we can print each token back out on its own line:

    // If you read in an operator, a subtraction or multiplication
    
    // See into what token is doing (cin is a line) (see what the token stuff)
    
    // If the token reads in a plus, then it will call addition: but if you read in a number, then it pushes it into the stack. There's multiple ways that you can do that. 

    // separate function in the cpp file that handles it
  }
  cout << n.gettopvalue() << endl; // Gets you the element at the top of the stack   
  return 0; // You must return 0 at the end of each main method  
}
