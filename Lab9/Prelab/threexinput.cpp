/*Name: Steven Song   
  UVA ID: sqs5hrn 
  Date: April 18, 2021 
  CS2150 Lab 9 Pre Lab threexinput.cpp 
*/

// Stuff we have to import/include in this file for everything to work properly
#include "timer.h" // We have to include timer.h obviously as the instructions for the Pre Lab clearly state 
#include <cstdlib> // C++ header necessary to use the namespace 
#include <iostream> // We have to include iostream to take in user input and print out stuff from cin/cout 

using namespace std; // namespace std is used in the scope of the file that is present to differentiate similar functions, classes, variables, etc. with the same name available in different libraries. Basically, namespace allows you to define the context in which the names and everything are defined 

extern "C" long threexplusone (long); // This will input the threexplusone.s file and all of its functions 

int main() {
  
  int inputnumber; // Takes in the user input of type int for the positive integer/number to be passed into the subroutine
  int totaliterations; // The iterations are the number of times the user wants/needs to call the subroutine
  int numberofsteps; // The steps variable, as specified in the instructions, takes in a positive integer and is required for returning the number of steps required for the integer to reach 1 by following the Collatz conjecture (numberofsteps is what we want to print out)

  // In the exact format of the sample execution run input/output in the PDR 

  // Input:
  cout << "Enter a number: "; // Asks the user to input a number 
  cin >> inputnumber; // Runs the subroutine once to store the result 

  cout << "Enter iterations of subroutine: "; // Asks the user to input the number of times he/she wants to call the subroutine 
  cin >> totaliterations; // Runs the subroutine an iteration number of times with the parameter number as the input 

  timer timer1; // Timer variable that we will be using to find the number of steps 
  timer1.start(); // Starts the timer
  
  numberofsteps = threexplusone(inputnumber); // The numberofsteps variable counts how many times you input the number in threexplusone.s (number of times needed for the subroutine) and perform the Collatz Conjecture until you get 1 as the output
  timer1.stop(); // Stops the timer

  // Output: 
  cout << "Steps: " << numberofsteps << endl; // Prints out the number of steps it took for the integer to converge to 1

  // DO NOT PRINT OUT THE AVERAGE TIME OUTPUT 
  
  return 0; // We need to return 0 at the end of each cpp file for insurance in case the above code fails 
}
