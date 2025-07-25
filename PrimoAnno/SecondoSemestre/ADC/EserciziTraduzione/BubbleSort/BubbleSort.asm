BubbleSort:
addi sp, sp, -20
sw s0, 0(sp) //int i 
sw s1, 4(sp) //int j
sw s2, 8(sp) //int n
sw s3, 12(sp) //per il vettore
sw ra, 16(sp) //per la chiamata a funzione

addi s1, a0, 0 //carico in s1 n
addi s3, a1, 0// carico in s3 il primo elemento di v
addi s0, x0, 0 //int i=0

fori: 
beq s0, s1, fineordinamento
addi s1, s0, 1

forj:
beq s1, s2, incrementai


slli t0, s0, 2 //t0= i*4
add t1, t0, s3 //t1= i*4+v
lw t2, 0(t1) //t4=v[i]

slli t3, s1, 2 //t3=j*4
add t4, t3, s3 //t4=j*4+v
lw t5, 0(t4) // t5=v[j]

ble t4, t5, swap

addi s1, s1, 1
j forj


incrementai:
addi s0, s0, 1
j fori

swap : 

addi t6, t5, 0
mv t5, t4
mv t4, t6

ret


fineordinamento:
lw s0, 0(sp)
lw s1, 4(sp)
lw s2, 8(sp)


exit:
li a7, 93
ecall
