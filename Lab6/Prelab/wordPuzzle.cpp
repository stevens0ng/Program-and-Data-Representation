/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 28, 2021 
   CS2150 Lab 6 Pre Lab wordPuzzle.cpp 
*/

#include <iostream> // Necessary for cin/cout 
#include <fstream> // Necessary for both reading and writing from/to files (readinGrid method) 
#include <string> // Necessary for string variables
#include <stdio.h> // Streams are handled in the cstdio library as pointers to FILE objects 
#include <stdlib.h> // Necessary for string conversions, dynamic memory management, random number generation, performing integer arithmetics, and searching/sorting (ex. exit(1) in the main method)
#include <algorithm> // Necessary for min/max function 
 
// These are all the header files that we must include in our Lab 6 Pre Lab/Post Lab 
#include "timer.h" 
#include "hashTable.h"

using namespace std;  // Defines the scope of the class 

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for Lab 6)

// NOTE: The #define MAXROWS/MAXCOLS and the char grid were copied over from the getWordInGrid.cpp file (source code) (didn't modify these 3 lines) 
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations 
bool readInGrid(string filename, int&rows, int&cols);
string getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);
bool checkprime(unsigned int p); 
int getNextPrime (unsigned int n);

/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main(int argc, char* argv[]) {
  // There must be two command line parameters when you do ./a.out for the wordPuzzle.cpp file: one for the dictionary file, and one for the grid. 
  if (argc != 3)  {
    cout << "There must be 2 command line parameters." << endl;
    exit(1);
  }
  int dictionaryfilelength = 0; // Variable that will be used to find the length of the dictionaryfile (so for example the length of "words.txt" or "word2.txt") 
  string dictionary = argv[1]; // Reads in the dictionary (first command line parameter) 
  // string dictionary = "words2.txt";
  string grid = argv[2]; // Reads in the grid (second command line parameter) 
  string prelabline = ""; // You have to initialize it to something: if you initialize it to an integer, it gives you an error because a string is NOT an integer

  // Each line in the dictionary file contains a word (1 word) so the number of words in a dictionary file is just equal to the length of the file (how many lines there are in a dictionary file)  
  ifstream firstfile(dictionary.c_str()); // Creates the stream of the first file.
  if (!firstfile.is_open()) { // If the first file (the dictionary) cannot be opened, then exit the file
    exit(1);
    cout << "File NOT found/available!"; 
  }
  
  else if (firstfile.is_open()) { // If the first file (the dictionary) can be read, then read in all of the lines in the file (ex. words2.txt" and increment the dictionaryfilelength for each line read in the file). That way, you can get the length of the file. 
    // getline(string) is a built in method
    while (getline(firstfile, prelabline)) { // While the lines are being read, increment the dictionaryfilelength. 
      dictionaryfilelength++; // This will get you the size/length of the file 
    }  
    firstfile.close(); // This closes the second file
  }
  
  // Reads in the same file but this inserts all of the words into the hash table 
  ifstream secondfile(dictionary.c_str()); // Creates the stream of the second file, which is the dictionary (again). Read in the dictionary again, but this time, add the words in the file to the hashtable.
  
  // hashTable* hashtabledictionary; // Creates a new hashTable variable 
  // hashtabledictionary = new hashTable(hashtabledictionary -> getNextPrime(dictionaryfilelength)); 
  hashTable* hashtabledictionary = new hashTable(getNextPrime(dictionaryfilelength)); // By doing it this way, you can get the actual size of the hash table by calling the getNextPrime method on the file length and NOT some arbitrary number like 100 or 1000 for the size 
  if (!secondfile.is_open()) {
    exit(1);
    cout << "File NOT found/available!" << endl;
  }
  else if (secondfile.is_open()) {
    while (getline(secondfile, prelabline)) { // Read in all of the lines in the dictionary file, but this time insert all of those words (each line contains a word) into the hashtable. 
      hashtabledictionary -> Inserthashword(prelabline);
    }
    secondfile.close(); // Close the file once you've finished inserting all of the words into the hash table 
  }
  
  // The part below was copied over from the main method in the getWordInGrid.cpp file (lines 82-91) 
  int rows; // The rows and cols variable are declared to find the rows and columns in the grid file 
  int cols; // to hold the number of rows and cols in the input file 
 
  bool gridresults = readInGrid(grid, rows, cols); // Sets the readInGrid to a boolean  
  if (!gridresults) {
    cout << "Error reading file!" << endl;
    exit(1); // Requires <stdlib.h>
  }
  // Attempts to read in the grid file
  string directions [8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"}; // All 8 directions 
  int numberofwords = 0; // Variable used to find the number of words found in the grid.   
  timer timer1; // Creates the timer to count the time of the operation  
  timer1.start();
  // Read in the grid 
  for(int w = 0; w < rows; w++) {
    for(int x = 0; x < cols; x++) {
      for(int y = 0; y < 8; y++) { // Since there are 8 directions total 
	// The word has to be of length 3 or greater and the longest word in the data file is 22 letters long (as stated in the PDR/lab instructions). Hence, why we only check for words that have length greater than or equal to 3 and less than 22 (since the max length of a word in any file is 22) in this last for loop condition. 
	int lengthmax = 0; // the max length to go for each direction 
	// When you reach the boundaries, the length hasn't reached 22 yet so you keep looping and you keep printing out the same thing until you reach 22. You have to get rid of all the duplicates (i.e. 3 to 22, 4 to 22 print out the same thing)
	// From the PDR: Searches are case-sensitive 
	// From the PDR: Duplicates: If a word occurs more than once in a grid, then each instance should be treated as a separate word 
	if (y == 0) {
	  lengthmax = min(w+2, 22);
        }
	
        else if (y == 1) {
	  lengthmax = min(w+2, cols-x+1);
          lengthmax = min(lengthmax, 22);
        }
	
        else if (y == 2) {
	  lengthmax = min(cols-x+1, 22);
        }
	
        else if (y == 3) {
	  lengthmax = min(rows-w+1, cols-x+1);
          lengthmax = min(lengthmax, 22);
        }
	
        else if (y == 4) {
	  lengthmax = min(rows-w+1, 22);
        }
	
        else if (y == 5) {
	  lengthmax = min(rows-w+1, x+2);
          lengthmax = min(lengthmax, 22);
        }
	
        else if (y == 6) {
	  lengthmax = min(x+2, 22);
        }
	
        else if (y == 7) {
	  lengthmax = min(w+2, x+2);
          lengthmax = min(lengthmax, 22);
        }
	
	for (int z = 3; z < lengthmax; z++) {
	  string wordchecker = (getWordInGrid(w, x, y, z, rows, cols)); // Gets the word from the grid. Since it's inside a for loop, it will check for all of the words that have length 3 or greater (and less than 22) and see if the word was found in the grid or not.
	  
	  // Now that all of the words from the dictionary file have been inserted into the hash table, I can now call all of the methods from the hash table class to check on if the word in the hash table meets the requirements of the lab or not.
	    
	  if (hashtabledictionary -> Checkhashword(wordchecker) == true && hashtabledictionary -> Findhashword(wordchecker) == wordchecker) {
	    numberofwords += 1; // Increments the number of words by one everytime you call the checkhashword method, which will check to see if the word in the dictionary has length 3 or greater
	    cout << directions[y] << " " << "(" << w << ", " << x << "): " << wordchecker << endl; // Outputs the location in the grid of the words that have length 3 or greater (Prints out the direction (i.e. N, S, W, E))
	  }
	}
      }
    }
  }  
  timer1.stop(); // Stop the timer 
  cout << numberofwords << " words found" << endl; // Prints out the number of words found in the grid that have length 3 or greater  
  // cout << "All of the words in the hash table were found in " << timer1 << " seconds!" << endl; // Prints out the time it took to find all of the words in the grid 
  return 0; // As always, we must return 0 at the end of our main method 
}

// NOTE: The checkprime method was copied over from the primenumber.cpp file (source code) for Lab 6 (didn't modify this method) 

// yes, there are much faster -- and much better -- ways to check if a
// number is prime (see the Sieve of Eratosthenes, for one example),
// but this code will work correctly, it is fairly straightforward,
// and it is fast enough for our purposes in the hash lab
bool checkprime(unsigned int p) {
    if (p <= 1) // 0 and 1 are not primes; the are both special cases
        return false;
    if (p == 2) // 2 is prime
        return true;
    if (p % 2 == 0) // even numbers other than 2 are not prime
        return false;
    for (int i = 3; i*i <= p; i += 2) // only go up to the sqrt of p
        if (p % i == 0)
            return false;
    return true;
} 

// NOTE: The getNextPrime method was copied over from the primenumber.cpp file (source code) for Lab 6 (didn't modify this method)
int getNextPrime (unsigned int n) {
    while (!checkprime(++n));
    return n; // all your primes are belong to us
}                                           

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */

// NOTE: The readInGrid method was copied over from the getWordInGrid.cpp file (source code) for Lab 6 (didn't modify this method)
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */

// NOTE: The getWordInGrid method was copied over from the getWordInGrid.cpp file (source code) for Lab 6 (didn't modify this method)
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
