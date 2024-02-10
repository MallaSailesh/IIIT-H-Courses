.global sum
.global prime 
prime:
    cmpq $1 , %rdi
    je .L1
    movq %rdi , %r10
    decq %r10
.L3:
    cmpq $1,%r10
    je .L2
    movq %rdi , %rax 
    cqto
    idivq %r10
    cmpq $0, %rdx
    je .L1
    decq %r10
    jmp .L3
.L1:
    movq $0 , %rax 
    ret
.L2:
    movq $1,%rax
    ret
 sum:
    # n :- %rdi , m :- %rsi i took n >= 2 and m >=1 
    movq $0 , %r11 # stores the sum 
    movq %rdi , %r12
    decq %r12
.L4:
    cmpq $1 , %r12 
    je .L5
    movq %r12 , %rdi 
    callq prime 
    cmpq $1 , %rax
    je .L6
    decq %r12 
    jmp .L4
.L5:
    movq %r11 , %rax 
    ret
.L6:
    addq %r12 , %r11 
    pushq %rax 
    movq %r11 , %rax
    cqto 
    idivq %rsi
    movq %rdx , %r11 
    popq %rax
    decq %r12 
    jmp .L4
