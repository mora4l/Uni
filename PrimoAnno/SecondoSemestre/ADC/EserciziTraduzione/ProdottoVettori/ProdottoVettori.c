#include <stdio.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
    int vectorA[5] = {1, 2, 3, 4, 5}; //s0
    int vectorB[5] = {2, 4, 6, 8, 10};//s1
    int result = 0;//s2
    int i = 0; //s3

    
    int valoreA = 0; //t0
    int valoreB = 0; //t1

    bool condizione = true; //t2
    
    int risultatointermedio = 0; //t3


    
    int *elementoA = vectorA; //t4
    int *elementoB = vectorB; //t5

    while (condizione)
    {

        valoreA = *elementoA;
        valoreB = *elementoB;

        risultatointermedio = valoreA * valoreB;
        result = result + risultatointermedio;

        i += 1;
        
        elementoB += 1;
        elementoA += 1; 


    }
    printf("result %d \n", result);
}