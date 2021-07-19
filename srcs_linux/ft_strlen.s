section .text
	global	ft_strlen

ft_strlen:
	xor		rax, rax				; set counter and retrun value = 0
.loop_counter:
	cmp		byte [rdi + rax], 0		; is the end of string, compare to 0
	je		.return					; jump to label .return if equal 0
	inc		rax						; rax++
	jmp 	.loop_counter			; jump to label .loop_counter
.return:
	ret								; return rax value
