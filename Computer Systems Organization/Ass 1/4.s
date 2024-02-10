
.global largest_prime
.global	Quotient
.global Remainder
.global c_prime

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



c_prime:
      movq %rdi,%rsi # take two registers and push value into %rsi
	  decq %rsi # now decrement the value %rsi :- n-1 
      cmpq $1 , %rdi # if n is 1 then it is not prime . so return 0 ( i.e false ) 
      je .L34
      cmpq $0 , %rdi # if  n is less than zero than  then return  -1 
      jle .L32
	  cmpq $2 , %rdi # if  n is it prime  so returning one 
      je .L33
      cmpq $1,%rsi # if n-1 is not equal to 1 then go to block  .L31 and solve   
      jne .L31
.L32:
      movq $-1 , %rax
      ret
.L34:
      movq $0 , %rax
      ret
.L31:
	  pushq %rdi # pushing the values into the stack so that they are not lost 
	  pushq %rsi
	  subq $0x10 , %rsp # as elements are added stack grows up . so the address decrease
      call Remainder # calling the function Remainder 
      addq $0x10 , %rsp # now add the address to it as we are poping 
	  popq %rsi # poping the stored values 
	  popq %rdi
      decq %rsi # again decrease the value in %rsi . bascially we check if the value is divisible by any number from n-1 to 2 
      cmpq $0,%rsi # if the value decresed to zero then it is clear that there is no number from n-1 to 2 which is divides n
      je .L33
      cmpq $0 , %rax # else if the value in the register %rax is 0 i.e remainder is zero then it is divisible then return 0 because it is not prime
      jne .L31 # else jump if it not equal to zero or the number still is greter than or equal to 2 
      movq $0 , %rax
      ret
.L33:
      movq $1 , %rax
      ret
        
          ret

largest_prime:
      movq %rdi , %rsi # now move the value of first argument into register into the %rsi also 
	  cmpq $1,%rdi # now if the first argument is  1 then as one is not prime . so return -1
	  jle .L41
.goback4:
	  pushq %rdi # pushing the values into the stack so that they are not lost 
	  pushq %rsi
	  subq $0x10 , %rsp # as elements are added stack grows up . so the address decrease
	  call c_prime # calling the function c_prime 
	  addq $0x10 , %rsp # now add the address to it as we are poping 
	  popq %rsi # poping the stored values 
	  popq %rdi
	  cmpq $1,%rax # if it is 1 then it is prime 
	  je .complete1 # now checks if it is  a factor or not
      decq %rdi # if not prime then decrement the value and check from starting again
	  jmp .goback4 # and then jmp unconditionaly 
.complete1:
      movq %rdi , %r10 
	  movq %rsi , %rdi
	  movq %r10 , %rsi # above three lines are used for swapping the values in the registers because we should check the value in %rsi is divisible by value in %rdi . as first argument is %rdi . so we swapped 
	  pushq %rdi
	  pushq %rsi # pushing the values into the stack so that they are not lost 
	  subq $0x10 , %rsp # as elements are added stack grows up . so the address decrease
	  call Remainder
	  addq $0x10 , %rsp # now add the address to it as we are poping 
	  popq %rsi
	  popq %rdi # poping the stored values 
	  cmpq $0 , %rax # if it zero then we can confirm that 2nd argument divides first 
	  je .complete2 # now if eaul then jmp 
	  decq %rsi # or else then decrese the value of %rsi 
	  movq %rdi , %r10
	  movq %rsi , %rdi
	  movq %r10 , %rsi # now swap again so that %rsi  should be checked that if it prime or not 
	  jmp .goback4 # now unconditionaly goback 
.complete2:
      movq %rsi,%rax # copy the value of %rsi into %rax if both conditions prime and factor satisifies 
	  ret
.L41:
      movq $-1,%rax # if first argument is 1
	  ret
      
    