section .text
	global ft_strcmp

ft_strcmp:
	; rdi == s1
	; rsi == s2
	xor rcx, rcx

.loop:
	mov al, BYTE [rdi + rcx]
	mov dl, BYTE [rsi + rcx]
	cmp al, dl
	jne .finish ; if they are not equal

	test al, al
	jz .finish ; if strings ended

	inc rcx
	jmp .loop


.finish:
	movzx rax, al
	movzx rdx, dl
	sub rax, rdx
	ret

