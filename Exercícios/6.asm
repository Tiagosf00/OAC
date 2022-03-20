.text
	add a1, zero, zero
readN:
	li a7, 5
	ecall
	
countBit:
	beq a0, zero, showSum
	
	add a2, zero, zero
	andi a2, a0, 1
	add a1, a1, a2
	srli a0, a0, 1
	
	b countBit

showSum:
	add a0, a1, zero
	li a7, 1
	ecall
	b exit

exit:
	li a7, 10
	ecall