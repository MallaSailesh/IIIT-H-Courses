.global factorial
factorial:
     # %rdi - n
     movq $1 , %r10 
     movq $1 , %r11 # for storing the value of factorial 
.L1 :
     imulq %r10 , %r11
     movq %r11 , %rax
     cqto
     idivq %rdi
     cmpq $0 , %rdx 
     je .L2
     incq %r10
     jmp .L1 
.L2:
     movq %r10 , %rax
     ret 

