; Name: Steven Song 
; UVA ID: sqs5hrn 
; Date: April 11, 2021 
; CS2150 Lab 8 Pre Lab mathlib.s 

; You have to declare global product, power so that you can use them in other files (in order for routines in an assembly to be callable from C/C++, you need to declare them with global) 
global product, power
	section .text
	
; The first subroutine computes the product of the two integer parameters passed in (it can only use addition and cannot use the multiplication operation though as restrictions)
; This subroutine should be called product  
product:
	; Subroutine body: (Very similar to vecsum.s) 
	; Standard prologue: we do NOT have to create any local variables (those values will be kept in the registers)
	; rax is the one register used for the return value 
	xor	rax, rax	; zeros out the register
				; rax is the registar that's used for the return value
				; rcx could be used as a counter
	xor	rcx, rcx	; zeros out the i (i is the counter used in this file)
	; rdi is used to pass the first argument to the function 
	; rsi is used to pass the second argument to the function (ex. 3 x 4: 4 is rsi in this case) 
start:	
	cmp	rcx, rsi	; Checks to see if i = n: cmp sets the machine status word (can be done prior to an conditional jump) (i.e. when you do 3*4, this means that it's looping 4 times for the counter) 
	je	done		; If i is equal to n, then end the loop as we are done with the loop 
	add	rax, rdi	; Adds rdi to rax (since anything greater than 8 bytes we use rsi) (Adds the first argument to rax: i.e. When you do 3*4 = 12, you have to add 3 4 times so this is just adding 3 1 time) 
	; rdi, rdx, rsi, rcx are the registers that are used for parameter passing  
	; rdi is the first parameter, rsi is the second parameter, rdx is the third parameter, rcx is the fourth parameter 
	inc	rcx		; Increments the counter by i (i++) 
	jmp	start		; Jumps back to start and proceeds to the next part of this file 
done:	
				; Does nothing here since there's nothing to deallocate
	ret			; pops the return address from that stack and then jumps to that address 

; The second subroutine computes the power of the two integer parameters passed in (it can only use the multiplication routine though and it must be defined recursively as restrictions). Assume that the first parameter is the base and the second parameter is the exponent

; 3*4 = 12	
; 3^4 = 81
; 3*3 = 9
; 3^3 = 27

; This subroutine should be called power 
power: 				
	xor	rax, rax	; rax is the very first register in 64 bits (resets rax back to 0)
	mov	rax, 1		; Sets rax equal to 1
	
startpower:	
	cmp 	rsi, 0		; Tests to see if the rsi is equal to 0. If it is then it returns the value in rax (recursion call: base condition) 
	je 	basepower	; Jumps to the basepower label
	                        
	push 	rsi		; pushes rsi
	
	dec	rsi		; Decrements rsi by 1 (n-1)
	call 	startpower	; Calls the power function recursively by passing in the two parameters for rdi and rsi-1 as the base and the power respectively for the exponent

	pop 	rsi		; pops rsi
	
	mov	rsi, rax	; Changed it from rsi to rdi puts the first parameter in rsi, second in rax
				; (Pseudocode: x * recursion(x, n-1)) 
				; rax * rsi (x * n-1)
	
				; Calls product (pushes a return address onto the stack and jumps to the location in memory where the product is). Then it executes the function
				; The return value of the product will be placed in rax. Once the product method is finished, it calls ret  
	call	product		; Calls the product function (which is equal to base(rdi) * power(rdi, rsi - 1). (The call instruction places the return address on the stack) 
	je 	donepower	; Jumps to the end 
	
basepower:
	mov 	rax, 1 		; Pseudocode: if (n == 0), return 1
	
donepower:
	ret		        ; End of the file
