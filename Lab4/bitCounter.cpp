/* Name: Steven Song  
   UVA ID: sqs5hrn 
   Date: March 17, 2021     
   CS2150 Lab 4 Post Lab bitCounter.cpp 
*/

#include <iostream> // Necessary for cin/cout 
#include <stdio.h> // Necessary for input/output functions like atoi(argv[i]) (converts the nth command line argument to an integer)  
#include <string> // Necessary for string conversions 
#include <bits/stdc++.h> // A header file that includes every standard library 

using namespace std; // Defines the scope of the class

// From the PDR, create a recursive function that returns the number in 1's in binary representation of n: which will be passed in as a command-line parameter. Use the following fact: if n is even, the number of 1's in the representation of n is the same as that in n/2. If n is odd, the number of 1's is one more than that in floor(n/2). 

int bitcountnumber (int n) { // Takes an integer and returns the number of 1's in a binary representation of that number (in command-line parameter) From the PDR: you may assume that n is a non-negative integer that will be sorted in two's complement. n will be passed in the standard decimal (base 10) format 
  if (n == 0) { // Base case of the recursive method 
    return 0;
  }
  if (n % 2 == 0) { // If the number is even, call it recursively as the instructions state for this part 
    return bitcountnumber(n/2);
  }
  else { // Else if the number is not even (meaning it's odd) 
    return 1 + bitcountnumber(floor(n/2)); // You have to add one to the floor(n/2) as the instructions state
    // Since this method is recursive, you have to call bitcountnumber recursively on the floor function 
  }
}

// Create a function that takes a number n from startBase and returns the number in endBase. This means that your program will take in 4 command-line parameters total: 1) bitcount number (int), 2) number to convert (string), 3) start base(int), 4) end base(int)
string baseconvertermethod (string numbertoconvert, int startbase, int endbase) { // Assume that all inputs will be valid numbers for their bases (no negative numbers) 
  if (startbase < 1 || endbase > 36) { // As the instructions in the PDR/lab instructions state: we will NOT provide any bases less than 1 or greater than 36 
    return "Invalid base conversion entered!";
    // cout << "base conversion incorrect!" << endl; 
  } 

  // Step 1: First convert the number from the start base to base 10 
  int power = 1;
  int numberinbase10 = 0; // Convert those numbers to integers, then add up all the powers
  // int sizeofletters = numbertoconvert.size()-1;
  // string is stored as an array of chars (string x = "123AB") stored in an array of characters [1][2][3][a][b]
  
  // b is in the 0th place: value of b is b*16^0
  // a is in the 1st  place: value of a is a*16^1
  // when you have those values from the string,
  // increment power, but you need to add those numbers to the sum
  // b is 13, a is 10 (you add those two numbers to get the base 10 value of ab)
  // while (sizeofletters > 0) {
  
  for (int i = numbertoconvert.length() - 1; i >= 0; i--) { // Converts the number from the start base to the end base 
    // int digit = numbertoconvert[i] - '0';
    if (numbertoconvert[i] >= 'A' && numbertoconvert[i] <= 'Z') { // Check if it's between A-Z (Assume that all characters are capitalized) 
      // A is 65, Z = 90 in ASCII 
      numbertoconvert[i] = numbertoconvert[i] - 55; // 65-55 = 10 (A in base 16 is 10 in base 10) 
    }
    else if (numbertoconvert[i] >= '0' && numbertoconvert[i] <= '9') {
      numbertoconvert[i] = numbertoconvert[i] - 48; // From the PDR: the ASCII value for the character '9' is 57. To convert the character '9' to an integer is simple subtraction (int converted = 9 - 48)  
    }
    numberinbase10 += power * numbertoconvert[i];  
    power = power * startbase;
    // cout << "power : " << power << endl;
    // sizeofletters--;
  }
  // cout << "base10 output: " << numberinbase10 << endl;
  // returning an empty string at the end 

  // Step 2: Convert the base 10 number to the end base 
  string officialconversion = "";
  
  while (numberinbase10 > 0) { // Convert the base 10 number to the end base 
    int remainderbase = numberinbase10 % endbase;
    // officialconversion = " " + officialconversion;
    char a;  // goes through every single number/letter converted in base 10 and goes through a new case each time 
    if (remainderbase < 10) {
      a = remainderbase + '0'; 
    } // when you get a remainder base, you get a number from 1-36. If you set 1 equal to a char, what does it represent in ASCII:
    // if you don't add '0', you're stuck at the number 0, where it just prints out a white space instead of a character 0 
    // you need + '0' at the end to make sure that the char starts at the character 0 
    else {
      a = remainderbase - 10 + 'A'; // If your remainder base is 10, it means that it is A
    } // ex. 10-10 + A, converting from your number back into an ASCII value
    officialconversion = a + officialconversion; 
    numberinbase10/= endbase;
  } // you reach 0 but while condition is still 0 
  // cout << "final conversion: " << officialconversion << endl; 
  return officialconversion; // The number you are converting will be passed in as a string 
}

int main(int argc, char **argv) { // command line parameters as stated in the PDR/Post Lab instructions
  // The first parameter, argc, is the number of parameters plus one - the 0th parameter is always the name of the executable itself (a.out)
  // The second parameter, argv, is an array of C-style strings 
  if (argc < 5) {
    cout << "Enter number that will count the number of 1's in binary representation" << endl; 
    cout << "Enter number/letter to convert from start base to end base" << endl;
    return 0; 
  }
  int number = atoi(argv[1]);   
  int numberofbits = bitcountnumber(number); // 1st command line parameter

  // Prints the bit counter method and the base converter method in the exact format that the PDR/lab instructions state in the "Sample Execution Run" section (Your program must print the results of the bit counter before the results of the converter) (Ex: ./a.out 1 ABCD 16 10)  

  // Results of the bit counter  
  cout << number << " has " << numberofbits << " bit(s)" << endl; 

  string numbertoconvert = argv[2]; // 2nd command line parameter 

  int startbase = atoi(argv[3]); // 3rd command line parameter 
  int endbase = atoi(argv[4]); // 4th command line parameter 

  string finalnumberconversion = baseconvertermethod(numbertoconvert, startbase, endbase); // Calls the base converter method (start base converted to end base) (i.e. base 10 converted to base 16)  

  // Results of the base converter 
  cout << numbertoconvert << " (base " << startbase << ") = " << finalnumberconversion << " (base " << endbase << ")" << endl;   
  return 0; // Always return 0 at the end of each main method 
}
