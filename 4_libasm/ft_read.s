global _ft_read

extern ___error

_ft_read:
	push rbp
	call ___error
	pop rbp
	mov rbx, rax
	mov rax, 0x2000003 ;call write system call
	syscall
	jc error ;if doesn't work, set carry flags to 1
	ret
error:
	mov [rbx], rax
	ret