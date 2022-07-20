; Name: Steven Song 
; UVA ID: sqs5hrn 
; Date: April 18, 2021  
; CS2150 Lab 9 Pre Lab threexplusone.s

global threexplusone 		; We have to declare threexplusone as a global variable since threexplusone is the name of this file


section .text			; This file is where we write the assembly code for the Collatz Conjecture (x/2 = even, 3x+1 = odd) to count the number of steps it takes to get 1 as the output for f(x)
				 
threexplusone:
	push	rdx		; Pushes rdx onto the stack (rdx is the register that stores the remainder)
	xor 	rax, rax	; rax is just the return register that stores the number of steps/the step counter (Sets rax (number of steps) equal to 0 since this is the beginning of the program and it just started) 
	mov	rdx, 1		; Sets rdx (the remainder) equal to 1 at default to compare later on in the program; as each of the cases is being tested one at a time 

basecase:				
	cmp	rdi, 1		; Checks to see if rdi is equal to 1 (rdi is the first parameter) 
	je	endoffunction	; If it is, then jumps to the end function as the program is finished 
	and	rdx, rdi	; 'and' is the optimization that we're going to be using in this file to find the remainder
	cmp	rdx, 1		; If the remainder is equal to 1, then go to the oddnumbers function 
	je	oddnumberfunction ; If the oddnumbers function fails, then immediately jump to the even number function (If it fails to jump to odd, then it goes to even) 

; You have to have EVEN always before ODD because even is always checked first in the conjecture  
evennumberfunction:
	sar	rdi, 1		; Shifts rdi (the remainder) right by 1 to store the new result (Same as doing x/2 for the even function (from the PDR))
				; Sar is more efficient than idiv 
	
	call	threexplusone	; Recursively calls the threexplusone function in order to keep pushing new values onto the stack
	inc	rax 		; Increments the step counter by 1 each time we do a step to check if the number inputted into f(x) is even or odd and keeps doing that until we eventually get 1 as the output/result (rax is the register that stores the number of steps) 
	jmp	basecase	; Jumps to the base case function to compare after we reach the end of this function (same goes with the oddnumber function)
	
oddnumberfunction:
	mov	rdx, rdi	; Pushes rdi (remainder) onto rdx (the register that stores the remainder)

	lea     rdi, [rdx + 2*rdx + 1] ; 3x+1 for the odd function (from the PDR) 

	call	threexplusone	; Recursively calls the threexplusone function (same as in evennumbers)
	inc 	rax 		; Increments the new steps that were performed (just like in evennumbers) in order to achieve the Collatz conjecture. So that it prints out the number of steps 
	jmp	basecase	; Goes back to the base case to compare. Basically, it will keep comparing it until we've reached the final number of steps it takes to get 1. 
	
endoffunction:			; End of function
	pop	rdx		; Similar to Lab 8, we have to pop whatever we pushed onto the stack in reverse order
	ret			; Returns the number of steps required for the integer to return 1 by following the Collatz conjecture 

; Collatz conjecture in a nutshell: (the bottom is just pseudocode)
; The 1st parameter refers to the integer that is inserted/inputted into the function (rdi)
; The 2nd parameter refers to the integer that represents the remainder of the function calls (rdx)
; The 3rd parameter refers to the integer that represents the number of iterations in threexplusone (rax)  

; Example:

; threexplus takes in a positive integer and returns the number of steps required for that integer to reach 1 by following the Collatz conjecture. 

; Collatz Conjecture 
; f(x) = x/2 if x is even  
; f(x) = 3x+1 if x is odd 
	
; f(13) = 3(13) + 1 = 40
; f(40) = 40/2 = 20
; f(20) = 20/2 = 10
; f(10) = 10/2 = 5  
; ... f(2) = 1 so it took 9 steps to reach the value of 1 (won't be testing any values above 10^13) 
