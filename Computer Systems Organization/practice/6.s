.global gcd 
gcd:
   cmpq %rdi,%rsi
   jg .L1 
.L2:
   movq %rdi ,%rax
   cqto 
   idivq %rsi
   cmpq $0 ,%rdx
   je .L3
   movq %rsi , %rdi
   movq %rdx , %rsi
   jmp .L2 
.L1:
    movq %rsi , %r11
    movq %rdi , %rsi
    movq %r11 , %rdi
    jmp .L2
.L3:
    movq %rsi , %rax 
    ret
