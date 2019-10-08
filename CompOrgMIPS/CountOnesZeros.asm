.data
string1: .asciiz "Enter the integer: "
string2: .asciiz "Number of 0's: "
string3: .asciiz "Number of 1's: "
endl:	.asciiz "\n"
.text
.globl main
main:
	li $v0, 4		# printing the first prompt
	la $a0, string1
	syscall
	
	li $v0, 5		# reading the integer
	syscall
	
	move $a0, $v0		# saving the input in $a0
	

##store needed registers
	li $s0,0
	li $s1, 0
	li $t7 ,32
	move $t0 $a0
	
loop:	
	subi $t7,$t7,1			## increment counter
	srlv $t1, $t0, $t7		## shift right by counter
	
	beq $t1, $zero, inc_zero	## check if 0 or 1

	addi $s1, $s1, 1		## increment 1, check if done counting and loop if not
	beq $t7, $zero, Exit	
	j loop
inc_zero:
	addi $s0, $s0, 1		## increment 0, check if done counting and loop if not
	beq $t7, $zero, Exit
	j loop

Exit:




	li $v0, 4		# printing the "Number of 0's: " string
	la $a0, string2
	syscall
	
	move $a0, $s0		# printing the actual result
	li $v0, 1
	syscall
	
	la $a0, endl		# printing the newline
	li $v0, 4
	syscall
	
	li $v0, 4		# printing the "Number of 1's: " string
	la $a0, string3
	syscall
	
	move $a0, $s1		# printing the actual result
	li $v0, 1
	syscall
	
	li $v0, 10		# ending the program
	syscall
	
