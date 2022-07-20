/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 15, 2021 
   CS2150 Lab 1 In Lab LifeCycle.cpp
*/

#include <iostream> // Necessary for cin/cout 
#include <string> // Necessary for string variables and string conversions 
#include "LifeCycle.h" // Includes the header files for LifeCycle.h to access all of its members, definitions, and functions. (Definitions can only appear in 1 place)

// Remember: member functions are defined as Class::method()

// This is the .cpp file that contains member function implementations 
// Constructors and destructors - no return types
MyObject::MyObject() {
  // Important: notice how we don't define 'name' or 'id' here
  // Instead, we're setting the variables that we declared in MyObject
  name = "--default--";
  id = ++numObjs;
  cout << "MyObject Default constructor:   " << *this << endl;
}

MyObject::MyObject(string n) {
  name = n;
  id = ++numObjs;
  cout << "MyObject Parameter constructor: " << *this << endl;
}

MyObject::MyObject(const MyObject& rhs) {
  name = rhs.name;
  id = ++numObjs;
  cout << "MyObject Copy constructor:      " << *this << endl;
}

MyObject::~MyObject() { // Destructors are called whenever an object goes out of scope, or when delete is called. The purpose of destructors is to free up any resources that the object reserved. 
  cout << "MyObject Destructor:            " << *this << endl;
}

// Regular methods, with return types
string MyObject::getName() const { // Accessor method 
  return name;
}

void MyObject::setName(const string& newName) { // Mutator method 
  name = newName;
}

// operator = ()
// also known as a copy assignment operator
// intended to copy the state of original into copy 

// Let cout know how to print MyObjects
ostream& operator<<(ostream& output, const MyObject& obj) {
  // output in format: ("object name", id)
  return output << "(\"" << obj.name << "\", " << obj.id << ")";
}

// Define the functions we declared earlier
int cmpMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 == name2) {
        return 0;
    } else if (name1 < name2) {
        return -1;
    } else {
        return 1;
    }
}

MyObject getMaxMyObj(const MyObject o1, const MyObject o2) {
  string name1 = o1.getName(), name2 = o2.getName();
  if (name1 >= name2) {
    return o1;
  } else {
    return o2;
  }
}

void swapMyObj(MyObject& o1, MyObject& o2) {
  MyObject tmp(o1);
  o1.setName(o2.getName());
  o2.setName(tmp.getName());
}

// Static variables
int MyObject::numObjs = 0;  // static member for all objects in the class
static MyObject staticObj("I'm static, outside of main");

// Initializing num objects, you'd want to do that in a C++ file rather than a header file 
// static variables also belong in .cpp files 
