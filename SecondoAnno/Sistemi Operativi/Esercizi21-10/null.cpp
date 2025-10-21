/*
si chiama null.c

crea un puntatore a intero e lo imposta a null
prova ad accedere all'area di memoria e lo stampa (deferenziare) 
*/

#include <iostream>
using namespace std;

int main(){

    int *p=NULL;

    cout<<&p<<endl;

    free(p); 

    return 0 ; 
}