/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 21, 2021  
   CS2150 Lab 2 Pre Lab List.cpp
*/

#include <iostream> // Necessary for printing out user inputs/outputs 
// As always, we have to include the relevant header files in order for our cpp files to work properly (List.h, ListNode.h, and ListItr.h in order to access the ListNode constructor, as well as its methods) 
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std; // Defines the scope of the class

// The arrow just means to "follow the pointer" (the arrow operator is used to access members of a structure through a pointer

// The List class represents the list data structure containing ListNodes. It has a pointer to the first (head) and last (tail) ListNodes of the list, as well as a count of the number of ListNodes in the list.  

// A ListNode contains an integer value, as well as next and previous pointers to other ListNodes

// A ListItr maintains a pointer to a current position in a List to allow for easy traversal through the List 

// List constructor (almost the same as the beginning part of the copy constructor) 
List::List() { // What does a list have: list nodes. 
  head = new ListNode(); // Use the notation for pointers to assign the head to be equal to your tail
  tail = new ListNode(); // Empty list: what would the pointers point to
  head -> next = tail; // By definition, the tail is the next node after the head, so when head points to next, the value of the 'next' node equal to tail 
  tail -> previous = head; // The same logic applies for tail: the head is the node that comes directly before tail. So when tail points to previous, the value of the 'previous' node is equal to tail
  count = 0; // A brand new list: dummy head/tail
  // What values do list nodes have in the constructor when I create them
}

// NOTE: The next two constructors (the copy and the copy assignment operator) were copied over from the PDR. (They were provided to us in the lab instructions) 
// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) { 
  head = new ListNode(); // Creates a new ListNode for the head and the tail
  tail = new ListNode();
  head -> next = tail;
  tail -> previous = head;
  count = 0;

  // Make a deep copy of the list
  ListItr iter(source.head -> next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
  if (this == &source) { // The two are the same list; no need to do anything
    return *this; // This just means to evaluate the object to which the pointer points (in this case, it returns whatever value is stored in this) 
  } else {
    // Clear out anything this list contained
    // before copying over the items from the other list
      makeEmpty();
	 
      // Make a deep copy of the list
      ListItr iter(source.head -> next);
      while (!iter.isPastEnd()) {
	insertAtTail(iter.retrieve()); // retrieves the value at the tail position 
	iter.moveForward();
      }
  }
  return *this;
}

// Destructor
List:: ~List() { // The Destructor should delete all dynamically-allocated memory (i.e. all of the elements in the List) 
  makeEmpty(); // Must call makeEmpty() in order to delete all of the ListNodes in order to ensure that our file doesn't have any memory leaks
  delete head; // Calling the makeEmpty() method deletes everything except the dummy nodes
  delete tail; // The dummy nodes are separately deleted: (in a double linked list, we have dummy nodes: head, tail) (Everytime you dynamically allocate something with new, it must be deallocated with delete)  
}

// Returns true if empty, else returns false 
bool List::isEmpty() const {
  if (count == 0) { // If the the number of elements in the list is equal to 0, then return true; otherwise return false
    return true;
  }
  return false; 
} 

// makeEmpty should clear the list of all elements. It should also make sure that head and tail no longer point to those deleted elements. 
void List::makeEmpty() {
  ListItr firstelement = first(); // A ListItr object contains a ListNode parameter 
  ListNode *n = new ListNode(); // Dynamically allocating the ListNode 
  while (!firstelement.isPastEnd()) { // While the first element in the linked list has not reached the end of the list, loop through the list and delete all of the elements 
    n = firstelement.current; // Sets the position of the ListNode n to be equal to the position of the first element  
    firstelement.moveForward(); // Moves forward in the linked list. Once you reach the end, then you back out of the while loop 
    delete n; // Delete every ListNode that's in the linked list as you iterate through the linked list 
  }
  // This is the second part of the makeEmpty method that we have to implement 
  head -> next = tail; // Sets the head and the tail (when you delete the entire list, head and tail should only point towards each other) 
  tail -> previous = head;
  count = 0; // Same as the constructor, since the list now has 0 elements in it 
}

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first() {
  return ListItr(head -> next); // All you have to do is to point to the next node after head 
} // Head is the first ListNode in the list 

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last() { // Same as first() except you do tail instead of head and previous instead of next for the pointers in the ListItr object 
  return ListItr(tail -> previous); // Tail is the last ListNode in the list 
}

