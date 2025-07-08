.data

.globl main
.text

main:

addi t0, x0, 1 //li uso per il primo if
addi t1, x0, 0 //li uso per il primo if
addi s3, x0, 5

addi s0, x0, -1     //int fibN = -1;
addi s1, x0, x0      //int fibNminus1; 
addi s2, s2, x0      //int fibNminus2;

beq s3, t0, salta //if con or n==1 o n==0
beq s3, t1, salta

addi s1, s1, 1 //ultimo valore
addi s2, s2, 0 //penultimo valore

addi s4, s4, 2 //int i =2

loop:

blt s3, s4, exit //ho fatto il for al contrario , cioe che se n è minore di i ,salta (la conzione sarebbe che il for va avanti fino a  i<=n

add s0, s1, s2 //        fibN = fibNminus1 + fibNminus2; 

addi s2, s1, x0 //        fibNminus2 = fibNminus1; 

addi s1, s0, x0
addi s4, s4, 1


j loop



salta:
li s0, 0
add s0, s0, s3
j exit

exit:
li a7, 93
ecall