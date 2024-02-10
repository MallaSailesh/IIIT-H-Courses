.global bubblesort

bubblesort:
    movq $0,%r10 # %r10 is for cnt 
    movq $0,%r11 # %r11 is for i
    decq %rsi # now rsi contains n-1
.L1: 
    cmpq %r11,%rsi 
    jle .L2
    cmpq $0, %r10
    jg .L3
    ret
.L2:
     movq %r11,%rax
     ret
     movq (%rdi,%r11,8) , %r8
     incq %r11
     cmpq %r8 , (%rdi,%r11,8)
     jl .L4
     jmp .L1
.L3:
     call bubblesort
.L4:
     decq %r11
     movq (%rdi,%r11,8),%r8
     incq %r11
     movq (%rdi,%r11,8) ,%r12
     movq %r8 , (%rdi,%r11,8) 
     decq %r11
     movq %r12 , (%rdi,%r11,8)
     incq %r11
     incq %r10
     jmp .L1
