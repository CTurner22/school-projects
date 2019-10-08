# Program By: Casey Turner 10755330
# Section: B


.data	

binary_digit:		.word		0 1 1 1 0 0 0 1		# is 113 in decimal

.text
.globl main

main:
	# Load arguments to argument registers
	la $a0, binary_digit
	li $a1, 8		#hard coded size
	
	# Call convert()
	jal convert
	# Print return value
    	move $a0, $v0	
	li $v0, 1
	syscall
	# Properly end program
	li $v0,10       # Exit program function
 	syscall         # Exit

convert: 
	li $t0, 0
	li $v0, 0 
	li $t7, 1
	subi $t6, $a1, 1
	
	loop:	bge $t0,$a1, end_lp
		sll $t1, $t0, 2
		add $t1, $a0, $t1
		lw $t1, ($t1)	#t1 contains current bit
		beq $t1, $zero, skip #if bit is zero skip the rest of loop
		
		sub $t3, $t6, $t0	#get power index
		sllv $t2, $t7, $t3	#multiply by power
		add $v0, $v0,$t2	#add to result value
		
	skip:	addi $t0, $t0, 1
		j loop
		
	end_lp:	jr $ra


