global ft_strcmp
extern ft_strlen

section .text
;rdi - first argument
;rsi - secong argument
;rcx - counter
ft_strcmp:
	call ft_strlen
	mov r9,rax		;so len of str1 now in r9
	push rdi
	mov rdi,rsi
	call ft_strlen
	pop rdi
	mov r10,rax		;so len of str2 now in r10
	cmp r9,r10
	jl _finish_l
	jg _finish_g
	xor rcx,rcx

_compare:
	cmp byte [rdi + rcx],0 ;if EOL - str1 eq str2
	jz _finish_eq
	mov al,[rdi + rcx]
	cmp al,[rsi + rcx]	;compare bytes
	jl _finish_l		;if less - ret -1
	jg _finish_g		;if greater - ret 1
	inc rcx				;else go on
	jmp _compare

_finish_l:
	mov rax,-1
	ret

_finish_g:
	mov rax,1
	ret

_finish_eq:
	mov rax,0
	ret