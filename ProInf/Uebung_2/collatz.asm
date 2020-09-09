global collatz

section .text

collatz:

  mov rsi, 0  ; rsi := k
  mov rdx, 1  ; für is_even(): bitweise verundung mit 1

  _while:

    cmp rdi, 1    ; Abbruchbedingung while
    jle _end

    test rdi, 1   ; rdi & 1: ZF=0 -> gerade, ZF=1 -> ungerade
    jne _odd      ;  je<-> ZF = 0, jne <-> ZF = 1
    
    ; even
    shr rdi, 1
    jmp _endwhile

    _odd:

      mov rax, 3
      mul rdi
      mov rdi, rax
      inc rdi

    _endwhile:
    
      inc rsi
      jmp _while

  _end:
    mov rax, rsi
    ret