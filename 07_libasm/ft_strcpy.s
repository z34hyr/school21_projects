global ft_strcpy

section .text
;rdi - first argument
;rsi - secong argument
;rcx - counter
ft_strcpy:
	xor rcx, rcx

_again:
	cmp byte [rsi + rcx],0	;cmp if EOL
	jz _finish
	mov al, [rsi + rcx]		;can't move if both pointers so make a copy
	mov [rdi + rcx], al
	inc rcx
	jmp _again

_finish:
	mov [rdi + rcx],byte 0	;put EOL after data
	mov rax,rdi
	ret
