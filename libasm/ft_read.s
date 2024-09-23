section .text
	global ft_read
	extern __errno_location 

ft_read:
	; rdi == fd
	; rsi == char *
	; rdx == len
	; all the registers are already saved (they servere as correct parameters)

	cmp rsi, 0
	je .null_ptr

	mov rax, 0
	syscall
	cmp rax, 0
	jge .no_err

	mov r8, rax
	call __errno_location
	neg r8
	mov [rax], r8
	mov rax, -1
	ret

.no_err:
	ret

.null_ptr:
    mov r8, 22          ; EINVAL error code is 22
    call __errno_location
    mov rbx, rax        ; rbx holds the address of errno
    mov [rbx], r8       ; Set errno to EINVAL
    mov rax, -1         
    ret
