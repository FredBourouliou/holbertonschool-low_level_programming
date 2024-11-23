    .section __TEXT,__text           // Section texte pour le code exécutable
    .global _start                   // Point d'entrée global

_start:
    // Appel système write
    mov x8, #64                      // Numéro du syscall pour write (64 pour ARM64 sur macOS)
    mov x0, #1                       // File descriptor: STDOUT
    adrp x1, msg                     // Charger la page de msg dans x1
    add x1, x1, :lo12:msg            // Ajouter l'offset pour obtenir l'adresse complète
    mov x2, #13                      // Longueur fixe du message "Hello, World\n"
    svc #0                           // Appel système

    // Appel système exit
    mov x8, #93                      // Numéro du syscall pour exit
    mov x0, #0                       // Code de retour : 0 (succès)
    svc #0                           // Appel système

    .section __DATA,__data           // Section data pour les données
msg:
    .asciz "Hello, World\n"          // Message ASCII avec un saut de ligne