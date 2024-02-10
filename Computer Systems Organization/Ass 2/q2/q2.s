.global recursion

recursion:
   movq $0 , %r10
.L1:
   cmpq %rdi,%rsi
   jg .L5
   imulq $-1,%rsi
   cmpq %rdi,%rsi
   jg .L5
   cmpq $1,%rdi
   je .L2
   jmp .L6
.L2:
   cmpq $0 , %rsi
   je .L3
   cmpq $1 , %rsi
   je .L4
   cmpq $-1 , %rsi
   je .L4
.L3: 
   addq $2,%r10
   movq %r10,%rax
   ret
.L4: 
   addq $1,%r10
   movq %r10,%rax
   ret 
.L5:
   movq %r10,%rax
   ret
.L6:
   pushq %r10
   pushq %rdi
   pushq %rsi
   decq %rdi
   callq recursion
   imulq $2,%rax
   popq %rsi
   popq %rdi
   popq %r10
   addq %rax,%r10
   pushq %r10
   pushq %rdi
   pushq %rsi
   decq %rdi
   decq %rsi
   callq recursion
   popq %rsi
   popq %rdi
   popq %r10
   addq %rax,%r10
   pushq %r10
   pushq %rdi
   pushq %rsi
   decq %rdi
   incq %rsi
   callq recursion
   popq %rsi
   popq %rdi
   popq %r10
   addq %rax,%r10
   movq %r10,%rax
   movq $13 , %r11
   cqto
   idivq %r11
   movq %rdx,%rax
   ret
