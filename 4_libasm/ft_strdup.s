global _ft_strdup
;char	*ft_strdup(const char *s1)
;ft_strdup(rdi)
extern _malloc; malloc(rdi(size))
extern _ft_strlen;ft_strlen(rdi)
extern _ft_strcpy;ft_strcpy(rdi, rsi)
extern ___error

_ft_strdup:
	call _ft_strlen
	add rax, 1 ;rax = length + 1 = result

	push rdi
	mov rdi, rax
	call _malloc
	pop rdi

	push rbp
	call ___error
	pop rbp
	jc error ;if malloc fails ENOMEM(12)

	push rsi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	pop rsi

	ret
error:
	mov [rbx], rax
	ret