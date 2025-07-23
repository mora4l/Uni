.globl main
.text
main:
//int m -> s0
//int A[][] -> s1
//int elementoCorrente -> t0

la s0, dim
la s1, matrix

addi s2, s1, 0 //int *matrice=A 
addi s3, x0, 0 //int indice=0 

addi t0, x0, 0 //int elementoCorrente=0 

li t1, 1 //mi serve per slti
while:
slti t2, s3, 100 //mette t2 a 1 se s3 (indice) è < 100
beq t2, t1, exit //se t2 = t1 skippa


sw t0, 0(s2) //int A[][]=0 scrive il valore di t0 nell elemento di memoria puntato da s2


addi s2, s2, 4 //incrementa lo scorrimento della matrice
addi s3, s3, 1 //i++

j while



exit:
li a7, 93
ecall

.data
matrix: .skip 4*10*10 //alloco una matrice di 10*10 , ogni elemento occupa 4 byte
dim: .word 10 //#define M 10