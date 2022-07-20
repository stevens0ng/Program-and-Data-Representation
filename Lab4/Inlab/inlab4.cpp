/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 15, 2021    
   CS2150 Lab 4 In Lab inlab4.cpp 
*/

#include <iostream> // Necessary for cin/cout 
#include <stdio.h> // Necessary for performing input and output (printf function) 
#include <string> // Necessary for string conversions 

using namespace std; // Defines the scope of the class 

void tableDump(string (*arr)[5], string (*arr1)[4]);

// Half a byte is equal to to 4 bits
// Each hex digit is equal to half a byte: meaning that if you have 4 bits then there are 8 digits

int main() {

	// Replace the empty strings below with
	// the values you found while experimenting.

	string nonPointers[6][5] = {
		{"int", "4" /*size*/, "2,147,483,647" /*max value*/, "0x00000000" /*zero as stored in hex*/,"0x00000001" /*one as stored in hex*/},

		// int size: 2^31 -1 or 2,147,483,647 
		
		{"unsigned int", "4" /*size*/, "4,294,967,295" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x00000001" /*one as stored in hex*/},

	        // unsigned int size: 2^32 - 1 or 4,294,967,295
		
		{"float", "4" /*size*/, "2^128" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x3F800000" /*one as stored in hex*/},

		// float size: 2^128 or 3.40282e+38  

		// float: for 0, you have to know how to transfer the number of bytes in a rpresentation of 0: (if it's 0, it has to fill all of that bytes with 0 and has to have a representation with 0) (8 bits: endean)
		
		// how a float stores numbers: the exponent bits 
		
		{"double", "8" /*size*/, "2^1024" /*max value*/, "0x0000000000000000" /*zero as stored in hex*/, "0x3FF0000000000000" /*one as stored in hex*/},

		// double size: 2^1024 or 1.79769e+308
		// stored in hex: convert from big endian to low endian  
		
		{"char", "1" /*size*/, "127" /*max value*/, "0x30" /*zero as stored in hex*/, "0x31" /*one as stored in hex*/},

		// char: 0x30 for 0 in hex (size: 2^7 - 1) 

		{"bool", "1" /*size*/, "1" /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},

		// bool: 0 is false 1 is true
		// zero stored in hex: false, one stored in hex: true
		// 0x

	}; // 2 times the number of bits you have 

	string pointers[3][4] = { // all have 8 bits, 0x16fs for the max value, and 0x160s for each for the null  
		{"int*", "8" /*size*/, "0xFFFFFFFFFFFFFFFF" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"char*", "8" /*size*/, "0xFFFFFFFFFFFFFFFF" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"double*", "8" /*size*/, "0xFFFFFFFFFFFFFFFF" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
	}; // size of 8 means that you have 16 digits, the biggest hex digit you can get in base 16 is F so we want to make the biggest possible number in hexademical

	// NULL is stored at 0

	tableDump(nonPointers, pointers);
	return 0;
}
// hexadecimal: 0-9, A-F
// 10 in hexademical = 0xA
// 11 in hexadecimal = 0xB
// 12 in hexadecimal = 0xC
// 13 in hexadecimal = 0xD
// 14 in hexadecimal = 0xE
// 15 in hexademical = 0xF
// 16 in hexadecimal = 0x10
// 17 in hexadecimal = 0x11
// ...
// 25 in hexadecimal = 0x19 
// 26 in hexadecimal = 0x1A
// ... 
// 31 in hexadecimal = 0x1F
// 32 in hexadecimal = 0x20
// ... 
// 41 in hexadecimal = 0x29
// 42 in hexadecimal = 0x2A 

/* Hexadecimal converted to Binary
   Hex  Binary
   0    0000
   1    0001
   2    0010
   3    0011
   4    0100
   5    0101
   6    0110
   7    0111
   8    1000
   9    1001 
   A    1010
   B    1011
   C    1100
   D    1101 
   E    1110
   F    1111
   10   10000
   11   10001
   12   10010 
   13   10011
   14   10100 
   15   10101
   16   10110 
   17   10111 
   18   11000
   19   11001
   1A   11010 
   1B   11011
   1C   11100
   1D   11101
   1E   11110
   1F   11111
   20   100000
   21   100001 
   22   100010 
   23   100011
   24   100100
   25   100101 
   26   100110
   27   100111
   28   101000
   29   101001
*/

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	//printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}

// The values for the "Zero" and "One" columns should be interpreted appropriately for the data type. For example, "zero" is 0 for an int, 0.0 for a float, false for a bool, the character '0' for a char, etc.
// All hex values should be given as big-endian and in the same size as their data type. 
// 0xd97c34a2 is stored as a2 34 7c d9 
