extern __errno_location
global ft_read

section .text

ft_read:
	mov rax,0
	syscall
	cmp rax,0
	jge _ok

_erro:
	neg rax
	mov rdx,rax
	call __errno_location
	mov [rax],rdx
	mov rax, -1
	ret

_ok:
	ret