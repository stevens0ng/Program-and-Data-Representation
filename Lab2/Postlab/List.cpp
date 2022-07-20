/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 25, 2021  
   CS2150 Lab 2 Post Lab List.cpp
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

// Post Lab: A memory leak occurs when you forget to deallocate some memory that you dynamically allocatted earlier, which causes your program to hold onto that memory forever until it exits

// A memory allocation occurs when your code attempts to access some memory address that it DOES NOT have access to. For example: attempting to read or write to a previously deleted pointer. C++ will blindly dereference a pointer WITHOUT checking for its validity. 

List::List() { // What does a list have: list nodes. 
  head = new ListNode(); // Use the notation for pointers to assign the head to be equal to your tail
  tail = new ListNode(); // empty list: what would the pointers point to
  head -> next = tail; 
  tail -> previous = head; 
  count = 0; // a brand new list: dummy head/tail
  // what values do list nodes have in the constructor when I create them
}

// NOTE: The next two constructors (the copy and the copy assignment operator) were copied over from the PDR. (They were provided to us in the lab instructions) 

// Copy constructor
List::List(const List& source) { // Called when the code looks something like List list2 = list1; (In other words, it is called when you are trying to construct a **new** list from an existing one)
  head = new ListNode(); // Creates a new ListNode for the head and the tail
  tail = new ListNode();
  head -> next = tail;
  tail -> previous = head;
  count = 0;
  
  // This is the only part that we have to add to this constructor (since it's a copy constructor) 
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
       ListItr iter(source.head->next);
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
  delete head; // Calling the makeEmpty() method deletes everything except the dummy node
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
// sanitzer test!!! must update/change what you did in the Pre-Lab for the makeEmpty() method to account for memory leaks 

void List::makeEmpty() {
  ListItr firstelement = first();
  while (!firstelement.isPastEnd()) { // If the first element is not past the end of the linked list, then you have to loop through it and delete nodes one by one starting from the first element
    ListNode *n = firstelement.current; // We already have the List Node here, we're saving it (This line is not allocating memory). Sets the position of the List Node n to be equal to the position of the first element in the List
    // n = firstelement.current; // what we did last time in the makeEmpty() method      
    // iterate through the list (current is a pointer to a List Node)
    // remove(firstelement.current -> value); // it should adjust the pointer
    // Since n is a pointer, you have to do n -> remove instead of n.remove()
    // we don't have the remove method in ListNode (it's a method in the List class)
     
    // remove takes care of the deallocation
    // after you remove it, you need to set up the next iteration in the makeEmpty while loop
    // reassign our list iterator to the value we saved: then, we don't need to call move forward
    firstelement.moveForward(); // Moves forward in the linked list. Once you reach the end, then you back out of the while loop. You don't need to moveforward if you're not using a ListItr
    delete n; // Delete every ListNode that's in the linked list as you iterate through the linked list
  } // (Inside the while loop you're already deleting, and not instantiating it)
  head -> next = tail; // Sets the head and the tail to its respective values
  tail -> previous = head;
  count = 0; // same as the constructor
}

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first() {
  return ListItr(head -> next); // All you have to do is to point to the next node after head  
} // Head is the first ListNode in the list 

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last() { // Same as first() except you do tail instead of head and previous instead of next for the pointers in the ListItr object 
  return ListItr(tail -> previous); // Tail is the last ListNode in the list 
}

// The Post Lab requires you to finish the insertAfter and the insertBefore methods
// Inserts x after current iterator position 
void List::insertAfter(int x, ListItr position) { // insert after is almost the same as insert before except you have to switch the order of next and previous
  ListNode *n = new ListNode(); // creating a new node (the * is the pointer which will allow you to add the nodes to the linked list) 
  n -> value = x; // no matter what value you insert into your linked list, it will always be 0, hence why you have to set value = x (the default value is equal to 0) 
  position.current -> next -> previous = n; // you have to set the pointer equal to n in order to keep track of the position of the node in the linked list point to next then previous  
  n -> next = position.current -> next; // whatever is before n (the list iterator) is what it is currently before it (hence why you point posititon to next) the pointer of position.current  adds next 
  position.current -> next = n; // the list iterator node points to the new node (n). The next pointer of the new node is position.current
  n -> previous = position.current; // you have to make the previous node at that spot the previous position
  // whatever your new node is, the next pointer is the one you're on
  count++; // count is the number of List nodes you have so you have to increment count at the end 
} 

// Inserts x before current iterator position 
void List::insertBefore(int x, ListItr position) {
  ListNode *n = new ListNode(); // creating a new node (the * is the pointer which will allow you to add the nodes to the linked list) 
  n -> value = x; // no matter what value you insert into your linked list, it will always be 0, hence why you have to set value = x (the default value is equal to 0) 
  position.current -> previous -> next = n; // You have to set the pointer equal to n in order to keep track of the position of the node in the linked list point to previous then next,

  // Ex. If we have the List Nodes 12, 37, 99, and we want to insert a number 20 before the current position 37, then we have to go to the previous of 37, which is 12, and then insert a new node to the right of 12 which is equal to the List Node n that we created above, and then we have to insert n to the right of 12 so that the ListNode to the right of 12 is equal to 20 instead of 37. 
  
  n -> previous = position.current -> previous; // Whatever is before n (the list iterator) is what it is currently before it (hence why you point posititon to previous) the position.current adds next

  // Ex. We have to cover all bases here: If we do the previous of 20, which is 12, we have to set that equal to the position of the ListNode that we're on right now, which is 37 and set that to the previous pointer of that, which is 12. Hence, the new node that we inserted: 20, the previous/left of that is 12, as it should be
  
  position.current -> previous = n; // the list iterator node points to the new node (n). The previous pointer of the new node is position.current

  // In the example: 12, 37, 99, where we're trying to insert 20 in between 12 and 37 so that it's 12, 20, 37, 99, the position that we're on right now is 37 so the previous of that is 20 instead of 12 so we have to set that equal to n 
  
  n -> next = position.current; // The next of 20 is 37, which is in fact the position that we're on right now 
  // whatever your new node is, the next pointer is the one you're on
  count++; // count is the number of nodes you have so you have to increment count at the end
} 

// Inserting at the end (tail)
void List::insertAtTail(int x) { // x is a value 
  ListNode *n = new ListNode(); // Creating a new node
  n -> value = x; // The value of the ListNode n is obviously equal to x 
  n -> next = tail; // The ListNode after n (next) is equal to tail (also a ListNode)
  n -> previous = tail -> previous; // The ListNode before n (previous) is equal to the ListNode before tail (also previous) since you're trying to insert n in the tail  

  tail -> previous -> next = n; // You're inserting tail into n so you have to set it equal to n
  tail -> previous = n; // The ListNode before the tail (previous) is equal to n 
  count++; // Since you inserted a node at the tail in the list, you have to increment the count since count is the number of ListNodes in the list  
}

// Returns an iterator that points to the first occurrence of x
ListItr List::find(int x) {
  ListItr iter (head -> next); // ListItr has constructor that takes in a ListNode object 
  while (iter.retrieve() != x && !(iter.isPastEnd())) { // If you haven't found x yet, then you have to keep iterating through the iter by moving forward  
    iter.moveForward(); // If you're not able to retrieve x, then keep searching for iter (As the instructions state, you can test the return from find() to see if isPastEnd() is true)
  }
  // If you're able to get out of the while loop, then that means that you've found a ListNode in the list that has value = x 
  if (iter.current == NULL) { // Edge case for finding an element that's not in the list 
    iter.current = tail; // You've iterated through the whole linked list and don't find it. If it's not there, then it will keep iterating to the tail.
  // The tail is the second dummy node that represents the end of the list so set the position of current equal to tail to signify that you've reached the end of the list 
  }
  return iter; 
} // If you're just trying to find x, then you don't need the count   

// sanitizer: not deleting certain things that were dynamically allocated
// Remove takes in an integer rather than a ListItr, we first need to determine whether or not that integer exists in our list
void List::remove(int x) { // Removes the first occurence of x 
  if (isEmpty() == true) { // If there are no List Node elements in the List, then there's nothing to remove from the List, so you just break or return; This is the edge case for removing an element from an empty list
    // cout << "List is already empty " << endl; 
    return;
  }
  
  ListItr iter = find(x); // Gets a list iterator at a certain integer value (if x is not in the list, if it can't find x, then it should return something that's not in the list) 
  // current is the position of the ListNode in the List
  if (iter.isPastEnd()) { // This is the edge case for removing an element that's NOT in the list (i.e. trying to remove 6 from the list 13, 14, 15) (6 is not in the list so you can't remove 6 from the list) 
    // cout << x << " is not found in the list " << endl;
    return; // terminates the program 
  }
  iter.current -> previous -> next = iter.current -> next; // new iterator's next
  // next is a list node (when you remove the node, the node's previous next pointer will have to point to the one that's deleted)

  // 2nd to last node that exists: last node that exists is tail and it doesn't have anything
  
  iter.current -> next -> previous = iter.current -> previous;
  // You're setting the (keyword) next ListNode's previous element to be the List Node you're on right now's previous element, rather than the List Node you're on right now.
  // flip previous and next (you're changing the pointers, not the nodes)
  
  // Ex. 12 -> 37 -> 99. If we want to remove 37, then we do 37's next which is 99, then set the previous of 99 to be equal to 12 instead of 37. Hence why we do the previous of 37 which is 12 so it works. (when we remove 37, the previous of 99 is equal to 12 instead of 37 like it was before). 
  
  delete iter.current; // Nothing's pointing to iter.current so you have to delete it
  count--; // You have to decrement one count to keep track of the node you deleted 
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
  else { // Prints out the list backwards (it's just the same algorithm as forward except everything's the opposite (i.e. instead of doing source.first(), you do source.last(), etc.)
    ListItr iter (source.last()); // Starts at the last element in the address of List
    while (!iter.isPastBeginning()) {
      cout << iter.retrieve() << " "; // Starts the next print on a new line
      iter.moveBackward();
    }
  }
  cout << endl;
}
