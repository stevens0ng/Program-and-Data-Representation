; Name: Steven Song
; UVA ID: sqs5hrn 
; Date: April 12, 2021  
; CS2150 Lab 8 In Lab mergeSort.s 

global mergeSort
global merge

section .text

; Parameter 1 is a pointer to the int array (rdi)
; Parameter 2 is the left index in the array (rsi)
; Parameter 3 is the right index in the array (rdx)
 
; Return type is void 
mergeSort:
	; r12 - r15 is all the callee (saved) registers 
	; Implement mergeSort here (the assembly part)
	
	; The reason why you don't have to push rdi is because rdi is never going to change (it's always going to be the array)
	
	cmp rsi, rdx		; This will compare the start index (rsi) and the end index (rdx) (Must compare in this order since rsi comes before rdx) 
	jge endofthisprogram	; If the start index is greater than the end index, then it will go to the end of program label automatically
	
	; First recursive call: (array, left, middle)
	
	; push rsi 		; Pushes the rsi, the 2nd index in the array, onto the stack (Don't need it since you never modified rsi) 
	push rdx		; Pushes the rdx, the 3rd index in the array, onto the stack
	mov r8, rsi 		; Moves the value at rsi (the left/second index in an array) to the r8 register (Sets r8 (the middle element) to be rsi (the left element) for now)
	add r8, rdx 		; Adds the value at rdx to rsi to form (rsi+rdx) and then sets that to the register r8 
	shr r8, 1 		; Divides what we had above by 2 to get the official middle element of our array. (it divides left + right by 2) ((rsi + rdx)/2)

	push r8 		; r8 is essentially equal to the middle element (left + right)/2 (the reason why you have push r8 again is so that you update it so that it becomes (left+right)/2 instead of just (left+right) 
	mov rdx, r8 		; The first half of the array is basically now (array, left, middle) so we set/move the middle element into the third index position (rdx)

	call mergeSort		; This is the first time that we recursively call the mergeSort function (array, left, middle)

	pop r8			; We basically have to pop whatever we pushed in the opposite order (So if we did push rsi, push rdx, push r8: we would do pop r8, pop rdx, pop rsi: basically the reverse order of it) 
	pop rdx
	; pop rsi

	; Second recursive call: (array, middle+1, right)
	
	push rsi		; You basically push the same things that you did in the first recursive call where rsi is the second (left) index in the array, rdx is the third (right) index in the array, and r8 is the middle element in the array
	; push rdx		; rdx never got modified so you don't need it 
	push r8 		; r8 is the middle element
	push r9			; r9 is the middle element + 1 
	
	inc r8, 		; Increments the middle element by 1 here (middle+1)
	mov r9, r8 		; Moves r8 into the r9 registesr 
	mov rsi, r9 		; You're moving your new value of r8 (middle +1) into your start/second index (rsi) since you're doing array, middle +1, right for your second recursive call 
	
	call mergeSort		; Calls mergeSort a second time (for the second recursive call)

	pop r9 			; Like before, the pop operations are called in reverse order of push
	pop r8
	; pop rdx 		
	pop rsi
	
	; Call to merge: (array, left, middle, right)
	; Parameter 4 is the middle index in the array (rcx)
	
	; push rsi		; Pushes rsi (left) (the exact same order as what we did for the first two recursive calls) (Again, rsi never got modified here so you don't need it) 
	push r8			; Pushes r8 (middle)
	push rdx 		; Pushes rdx (right) (3rd argument) 

	mov rcx, rdx 		; You're setting the fourth index in the array equal to the rdx (or right) we don't have to modify (mov) rdx again as assembly already knows that rdx is referring to the right element in an array    
	mov rdx, r8 		; You're setting the third index in the array equal to r8 or the middle element (this makes sense since in the final merge: the third index is middle and the fourth index is right) 
	
	call merge	 	; Calls merge one last time to combine the first two arrays together into one: the reason why we don't have to mov rsi is because the second index in the final merge sorted array is always equal to left. It essentially calls merge on the two recursive functions we just did above
	
	pop rdx			; Like always, we have to pop the variables/elements we pushed in reverse order
	pop r8
	; pop rsi
	
	; Pseudocode 
	; Call mergesort for the first half (mergesort(array, left, middle))
	; Call(merge(rdi, rsi, (rsi+rdx)/2))

	; Call mergesort for the second half(mergesort(array, middle+1, right))
	; Call(merge(rdi, ((rsi+rdx)/2) + 1, rdx))

	; Call merge on the previous 2 recursive functions
	; (mergesort(array, left, middle, right))
	
	; Call(merge(rdi, rsi, ((rsi+rdx)/2), rdx)) label: jump to the same point
	
endofthisprogram:		
	ret 			; End of program  

; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void
	
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
