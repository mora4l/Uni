#include <stdio.h>
#include <stdbool.h>
int FibonacciIterativa(int n) { //s3
int fibN = -1;   // s0
int fibNminus2; //s2
int fibNminus1; //s1
 
if ( n==0 || n==1 ) {
    fibN = n; 

}


else {     // ad ogni iterazione ricordare gli ultimi due valori calcolati 
     // nelle iterazioni precedenti 

 fibNminus2 = 0;   // penultimo valore 
 fibNminus1 = 1;   // ultimo valore 

    int i =2; //s4
    bool condizione = true; 

    while (condizione){ // se i >= n -> se n< i 
        
        fibN = fibNminus1 + fibNminus2; 
        fibNminus2 = fibNminus1; 
        fibNminus1 = fibN; 
        i++;


    }



 } 
return fibN; 
} 
 
