.global fun

fun:
	cmp %rdi, %rsi
	jle .branch
	mov $0, %rax
	ret

.branch:
	mov $1, %rax
	ret
