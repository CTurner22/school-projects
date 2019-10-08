# Program By: Casey Turner 10755330
# Section: B


.data	
    inputA: .asciiz "Enter a: "
    inputB: .asciiz "Enter b: "
    output: .asciiz "LCM(a,b): "

.text
.globl main

main:

    #Print message to A input from user
    	li $v0, 4		
	la $a0, inputA
	syscall
    # Read integer
    	li $v0, 5		# reading the integer
	syscall
	move $s0, $v0		
    #Print message to B input from user
    	li $v0, 4		
	la $a0, inputB
	syscall
    # Read integer
    	li $v0, 5		# reading the integer
	syscall
	move $s1, $v0		# a in s0 and b in s1
    
    #call product
    	move $a0, $s0
   	move $a1, $s1
    	jal product
    	move $s2, $v0
    
    #call GCD
    	move $a0, $s0		
   	move $a1, $s1
	jal GCD
	move $s3, $v0
	div $s2, $s3
	
    # Print return value
        la $a0, output
	li $v0, 4
	syscall	
	
    	mflo $a0	
	li $v0, 1
	syscall			
		

    # Properly end program
	li $v0,10       # Exit program function
 	syscall         # Exit



GCD:	##USED RECURSION FROM C++ EXAMPLE

		bne $a1, $zero, recurse
		move $v0, $a0
		jr $ra

	recurse:
		addi $sp, $sp, -12 ##only need to store return adress, arguements so it doesnt keep recursing on base case
		sw $ra, 0($sp)
		sw $a0, 4($sp)
		sw $a1,8($sp)
		
		div $a0, $a1	##set new arguements
		mfhi $t0
		move $a0, $a1
		move $a1,$t0
		jal GCD		##recurse
		lw $ra, 0($sp)
		lw $a0, 4($sp)
		lw $a1, 8($sp)
		
		addi $sp, $sp, 12
		jr $ra ##return
		
product:	##USED OPTIMIZED ALGORITHM

		#multiplier and product should be one 64 bit register with multiplier as lo and product starting as high and ending as the lo,
		#but since they are two seperate 32 bit regiters, its basically the same to just shift the multiplican left instead of the entire 64 bits right
		#and worrying about the flow of bits from the hi to the lo when shifting
		
		move $t0, $a0 ##A is multiplican
		move $t1, $a1 ##B is multiplier
		li $t2, 0 ## t2 is product
		li $t3, -32 ##t3 is counter
	Loop:
		beq $t3, $zero, Exit	##begin loop
		andi $t9, $t1, 1
		beq $t9, $zero, skipAdd
		add $t2,$t2,$t0	##update product
	skipAdd:
		sll $t0, $t0,1	## shift
		srl $t1, $t1, 1
		addi $t3, $t3, 1 #incre counter
		j Loop
	Exit:
		
		##mult $a0,$a1
		##mflo $v0
		move $v0, $t2
		jr $ra	
		
