.global sume 
sume:
    movq $0 , %r10 # store the sum
    movq $0 , %r9 # i ,max is in %rdi(m)
    movq $0 , %r8 # j max is in %rsi(n)
.L2:
    cmpq %r8,%rsi # jumps on j == n 
    je .L1
    movq %r9,%r13
    imulq %rsi , %r13
    addq %r8 , %r13
    movq (%rdx,%r13,8), %rax
    pushq %rax 
    pushq %rdx 
    movq $2 , %r12 # %r12 store 2 
    cqto
    idivq %r12
    movq %rdx , %r15
    popq %rdx
    popq %rax
    cmpq $0 , %r15
    je .L4
    incq %r8
    jmp .L2
.L1: # kind of similar to first loop
    incq %r9 # i 
    movq $0 , %r8
    cmpq %r9 , %rdi
    je .L3
    jmp .L2
.L3:
    movq %r10,%rax
    ret
.L4:
    addq %rax , %r10
    incq %r8
    jmp .L2
