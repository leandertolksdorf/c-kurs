GLOBAL sort

section .data
    %define LENGTH rdi
    %define ARRAY rsi

section .text

sort:
    ; i = array.length
    mov r8, LENGTH
    .outer_loop:
        ; loop condition: i > 1
        cmp r8, 1
        jna .outer_end
        ; j = 0
        mov r9, 0
        .inner_loop:
            ; loop condition: j < i-1
            mov rcx, r8
            dec rcx
            cmp r9, rcx
            jnb .inner_end
            .debug:
            .if_condition:
                ; j+1
                mov rcx, r9
                inc rcx
                ; extract array[j] and array[j+1]
                mov rax, qword [ARRAY + 8*r9]
                mov rdx, qword [ARRAY + 8*(rcx)]
                ; condition: array[j] > array[j+1]
                cmp rax, rdx
                jna .inner_continue
                ; swap array[j] and array[j+1]
                ; array[j]
                mov r10, qword [ARRAY + 8*r9]
                ; array[j+1]
                mov r11, qword [ARRAY + 8*(rcx)]
                ; re-assign
                mov qword [ARRAY + 8*r9], r11
                mov qword [ARRAY + 8*(rcx)], r10
        .inner_continue:
            ; j++
            inc r9
            jmp .inner_loop
        .inner_end:
    .outer_continue:
        ; i--
        dec r8
        jmp .outer_loop
    .outer_end:

    .exit:
        ret