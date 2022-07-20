; Name: Steven Song 
; UVA ID: sqs5hrn 
; Date: April 21, 2021   
; CS2150 Lab 9 Post Lab binarySearch.s

global binarySearch

section .text

; Parameter 1 is a pointer to the array (rdi)
; Parameter 2 is an integer representing the beginning of the array (rsi)
; Parameter 3 is an integer representing the end of the array (rdx)
; Parameter 4 is an integer representing the target element to find in the array (rcx) (ecx for 32 bit registers)  
; edx: 32-bit version for parameter 4 (We use edx in binarySearch.s file since we're returning an int) 
; rdx: 64 bit version for parameter 4 
; The return type of this function is int and will be the index into the array that the target was found, or -1 if the target was NOT found.
; The array is of type int obviously
	
; Basically the way binarySearch works is that it begins in the middle of a sorted array and continuously splits the search space in half until it finds the target element or reaches a point where it knows the target is NOT in the array.

; Begin with an interval covering the whole array. If the value of the search key is LESS than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty. 
	
binarySearch:
	xor rax, rax		; We have to empty out the return register (set it to 0 as all of the values are passed in for us already)
	
; left is the first half of the array, right is the second half of the array
	
binarysearchloop:		; r8 is the address. Because you're doing a binary search 
	cmp rdx, rsi 		; If the end of the array is smaller than the beginning of the array, then that means that the array is not sorted so we jump to the end of the loop since we can't perform binary search on an unsorted array 
	jl targetnotfound       ; Jumps to the end of the loop if the array isn't sorted or if the right element is miraculously less than the left element in the array 
	
	mov r8, rsi		; This allows you to put the element of left (rsi) into r8 (Result: rsi) 
	add r8, rdx		; This allows you to add the value of the right (rdx) into r8 (Result: rsi + rdi) 

	shr r8, 1	        ; The middle element is equal to r8 divided by 2. This is how we get the middle element in our array through assembly (middle = r8/2) (Result: (rsi + rdi)/2)
	
	cmp [rdi + 4*r8], ecx   ; r8 is the address, ecx is the target. This compares the target to the value at the index of r8 of the array. (you're basically taking the array and you're going to the address r8 and you're getting the value from it). You're comparing the value in the middle element to your target (ONLY ecx works) (array[middle] == target)  
	je endofprogram	        ; je means jumps if equal so this means that you found the value of target and you jump to the end of your program where you return that value which means that you're done (you successfully found the target value in binarySearch)   
	jl targetgreaterthan    ; If target > middle element (compares the middle element to target) (middle < target here) (if it's greater than target, then you have to look at the upper/top half of the array) (array[middle] > target)
	jg targetlessthan  	; If target < middle element (compares the middle element to target (middle > target here) (if it's less than target, then you have to look at the lower/bottom half of the array) (array[middle] < target) 
	jmp targetnotfound      ; If you never found the target in the array, then you jump to the end of the loop (I titled mine targetnotfound) where you return -1 

targetgreaterthan:
	mov rsi, r8		; Loads r8 (which is the middle variable) into the beginning of the array 
	inc rsi 	 	; Adds 1 to r8 so that the (modified) lowest element in the array is equal to r8+1 or middle+1 (meaning that the target can only be present in the second half of the array)		
	jmp binarysearchloop	; Recursively loops through the array again with the lowest element = r8+1. Basically, only loop through the upper/top half of the array 
	
; Basically greaterthantarget will do the equivalent of binarySearch(array, middle+1, right, target)  

targetlessthan:
	mov rdx, r8	        ; Loads r8 (which is the middle variable) into the end of the array (basically the opposite of the greaterthantarget function does) 
	dec rdx			; Subtracts 1 from r8 so that the (modified) greatest element in the array is equal to r8-1 or middle-1 (meaning that the target can only be present in the first half of the array)		
	jmp binarysearchloop	; Recursively loops through the array again with the lowest element = r8-1. Basically, only loop through the lower/bottom half of the array

; Basically lessthantarget will do the equivalent of binarySearch(array, left, middle-1, target)
	
targetnotfound:
	mov rax, -1		; If the target value was never found in the array, then set rax equal to -1 and return -1 (since you never found the target value in the Binary Search loop) 
	ret
	
endofprogram:
	mov rax, r8 		; If you were able to successfully find the target value in the array (r8), then set rax equal to r8's value (the target value) and then return rax
	ret
	
; End of file 
