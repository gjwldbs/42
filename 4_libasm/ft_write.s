global _ft_write
;ft_write(rdi, rsi, rdx)
extern ___error

_ft_write:
	push rbp
	call ___error
	pop rbp
	mov rbx, rax
	mov rax, 0x2000004 ;call write system call
	syscall
	jc error ;if doesn't work, set carry flags to 1
	ret
error:
	mov [rbx], rax
	ret