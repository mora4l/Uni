.globl main
.text
main:

la s0, dim //carico in s0 l' indirizzo di dim
la s1, matrice //carico in s1 l'indirizzo primo della matrice (primo elemento)

addi s2, x0, 0 //int i =0 
addi s3, x0, 0 //int j=0

addi s4, s1, 0 //int *puntatore=A
addi s5, x0, 0 //int byte=0
addi t0, x0, 0 //int byteintermedio =0
addi t1, x0, 0 //int indirizzomatrice=0

lw t2, 0(s0) //carico in t2 il valore dim 


fori:
bge s2, t2, exit //se i >= 10 , esce , se no mette j=0 e rinizia  a scorrere la colonna
addi s3, x0, 0 //int j=0

forj:
bge s3, t2, incrementai //se j>=10 , va ad incrementare la riga i 

mul t0, s2, t2 // inizio a costruire l'indirizzo che mi serve per accedere all'elemento ij ------- i*dim
add s5, t0, s3   // byte = byteintermedio+j
add t1, s4, s5   //indirizzomatrice = puntatore +byte

sw x0, 0(t1) // //*(indirizzomatrice)=0

addi s3, s3, 1 //j++

j forj

incrementai:
addi s2, s2, 1

j fori

exit:
li a7, 93
ecall

.data
matrice : .skip 4*10*10
dim: .word 10