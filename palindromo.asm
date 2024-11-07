section .text
    global es_palindromo

es_palindromo:
    ; Entrada: rdi puntero a la cadena
    ; Salida: eax 1 si es palindromo, 0 si no lo es

    test rdi, rdi
    jz .exit_false
    mov rcx, 0;

.count_length:
    cmp al, byte [rdi + rcx]
    test al, al
    jz .length_found
    inc rcx
    jmp .count_length

.length_found:
    cmp rcx, 1
    jle .exit_true
    mov rsi, rdi
    add rsi, rcx
    dec rsi

.check_palindrome:
    mov al, byte [rdi]
    mov bl, byte [rsi]
    cmp al, bl
    jne .exit_false
    inc rdi
    dec rsi
    cmp rdi, rsi
    jg .exit_true
    jmp .check_palindrome

.exit_true:
    mov eax, 1
    ret

.exit_false:
    mov eax, 0
    ret
