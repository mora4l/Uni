.data


.globl main
.text

main:
addi s0, s0, 1 //int f=1 ; 
li s1, 5 //int i = numero (5)


while:

beq s1, x0, exit
mul s0, s0, s1

addi s1, s1, -1

j while

exit: 
li a7, 93
ecall