global strToInt

section .text

%macro power 2
; 1. Argument: Basis, 2. Argument: Exponent, Ergebnis: rax:rdx

  ; Register pushen, um später wiederherzustellen
  push %1
  push %2

  ; Prüfen, ob Exponent 0 -> Dann Ergebnis = 1
  cmp %2, 0
  je %%expIsNull

  ; Basis in rax für Multiplikation schreiben
  mov rax, %1

  ; Solange Exponent != 0: 
  ; Basis mit sich selbst multiplizieren und Exponenten dekrementieren.
  %%powerLoop:
    dec %2
    cmp %2, 0
    je %%endPower
    mul %1
    jmp %%powerLoop

  ; Wenn Exp = 0 -> 1 returnen
  %%expIsNull:
    mov rax, 1
    mov rdx, 0
  
  ; Register wiederherstellen
  %%endPower:
    pop %2
    pop %1

%endmacro

%macro asciiToInt 1
; Konvertiert ASCII-Code in Ganzzahl. Bei Sonderzeichen -> Error und return
; Geht nur mit Großbuchstaben

  cmp %1, 48 ; Wenn kleiner als 48 -> Zeichen ungültig
  jl %%invalid
  cmp %1, 58 ; Wenn kleiner als 58 -> Ziffer
  jl %%digit
  cmp %1, 65 ; Wenn kleiner als 65 -> Zeichen ungültig
  jl %%invalid
  cmp %1, 91 ; Wenn kleiner als 91 -> Buchstabe
  jl %%letter
  jmp %%invalid ; Ansonsten -> Zeichen ungültig

  %%digit:
    ; Bei Ziffern -> 48 abziehen.
    sub %1, 48
    jmp %%end

  %%letter:
    ; Bei Buchstaben -> 55 abziehen 
    ; ("A" = 10 im Zehnersystem, 65 in ASCII -> 65 - 55 = 10)
    sub %1, 55
    jmp %%end

  %%invalid:
    mov eax, 1 ; Interrupt-Funktion setzen -> exit()
    mov ebx, 1 ; Return code setzen -> 1 wegen Error.
    int 0x80   ; Interrupt senden 
  
  %%end:

%endmacro

strToInt:

  mov rcx, 0

  ; Stringlänge ermitteln

  _strLenLoop:

    cmp [rdi + rcx], BYTE 0 ; Vergleiche Byte mit Null, um Nullterminator zu finden.
    je _strTerm ; Wenn Nullterminator -> fertig.
    inc rcx ; Zähler inkrementieren
    jmp _strLenLoop
  
  _strTerm:
    mov r8, rcx ; In r8 steht jetzt die Länge des Strings (ohne Nullterminator)


; Von vorne nach hinten: Potenzen berechnen und aufaddieren
  mov rcx, 0  ; rcx := Zähler für aktuelle Stelle
  mov r10, 0  ; r10 := Zwischenergebnis

  _addLoop:
    dec r8
    power rsi, r8 ; Erst: Basis ^ Exponenten (den Stellenwert) an Stelle rcx berechnen.
    ; In rax:rdx steht jetzt (Basis ^ Exponent)

    movzx r9, BYTE [rdi + rcx] ; ASCII Code des Zeichens an Stelle rcx in r9 schreiben.

    asciiToInt r9 ; ASCII Code in Integer konvertieren.
    mul r9 ; rax:rdx = Ziffer * Stellenwert
    add r10, rax ; Ergebnis zu Zwischenergebnis addieren.
    cmp r8, 0 ; Wenn letzte Stelle -> Ende.
    je _end
    inc rcx ; Sonst: nächste Stelle.
    jmp _addLoop
  
  _end:
    mov rax, r10 ; Ergebnis in rax schreiben
    ret ; und tschüss...

