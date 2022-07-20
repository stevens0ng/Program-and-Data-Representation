/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: April 11, 2021 
   CS2150 Lab 8 Pre Lab mathfun.cpp  
*/

// Stuff we include that's necessary for this file to function (NOTE: these headers are the same as the ones in main.cpp)  
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std; // Defines the scope (the context of the file in which all the names are declared) 

// You need this to import your .s file since you're writing it in C, not C++. Similar to main.cpp
extern "C" long product (long, long);

// Product and power are the two functions you're trying to import into this file 
extern "C" long power (long, long);

int main() {

   // Declares all of the local variables
   int firstnumber = 0; // first input parameter
   int secondnumber = 0; // second input parameter 
   int multiplication = 0; // computes the product of the two integer inputs 
   int exponent = 0; // computes the exponent/power of the two integer inputs 

   // Takes the user input for the first number 
   cout << "Enter integer 1: " << endl;
   cin >> firstnumber;

   // Takes the user input for the second number 
   cout << "Enter integer 2: " << endl;
   cin >> secondnumber;

   // Finds the product of the 2 numbers and prints out the result 
   multiplication = product(firstnumber, secondnumber);
   cout << "Product: " << multiplication << endl;

   // Finds the exponent/power of the 2 numbers with the first number being the base and the second number being the power and then prints out the result 
   exponent = power(firstnumber, secondnumber);
   cout << "Power: "<< exponent << endl;
   return 0; // End of the file: Always return 0 at the end of each main method 
}
