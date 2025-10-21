Fattoriale: //dichiaro la funzione
addi sp, sp, -8 //alloco spazio in stack
sw s0, 0(sp) //n dichiaro il parametro della funzione
sw ra, 4(sp)// ra dichiaro il registro che salva l'indirizzo da cui ha saltato


addi t1, x0, 0 //inizializzo la variabile temporanea

beq s0, x0, impostaf //se il parametro è =0 , salta a impostaF
addi s0, s0, -1 //se no procedo 
jal ra, Fattoriale //qua chiamo ricorsivamente la funzione

lw t1, 0(sp) //e mi salvo s0 originale in t1 poichè mi serve
mul s0, s0, t1 //faccio la moltiplicazione che devo

lw ra, 4(sp) //ripristino ra dallo stack perche devo tornare all inizio
addi sp, sp, 8 //libero lo spazio
jr ra //salto al punto da cui sono partito


impostaf:
li s0, 1
lw ra, 4(sp)
addi sp, sp, 8
jr ra

exit:
addi sp, sp, 8
lw s0, 0(sp)
lw ra, 4(sp)

li a7, 93
ecall