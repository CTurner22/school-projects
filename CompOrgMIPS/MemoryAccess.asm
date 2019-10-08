.data
	a: .word 1, 5, 12, -1, 15, 18, 33, 7, 0, 222
	string1: .asciiz "Enter an index from 1 to 8: "
	string2: .asciiz "Value at index "
	string3: .asciiz " before modification: "
	string4: .asciiz " after modification: "
	endl:	.asciiz "\n"
	
.text
.globl main
main:

	li $v0, 4		# printing the first prompt
	la $a0, string1
	syscall
	
	li $v0, 5		# reading the integer
	syscall
	move $s0, $v0		# saving the input in $s0
	 
	sll $t0,$s0,2
	lw $s1, a($t0)		#accessing array at offset
	
	li $v0, 4		# printing the first index and number
	la $a0, string2
	syscall
	li $v0, 1		
	move $a0, $s0
	syscall
	li $v0, 4
	la $a0, string3
	syscall
	move $a0, $s1		
	li $v0, 1
	syscall
	
	addi $t0,$s0,1		#accessing array at offset i+1
	sll $t0,$t0,2
	lw $s2, a($t0)
	
	subi $t0,$s0,1		#accessing array at offset i-1
	sll $t0,$t0,2
	lw $s3, a($t0)
	 
	add $s1, $s2, $s3	#sum numbers and save into array
	sll $t0,$s0,2
	sw $s1, a($t0)		
	
	li $v0, 4		# printing the index and number after modification
	la $a0, endl
	syscall
	la $a0, string2
	syscall
	li $v0, 1		
	move $a0, $s0
	syscall
	li $v0, 4
	la $a0, string4
	syscall
	
	sll $t0,$s0,2
	lw $t1, a($t0)		#accessing array at offset
	move $a0, $t1		
	li $v0, 1
	syscall

	 
	 
	# Exit  
	li $v0, 10
	syscall
	 
