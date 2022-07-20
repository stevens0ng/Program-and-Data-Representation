/*Name: Steven Song 
  UVA ID: sqs5hrn 
  Date: April 19, 2021  
  CS2150 Lab 9 In Lab linkedlist.c
*/

#include <stdio.h> // The <stdio.h> is where printf() and later scanf() live. These are the basic input and output routines in C, analogous to cout and cin in C++  
#include <ctype.h> // <ctypeh> declares a set of functions that classifies and transforms individual characters 
#include <stdlib.h> // <stdlib.h> is necessary in order to include malloc() which is the C version of "new" 
#include <string.h> // <string.h> is the header in the C library that is used to contain the constants and declarations of functions and types 

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

// NOTE: Everything above was provided to us already from the instructions for the Lab 9 In Lab in the repo 

// C does not have any classes, but it has structures. In this case, we want the variable type to be a node

// These are all variables that we declare in our linkedlist.c. Very similar to what we did in Labs 2 and 3

struct list_item { // This is the structure of the nodes in the linked list (list_item was provided to us in the PDR in the source code for linkedlist.c so I just called it list_item) 
  int linkedlistdata; // Basically the data variable keeps track of the value of the node that we're on
  struct list_item *next; // next pointer for all of the nodes in the list 
  struct list_item *previous; // previous pointer for all of the nodes in the list 
  // previous goes back an element in the list, next goes forward an element in the list   
};

struct officiallist { // This is the structure of the list 
  int sizeoflist; // The size of the list
  struct list_item *tail; // This is the dummy tail node for our linked list 
  // remove at head: remove an integer from the front of the linked list
  // remove at tail: remove an integer from the back of the linked list 
  struct list_item *head; // This is the dummy head node for our linked list 
  // insert at head: push an integer onto the front of the linked list 
  // insert at tail: push an integer onto the back of the linked list  
};

