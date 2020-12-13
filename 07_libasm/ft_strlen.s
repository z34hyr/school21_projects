global ft_strlen

section .text
ft_strlen:
	xor		rcx,rcx	;set it to zero

_again:
	cmp 	byte [rdi + rcx], 0	;cmp value on pointer with EOL
	jz		_finish	;quit if EOL
	inc 	rcx		;else incr counter
	jmp		_again	;loop

_finish:
	mov rax, rcx	;_again or ft_strlen put rcx to rax
	ret