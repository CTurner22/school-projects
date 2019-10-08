# Program By: Casey Turner 10755330
# Section: B


.data
string1: .asciiz "Enter the number: "
string2: .asciiz "The number of unique digits: "
array: .word 40
endl:	.asciiz "\n"
.text
.globl main

main:
	li $v0, 4		# printing the first prompt
	la $a0, string1
	syscall
	
	li $v0, 5		# reading the integer
	syscall
	
	move $s0, $v0		# saving the number in $s0
	

	##store needed registers
	li $s1,0		# $s1 is the size of array that stores the unigue numbers
	li $s2,10		#used for mod and div
	la $s3, array
	
	##enter loop
	loop:	
		div $s0,$s2
		mflo $t0	
		mfhi $t1	#t1 contains number in question
		move $s0,$t0
		
			li $t3,0
		loop2:
			beq $t3,$s1,new_unique
		
			sll $t4, $t3, 2		#multiply counter by 4
			add $t4, $s3, $t4	#add to adress
			lw $t4, ($t4)		#t4 contains an already determined unique number from array
			beq $t1,$t4,done
			addi $t3,$t3,1		#inc and loop
			j loop2
			
		new_unique:			#save new unique
			sll $t3, $s1, 2		
			add $t3, $s3, $t3
			sw $t1, ($t3)
			addi $s1,$s1,1
		done:
		bne $t0,$zero,loop


	li $v0, 4		
	la $a0, string2
	syscall
	
	move $a0, $s1		
	li $v0, 1
	syscall

	
	li $v0, 10		# ending the program
	syscall
	
