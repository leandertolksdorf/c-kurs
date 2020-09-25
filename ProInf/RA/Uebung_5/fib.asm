global asm_fib_it
global asm_fib_rek

section .data
    %define X r8
    %define Y r9
    %define K r10
    %define N rdi

section .text

%macro return 1
    mov rax, %1
    ret
%endmacro

asm_fib_it:
    ; x = 0
    mov X, 0
    ; y = 1
    mov Y, 1
    ; k = 0
    mov K, 0
    .while:
        ; execute if: n > 0
        cmp N, 0
        jna .while_end
        ; x = y
        mov X, Y
        ; y = k
        mov Y, K
        ; rcx = x+y
        mov rcx, X
        add rcx, Y
        ; k = x+y
        mov K, rcx
        ; n--
        dec N
        ; continue loop
        jmp .while
    .while_end:
    .exit:
        return K

asm_fib_rek:
    .debug:
    .if:
        ; n < 3
        cmp N, 3
        jnb .else
        return 1
    .else:
        ; x = fib_rek(n-1)
        push N
        dec N
        call asm_fib_rek
        mov X, rax
        pop N
        ; push to save X between function contexts
        push X
        ; y = fib_rek(n-2)
        push N
        sub N, 2
        call asm_fib_rek
        mov Y, rax
        pop N
        ; pop saved X
        pop X
        ; return x+y
        add X, Y
        return X