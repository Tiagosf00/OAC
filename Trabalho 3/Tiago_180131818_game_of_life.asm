.data
	mat1: .byte
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0
	0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0
	0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 1 1 0 0 0 0 0 1 1 1 0 0 0
	0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0
	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	
	mat2: .byte
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	
	mov: .byte
	1 1
	1 0
	1 -1
	0 1
	0 -1
	-1 1
	-1 0
	-1 -1
	
	mat_color: .word

	0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc
	0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc 0xb3e5fc
	0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa
	0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa 0x81d4fa
	0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7
	0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7 0x4fc3f7
	0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6
	0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6 0x29b6f6
	0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4
	0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4 0x03a9f4
	0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5
	0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5 0x039be5
	0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1
	0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1 0x0288d1
	0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd
	0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd 0x0277bd
	
	
.text

la s0, mat1
la s1, mat2

run:

	# plot matrix
	jal plotm
	
	# sleep
	jal sleep
	
	# update matrix
	jal updatem
	
	# swap mat1 and mat2
	add s2, s0, zero
	add s0, s1, zero
	add s1, s2, zero
	
	# loop back
	b run



#	Update mat2 with the new frame
#
#	a0 = mat1 address
#	a1 = mat2 address
#	a3 = moviments
# 	a4 = moviments size
#	t1 = x coordinate
#	t2 = y coordinate
#	t3 = matrix dimension
#	t4 = number of neighbors

updatem: # initialize update

	add a0, s0, zero
	add a1, s1, zero
	li t1, 0
	li t2, 0
	li t3, 16

update: # update all cells in the matrix

	li t4, 0
	
	beq t2, t3, done # y == 16
	beq t1, t3, next_line_update # x == 16
	
	la a3, mov
	li a4, 8
	
	b count_neighbors
	
count_neighbors: # iterate the 8 neighbors
	beq a4, zero, process_neighbors
	addi a4, a4, -1 # decrement neighbors left
	
	add a5, t1, zero # copy x
	add a6, t2, zero # copy y

	lb a7, (a3) # dx
	addi a3, a3, 1
	add a5, a5, a7 # x += dx
	
	lb a7, (a3) # dy
	addi a3, a3, 1
	add a6, a6, a7 # y += dy

	blt a5, zero, count_neighbors # if x < 0
	blt a6, zero, count_neighbors # if y < 0
	
	bge a5, t3, count_neighbors # if x >= 16
	bge a6, t3, count_neighbors # if y >= 16
	
	# position = 16 * y + x
	
	mul t5, t3, a6 # 16 * y 
	add t5, t5, a5 # 16 * y + x
	

	add t6, s0, t5
	lb t5, (t6) # neighbor pixel
	
	add t4, t4, t5 # increment the number of neighbors
	
	b count_neighbors


process_neighbors: # update acording to the number of neighbors

	lb a5, (a0) # pixel mat1
	lb a6, (a1) # pixel mat2

	addi t5, zero, 2
	beq t4, t5, two_neighbors
	
	addi t5, zero, 3
	beq t4, t5, three_neighbors
	
	b other
	
	
two_neighbors: # same state
	add a6, a5, zero
	b update_pixel

three_neighbors: # alive state
	li a6, 1
	b update_pixel

other: # dead state
	li a6, 0
	b update_pixel

update_pixel: # update pixel
	sb a6, (a1)
	b next_column_update

next_column_update:

	addi a0, a0, 1
	addi a1, a1, 1
	addi t1, t1, 1
	b update


next_line_update:
	addi t2, t2, 1
	li t1, 0
	b update




#	Plot the frame on the Bitmap Display
#
#	a0 = matrix address
#	t0 = bitmap address
#	t1 = x coordinate
#	t2 = y coordinate
#	t3 = matrix dimension
#	t4 = color map address
plotm: # initialize plot
	add a0, s1, zero
	li t0, 0x00003000 # heap address
	li t1, 0
	li t2, 0
	li t3, 16
	la t4, mat_color
	b plot

plot:
	beq t2, t3, done # y == 16
	beq t1, t3, next_line_plot # x == 16

	lb a3, (a0) # pixel
	
	sw zero, (t0) # uncolor pixel
	beq a3, zero, next_column_plot # dead pixel
	lw a2, 0(t4) # color
	# li a2, 0x00ff0000
	sw a2, (t0) # paint pixel
	b next_column_plot
	
next_column_plot:
	addi a0, a0, 1
	addi t0, t0, 4
	addi t4, t4, 4
	addi t1, t1, 1
	b plot


next_line_plot:
	addi t2, t2, 1
	li t1, 0
	b plot


sleep:
	addi a7, zero, 32
	addi a0, zero, 300 # sleep 500ms
	ecall
	b done

done:
	ret

exit:
	addi a7, zero, 10
	ecall
