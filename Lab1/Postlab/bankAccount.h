/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 17, 2021 
   CS2150 Lab 1 Post Lab bankAccount.h
*/

// bankAccount.h will contain the headers of the methods that will be implemented in bankAccount.cpp 

#ifndef BANKACCOUNT_H // ifndef has to go before #include (If bankAccount.h has not been defined yet, then define it)

#define BANKACCOUNT_H // header file only needs to be defined once in any file

#include <iostream> // We're dealing with doubles here so no need to include string 
// define: what method you have in your class: it looks at the header file. when it compiles, it wants to make sure that it references are included in the header file

using namespace std; // Defines the scope of the class 

// Declares the bankAccount.h class
class bankAccount {
public:
  bankAccount();                    // default constructor (A default constructor that will be called when a program creates a bankAccount object. This constructor should set the bankAccount balance to $0.00)
  
  bankAccount(double amount);       // constructor with a name parameter (A constructor that will be called when a program creates a bankAccount object with an initial balance) 
   
  ~bankAccount();                   // destructor (A destructor that will be called when an object is deleted from program memory. You must have this in your .h and .cpp file, but you can leave the implementation empty 

  double withdraw(double amount); // A method that withdraws the specified amount of money from your bank account. The method will return the new amount in the bank account after the withdraw goes through. If the withdraw amount is too high, don't withdraw any amount and return the current balance in the account. (Assume that amount >= 0) 
  
  double deposit(double amount); // A method that deposits the specified amount of money from your bank account. The method will return the new amount in the bank account after the deposit goes through. (Assume that amount >= 0)    

  double getBalance(); // A method that will return the balance currently in the bank account 
    
private:
  double balance; // A private variable that will hold the amount of money in the bank account 
};

#endif // Specifies the endif sign 
// At the end of your header file, you're supposed to have the end if sign



