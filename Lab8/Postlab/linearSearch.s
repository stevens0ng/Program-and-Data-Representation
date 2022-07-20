; Name: Steven Song 
; UVA ID: sqs5hrn 
; Date: April 14, 2021   
; CS2150 Lab 8 Post Lab linearSearch.s 

global linearSearch

section .text

; From the PDR: This function will scan through an array from left to right iteratively until it finds the target element or reaches the end of the array
; The function takes in 3 parameters: 
; Parameter 1 is a pointer to the int array (rdi)
; Parameter 2 is the size of the integer array (rsi) (Since we increment r8 by one each time we don't find the target. If we don't find the target, then r8 just becames the same as rsi and then you jump to the end saying that you didn't find it)
; Parameter 3 is the integer value that represents the target element to be found in the array (edx) (The first occurrence of the target) 
	
linearSearch:
   xor   rax, rax		; This sets the return register to zero (alternatively you could've done it where you had mov rax, 0 because you're resetting the register to print it back) but you set the return register to zero so that you can increment it each time you search through an element in the array until you found that value that you're looking for 
   xor   r8, r8      		; This sets the value of the register r8 to 0 (r8 is the index) 
	
linearsearchloop:	
   cmp   rsi, r8		; This compares the value of rsi and the value of r8 (if rsi equals r8 then it's unsuccessful because you incremented r8 every single time you didn't find the value (eventually r8 is equal to the length of the array which means it's unsuccessful)
   je    unsuccessfulloop 	; If the value is not found in the array, then go/jump to the unsuccessfulloop label and return -1  
	
   cmp   edx, [rdi+4*r8]  	; Compares the edx (the 32 bit register with the rdx) with rdi+4*r8 since all of the rbits are 64 bits and all the ebits are 32 bits (integers are 32 bits) 
   je    successfulloop		; Jumps to the successfullooplabel. If the value that's there at index rdi+4*r8 is equal to the index at edx (your target) then you're finished with the loop since you successfully found the value in the array through linearSearch. (Similar to the formula given in the PDR: &a[i] = &a + <size_of_elements>*i where <sizeofelements> = 4 since integers have 4 bytes and &a = rdi)   
   inc 	 r8      		; This increments r8 by 1 in order to look for the next value in the array
	
   jmp   linearsearchloop	; Restarts the loop (loops through it) again to search for the value in case it still hasn't been found yet
	
unsuccessfulloop:
   mov   rax, -1		; If the value was not found, then you set rax equal to -1 and then you return -1 since it finishes the loop (Since you didn't find the value) 
   ret

successfulloop:
   mov   rax, r8     		; Sets rax equal to the value that was found and then returns it and then you're done. (Returns the index in the array that contains the value)
   ret				; The return type of this function is int, and will be the index into the array that the target was found

; PSEUDOCODE
; Start from the leftmost element of the array and compare the value with each element in the array one by one 
; If the value matches the element in the array, then it returns the index of that value in the array
; If the value doesn't match any of the elements in the array, then it returns -1 
