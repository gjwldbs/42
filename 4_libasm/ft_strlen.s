;section .text
global _ft_strlen

_ft_strlen:
	xor rax, rax ;mov rax, 0
	jmp compare
increment:
	inc rax
compare:
	cmp BYTE[rax + rdi], 0
	jne increment ;jne == while in C language
return:
 	ret