section	.text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	extern	___error


_ft_strdup:
	push	rdi				; save rdi (the source string) to stack
	call	_ft_strlen		; count the line length (rdi register)
	inc		rax				; rax++ increase the line length by 1 for the end of the string (\0)
	mov		rdi, rax		; copy len of the string to rdi for malloc
	call    _malloc			; call malloc
	pop		rsi				; restore the source string from stack to rsi for ft_strcpy
	test	rax, rax		; checking retrun, set flags
	jz		.error_exit		; jump to .error_exit if malloc error (rax == 0)
	mov		rdi, rax		; copy the string address from rax (malloc return) to rdi (destination) for ft_strcpy
	call 	_ft_strcpy		; call ft_strcpy
	ret						; return rax of ft_strcpy - pointer ot dest
.error_exit
	push	rax				; save rax to stack
	call    ___error		;  __error returns the address of error number
	mov		qword [rax], 12	; move error code (ENOMEM = 12) to address returned by ___error
	pop		rax				; restore rax
	ret						; return rax value
