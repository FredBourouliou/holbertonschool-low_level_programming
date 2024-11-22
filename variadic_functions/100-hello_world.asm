section .data
    message db "Hello, World", 10 ; Le message à imprimer
    msg_len equ $ - message       ; Longueur du message

section .text
    global _start                 ; Point d'entrée pour macOS

_start:
    ; write syscall
    mov rax, 0x2000004           ; write (syscall numéro pour macOS)
    mov rdi, 1                   ; descripteur de fichier : 1 (stdout)
    lea rsi, [rel message]       ; charge l'adresse relative de `message`
    mov rdx, msg_len             ; longueur du message
    syscall                      ; exécute le syscall

    ; exit syscall
    mov rax, 0x2000001           ; exit (syscall numéro pour macOS)
    xor rdi, rdi                 ; code de retour : 0
    syscall                      ; exécute le syscall