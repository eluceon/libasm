section	.text
	global _ft_write
	extern	___error

_ft_write:
	mov		rax, 0x02000004		; set system call number to 0x02000004 for write
	syscall						; nvokes the system call
	jc 		.error_exit			; jump to .error_exit if error (carry flag)
	ret
.error_exit:
	push	rax					; save rax to stack
	call    ___error			;  __error returns the address of error number
	pop		rdx					; restore rax from stack to rdx
	mov		[rax], rdx			; move error code to address returned by ___error
	mov 	rax, -1				; set return to -1
	ret							; return rax value
