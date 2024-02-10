.global special 
special:
    movq $0,%r10 # %r10 is sum
    movq %rdi,%r8 # %r8 is n
    movq $0 , %r11 # %r11 is i 
    # %rsi is a[]
    movq $1 ,(%rsi,%r11,8) # a[0] = 1
    incq %r11
    movq $1 ,(%rsi,%r11,8) # a[1] = 1
.L2:
    cmpq $10,%r11
    jl .L1
    jmp .L3
.L1:
    movq (%rsi,%r11,8) , %r9
    incq %r11
    imulq %r11 , %r9 # %r9 stores i*a[i-1]
    movq %r9 , (%rsi,%r11,8)
    jmp .L2
.L3:
    cmpq $0,%rdi
    jne .L4
    cmpq %r8,%r10
    jne .L5
    movq $1 , %rax
    ret
.L4:
    movq %rdi , %rax
    pushq %rsi
    movq $10,%rsi
    cqto
    idivq %rsi
    popq %rsi
    movq %rax , %rdi
    movq %rdx , %rax
    addq (%rsi,%rax,8),%r10 
    jmp .L3
.L5: 
    movq $0 , %rax
    ret
