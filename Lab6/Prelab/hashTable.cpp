/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 28, 2021 
   CS2150 Lab 6 Pre Lab hashTable.cpp  
*/

#include <iostream> // Necessary for cin/cout and print statements 
#include <stdlib.h> // Necessary for sizeof keyword, conversions between double and int
#include <string> // Necessary for string variables
#include <math.h> // Necessary for computing the power of a base to an exponent (i.e. x^n). If <math.h> is NOT included, then the pow function will NOT work: it will error.
#include "hashTable.h" // We must include the header file for "hashTable.h" in order to access its members and functions

using namespace std; // Defines the scope of the class 

// A hash table is a dictionary in which the keys are mapped to array positions by a hash function.

// NOTE: Linear probing takes 36.938326 seconds to find all 27409 words in the words.txt 300x300.grid.txt
// Changing the load factor improves the time slightly 

// Constructor part
hashTable::hashTable(int size) { // Creates a new HashTable and sets the size of the hash table to be equal to the parameter for size .
  // sizeofhashtable = getNextPrime(size); 
  double loadfactor = 1.6; // The whole point of a load factor is to make the size of the hash table bigger than the input size (the parameter size): that way it reduces the likelihood of having collisions. (You can adjust the size of the hash table to make the hash table work faster/more efficiently)

  // Load factor is used for rehashing 
  
  sizeofhashtable = getNextPrime(size*loadfactor); // Remember, the size of the hash table/array must be a prime number as stated in the Lab instructions and in Slide 6, hence why you have to call the getNextPrime method on the size function in order to make it prime.   
  // cout << "Size of hash table is " << sizeofhashtable;  
  hashtable = new string[sizeofhashtable];  
}

// From 4.10 in Slide 6, it says that the standard set of operations for a hash table are find, insert, and delete so I'm just going to implement a find, insert, and then a check method to see if the word is in the hash table or not. I'm pretty sure you don't need to implement a delete method for your hash table in Lab 6 

// The insert method is pretty self-explanatory: You're just inserting the word into the hashtable if the word has length greater than or equal to 3, and if the length of the word is less than 3, then you don't add/insert the word to the hash table

void hashTable::Inserthashword(string word) { // Inserts a word into the HashTable and sets the hash index of that word equal to it 
  if (word.length() >= 3) { 
    int hashindex = wordhash(word); // Gets the hash index of the word

    while (hashtable[hashindex] != word && hashtable[hashindex] != "") { // If the hash table is occupied and if it's not equal to the word, then linear probe to make sure that you insert it correctly into the table 
      // cout << hashindex << " has been occupied by " << hashtable[hashindex] << " collied with " << word; 
      hashindex++; // Increments the hashindex by 1 each time you don't find the word in the hash table at that hash index that you just got from the hash function. (basically, you keep incrementing the index until you eventually find the word in the hash table and whatever location that word is in the hash table, you set the hash index to be equal to that) 
      hashindex = hashindex % sizeofhashtable; // If a slot is empty in the hash table, then you insert the word into the hash table. If a slot is occupied though, then you have to move to the next slot in the table (linear probing). You check the next slot, see if it's occupied or not, and you linear probe until you find an empty spot. Linear probing: what if your hash table is full, you don't have empty slots, then you have an infinite loop. Then, you keep checking and checking.

      // The reason why you have to set the hashindex to be equal to the hashindex % sizeofhashtable is because you have to wrap around the array once you reach the end of the hash table (the last index in the array) so you can start from the first index in the array again. You can't just do hashindex++ only because otherwise your array index will go out of bounds. Thus, you need to mod the size of the hashtable in order to wrap around the hash table (hence the % sizeofhashtable) and start from the beginning of the array again.  

      // cout << word << " has collisions " << endl; (This was just used to test how many collisions there were in the hash table for a specific word) 
    }
    hashtable[hashindex] = word;
    // cout << "Inserted Hash table index is " << hashindex << endl;
    // cout << word << " inserted into the hash table " << endl;
    // NOTE: All of these cout statements that are commented out in this file (the hashTable.cpp file) are just used for debugging to see if all of these hash table methods work or not  
  }
  /*
  else if (word.length() < 3) {
    cout << word << " NOT inserted into the hash table" << endl;
  } 
  */
}

// The checkhashword will method will check to see if the word is found in the hashtable at the hashindex or not. If it is found in the hash table, then return true, and if it's not found in the hash table, then return false. 
bool hashTable::Checkhashword(string word) {
  int hashindex = wordhash(word);
  while (hashtable[hashindex] != "") {
    if (hashtable[hashindex] == word) {
      // cout << "The word " << word << " is found in the hash table " << endl;
      return true; // If a word has successfully been inserted into the table, then return true
    }
    // Needs to be able to handle collisions 
    hashindex++;
    hashindex = hashindex % sizeofhashtable; // If the word is not found, then need to mod the size of the hashtable to wrap around the array and start back at index 0/the first element again. 
    
  }
  // cout << "Word " << word << " is NOT found in the hash table " << endl;
  return false; // Else if the word does NOT exist in the hashtable, then return false 
}

