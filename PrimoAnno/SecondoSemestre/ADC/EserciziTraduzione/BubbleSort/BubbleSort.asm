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
//i*4+array
lw t2, 0(t1) //t2=v[i]

slli t3, s1, 2 //t3=j*4
add t4, t3, s3 //t4=j*4+v
lw t5, 0(t4) // t5=v[j]

ble t5, t2, noswap

addi t6, t2, 0 //int temp= v[i]
sw t5, 0(t1) // in v[i] ci devo mettere v[j] , quindi : in t5 io avevo salvato il valore di v[j] , io invece l'indirizzo di v[i] lo ho in 0(t1) . quindi devo dire che in 0(t1) ci va il valore contenuto in t5
sw t6, 0(t4) //v[j] = v[i]

addi s1, s1, 1
j forj


incrementai:
addi s0, s0, 1
j fori

noswap:
add s1, s1, 1
j forj

addi t6, t5, 0
mv t5, t4
mv t4, t6

ret


fineordinamento:
lw s0, 0(sp)
lw s1, 4(sp)
lw s2, 8(sp)
lw s3, 12(sp)
lw ra, 16(sp)
add sp, sp, 20
ret


exit:
li a7, 93
ecall
