/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: February 15, 2021 
   CS2150 Lab 1 In Lab TestLifeCycle.cpp
*/

#include <iostream> // Used for cin/cout 
#include <string> // Used when you have a variable of string type 
#include "LifeCycle.h" // Includes the header file for LifeCycle 

using namespace std; // Defines the scope of the class 

// This is the .cpp file that contains a main function()

// The main() method is NOT part of any class. It's a function and it must be global. 
int main () {
    cout << "--PART 1: Start of main--" << endl;
    cout << "--Defining o1, o2(\"Bob\")--" << endl;
    MyObject o1, o2("Bob");

    cout << "--Defining o3(o2)--" << endl;
    MyObject o3(o2);

    cout << "--Defining array of 3 objects--" << endl;
    MyObject array[3];

    cout << endl;

    cout << "--PART 2: call function using call-by-value, return int--" << endl;
    cmpMyObj(o1, o3);

    cout << "--call function using call-by-value, return MyObject--" << endl;
    getMaxMyObj(o1, o3);

    cout << endl;

    cout << "--PART 3:  o1: " << o1 << endl;
    {
        cout << "  --entering new block, define new o1(Sally)--" << endl;
        MyObject o1("Sally");
        o1.setName("Sally");
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;

        cout << "  --call swap function using call-by-reference--" << endl;
        swapMyObj(o1, o2);

        cout << "  --were their values swapped?--" << endl;
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;
        cout << "  --leaving new block--" << endl;
    }
    cout << "o1: " << o1 << endl;

    cout << endl;

    cout << "--PART 4: Define reference var: { MyObject& oref=o1; } --" << endl;
    {
        MyObject& oref=o1;
    }
    cout << "-- was anything constructed/destructed?--" << endl;

    cout << endl;

    cout << "--PART 5: new and delete--" << endl;
    cout << "--use new to create one object, then array of 2 objects--" << endl;
    MyObject *op1 = new MyObject, *op2 = new MyObject[2];

    cout << "--use delete to remove that one object--" << endl;
    delete op1;

    cout << "--use delete [] to remove that array of 2 objects --" << endl;
    delete[] op2;

    cout << endl;

    cout << "--LAST PART:  End of main--" << endl;
    return 0; // By convention, the main method returns 0 (You must ALWAYS return 0 from main()) (From Slide set 1: 4.6) 
}
