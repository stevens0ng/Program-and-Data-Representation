/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: February 14, 2021  
   CS2150 Lab 1 Pre Lab xToN.cpp  
*/

#include <iostream> // Used for cin/cout to print out user inputs and outputs  
using namespace std; // Defines the scope of the class (the context of the file in which all names are declared)  

int xton(int x, int n); // Prototype: order of appearance matters without a function prototype

// We have to declare the recursive method up here with the parameters, otherwise it will give an error that says "use of undeclared identifier xton".

// It's also known as a forward declaration 

int main () { // Similar to the example C++ file provided in the PDR/Lab 1 instructions 
  int x, y, z;
  
  cin >> x;
  cin >> y;
  
  z = xton(x, y);
   
  cout << z << endl; 
    
  return 0; // We need to return 0 at the end of each main method in C++ 
}

// Actual function implementation 
int xton(int x, int n) { // Recursive method/function that computes x^n for non-negative integers n
  if (n!= 0) { // If n is NOT equal to 0, that means that we just compute the recursive method of the power of x to n. x^1 * x^n-1 = x^n 
    return x * xton(x, n-1);
  }

  // Ex. If x = 2, n = 3, then x^n = 2^3 = 8. If we plug in 2 and 3 into the parameters of this recursive method, we get 2*xTon(2,2) = 2*2*xTon(2,1) = 2*2*2*xTon(2,0) = 2 * 2 * 2 * 1 = 8 so this recursive method works perfectly.  

  else { // When n = 0, we're just returning 1 since anything to the 0 power is equal to 1 (i.e. 2^0 = 1, 3^0 = 1) 
    return 1;  
  }
}
