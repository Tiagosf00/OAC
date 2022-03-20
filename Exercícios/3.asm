.text
	
	add a0, zero, zero
	
readN:
	li a7, 5
	ecall
	add a1, a0, zero
	
readXi:
	beq a1, zero, showSum
	li a7, 5
	ecall
	add a2, a2, a0
	
	addi a1, a1, -1
	b readXi

showSum:
	add a0, a2, zero
	li a7, 1
	ecall	
exit:
	li a7, 10
	ecall