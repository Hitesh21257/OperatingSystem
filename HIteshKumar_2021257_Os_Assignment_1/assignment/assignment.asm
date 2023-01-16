section .data
	text1 db "Please Enter the integer and String->"
	x dq 0

	text2 db "Output->"

	n dd 0
	s times 100 db 0

	fmt db "%d %s",0

section .text

	global main
	extern scanf
	extern printf
	extern exit

_printtext1:
	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, 38
	syscall
	ret

main:
	call _printtext1

	push rbp
	mov rbp, rsp
	lea rdi, [fmt]
	lea rsi, [x]
	lea rdx, [s]
	xor eax, eax
	call scanf
	pop rbp

	call _printtext2

	push rbp

	lea rdi, [fmt]
	mov rsi, [x]

	lea rdx, [s]
	xor eax, eax
	call printf
	pop rbp

	mov rax, 60
	mov rdx, 0
	ret

_printtext2:

	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, 9
	syscall
	ret

