GLOBAL sort

section .data
    %define LENGTH rdi
    %define ARRAY rsi
    %define I r8
    %define J r9

section .text

sort:
    ; i = array.length
    mov I, LENGTH
    .outer_loop:
        ; continue loop if: i > 1
        cmp I, 1
        jna .outer_end
        ; j = 0
        mov J, 0
        .inner_loop:
            ; rcx = i-1
            mov rcx, I
            dec rcx
            ; continue loop if: j < i-1
            cmp J, rcx
            jnb .inner_end
            .if_condition:
                ; rcx = j+1
                mov rcx, J
                inc rcx
                ; rax = array[j]
                ; rdx = array[j+1]
                mov rax, qword [ARRAY + 8*J]
                mov rdx, qword [ARRAY + 8*(rcx)]
                ; execute if: array[j] > array[j+1]
                cmp rax, rdx
                jna .inner_continue
                ; swap array[j] with array[j+1]
                ; r10 = array[j]
                mov r10, qword [ARRAY + 8*J]
                ; r11 = array[j+1]
                mov r11, qword [ARRAY + 8*(rcx)]
                ; array[j] = r11
                ; array[j+1] = r10
                mov qword [ARRAY + 8*J], r11
                mov qword [ARRAY + 8*(rcx)], r10
        .inner_continue:
            ; j++
            inc J
            jmp .inner_loop
        .inner_end:
    .outer_continue:
        ; i--
        dec I
        jmp .outer_loop
    .outer_end:

    .exit:
        ret