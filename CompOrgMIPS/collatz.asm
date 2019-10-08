#Casey Turner section B
.data
    # Declare input output strings
    inputPromt: .asciiz "Input: "
    output: .asciiz "Output: "
.text
.globl main
main:
    #Print message to get input from user
    	li $v0, 4		
	la $a0, inputPromt
	syscall
    # Read integer
    	li $v0, 5		# reading the integer
	syscall
	
	move $a0, $v0		# saving the input in $a0
    
    add $v0, $zero, $zero # Zero return register

collatz:
    
	li $s0, 0		#counter
	move $s1, $a0		#n

	Loop:	ble $s1,1, Exit
		addi $s0,$s0, 1
		andi $t0,$s1,1
		beq $t0,$zero,Else	#check if even or odd
		sll $t1,$s1,1
		add $s1,$s1,$t1
		addi $s1, $s1,1
		j Loop

    	Else:	srl $s1, $s1,1
		j Loop
	Exit:
    
    	# Print output message
    	li $v0, 4
	la $a0, output
	syscall
    
    	# Print result
    	move $a0, $s0	
	li $v0, 1
	syscall

    li $v0,10       # Exit program function
    syscall         # Exit
