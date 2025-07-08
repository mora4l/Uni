#include <stdio.h>
#include <stdbool.h>
int Fattoriale_Iterativa(int numero)
{


    int f = 1; //s0

    int i = numero; //s1
    bool condizione = true;//t1

    while (condizione)
    {

        do{
            f = f * i;
            i--;

        }while(i>0);
    }

    return f;
}