int main() {

  // TODO: INSTANTIATE YOUR LINKED LIST HERE.

  struct officiallist *listthatweuse = (struct officiallist *)malloc(sizeof(struct officiallist)); // We instantiate the linked list here. I called my list "listthatweuse"
  struct list_item *tailNode = (struct list_item *)malloc(sizeof(struct list_item)); // This will create a dummy node for tail 
  struct list_item *headNode = (struct list_item *)malloc(sizeof(struct list_item)); // This will create a dummy node for head 
   
  listthatweuse -> tail = tailNode; // I called the linked list's head and tail "headNode" and "tailNode" respectively 
  listthatweuse -> head = headNode; // Head/tail nodes (headNode and tailNode are both dummy nodes here)
  tailNode -> previous = headNode; // Goes back one element in the linked list: the tail's previous node is the head
  headNode -> next = tailNode; // Goes forward one element in the linked list: the head's next node is the tail 
	//----END----
	
	int option, value;
	printOptions();

	do {
	        option = readInput(&value); // This was already provided to us in the PDR
		struct list_item* node; // This was already provided to us in this file in the repo 
		struct list_item* temp; // NEWLY ADDED: The temp is used for printing out the list which you'll see in the PRINT_LIST case down below 

		switch(option){
			case PUSH_FRONT:
			// Pushes a node onto the front of the list
			// You don't need to do an if loop for the size of the list for PUSH FRONT or PUSH BACK since you're always going to be adding elements to the linkedlist 
			  
			// TODO: Insert code to push val onto front of linked list here.
			  // From Piazza: use struct list_item and malloc 
			  node = (struct list_item *)malloc(sizeof(struct list_item)); // You need to declare/set node equal to malloc to make space in order to insert the node onto the linked list (You do this to dynamically allocate the node using the malloc and you need to deallocatte it using free)
			  // FROM PIAZZA: whenever you malloc a list_item n, you'd simply say n -> value = <insert whatever value here> (hence the node -> linkedlistdata = value always has to come second) 
			  node -> linkedlistdata = value; // Sets what we have in the linkedlistdata for the node to value 
			  node -> previous = headNode; // This is the new node that we're inserting: head function is the dummy node: you shouldn't set your new node next to the head. (it exists before your dummy node, but it should exist after the dummy node)
			  // The new node's previous pointer is the head or what I called "headfunction" in this file 
			  node -> next = headNode -> next; // Naturally, that would mean that the new node's next pointer is equal to the head's next pointer 

			  headNode -> next -> previous = node; // The previous pointer for the next node is the new node that we're going to be pushing onto the front of our list 
			  headNode -> next = node; // The next pointer for head is the new node that we want to push onto the front of our list 

// THIS IS WHAT WE NEED TO ADD TO THE IN LAB THAT'S NECESSARY FOR THE HIDDEN TEST CASES 
			  listthatweuse -> sizeoflist++; // You need to increment the size of the list at the end of PUSH_FRONT since you're pushing an element into the list
				//----END----
				break;
			case PUSH_BACK:
			// Pushes a node onto the back of the list
			  
			// TODO: Insert code to push value onto the back of linked list here.
			  node = (struct list_item *)malloc(sizeof(struct list_item)); // Similar to PUSH_FRONT, we have to use malloc for the node here in order to create space so that it can get added on to the back of the linked list (We have to dynamically allocatte it)  
			  node -> linkedlistdata = value; // Like above in PUSH_FRONT, we have to set the data in the node equal to the value of that node  
			  node -> next = tailNode; // Since we're pushing/adding to the back of the linked list now, the next pointer for the new node is going to be the tail (we basically reverse the order of what we did in this line from PUSH_FRONT)  
			  node -> previous = tailNode -> previous; // The previous pointer of the new node that we're pushing to the back of the linked list is now equal to the head's previous pointer
			  // Opposite of PUSH_FRONT (everything here is flipped from PUSH_FRONT and you're using tailNode instead of the headNode) 
			  tailNode -> previous -> next = node; // As such, we set the new node equal to the previous node's next pointer 
			  tailNode -> previous = node; // The new node is essentially equal to the tail's previous pointer (it's basically the opposite of what we did in PUSH_FRONT)

// THIS IS WHAT WE ADDED TO THE IN LAB THAT'S NECESSARY FOR THE HIDDEN TEST CASES 
			  listthatweuse -> sizeoflist++; // You need to increment the size of the linked list at the end of PUSH_BACK since you're pushing an element into the list
				//----END----
				break;
				
			case POP_FRONT:
			// remove from front of list
			// TODO: Insert code to remove from front of linked list here.

			  // If list is empty, do nothing
			  if(listthatweuse -> sizeoflist == 0) { // If the size of the linked list is equal to 0, then break (don't do anything to it: it immediately stops POP_FRONT right here)
			    break; 
			  }
			  // remove from front of linked list
			  // TODO: Insert code to remove from front of linked list here.
			  node = headNode -> next; // Since we're doing POP_FRONT Here, the new node that we're trying to remove from the linked list is the head's next pointer
			  headNode -> next = node -> next; // The node that we're trying to remove's next pointer is equal to the head's next pointer 
			  node -> next -> previous = headNode; // The next node's previous pointer is head 
			  free(node); // We have to deallocate the node at the end of our POP_FRONT method/case. Don't need to do free in PUSH_FRONT or PUSH_BACK
			  
// THIS IS WHAT WE ADDED TO THE IN LAB THAT'S NECESSARY FOR THE HIDDEN TEST CASES
			  listthatweuse -> sizeoflist--; // You need to decrement the size of the list at the end of POP_FRONT since you're popping an element off the list
			  
			  // remove at tail (double linked list) 
			  // remove method at a linked list now (remove first element)
				//----END----
				break;
				
			case POP_BACK:
			// remove from back of list
			// TODO: Insert code to remove from back of linked list here. 
			  
			  // If list is empty, do nothing
			  if(listthatweuse -> sizeoflist == 0) { // If the size of the list is equal to 0, break (don't do anything to it: it immediately stops POP_BACK right here)
			    break; 
			  }
			  // remove from back of list
			  // TODO: Insert code to remove from back of linked list here.
			  node = tailNode -> previous; // Same idea as POP_FRONT, except now the node that we're trying to remove is the tail's previous pointer (since we're removing from the back of our linked list) 
			  tailNode -> previous = node -> previous; // As such, the tail's previous pointer is set to the node's previous pointer 
			  node -> previous -> next = tailNode; // The previous node's next pointer is equal to/set to the tail  
			  free(node); // Similar to what we did in POP_FRONT, we have to deallocate the node/delete the node since we dynamically alloccated it (since we did malloc in push, we have to do free in the pop to dynamically deallocate it) 

// THIS IS WHAT WE ADDED TO THE IN LAB THAT'S NECESSARY FOR THE HIDDEN TEST CASES
			  listthatweuse -> sizeoflist--; // You need to decrement the size of the list at the end of POP_BACK since you're popping an element off the list
			  
			  // remove the last element in the list 
				//----END----
				break;
			/*
		        isPastEnd:
			  if (node -> next == NULL) {
			    return true;
			  }
		    	  return false;

		        moveForward:
			   if(isPastEnd()) {
			     return;
			   }
			   node = node -> next;

		        retrieve: 
			  return node -> value;
			*/
			      
			case PRINT_LIST:				// print list
			// TODO: Insert code to print list forwards here.
			// Simply print each element separated by a space as shown below:
			// Elements: 1 2 3 4 5

			// Print forward: prints the elements in forward order, delimited by a space 
			  printf("Elements: "); // This was given to us in the instructions

// Print out each element so you have to iterate through the list and printing out each element(OR you can just recurse through the list)
			  
			  temp = listthatweuse -> head -> next; // This will set temp equal to the first element in the list

// While the temp that we're on hasn't reached the end of the linked list yet (hasn't reached the last element in the linked list yet) print out each element and move forward in the list  
			  while (temp -> next != NULL) { // Checks to make sure that the first element isn't past the end of the list. As long as it's not past the end of the list, it should print out each element starting from the first one  
			    printf("%d", temp -> linkedlistdata); // prints out each and every element in the list starting from the first one 
			    printf(" "); // In order to separate the numbers by a space when you print them out 
			    // free(temp); free will free up the memory deallocates the memory of temp  (you no longer have access to it) in pop you need to free memory (WE DON'T NEED TO DO THIS FOR THE PRINT LIST) 
			    temp = temp -> next; // In order to move forward in the linked list to the next element, we need to set the pointer of temp to next in order to move onto the next element in the list one by one (similar to iterator.moveForward() in Lab 2). That way we can print out every element in the linked list in forward order. 
    		          }
			  printf("\n"); // We need printf("/n") at the end of our print list method in order to print out a new line because if we don't do that, then it will print out all the elements on the same line with no spaces (i.e. "Enter command" will be on the same line as "Elements") 

			  // Pseudocode that I used to help me understand the print list method/case 
			  
			  /*while (listthatweuse.head->next.isPastEnd() != TRUE) {
			       printf(listthatweuse.head->next.retrieve());
			       listthatweuse.head->next.moveForward(); 
			  */
			  
			
			  
			  /*void printList(List& source) {
			     ListItr iter = source.first(); (linkedlist.head -> next) 
			     while (source.first.isPastEnd() != TRUE) {
			        printf(iter.retrieve());
			        iter.moveForward();
			     }
			  }
			  */

			  /*
			  bool ListItr:: isPastEnd() const {
			    if (node -> next == NULL) {
			       return true;
			    }
		    	    return false;
		          } 
		          */

		          /* void ListItr::moveForward() {
			       if(isPastEnd()) {
			         return;
			      }
			      node = node -> next;
			     }   
			  */

			  /* int ListItr:: retrieve() const {
			        return node -> value; 
			  */ 
				//----END----
				break;
			case HELP: 						// print menu
				printOptions();
				break;
			case QUIT: 						// quit
				break;
			case INVALID: 					// bad input
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
				break;
		}

	} while(option != QUIT);

	// TODO: free any memory used by your linked list here
	 free(listthatweuse); // We have to dynamically deallocate the linked list that we used in our file, the head, and the tail
	 free(tailNode); // The order for tailNode and headNode don't matter here
         free(headNode);
	//----END----

	 return 0; // We have to return 0 at the end of this for insurance 
}

//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");
	
	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1;
}
