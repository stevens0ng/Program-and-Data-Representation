/*
 * Filename: ListItr.h
 * Description: ListItr class definition
 */

/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 21, 2021  
   CS2150 Lab 2 Pre Lab ListItr.h
*/

// This file was downloaded from the source code/PDR (didn't modify this file)

// A ListItr maintains a pointer to a current position in a List to allow for easy traversal through the List 

#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    // Constructors
    ListItr();
    ListItr(ListNode* theNode);

    // Returns true if the iterator is currently pointing past the end position
    // in the list (i.e., it's pointing to the dummy tail), else false
    bool isPastEnd() const;

    // Returns true if the iterator is currently pointing past (before) the first position
    // in list (i.e., it's pointing to the dummy head), else false
    bool isPastBeginning() const;

    // Advances `current` to the next position in the list (unless already past the end of the list)
    void moveForward();

    // Moves `current` back to the previous position in the list (unless already past the beginning of the list)
    void moveBackward();

    // Returns the value of the item in the current position of the list
    int retrieve() const;

private:
    ListNode* current; // Holds the position in the list

    friend class List; // List class needs access to "current"
};

#endif
