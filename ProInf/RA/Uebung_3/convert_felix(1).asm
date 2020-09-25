GLOBAL strToInt
GLOBAL intToStr
SECTION .text

; POWER FUNCTION
; rdi = exponent
; rsi = base
power:
    mov rax, 1
    .loop:
        cmp rdi, 0
        je .exit
        mul rsi
        dec rdi
        jmp .loop
    .exit:
    ret

; ASCII CHARACTER VALUE FUNCTION
; rdi = character
char_val:
    ; initialize char value into rax
    mov rax, rdi
    ; compare char to valid char types
    ; jump to respective label
    cmp rdi, '0'
    jl .invalid
    cmp rdi, '9'
    jle .digit
    cmp rdi, 'A'
    jl .invalid
    cmp rdi, 'Z'
    jle .letter_big
    cmp rdi, 'a'
    jl .invalid
    cmp rdi, 'z'
    jle .letter_small
    
    ; char types
    .digit:
        sub rax, 48
        jmp .exit
    .letter_big:
        sub rax, 55
        jmp .exit
    .letter_small:
        sub rax, 87
        jmp .exit
    .invalid:
        mov rax, -1
    .exit:
    ret

; MAIN STRING TO INTEGER FUNCTION
; rdi = string: pointer
; rsi = base: integer
strToInt:

    ; init variables
    mov rcx, 0                                  ; initalize counter
    mov rax, 0                                  ; initialize sum

    ; loop iterating through characters
    .loop:
        ; extract character
        push rdi                                ; save rdi string pointer
        movzx rdi, byte [rdi + rcx]             ; move current char into rdi

        ; exit if string finished
        cmp rdi, 0                              ; check whether char is NUL (0)
        je .exit                                 ; if char is NUL, exit function

        ; get character value
        push rax                                ; save rax sum
        call char_val                           ; call char value function
        mov r8, rax                             ; move char value into r8
        pop rax                                 ; restore rax sum
        pop rdi                                 ; restore rdi string pointer

        ; perform calculations for each character
        mul rsi                                 ; multiply sum by rsi base
        add rax, r8                             ; add char value code to sum

        ;restart loop
        inc rcx
        jmp .loop

    ; exit function
    .exit:
        ret                                     ; return sum in rax
