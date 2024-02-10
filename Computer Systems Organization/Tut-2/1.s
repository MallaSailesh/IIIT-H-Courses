.global add

add:
	add %rdi, %rsi
	movq %rsi, %rax
	ret
