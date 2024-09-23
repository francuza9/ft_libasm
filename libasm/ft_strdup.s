section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	push rdi
	call ft_strlen

	mov rdi, rax
	inc rdi ; for the null terminator
	call malloc

	pop rsi
	mov rdi, rax
	call ft_strcpy

	ret
