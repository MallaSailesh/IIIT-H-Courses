
.global checkbits
.text

checkbits:
	movq $0,%rax

whileloop:
	mov $1,%rbx
	and %rdi,%rbx
	add %rbx,%rax
	sar $1,%rdi
	jg whileloop

	and $1,%rax 	
	ret 

