/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 14, 2021   
   CS2150 Lab 4 Pre Lab prelab4.cpp 
*/

#include <iostream> // Necessary for printing out user input/output  
#include <string> // Necessary for string functions
#include <limits> // Necessary for float and numeric_limits 
#include <climits> // Has constants containing the max values of many type (UINT_MAX is included in <climits>) 
#include <cmath> // Necessary for pow function, sqrt function, ceil/floor function
#include <cfloat> 

using namespace std; // Defines the scope of the class 

void sizeOfTest(); // Function to view the sizes of various types 
void overflow(); // Function to investigate how C++ handles integer overflow 
void outputBinary(unsigned int x); // Function to display the binary representation of integers (NOTE that outputBinary() takes in x as the parameter) 

int main() {
  unsigned int x; // Your program should ask for a single unsigned integer value for input (via cin), which we will call x
  // The reason why you have to do an unsigned int x instead of int x for the input is because if you just do int x for the input, then whenever you have an input that's greater than the maximum value of the unsigned int (i.e. 4 billion or 5 billion), then it will truncate back to the unsigned int max/UINTMAX of 2^31-1 or 2,147,483,647 as the input so it won't print out the right conversion to binary (in the outputBinary() method) for the input. (2,147,483,647 when converted to binary is 0111 1111 1111 1111 1111 1111 1111 1111) 
  cin >> x; // Read in x as the single integer value for input (cin) 
  
  // cout << "Input: " << x << endl;
  // unsigned int max = (unsigned int) pow(2,31);
  // cout << "Max: " << max << endl;

  // From the PDR: The ordering of these print outs are very important: sizeOfTest() -> overflow() -> outputBinary() 
  sizeOfTest(); // Calls the sizeOfTest method  
  overflow(); // Calls the overflow method 
  outputBinary(x); // Calls the outputBinary method 
  return 0; // You always have to return 0 at the end of each main method 
}

// The sizeOfTest() is a function that is used to view the sizes of various types such as int, unsigned int, float, double, char, bool, int*, char*, double*. This function should print out all the types and their respective sizes. 

void sizeOfTest() {
  int a = 89;
  unsigned int b = 13;
  float c = 2.7;
  double d = 4.38; 
  char e = 'z';
  bool f = false; 
  int* g = NULL;
  char* h = NULL;
  double* i = NULL;
  
  // sizeOf() returns the size, in bytes, of a given variable or data type
  cout << "Size of int: " << sizeof(a) << endl; // You need to #include <cmath> in order for the sizeof operator to compile 
  cout << "Size of unsigned int: " << sizeof(b) << endl; // You need to #include <climits> in order for UINT_MAX to compile   
  cout << "Size of float: " << sizeof(c) << endl; 
  cout << "Size of double: " << sizeof(d) << endl;
  cout << "Size of char: " << sizeof(e) << endl;
  cout << "Size of bool: " << sizeof(f) << endl;
  cout << "Size of int*: " << sizeof(g) << endl;
  cout << "Size of char*: " << sizeof(h) << endl;
  cout << "Size of double*: " << sizeof(i) << endl;
}

// The overflow method is a function that is used to investigate how C++ handles integer overflow 
void overflow() {
  // Create an unsigned int, give it the max value, and add 1 to that 
  unsigned int x = UINT_MAX + 1; // UINT_MAX is the maximum value for an object of type unsigned int 
  cout << UINT_MAX << " + 1 = " << x << endl;  // The U stands for unassigned
  // cout << x << endl; 
  // From the PDR, your function should create an unsigned int, give it the max value, and then add 1 to it. Your cout statement should have the format <max_number> + 1 = <result>  
}

// Function called outputBinary() that takes in one parameter that is an unsigned int, and prints out the 32 bit binary representation (including leading 0's) of the passed parameters in big Endian format.

// Basically, you're converting a number to binary in the outputBinary method 

void outputBinary(unsigned int x) { // Takes in one parameter: an unsigned int  
  // First convert a number to binary and then develop an algorithm
  string binaryoutputstring = ""; // 32 bit binary digit representation
  // unsigned int max = (unsigned int) pow (2,31);
  // cout << max << endl;
  for (int i = 31; i >= 0; i--) { 
    // A 32 bit int has a range from -2^31 -> 2^31 - 1. However, an unsigned int has a range from 0 to 2^32 - 1
    if (x/ (unsigned int) pow(2,i) != 0) { // Meaning that the number is NOT divisible by 2^n 
      binaryoutputstring += "1"; // Whether or not you add 2^n power depends on if the mod of x/(2^i) is equal to 0 or 1 (If the mod is not equal to 0, then you would add 1 to the binary string and if it's equal to 0, then you would add 0 to the binary string)
      x = x - pow(2,i);  
      // Ex. If your input is equal to 5, then in order to convert that to binary, you would first find the highest power of 2 that's less than 5, which is 4, and then you would have to subtract 2^2 = 4 from 5 to get 5-4 = 1.
      // You keep repeating this process (hence the i--) until you're left with 1 (as in the case of 5) 
      // 5 = 1*2^2 + 0*2^1 + 1*2^0 = 101 in binary
      // 8 = 1*2^3 + 0*2^2 + 0*2^1 + 0*2^0 = 1000 in binary
      // 20 = 1*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 0*2^0 = 10100 in binary
      // 32 bits overflow: 2,147,483,647 + 1 = -2,147,483,648
      // cout << "Inside a greater than " << i << ": " << binaryoutputstring << endl;
    }
    else if (x/ (unsigned int) pow(2,i) == 0) { // Meaning that the number is divisible by 2^n   
      binaryoutputstring += "0";
      // If it's divisible by 2^n where n ranges from 1-32, then add 0 to the end of the output
      // cout << "Inside a less than " << i << ": " << binaryoutputstring << endl;
    }
    if (i % 4 == 0) { // If you're grouping by 4 numbers, then you have to do % 4 to make it grouped/separated by 4 numbers for each sequence of the binary conversion    
      binaryoutputstring += " ";
    }
  }
  cout << binaryoutputstring << endl; // Prints out the 32-bit binary representation (including leading 0's) of the passed parameters in big Endian format  
}
