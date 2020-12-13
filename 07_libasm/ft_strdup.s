extern malloc
extern ft_strlen
extern ft_strcpy
global ft_strdup

section .text
;rdi - first argument
;rsi - secong argument
;rcx - counter
ft_strdup:
	call ft_strlen
	add rax,1
	mov r9, rax
	push rdi		;src str in rdi
	mov rdi,rax
	call malloc
	cmp rax,0		;if malloc returns NULL it also changes errno to ENOMEM
	jz _erro
	pop rdi
	mov rsi,rdi		;move src to second arg
	mov rdi,rax		;move malloced memory to first arg
	call ft_strcpy	;call strcpy, so in rax - pointer to dest str
	ret

_erro:
	ret
