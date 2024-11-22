section .data
    msg db "Hello, World", 0xA  ; Message à afficher, suivi d'un saut de ligne
    len equ $ - msg             ; Longueur du message

section .text
    global _start               ; Point d'entrée du programme

_start:
    ; Appel système write
    mov rax, 1                  ; syscall number pour write
    mov rdi, 1                  ; file descriptor pour stdout
    mov rsi, msg                ; adresse du message à afficher
    mov rdx, len                ; longueur du message
    syscall                     ; appel système

    ; Appel système exit
    mov rax, 60                 ; syscall number pour exit
    xor rdi, rdi                ; code de retour 0
    syscall                     ; appel système