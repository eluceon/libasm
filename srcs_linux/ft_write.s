section	.text
	global ft_write
	extern	__errno_location

ft_write:
	mov		rax, 1						; set system call number to 1
	syscall								; nvokes the system call
	test	rax, rax					; checking retrun, set flags
	jl 		.error_exit					; jump to .error_exit if error (rax < 0)
	ret
.error_exit:
	neg  	rax							; set rax to a positive number
	push	rax							; save rax to stack
	call    __errno_location  wrt ..plt	; __errno_location returns the address of error number
	pop		rdx							; restore rax from stack to rdx
	mov		[rax], rdx					; move error code to address.
	mov 	rax, -1						; set return to -1
	ret									; return rax value
