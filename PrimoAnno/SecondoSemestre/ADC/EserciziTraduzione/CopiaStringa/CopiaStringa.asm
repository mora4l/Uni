.data
src: .asciz "abcd"
dst: .asciz "    "

.text
.globl main
main:
la s1, src //carico nel registro s1 il puntatore al primo indirizzo dell'array src
la s0, dst //uguale per l'array dest


addi t0, s0, 0 //    char *pointerdest=dest; creo un puntatore che punti al primo indirizzo dell array dest
addi t1, s1, 0 //    char *pointersrc=src; - uguale per src

addi t4, x0, 1 //     int condition = 1 - creo una condizione per verificare poi se siamo alla fine dell'array

while:

lb t3, 0(t1)//         valoresrc=*pointersrc;  //prendo il valore puntato e lo metto in un registro

beq t3, x0, exit //prima controllo se non siamo mica al carattere terminatore ( \0 = x0 )

sb t3, 0(t0) //in caso non lo fossimo , faccio STORE BYTE in t3 dell' elemento puntato
addi t0, t0, 1 //        pointerdest+=1; //incremento tutti e due i puntatori

addi t1, t1, 1 //        pointersrc+=1; 

j while

   
exit:
li a7, 93       
ecall
