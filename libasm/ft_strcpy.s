section .text
	global ft_strcpy

ft_strcpy:
	; rdi == destination
	; rsi == source
	xor rcx, rcx
.loop:
	mov al, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], al
	cmp al, 0
	je .finish
	inc rcx
	jmp .loop
.finish:
	mov rax, rdi
	ret

