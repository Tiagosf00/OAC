.data
	rsp:  .space 30
	size: .word 30
	
	a: .word 97
	z: .word 122

.text
	lw a5, a
	lw a6, z

	li a7, 8
	la a0, rsp
	add a2, a0, zero
	lw a1, size
	ecall

testChar:
	addi a1, a1, -1
	lb a3, (a2)
	
upperChar:
	blt a3, a5, nextChar
	bgt a3, a6, nextChar
	addi a3, a3, -32
	
nextChar:
	sb a3, (a2)
	addi a2, a2, 1
	beqz a1, showRsp
	b testChar

showRsp:
	li a7, 4
	ecall
	
exit:
	li a7, 10
	ecall