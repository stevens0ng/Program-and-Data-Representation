/* Name: Steven Song
   UVA ID: sqs5hrn 
   Date: February 25, 2021  
   CS2150 Lab 2 Post Lab ListNode.cpp
*/

//NOTE: Everything in ListNode.cpp was copied over from the Pre Lab (didn't modify this file for the Post Lab)

// A ListNode contains an integer value, as well as next and previous pointers to other ListNodes 

#include <iostream>
#include "ListNode.h"

using namespace std; // Defines the scope of the class 

// The only thing that we have to include in the ListNode class is the constructor

ListNode::ListNode() { // Set next and previous equal to NULL and the value of the ListNode equal to 0 by default as the instructions state
  value = 0; // Just like in Slide Set 1, 10.3
  next = NULL;
  previous = NULL;
}

// Each ListNode points to the nodes before and after it (although the dummy nodes each have one pointer pointing to NULL) 