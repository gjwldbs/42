global _ft_strcpy

_ft_strcpy:
	xor rax, rax
	xor rcx, rcx
	jmp cpy

increment:
	inc rcx

cpy:
	cmp BYTE[rcx + rsi], 0
	je return
	mov dl, BYTE[rcx + rsi]
	mov BYTE[rcx + rdi], dl
	jmp increment

return:
	mov BYTE[rcx + rdi], 0
	mov rax, rdi
	ret