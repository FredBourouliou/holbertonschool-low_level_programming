section .data
msg db 'Hello, World', 0xA
len equ $ - msg

section .text
global _start

_start:
mov rax, 1      ; write
mov rdi, 1      ; stdout
mov rsi, msg    ; address of message
mov rdx, len    ; length of message
syscall         ; perform system call
mov rax, 60     ; exit
xor rdi, rdi    ; status 0
syscall         ; perform system call