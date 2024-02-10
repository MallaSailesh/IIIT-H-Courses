.global solve 
solve:
     movq $0,%r11
.L2:
     cmpq $0,%rdi
     jne .L1
     movq %r11 , %rax
     ret
.L1:
     movq %rdi , %rax
     movq $2 , %rsi
     cqto 
     idivq %rsi
     movq %rax , %rdi
     cmpq $1 , %rdx
     je .L3
     jmp .L2
.L3:
     incq %r11
     jmp .L2 
