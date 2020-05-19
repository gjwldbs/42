global _ft_read

_ft_read:
	xor rax, rax
	cmp rsi, 0 ; if string == NULL
	je error
	mov rax, rdi
	cmp rax, 0 ;if fd < 0
	jb error
	cmp rax, 2 ;if fd > 2
	ja error
	mov rax, 0x2000003 ;call read system call
	syscall
	jc error ;if doesn't work, set carry flags to 1
	ret
error:
	mov rax, -1
	ret