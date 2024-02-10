.global solve
solve:
     cmpq $1,%rdx
     je .L1
     cmpq $2,%rdx
     je .L2
     cmpq $3,%rdx
     je .L3
     cmpq $4,%rdx
     je .L4
     cmpq $5,%rdx
     je .L5
.L1:
     addq %rdi , %rsi 
     movq %rsi , %rax
     ret
.L2:
     subq %rsi , %rdi 
     movq %rdi , %rax
     ret
.L3:
     movq %rdi , %rax
     cqto
     idivq %rsi
     ret
.L4:
     movq $1,%r10
     cmpq $0,%rsi
     jg .L6
     movq %r10,%rax
     ret
.L5:
     movq %rdi , %rax
     cqto
     idivq %rsi
     movq %rdx , %rax
     ret
.L6:
     imulq %rdi,%r10
     decq %rsi
     cmpq $0,%rsi
     jg .L6
     movq %r10 , %rax
     ret
