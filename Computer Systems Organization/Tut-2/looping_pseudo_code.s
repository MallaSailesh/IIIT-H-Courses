.global fun

fun:
	cmp %rsi, %rdi
	# some condition (check using cmp)
	# If condition met 
	# jump to branchX (use commands like jle, jeq, jge etc.)
	# If condn not met jump back to this branch; Make sure you update the check values within this branch

# branchX
	# Some code
