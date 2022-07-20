/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 25, 2021   
   CS2150 Lab 3 Post Lab ListItr.cpp
*/

//NOTE: Everything in ListItr.cpp was copied over from the Lab 2 Pre Lab/Post Lab (didn't modify this file for the Lab 3 Post Lab) 
#include <iostream> // Necessary for any print statements 
#include "ListItr.h" // Must include the header file for ListItr in order to access all of its members and functions

//IMPORTANT: The reason why we don't have to include "List.h" or "ListNode.h" in this file (in order to access 'next' and 'previous') is because ListItr.h already included those header files for us so we don't have to include them again in the cpp file for the ListItr class

//The arrow just means to "follow the pointer" (the arrow operator is used to access members of a structure through a pointer)

using namespace std; // Defines the scope of the class 

// Constructors 
ListItr::ListItr() {
  current = NULL; // The private variable current is from ListItr.h
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode; // current is of ListNode* type (* means current is a pointer to ListNode) 
}

// Returns true if the iterator is currently pointing past the end position in the list (i.e. it's pointing to the dummy tail), else return false
bool ListItr::isPastEnd() const { // Basically the same process as the isPastBeginning method above, except the opposite (since it's asking for the end as opposed to the beginning) 
  if (current -> next == NULL) { // If the value of the "next" member of the ListNode object is equal to NULL, that means that you've reached the end of the list so you just return true
    return true; 
  }
  return false; 
}  

// Returns true if the iterator is currently pointing past (before) the first position in the list (i.e. it's pointing to the dummy head), else return false 
bool ListItr::isPastBeginning() const {
  if (current -> previous == NULL) { // Nothing exists outside of null 
    return true; // Same as isPastEnd() except you have current point to next instead of previous, and then if the value of the "previous" member of the ListNode object is equal to NULL, that means that you've reached the beginning of the list so you just return true  
  }
  return false; 
}

// Advances "current" to the next position in the list (unless already past the end of the list) 
void ListItr::moveForward() {
  if (isPastEnd()) { // If it's past the end, then don't move forward (either break or return)
    return; // Or just break 
  }
  current = current -> next; // Moves current forward by 1 position in the list 
}

// Moves "current" back to the previous position in the list (unless already past the beginning of the list) 
void ListItr::moveBackward() {
  if (isPastBeginning()) { // If it's past the beginning, then don't move backward (either break or return;)
    return; // Or just break 
  }
  current = current -> previous; // Moves current backwards by 1 position in the list 
}

// Returns the value of the item in the current position of the list 
int ListItr::retrieve() const {
  return current -> value; // You just retrieve the value of the ListNode object: you take current and point to its value 
}
