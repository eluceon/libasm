section .text
	global	_ft_strcpy

_ft_strcpy:
	xor		rcx, rcx				; set counter to 0
	mov		rax, rdi				; put destination string address to rax
.loop_str:
	mov		dl, byte [rsi + rcx]	; copy char from source to tmp
	mov		byte [rdi + rcx], dl	; copy char from tmp to destination
	cmp		dl, 0					; is the end of source, compare tmp to 0
	je		.return					; jump to label .return if equal 0
	inc		rcx						; counter++
	jmp 	.loop_str				; jump to label .loop_str
.return:
	ret								; return rax value
