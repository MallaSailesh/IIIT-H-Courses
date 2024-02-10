.global qsort
qsort:
     # %rdi - n
     # %rsi - a[]
     movq $0 , %rax
     movq (%rsi,%rax,8) , %r10 # pivot - %r10
     movq  %rdi , %r11 # i - %r11
     movq %rdi , %r9
     decq %r9 # j - %r9
.L1:
     cmpq $0,%r9
     jle .L3
     cmpq (%rsi,%r9,8) , %r10
     jl .L2
     decq %r9
     jmp .L1
.L2:
     decq %r11
     movq (%rsi,%r11,8) , %r12 # %r12 - temp
     movq (%rsi,%r9,8) , %r13  # %r13 - temp2 
     movq %r13 , (%rsi,%r11,8)
     movq %r12 , (%rsi,%r9,8)
     decq %r9
     jmp .L1
.L3:
     decq %r11
     movq (%rsi,%r11,8) , %r12 # %r12 - temp
     movq %r10 , (%rsi,%r11,8)
     movq %r12 , (%rsi,%rax,8)
     ret
