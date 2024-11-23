section .data
    message db "Hello, World", 0xA  ; Message with a newline character
    msglen equ $ - message          ; Length of the message

section .text
    global _start                   ; Declare the entry point

_start:
    ; System call: write
    mov rax, 1                      ; Syscall number 1: write
    mov rdi, 1                      ; File descriptor 1: stdout
    mov rsi, message                ; Address of the message
    mov rdx, msglen                 ; Length of the message
    syscall                         ; Execute the syscall

    ; System call: exit
    mov rax, 60                     ; Syscall number 60: exit
    xor rdi, rdi                    ; Return code 0
    syscall                         ; Execute the syscall