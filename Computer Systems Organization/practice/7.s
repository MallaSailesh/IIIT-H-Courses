.global binarysearch
binarysearch:
     # %rdi - a[]
     # %rsi - m
     # %rdx - l
     # %rcx - r
     cmpq %rdx , %rcx 
     jl .L1
     movq %rdx , %rax 
     addq %rcx , %rax
     movq $2 , %r11 # for dividing it by 2 
     cqto 
     idivq %r11  
     movq %rax , %r10 # %r10 is used for storing mid value 
     cmpq (%rdi,%r10,8) , %rsi
     je .L2
     cmpq (%rdi,%r10,8) , %rsi
     jl .L3
     incq %r10
     movq %r10 , %rdx 
     callq binarysearch
     ret
.L2:
     movq %r10,%rax
     ret
.L3:
     decq %r10
     movq %r10 , %rcx 
     callq binarysearch
     ret
.L1:  
    movq $-1 , %rax
    ret
    