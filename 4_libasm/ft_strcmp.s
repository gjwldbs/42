global _ft_strcmp

_ft_strcmp:
	xor rcx, rcx
	jmp while
while:
	mov dl, BYTE[rdi + rcx]
	cmp dl, BYTE[rsi + rcx]
	je	increment
	jmp return_diff ;if they are not same anymore
increment:
	cmp dl, 0
	je return_zero ;cause it's equal
	inc rcx
	jmp while
return_diff:
	cmp BYTE[rsi + rcx], 0
	je return_1
	mov rax, -1
	ret
return_zero:
	mov rax, 0
	ret
return_1:
	mov rax, 1
	ret