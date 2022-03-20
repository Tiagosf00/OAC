.data

	ehpar: 	 .string "Eh par"
	ehimpar: .string "Eh impar"

.text
	
readN:
	li a7, 5
	ecall
	
	andi a0, a0, 1
	
	beq a0, zero, showPar
	b showImpar
	
showPar:
	li a7, 4
	la a0, ehpar
	ecall
	b exit

showImpar:
	li a7, 4
	la a0, ehimpar
	ecall
	b exit
exit:
	li a7, 10
	ecall