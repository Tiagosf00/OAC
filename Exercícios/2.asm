.text
	li a7, 5
	ecall
	add a1, a0, zero
	
	li a7, 5
	ecall
	
	add a0, a0, a1

	li a7 1
	ecall
	b exit
	
exit:
	li a7, 10
	ecall