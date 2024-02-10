.global q1
q1:
   # arr[] is %rdi , n is %rsi arr2[] is %rdx
   decq %rsi
   movq %rsp , %r10
.L2:
   cmpq $0 , %rsi
   js .L1
.L3:
   cmpq %rsp , %r10
   je .L7
   movq (%rdi,%rsi,8),%r11
   cmpq (%rsp) , %r11
   jge .L4
.L7:
   cmpq %rsp,%r10
   je .L5
   movq (%rsp),%r11
   movq %r11,(%rdx,%rsi,8)
.L6:
   pushq (%rdi,%rsi,8)
   decq %rsi
   jmp .L2
.L1: 
   cmpq %rsp,%r10
   jne .L8
   ret
.L4: 
   popq %r8
   jmp .L3
.L5:
    movq $-1,(%rdx,%rsi,8)
    jmp .L6
.L8:
    popq %r8
    jmp .L1

   