// The findhashword will attempt to find the word in the hash table or not. If the word is successfully found in the hash table, then return the word that you're trying to find, else return an empty string, which just signifies that the word was NOT found in the hash table. 
string hashTable::Findhashword(string word) { // Findhashword method that finds the word in the hashtable (if it's there)
  int hashindex = wordhash(word);
  while (hashtable[hashindex] != "") { // Since we already do a hashindex % sizeofhashtable, we don't need to have a condition inside the while loop for hashindex < sizeofhashtable, since the hash index will never be greater than the size of the hash table, so it will always be true and it will never exit the while loop that way, so we don't need the first condition (in the line I commented out above this)  
    if (hashtable[hashindex] == word) { // Returns the word in the hash table if you're able to find the word in the hashtable/array at the index "hashindex"
      // cout << word << " is found at index " << hashindex << " in the hash table " << endl;
      return word;
    }
    // Needs to be able to handle collisions 
    hashindex++;
    hashindex = hashindex % sizeofhashtable; 
  }
  // cout << "Word " << word << " is NOT found in the hash table " << endl;
  return ""; // Else if you do NOT find the word in the hashtable, then return an empty string so that it works for all cases where the word is NOT found in the hash table   
}

int wordhash(string word); // As covered in Slide Set 1, the wordhash method must be defined here as a prototype before 

// This is my hash function: the hash function/code is used to find the index (index = hash % sizeofhashtable) and all of the words at that index  
int hashTable::wordhash(string word) { // Hash function: it can be open ended as long as the index is reasonable   
  int index = 0;
  unsigned int hash = 0;   
  int hashword = 13; // We can pick any prime number here like the instructions state (I picked 13)
  for (int i = 0; i < word.length(); i++) {
    hash += ((int)word[i] * (pow(hashword,i)) + 89); // This is my hash function for a word in a dictionary file
  } // Note: the 89 above can replaced with any prime number here
  
  index = hash % sizeofhashtable; // You're returning the remainder of a hashtable you created with the size of the table (it will give you the index of where the word is in the hash)
  
  // cout << "The index for " << word << " is " << index << endl;
  return index;
} 

/* I haven't decided whether I'm going to use this for the Post Lab or not, but I might use this hash function for the Post Lab in place of the wordhash function I did for the Pre Lab. I might use Quadratic probing for the Post Lab or double hashing. Again, I don't know for certain yet, which is why this part is commented out for now. 

int wordhash2(string word); // Prototype for the second hash function 
 
int hashTable::wordhash2(string word) { // Second hash function
  int index = 0;
  unsigned int hash = 0;   
  for (int i = 0; i < word.length(); i++) {
    hash += (int)word[i]; 
  } 
  index = hash % sizeofhashtable; // You're returning the remainder of a hashtable you created with the size of the table (it will give you the index of where the word is in the hash)
  
  // cout << "The index for " << word << " is " << index << endl;
  return index;
}  
*/ 

int hashTable::getsize() { // Basic accessor method that just returns the size of the hash table 
  return sizeofhashtable; 
}

// NOTE: The checkprime method was copied over from the primenumber.cpp file (source code) for Lab 6 (didn't modify this method) 

// yes, there are much faster -- and much better -- ways to check if a
// number is prime (see the Sieve of Eratosthenes, for one example),
// but this code will work correctly, it is fairly straightforward,
// and it is fast enough for our purposes in the hash lab
bool hashTable::checkprime(unsigned int p) {
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

int hashTable::getNextPrime (unsigned int n) { // You have to invoke it by the class 
    while (!checkprime(++n));
    return n; // all your primes are belong to us
} 

// The main method below was just used to debug/test my hash table methods for the insert/find/and check the word to see if they were correct and operated/functioned correctly (i.e. do not insert a word with length < 3 into the hash table). Note, you have to declare the array for a hash table as a pointer in order to dynamically allocate it and you need to use a pointer/arrow (->) in order to get access to the size of the hash table because otherwise, it will give you an error that says "undefined reference to the getNextPrime() method"

/*
int main() {
  
  int totalsize = 61; //create a hash table
  hashTable* HashTable1 = new hashTable(HashTable1 -> getNextPrime(totalsize)); // you didn't use the instance of hash table to invoke it
  
  cout << "The size of the hash table is " << HashTable1 -> getNextPrime(totalsize) << endl; 
  
  HashTable1 -> Inserthashword("weed out class");
  HashTable1 -> Inserthashword("I hate this class");
  HashTable1 -> Inserthashword("w");
  HashTable1 -> Inserthashword("he");
  HashTable1 -> Inserthashword("a");
  HashTable1 -> Inserthashword("apple");
  HashTable1 -> Inserthashword("apple");
  HashTable1 -> Inserthashword("juice");
  HashTable1 -> Inserthashword("watermelon"); 
  HashTable1 -> Inserthashword("cheeseburger");
  HashTable1 -> Inserthashword("Brady");
  HashTable1 -> Inserthashword("Rodgers");
  HashTable1 -> Inserthashword("I freaking hate my life");

  cout << "---------------------------" << endl;
  HashTable1 -> Findhashword("Brady");
  HashTable1 -> Findhashword("apple");
  HashTable1 -> Findhashword("orange");
  HashTable1 -> Findhashword("banana");

  cout << "---------------------------" << endl;
  HashTable1 -> Checkhashword("a");
  HashTable1 -> Checkhashword("weed out class");
  HashTable1 -> Checkhashword("I hate this class");
  HashTable1 -> Checkhashword("apple");
  HashTable1 -> Checkhashword("juice");
  HashTable1 -> Checkhashword("Brady");
  HashTable1 -> Checkhashword("e");
  
  string* array = HashTable1 -> hashtable; // When you declare an array, you have to declare it with a * as a pointer (similar to in the first slide set (Slide 1) otherwise it will give you an undefined reference to HashTable1 and hashtable. 

  //string *arrayvalue = &HashTable1[5];
  for (int i=0; i < HashTable1 -> sizeofhashtable; i++) {
    cout << "Index: " << i << " " << array[i] << endl;
  }
  delete HashTable1; 
  return 0; 
} 
*/  
