
.data:
vectorA:  .word 1,2,3,4,5
vectorB: .word 2,4,6,8,10
//vectorA= s0
//vectorB= s1
//int result = s2
//int i = s3
//int valoreA = t0
//int valoreB=t1
//bool condizione =t2
//int risultatointermedio=t3
//int *elementoA=t4
//int *elementoB=t5
.globl main
.text

main:

la s0, vectorA //carico in s0 l'indirizzo di memoria al primo elemento degli array
la s1 vectorB // uguale riga 10

addi s3, x0, 0 // int i =0 
addi s2, x0, 0 //int result = 0

addi t4, s0, 0 //int *elementoA=vectorA
addi t5, s1, 0//int *elementoB=vectorB

li t6, 1 //variabile che mi serve per capire se saltare ad exit o meno . se condizione = t6 (1=1) , salto

WHILE:

slti t2, s3, 5 // se i >=5 , condizione = 0 (set less than immediate)
bne t2, t6, exit//se condizione!=1  / brench if is not equal 

lw t0, 0(t4) //carica il valore puntato da t4 in t0 / valoreA= vectorA
lw t1, 0(t5)//carica il valore puntato da t5 in t1 / valoreB= vectorB

mul t3, t4, t1 //        risultatointermedio = valoreA * valoreB

add s2, s2, t3 //         result = result * risultatointermedio
addi s3, s3, 1 // i++

addi t4, t4, 4 //        elementoA += 1;
addi t5, t5, 4 //        elementoB += 1; / non è più 1 ma 4 poichè sono i byte 


j WHILE

exit:
li a7, 93;
ecall;

