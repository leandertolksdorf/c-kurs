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
  
  ; Kleineren Exponenten ermitteln
  cmp al, bl
  je _calculate ; Gleich -> Mantissen addieren
  jg _alignExp2 ; exp1 > exp2 -> exp2 an exp1 angleichen

  _alignExp1: ; al < bl
    ; Differenz der Exponenten berechnen
    mov cl, bl
    sub cl, al
    mov al, bl ; Der Exponent des Ergebnisses kommt in al.
    shr ecx, cl ; 1. Mantisse um die Differenz nach rechts shiften

    jmp _calculate

  _alignExp2: ; al > bl
    mov cl, al
    sub cl, bl 
    ; Hier ist der größere Exponent schon im richtigen Register, deshalb kein mov.
    shr edx, cl ; 2. Mantisse um die Differenz nach rechts shiften

  _calculate:
    ; Für Negative -> ZK bilden
    test ah, 1
    jz _add
    neg ecx
    test bh, 1
    jz _add
    neg edx

    _add:
    add ecx, edx ; ecx = Summe der Mantissen

  _checkMantissa:
    ; Prüfen ob Mantisse zu weit links (durch Verundung)
    test ecx, 0xFF000000
    jnz _shiftRight
    ; todo: prüfen, ob zu weit rechts
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