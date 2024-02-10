.global matrix
matrix:
      movq $0,%r14 # %r14 :- i
      movq $0,%r10 # %r10 :- j
      movq $0,%r11 # %r11 :- k
    .repeat1:
      cmpq %r14 , %rdi
      jg .repeat2  
      ret
      .repeat2:
          cmpq %r10 , %rdx
          jg .L2
          movq $0,%r10
          incq %r14
          jmp .repeat1
          .L2:
              movq $0 , %r12 # %r12 - sum
          .repeat3:
              cmpq %r11 , %rsi 
              jg .L3
              movq %r14 , %r13
              imulq %rdx,%r13
              addq %r10 , %r13
              movq %r12 , (%r9,%r13,8)
              movq $0,%r11 
              incq %r10
              jmp .repeat2
              .L3:
              movq %r14 , %r13
              imulq %rsi,%r13
              addq %r11 , %r13 # %r13 is random register . it used as a helping register
              movq (%rcx,%r13,8) , %r15
              movq %r11 , %r13
              imulq %rdx,%r13
              addq %r10 , %r13
              imulq (%r8,%r13,8) , %r15
              addq %r15 , %r12
              incq %r11 
              jmp .repeat3
                  