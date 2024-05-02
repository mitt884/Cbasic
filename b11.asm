.data
	Name: .space 100
	Temp: .space 100
	Space: .asciiz " "
	Message1: .asciiz "Hay nhap vao ten (duoi 100 ki tu): "
	Message2: .asciiz "\n Ten dao nguoc la: "
	
	
.text
	
	li $v0, 54                #input Name from the keyboard
	la $a0, Message1
	la $a1, Name
	la $a2, 100               #space = 100
	syscall 
	
	li $t0, 0         #index i = 0
	la $s0, Name     

		
	jal printReversedName 
	
	
#------------------------------------------------
#print reversed Name


	li $v0, 10      #exit
	syscall 
	
#-----------------------------------------------
#print Reversed Name
	
printReversedName:
	 addi $t1, $t1, -1    #init lastSpaceIndex
			
	 addi $t0, $t0, 0     #find location of last space index, index i = 0

      #Find last space of the Name inputed from the keyboard
	Find_last_space: 
		lb $t2, ($a0)              #load Name[i]
		beq $t2, $zero, end_Find_last_space  #for(int i=0; Name[i] != '\0'; i++)
		
		beq $t2, ' ', update_last_space_index    #if Name[i] == ' '
		
		addi $a0, $a0, 1                         #i=i+1
		addi $t1, $t1, 1                         #lastSpaceIndex += 1
		j Find_last_space
		
	      update_last_space_index:
			move $t0, $t1        # update lastSpaceIndex = i
    			addi $a0, $a0, 1     #i=i+1
    			addi $t1, $t1, 1     #lastSpaceIndex += 1
    			j Find_last_space
		
	end_Find_last_space: 
	
	
     #copy name to temp
     la $t3, Temp           # $t3 = address of temp
     
     strcpy:
     	add $t4, $s0, $t0     #$t4 = $s0 + $t3 = Name[0] + i = address of Name[i]
     	lb $t5, 0($t4)        #$t5 = value at $t4 = Name[i]
     	add $t6, $t0, $t3     #$t6 = $t0 + $t3 = i + temp[0] = address of temp[i]
     	sb $t5, 0($t6)        #temp[i] = $t5 = Name[i]
     	beq $t5, $t1, end_strcpy #if Name[i] == t1, exit
     	addi $t0, $t0, 1        #i=i+1
     	j strcpy
     end_strcpy: 


 beq $t1, -1, print_original    #if(lastSpaceIndex != -1), else print original
    la $a0, Name
    addi $a0, $a0, 1     
    add $a0, $a0, $t1              #name + lastSpaceIndex  
    
    li $v0, 4
    la $a0, Message2
    syscall 
    
    li $v0, 4
    la $a0, Name
    syscall 
    
    li $v0, 4
    la $a0, Temp
    syscall
    
    li $v0, 4
    syscall
    j end
    
print_original:
    la $a0, Name
    li $v0, 4
    syscall
    
    
end:
    jr $ra	