// The Pre Lab doesn't require students to finish the insertAfter and insertBefore methods so I just left these two methods blank for now

void List::insertAfter(int x, ListItr position) { // Inserts x after the current iterator position
   
} 

void List::insertBefore(int x, ListItr position) { // current holds the position in the List for the ListNode 
  
} 

// Inserting at the end (tail) 
void List::insertAtTail(int x) { // x is a value 
  ListNode *n = new ListNode(); // Creating a new node
  n -> value = x; // Sets the value of the node equal to x 
  n -> next = tail; 
  n -> previous = tail -> previous;

  tail -> previous -> next = n; // You're inserting tail into n so you have to set it equal to n
  tail -> previous = n;
  count++; // Since you inserted a node at the tail, you have to increment the count
}

// Returns an iterator that points to the first occurrence of x
ListItr List::find(int x) { 
  // Uses the data structure that you made in another file to find something
  ListItr iter (head -> next);
  while (iter.retrieve() != x && !(iter.isPastEnd())) { // If you haven't found x yet, then you have to keep iterating through the iter by moving forward 
    iter.moveForward(); // If you're not able to retrieve x, then keep searching for iter (As the instructions state, you can test the return from find() to see if isPastEnd() is true) 
  }
  if (iter.current == NULL) {
    iter.current = tail; // you've iterated through the whole linked list and don't find it. If it's not there, then it will keep iterating to the tail.
    // The tail is the second dummy node and it points to NULL
  }
  return iter; 
}  // If you're just trying to find x, then you don't need the count. 

// sanitizer: not deleting certain things that were dynamically allocated
// Must revise this method (As remove takes in an integer rather than a ListItr, we first need to determine whether or not that integer exists in our list)

// Similar to the insertAfter and insertBefore methods, the Pre Lab doesn't require you to finish the remove method so I just left it blank for now. 
void List::remove(int x) {
  /* ListItr iter = find(x);
   if(iter.current == NULL) {
     cout << Number not found in the list" << endl;
     return;
   }
   // Ex. try removing 20 from the list 13, 20, 37, 60 
   iter.current -> previous -> next  = iter.current -> next; // The next element of 13 is going to be 37 instead of 20 (since you're deleting 20 from the list) 
   iter.current -> next -> previous = iter.current -> previous; // Likewise, the previous element of 37 is going to be 13 instead of 20 (since you're deleting 20 from the list)   
   delete iter.current;
   count--; 
  */
} // count is the number of elements in the list so you have to decrement count by 1 whenever you remove/delete x from the list

// Returns the number of elements in the list
int List::size() const {  
  return count;
}

// printList is a non-member function which means that it doesn't have access to any private variables 
void printList(List& source, bool forward) { // NOT A MEMBER/METHOD OF THE LIST CLASS
  if (forward == true) { // Prints out the list forwards 
    ListItr iter (source.first()); // initializes head/next
    // print list: use your ListItr class
    // next/previous are private so you can't access them
    while (!iter.isPastEnd()) {
      cout << iter.retrieve() << " "; // Starts the next print on a new line
      iter.moveForward(); // Prints out all of the elements in forward/chronological order 
    }
  }
  else { // Prints out the list backwards (it's just the same algorithm as forward except everything's the opposite (i.e. instead of doing source.first(), you do source.last(), instead of moving forward, you move backwards, etc) 
    ListItr iter (source.last()); // Starts at the last element in the address of List 
    while (!iter.isPastBeginning()) {
      cout << iter.retrieve() << " "; // Starts the next print on a new line
      iter.moveBackward();
    }
  }
  cout << endl;
}
