.text

readABC:
	li a7, 5
	ecall
	add a1, a0, zero

	li a7, 5
	ecall
	add a2, a0, zero
	
	li a7, 5
	ecall
	add a3, a0, zero
	
	mul a4, a2, a3
	add a0, a1, a4
	
showAns:
	li a7, 1
	ecall

exit:
	li a7, 10
	ecall