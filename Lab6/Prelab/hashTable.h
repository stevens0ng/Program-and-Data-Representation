/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 28, 2021 
   CS2150 Lab 6 Pre Lab hashTable.h  
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream> // Necessary for cin/cout 
#include <string> // Necessary for string variables

using namespace std; // Defines the scope of the class 

class hashTable {

public:
  hashTable(int size); // Default constructor for the hash table. It's just used for setting the size of the hash table
  
  void Inserthashword(string word); // Inserts the word into the hash table  
  bool Checkhashword(string word); // Checks to make sure that the word is valid and meets all of the requirements for the Lab 6 instructions

  string Findhashword(string word); // Finds the word in the hash table. If it's found in the hash table, then return the word, else return an empty string. 
  
  string* hashtable; // Since the Lab 6 instructions explicitly state that you can't use a vector of vectors to store a hash table or an STL hash table, I decided to use an array to store all of the words in the hash table. 
  
  int getsize(); // This is just the accessor method that returns the size of the hash table 

  // NOTE: The checkprime/getNextPrime method declarations/prototypes were copied over from the primenumber.cpp file (since the implementations for these two methods were down below in this file)
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  
  int sizeofhashtable; // Finds the size of the hash table
  int wordhash(string word); // Method for hashing the word (the hash function can be anything)
  // int wordhash2(string word); // Another hash function 
  
private:
  
};
#endif
