/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 15, 2021 
   CS2150 Lab 1 In Lab LifeCycle.h
*/

// This is the header file. It contains all of the function prototypes, class definitions, and macro definitions that will be used/implemented in the cpp files. (It contains the class definition of LifeCycle) 

#include <iostream> // Preprocessor 
#include <string> // Necessary for string variables and string conversions (string class) 
using namespace std; // Defines the scope of the class 

// Declares the MyObject class
class MyObject {
public:
  // Notice how none of these methods or functions have any implementation inside them 
  static int numObjs;
  
  MyObject();                    // default constructor (takes in no parameters)
  // Default constructors don't do anything by default. They're just there so you can call it without a compiler error.
  
  MyObject(string n);            // constructor with name parameter
  
  MyObject(const MyObject& rhs); // copy constructor (creates a new object, initialized to a copy of the same type of object)
  // Copy constructors are called in the following situations: 1) declaration with initialization 2) if an object is passed by value into a subroutine and 3) if an object is returned by value from a subroutine
  
  ~MyObject();                   // destructor
  // Destructors are called whenever an object goes out of scope, or when delete is called. The purpose of destructors is to free up any resources allocated during the use of an object (typically things are allocatted via new, but it can also free up files, network sockets, etc) (Ex. the destructor in List would delete all of the ListNodes) 
  string getName() const;
  void setName(const string& newName); // Call by constant reference (Used when there is a class type that CANNOT be changed by formal parameter)
  // In a constant reference, its address cannot be changed (address is constant) and it must be initialized upon declaration 

  friend ostream& operator<<(ostream& output, const MyObject& obj);
    
private: // These are just the instance variables 
  string name;
  int id;
};

// Prototypes for non-member functions we define later on

// These are *non-member* functions because we didn't declare them as part of the MyObject class
MyObject getMaxMyObj(const MyObject o1, const MyObject o2); // Parameters are constant (won't change) and are passed by value 
int cmpMyObj(const MyObject o1, const MyObject o2); // Parameters are constant (won't change) and are passed by value 
void swapMyObj(MyObject& o1, MyObject& o2); // Calls by reference (Passes references as parameters). Used when formal parameters should be able to change the value of the actual argument. (This is when references are used (and for return values)) 
