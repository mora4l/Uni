/*
L’area di un triangolo di cui sono noti i lati a, b e c può essere calcolata, utilizzando la
formula di Erone, come dove . Si scriva un
programma in linguaggio C++ che chieda all’utente di immettere da tastiera le lunghezze
dei lati a, b e c (tre numeri reali), calcoli l’area A e ne stampi il valore a video. Per il calcolo
della radice quadrata si può usare la funzione di libreria sqrt, disponibile in <cmath>.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main (){

    float p=0,a=0,b=0,c=0,area=0;

    cin>> a;
    cin>> b;
    cin>> c;

    p=(a+b+c)/2;


    
    area=sqrt(p*(p-a)*(p-b)*(p-c));

    cout<< area ;

    return 0;
    
    }