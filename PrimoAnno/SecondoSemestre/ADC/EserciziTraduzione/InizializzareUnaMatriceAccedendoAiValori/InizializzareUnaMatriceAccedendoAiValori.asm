.globl main 
.text
main:

la s0, dim
la s1, matrice

lw t0, 0(s0)

fori:
bge s2, t0, exit //se i>= dim , esce
addi s3, x0, 0 //int j=0

forj:
bge s3, t0, incrementai

mul t1, s2, t0 //int rismedio= i*dim
add t1, t1, s3 //int rismedio=i*dim+j
slli s4, s4, 2// rismedio in byte
add t2, s1, t1 //A[i][j]

sw x0, 0(t2) //A[i][j]=0

addi s3, s3, 1

j forj

incrementai:
addi s2, s2, 1
j fori

exit:
li a7, 93
ecall

.data
matrice: .skip 4*10*10
dim: .word 10