section .text
    global es_palindromo 

; Entrada: RDI -> dirección de la cadena (const char *cadena)
; Salida: RAX = 1 si es palíndromo, 0 si no lo es

es_palindromo:
    test rdi, rdi         ; Verificar si la cadena es nula  
    jz no_palindromo

    mov rcx, 0             ; contador de longitud
contar_longitud:
    cmp byte [rdi+rcx], 0  ; Comparar el byte actual con el carácter nulo (fin de cadena)
    je fin_contar
    inc rcx
    jmp contar_longitud

fin_contar:
    dec rcx                ; Ajustar el índice para la última posición de la cadena
    mov rsi, 0             ; Inicializar RSI al principio de la cadena

comparar:
    mov al, [rdi+rsi]      ; Cargar el carácter desde el extremo izquierdo
    mov bl, [rdi+rcx]      ; Cargar el carácter desde el extremo derecho
    cmp al, bl
    jne no_palindromo      ; Si no son iguales, no es palíndromo
    inc rsi                ; Moverse hacia el centro desde el extremo izquierdo
    dec rcx                ; Moverse hacia el centro desde el extremo derecho
    cmp rsi, rcx           ; Verificar si los índices se cruzaron o alcanzaron el centro
    jl comparar

es_palindromo_si:
    mov rax, 1
    ret

no_palindromo:
    mov rax, 0
    ret