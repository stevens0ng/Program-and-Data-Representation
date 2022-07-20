/* Name: Steven Song
   UVA ID: sqs5hrn  
   Date: February 17, 2021 
   CS2150 Lab 1 Post Lab bankAccount.cpp
*/

#include <iostream> // iostream is used for printing out stuff (cin/cout) 

#include "bankAccount.h" // Includes the header file for bankAccount.h to access all of its members and functions 
using namespace std; // Defines the scope of the class 

// Remember: member functions are defined as Class::method()

// Constructors and destructors - no return type

// A default constructor that will be called when a program creates a bankAccount object. This constructor should set the bankAccount balance to $0.00
bankAccount::bankAccount() { 
  balance = 0.00;
  // cout << "Bank Account default constructor: " << *this << end1;
  // You don't need to include these print statements in any of the constructors apparently 
}

// A constructor that will be called when a program creates a bankAccount object with an initial balance
bankAccount::bankAccount(double amount) { // parameter constructor 
  balance = amount;
  // cout << "Bank Account parameter constructor: " << *this << endl;
}

// A destructor that will be called when an object is deleted from program memory. You must have this in your .h and .cpp file, but you can leave the implementation empty
bankAccount::~bankAccount() { // destructor 
  // The destructor will delete things that it points to
  // The PDR says to leave the destructor empty so it's not getting rid of anything in this method 
  // cout << "Bank Account destructor: " << *this << endl;
}

// A method that withdraws the specified amount of money from your bank account. The method will return the new amount in the bank account after the withdraw goes through. If the withdraw amount is too high, donâ€™t withdraw any amount and return the current balance in the account.
double bankAccount::withdraw(double amount) { // withdraw method 
  if (amount >= 0) { // When we're withdrawing money from a bank account, we want to make sure that the amount of money withdrawn is a positive number (we don't want the amount of money withdrawn to be a negative number since it wouldn't make sense to take out a negative amount of money (Plus the instructions for Lab 1 state to assume amount > 0)   
    if (balance >= 0) { // I don't know if you need this line or not, but I'm assuming that the balance has to be greater than or equal to 0, since you don't ever want the balance to be negative
      if (!(amount > balance)) { // Only when the amount you're trying to withdraw is less than or equal to the balance do we want to withdraw money from the balance  
	balance -= amount; // balance = balance - amount 
	// If the balance ever dips below 0, then we don't want to just return a negative balance: we want to set the balance to be equal to 0 then in that case since otherwise the balance will be negative, which is not correct. As the PDR states:"If the withdraw amount is too high, don't withdraw any amount and return the current balance in the account. 
	// If the withdraw amount is too high, then don't withdraw any amount and return the current balance in the account.
	// Ex. If the balance is initially equal to 10 dollars and you try to withdraw 20 dollars from it, then the balance is still equal to 10. You don't set the balance equal to 0 since you're not subtracting 20 from 10. 
	// Initially: first thing you do is have an if statement checking if the amount you're trying to withdraw is greater than the balance 
      }
    }
  }
  return balance; 
}
 
// A method that deposits the specified amount of money from your bank account. The method will return the new amount in the bank account after the deposit goes through.
double bankAccount::deposit(double amount) { // deposit method 
  if (amount >= 0) { // Again, assume that amount >= 0 
    balance += amount; // balance = balance + amount 
  }
  return balance;
}

// A method that will return the balance currently in the bank account.
double bankAccount::getBalance() {
  // const means that the functions will not edit the class's variables 
  return balance; 
}
