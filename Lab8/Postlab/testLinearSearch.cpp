/*Name: Steven Song 
  UVA ID: sqs5hrn  
  Date: April 14, 2021  
  CS2150 Lab 8 Post Lab testLinearSearch.cpp 
*/

// NOTE: The testLinearSearch.cpp file was downloaded from the PDR/source code for the Lab 8 Post Lab (didn't modify this file)

#include <iostream>
#include <cstring>
using namespace std;

extern "C" int linearSearch(int * arr, int size, int target);

int main(){

	int size;
	// prompt for array size
    cout << "Enter the array size: ";
	cin >> size;
	int * arr = new int[size];

	// read in array values
	for(int i = 0; i < size; i++) {
        cout << "Enter value " << i << ": ";
        cin >> arr[i];
    }

    int target;
    // prompt for target
    cout << "Enter target to search for: ";
    cin >> target;

    int ind = linearSearch(arr, size, target);

    if (ind > -1)
    	cout << "\nFound " << target << " at index " << ind << endl;
    else
    	cout << "\nDid not find " << target << endl;

    return 0;

}
