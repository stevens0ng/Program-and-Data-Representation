/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 3, 2021  
   CS2150 Lab 3 Post Lab testPostfixCalc.cpp
*/

// NOTE: testPostfixCalc.cpp was copied over from the Pre Lab/In Lab for Lab 3 (didn't modify this file for the Post Lab)

#include <iostream> // Necessary for cin/cout, which you'll see down below in the code 
// #include <stack>
#include "Stack.h" // Since we're no longer using the STL built in stack, we have to include the header file for our own Stack class 
#include "postfixCalculator.h" // We must call postfixCalculator.h to access all of its methods and functions (i.e. pushnumber, topvalue, add, subtract, multiply, divide, negation, etc)  
#include <string> // Everything is space separated

using namespace std; // Defines the scope of the class 

// converts string to integers 

// documentation (ex. code 1 space 2 line 2 something to read everything in) (once you have all your tokens, you just need to decide if there are any operators, then you just need to call the methods that we called in the post operator"

// The testPostfixCalc.cpp accepts user input and evaluates that expression accordingly with the stack class that you created 

int main () {
  postfixCalculator n; // Since we created/instantiated the stack calculator in the constructor in our postfixCalculator class
  string token;
  while (cin >> token) { // run your program and then input a postfix expression and once you enter that in, the cin will take the string that you justenred and splits it once it up with token (white space)

    // the >> separates the characters from the space
    
    // int firstelement = stoi(token);
    if (token == "+") { // addition method 
      n.add();
    }
    
    else if (token == "-") { // subtraction method 
      n.subtract(); 
      // you don't have to separate negative numbers from the subtraction sign
      // it will read in the next word once it stops at a white space (it takes words separated by white space) 
      /* 
      if (atoi(token) >> i) { // If the "-" precedes an integer, push in a number   
	n.pushnumber(i); // If the "-" does NOT precede an integer, perform subtraction on the top two numbers in stack 
      }
      else { 
      */
    }

    else if (token == "*") { // multiplication method 
      n.multiply(); 
    }

    else if (token == "/") { // division method 
      n.divide(); 
    }

    else if (token == "~") { // negation method 
      n.negation(); 
    }
    
    else {
      int firstelement = stoi(token); // converts it from a string to an int 
      n.pushnumber(firstelement); 
    }
    
    // store the int into your calculator
   
    // check if it's a number of if it's a - or a + 
    // Do stuff with `token`!
    // For example, we can print each token back out on its own line:

    // If you read in an operator, a subtraction or multiplication
    
    // See into what token is doing (cin is a line ) (see what the token stuff)
    
    // Read in a plus, then it will call addition: but if you read in a number, then it pushes it into the stack. There's multiple ways that you can do that. 

    // separate function in the cpp file that handles it
  }
  cout << n.gettopvalue() << endl; // gets the top value for the stack calculator  
  return 0; // You must ALWAYS return 0 from main() 
}
