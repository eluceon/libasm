section .text
	global	_ft_strcmp

_ft_strcmp:
	mov		rcx, -1					; set counter to -1
.loop_str:
	inc		rcx						; counter++
	mov		dl, byte [rdi + rcx]	; copy char (1 byte) from source to tmp
	cmp		dl, 0					; is the end of source, compare tmp to 0
	je		.return					; jump to label .return if equal 0
	cmp		dl, byte [rsi + rcx]
	je	 	.loop_str				; jump to label .loop_str if comparison is equal
.return:
	movzx	rax, dl					; movzx - moves an unsigned value into a register and zero-extends it with zero
	movzx	rdx, byte [rsi + rcx]
	sub 	rax, rdx
	ret								; return rax value
