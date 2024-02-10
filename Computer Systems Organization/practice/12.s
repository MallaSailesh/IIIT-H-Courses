.global sum

sum:
   movq $0,%r10
   cmpq $0,%rdi
   jg .L1 
   movq %r10 , %rax
   ret
.L1:
   addq %rdi,%r10
   decq %rdi
   pushq %r10
   callq sum
   popq %r10
   addq %rax , %r10
   movq %r10 , %rax
   cqto
   idivq %rsi
   movq %rdx , %rax
   ret
