.global sum_of_square

sum_of_square:
       movq $0,%rax # moving the value zero into the register %rax
.goback5:
       cmpq $0,%rdi # comparing 0 with %rdi and if it is not equal to zero then jump to function calc
       jne .calc
       ret # returning the value
.calc:
       movq $1,%r10 # moving the value 1 into register
       imulq %rdi , %r10 # multiply with %rdi 
       imulq %rdi , %r10 # again do that so that we get the square of value in %rdi
       cmpq $0 , %r10
       js .L51 
.goback51:
       addq %r10,%rax # %rax stores the final value so we add the value to to %rax and stores in it 
       cmpq $0 , %rax
       js .L52 
.goback52:
       decq %rdi # decrement the value in %rdi and repeat the steps by jumping again
       jmp .goback5 # uncoditional jump
.L51:
       xor $2^63 , %r10
       jmp .goback51
.L52: 
       xor $2^63   , %rax
       jmp .goback52
