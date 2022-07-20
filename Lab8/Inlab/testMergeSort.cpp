/* Name: Steven Song  
   UVA ID: sqs5hrn   
   Date: April 12, 2021  
   CS2150 Lab 8 In Lab testMergeSort.cpp 
   Spring 2021   
   Test file for mergeSort
*/

// NOTE: The testMergeSort.cpp file was downloaded from the PDR/source code for the Lab 8 In Lab (didn't modify this file)

#include <iostream>
using namespace std;

extern "C" void mergeSort(int * arr, int left, int right);
extern "C" void merge(int * arr, int left, int mid, int right);

int main() {

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

    // print unsorted array
    cout << "Unsorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, size-1);

    // print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}
