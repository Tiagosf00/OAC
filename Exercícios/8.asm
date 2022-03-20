.data 
	str: .space 32
	nl: .word 10

.text
	li a7, 8
	la a0, str
	li a1, 30
	ecall

	lw  a1, nl
	add a2, a0, zero
	jal limpa

	li a7, 4
	la a0, str
	ecall

	li a7, 10
	ecall

limpa:
	
	lb a3, (a2)
	addi a2, a2, 1
	bne a3, a1, limpa
	
	addi a2, a2, -1
	sb zero, (a2)

	ret