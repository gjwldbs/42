global _ft_write

_ft_write:
	xor rax, rax
	cmp rsi, 0 ; if string == NULL
	je error
	mov rax, rdi
	cmp rax, 0 ;if fd < 0
	jb error
	cmp rax, 2 ;if fd > 2
	ja error
	mov rax, 0x2000004 ;call write system call
	syscall
	jc error ;if doesn't work, set carry flags to 1
	ret
error:
	mov rax, -1
	ret