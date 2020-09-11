; Op.1 steht in xmm0, Op.2 in xmm1. Ergebnis in xmm0
; xmm -> edx mit MOVD

global calc_add

section .text

calc_add:

  ; Zahl aus FP-Register in normales Register holen
  ; xmm0: erster Operand, xmm1: zweiter Operand
  movd eax, xmm0
  movd ebx, xmm1

  mov ecx, eax
  mov edx, ebx

  ; Mantisse freistellen
  and ecx, 0x7FFFFF
  and edx, 0x7FFFFF

  ; Implizite 1 anfügen
  or  ecx, 0x800000
  or  edx, 0x800000
  ; 1. Operand: Mantisse in ecx, 2. Operand: Mantisse in edx.
  ; Nach rechts shiften, um Mantissen wegzubekommen.

  shr rax, 23 ; 1. Operand: VZ in ah, Charakteristik in al
  shr rbx, 23 ; 2. Operand: VZ in bh, Charakteristik in bl
  
  cmp al, bl
  je _calculate

  _alignExp:
  ; todo: unterschiedliche charakteristik anpassen
    

  _calculate:
    add ecx, edx ; ecx = Summe der Mantissen
    
  _checkMantissa:
    ; Prüfen ob Mantisse zu weit links (durch Verundung)
    test ecx, 0xFF000000
    jnz _shiftRight
    ; todo: prüfen, ob zu weit links
    jmp _writeBack

  _shiftRight:
    shr ecx, 1
    inc al
    jmp _checkMantissa

  _writeBack:
    ; Hidden Bit entfernen durch Verundung
    and ecx, 0x7FFFFF

    ; VZ und Charakteristik wieder an Anfang von Register schieben
    shl rax, 23

    ; Mantisse durch Veroderung an VZ|Char. anhängen
    or rax, rcx

  _exit:
    movd xmm0, eax

    ret