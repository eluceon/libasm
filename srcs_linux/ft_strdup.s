section	.text
	global	ft_strdup
	extern	malloc
	extern	__errno_location
	extern ft_strlen
	extern ft_strcpy


ft_strdup:
	push	rdi							; save rdi (the source string) to stack
	call	ft_strlen					; count the line length (rdi register)
	inc		rax							; rax++ increase the line length by 1 for the end of the string (\0)
	mov		rdi, rax					; copy return value of ft_strlen (rax) to rdi for malloc
	call    malloc  wrt ..plt			; call malloc
	pop		rsi							; restore the source string from stack to rsi for ft_strcpy
	test	rax, rax					; checking retrun, set flags
	jz		.error_exit					; jump to .error_exit if malloc error (rax == 0)
	mov		rdi, rax					; copy the string address from rax (malloc return) to rdi (destination) for ft_strcpy
	call 	ft_strcpy					; call ft_strcpy
	ret									; return rax of ft_strcpy - pointer ot dest
.error_exit
	push	rax							; save rax to stack
	call    __errno_location wrt ..plt	;  __errno_location returns the address of error number
	mov		qword [rax], 12				; move error code (ENOMEM = 12) to address returned by ___error
	pop		rax							; restore rax
	ret									; return rax value
