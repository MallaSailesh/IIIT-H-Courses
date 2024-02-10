
.global gcd
.global	Quotient
.global Remainder
# %rdi :- m(first argument) %rsi :- n(second argument)
Quotient:
      movq $0 , %rax # used for calculating quotient 
	  movq $0 , %r10 # used for calculating number of negative arguments
	  cmpq $0 , %rsi  # checks if the second argument is zero or not 
	  je .L5 # if second arument is zero then jump to .L5 and return -1
	  cmpq $0 , %rdi # checks if the first argument is zero or not 
	  je .L6 # if first arument is zero then jump to .L6 and  return 0
.goback:
	  cmpq $0 , %rdi # comparing first argument with zero
	  js .L2 # if first argument is less than zero (i.e if signbit is set) jmp to .L2 
	  cmpq $0 , %rsi # comparing second argument with zero
	  js .L3 # if second argument is less than zero (i.e if signbit is set) jmp to .L3
	  cmpq $1 , %r10 # checks if there is one negative argument or not 
	  je .L4 # if there is one argument then jump to .L4
      cmpq %rsi ,%rdi # i am doing like this to check how many times first argument greater than second argument which is actually the quotient 
	  jge .L1  # jumps to .L1
	  ret # returning the value
.L1: # as first argument greater than second argument it enters here . 
      incq %rax # increases the quotient which was intialised to zero. i am doing like this to check how many times first argument greater than second argument which is actually the quotient 
	  subq %rsi ,%rdi # now decreasing the first argument by second argument 
	  cmpq %rsi ,%rdi # again checks if first argument is greater then or equal to second argument . 
	  jge .L1 # jumps to .L1
	  cmpq $1 , %r10 # now checks if only one   argument is negative or not
	  jne .complete
	  imulq $-1,%rax
	  ret # returning the value
.complete:
      ret # returning the value
.L2: 
      imulq $-1 , %rdi # converting the negative argument into positive then solve and finally multiply by -1 if number of negative arguments is -1 
	  incq %r10 # %r10 stores number of arguments which are negative 
	  jmp .goback # unconditional; jump
.L3:
      imulq $-1 ,%rsi  # converting the negative argument into positive then solve and finally multiply by -1 if number of negative arguments is -1
	  incq %r10 # %r10 stores number of arguments which are negative 
	  jmp .goback # unconditional; jump
.L4: # enters if there is one negative argument 
      cmpq %rsi ,%rdi # compares bith arguments
	  jge .L1 # if first argument is greater than second argument then go to .L1 
	  imulq $-1 , %rax # this multiplies the final value with if number of arguments which are negative is 1
	  ret # returning the value
.L5: 
      movq $-1 , %rax # as value cant be divided by zero . so for that we are returning -1
	  ret # returning the value
.L6:
      movq $0,%rax # if zero is divided by any number then the quotient is zero
	  ret # returning the value

Remainder:
	  pushq %rdi # pushing the value into stack so that the value is not lost
	  pushq %rsi  # pushing the value into stack so that the value is not lost
	  subq $0x10 , %rsp # as elements are added to stack. as stack grow upwards as elements add . so the address is decreased(0x10 == 16 bytes)
	  call Quotient # now calling the function Quotient and the Quotient is stored in %rax
	  addq $0x10 , %rsp # now as we are poping the elements we increase the address
	  popq %rsi # poping the values now
	  popq %rdi # poingt the value now 
	  cmpq $0 , %rsi 
	  jz .ZC # return directly if the n == 0
	  cmpq $0 , %rdi 
	  jz .ZC1 # return the value in %rsi directly if m == 0
	  imulq %rsi, %rax 
	  imulq $-1, %rax
	  addq %rdi , %rax # the above three operations are for performing (a = qb + r) r = a - qb;
	  ret 
.ZC:
	  ret
.ZC1:
      movq %rsi , %rax
	  ret


gcd: 
.goback21:
      cmpq $0,%rdi # check if the argument1 is negative
	  js .L23 # jumps to .L23 if it negative 
	  cmpq $0,%rsi # check if the argument2 is negative
	  js .L24 # jumps to .L23 if it negative 
      cmpq %rdi , %rsi # jmups if second element is greter than first element 
	  jg .change
.goback22:
      cmpq $0 , %rsi # as second element is smallest and postive only now check if it zero
	  je .L21 # if equal then return first argument 
.L22:
	  call Remainder # calling remainder 
	  movq %rsi , %rdi 
	  movq %rax , %rsi 
	  cmpq $0,%rax
	  jne .L22
	  movq %rdi , %rax # following euclids algortihm
	  ret # finally return 
.L23: 
      imulq $-1 , %rdi # as we calculate gcd of mod(a) and mod(b) we multiply by -1 if it negative 
	  jmp .goback21 # now goback
.L24:
      imulq $-1 ,%rsi # as we calculate gcd of mod(a) and mod(b) we multiply by -1 if it negative 
	  jmp .goback21 # now goback
.change:
     movq %rsi, %r10 
	 movq %rdi , %rsi 
	 movq %r10 , %rdi # above three lines :- now swaping the elements so that we make first element as gretest and second element as smallest 
	 jmp .goback22 # now go back
.L21:
     movq %rdi , %rax # return the first argument if second argument is equal to zero
	 ret
