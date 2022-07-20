/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 25, 2021   
   CS2150 Lab 2 Post Lab ListNode.h 
*/

//NOTE: Everything in ListNode.h was copied over from the Pre Lab (didn't modify this file for the Post Lab) 

// ListNode.h was downloaded from the source code/PDR (didn't modify this file)

// A ListNode contains an integer value, as well as next and previous pointers to other ListNodes 

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std; // Defines the scope of the class 

class ListNode {
public:
    ListNode();         // Constructor

private:
    int value;          // The value of the node!
    ListNode* next;     // The next ListNode in the List
    ListNode* previous; // The previous ListNode in the list
    // (i.e. current -> next == NULL)
    // (i.e. current -> previous == NULL) 

    // List needs access to value, next, and previous
    friend class List;

    // ListItr needs access to value
    friend class ListItr;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.
};

#endif