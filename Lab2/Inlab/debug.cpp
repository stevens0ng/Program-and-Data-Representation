/* Name: Steven Song  
   UVA ID: sqs5hrn 
   Date: February 22, 2021  
   CS2150 Lab 2 In Lab debug.cpp 
*/

//----------------------------------------------------------------------
// This program reads five numbers from the keyboard, and prints out the
// average and the maximum value
//----------------------------------------------------------------------

#include <iostream> // Necessary for cin/cout 
using namespace std; // Defines scope of the class 

// Global Constants
const int MAX = 5;

// Function Prototypes
double GetAverage( int nIn[], int nMax);
int GetMax( int nIn[], int nMax );

int main() {

    int nValues[MAX];
    int nCount;

    // Display a prompt:
    cout << "Enter five numbers: " << endl;

    // First we read in the numbers.
    for ( nCount = 0; nCount < MAX; nCount++ ) {
        cout << "Enter the next number : "; // Switched the order of these two lines
        cin >> nValues[nCount]; // Should say nCount inside the array brackets instead of 1 since we want to keep track of each value in the array when we're printing out the user input for the numbers         
    } // cin is taking in an input, 

    // Now we echo the input back to the user
    for ( nCount = 0; nCount < MAX; nCount++) { // Should say 1 instead of 0 in the for loop so that it starts from the first index, and not the second. 
      cout << "Value [ " << nCount << "] is : " << nValues[nCount] << endl; 
    }

    // Now lets call a function to get the average:
    cout << "The average is " << GetAverage(nValues, MAX ) << endl;

    // Now lets call a function to get the max:
    cout << "The max is " << GetMax(nValues, MAX ) << endl;

    return 0; // You always have to include a return 0 at the end of the main method 

} // End of main


double GetAverage(int nIn[], int nMax) { // nMax is the size of the array 
  
    double temp = 0.0;
    for ( int i = 0; i < nMax; i++) // Should say < than nMax instead of > than nMax
      temp += nIn[i];
    
    temp/= nMax;

    return temp;
} // End of GetAverage()


int GetMax( int nIn[], int nMax) {
    int nBiggest = nIn[0];
    for ( int i = 0; i < nMax; i++) // Should say i = 0 instead of i = 1 when we're trying to find the max value (we want to loop through every element in the array so we have to start from the first index) 
      if (nIn[i] > nBiggest) // Should say (if nIn[i] > nBiggest) instead of if (nBiggest > nIn[i]) 
	nBiggest = nIn[i]; // submit the correct/modified version for debug.cpp 
    return nBiggest;
} // End of GetMax()

//----------------------------------------------------------------------
// END OF LISTING
//----------------------------------------------------------------------
