# Program By: Casey Turner 10755330
# Section: B


.data	

promt: .asciiz "Enter a positive number (0 to quit): "
endPromt: .asciiz "List of prime numbers:"
space:	.asciiz " "
.text
.globl main

main:
	
	# Call convert()
	jal getPrime


	# Properly end program
	li $v0,10       # Exit program function
 	syscall         # Exit

getPrime: 
	addi $sp, $sp, -8 
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	li $v0, 4		# printing the first prompt
	la $a0, promt
	syscall
	li $v0, 5		# reading the integer
	syscall
	
	move $s0, $v0		# saving the input
	
	baseCase:
		bne $s0,$zero, skipBaseCaseLoop
		li $v0, 4		# printing the end prompt
		la $a0, endPromt
		syscall
		j return
	
	skipBaseCaseLoop:
		move $a0,$s0
		jal isPrime
		bne $v0,$zero,recurse
		
		
		li $v0, 4		# printing the first prompt
		la $a0, promt
		syscall
		li $v0, 5		# reading the integer
		syscall
	
		move $s0, $v0		# saving the input
		beq $s0,$zero,baseCase
		j skipBaseCaseLoop
		
	recurse:
		jal getPrime
		
		li $v0, 4		
		la $a0, space
		syscall
		
		move $a0, $s0
		li $v0, 1
		syscall
	
	return:
		lw $ra, 0($sp)
		lw $s0, 4($sp)
		addi $sp, $sp, 8
		jr $ra
		
		
isPrime:
	#check if 1,2,3
	move $t0, $a0
	blt $t0, 4, returnTrue
	
	#check if divisible by 2,3
	li $t1,2
	div $t0,$t1
	mfhi $t1
	beq $t1, $zero, returnFalse
	
	li $t1,3
	div $t0,$t1
	mfhi $t1
	beq $t1, $zero, returnFalse
	
	#check all others
	
	li $t1,5
	li $t2,2
	
	loop:
		mult $t1,$t1
		mflo $t3
		bgt $t3, $t0, returnTrue
		
		div $t0, $t1
		mfhi $t3
		beq $t3,$zero,returnFalse
		
		add $t1,$t1,$t2
		li $t3,6
		sub $t2,$t3,$t2
		j loop

	returnTrue:
		li $v0,1
		jr $ra
	returnFalse:
		li $v0,0
		jr $ra	
			
	
	
	
	
	
	


