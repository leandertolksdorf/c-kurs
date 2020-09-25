global gauss

section .text

gauss:

  mov rax, rdi  ; rax = n
  inc rdi       ; rdi = n + 1
  mul rdi       ; rax = n * (n+1)
  shr rax, 1    ; 1 nach rechts shiften <-> /2
  ret