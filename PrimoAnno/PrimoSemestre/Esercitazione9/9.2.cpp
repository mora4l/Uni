/*
Al fine di sviluppare un programma C++ per elaborare dati relativi a circonferenze:
− Si definisca la struttura punto2d: la struttura avrà come campi due numeri reali x e y.

− Si definisca la struttura circonferenza: la struttura avrà come campi tre numeri reali a, b,
c, che costituiscono i coefficienti dell’equazione x2 + y2 + ax + by + c = 0.

− Si scriva la funzione centro che riceva come parametro una struttura di tipo circonferenza
e restituisca come valore di ritorno una struttura di tipo punto2d. La funzione calcolerà e
restituirà il centro C della circonferenza calcolato come xC = -a/2, yC = -b/2.

− Si scriva, infine, la funzione main che chieda all’utente di inserire da tastiera, almeno una
volta e finché lo desidera, i coefficienti a, b e c dell’equazione di una circonferenza, chiami
la funzione centro e stampi a video le coordinate (xC, yC) del centro della circonferenza.
*/
#include <iostream>
using namespace std;

struct punto2d{
    double a=0,b=0;
};
struct circonferenza{
    double a=0,b=0,c=0;
};

punto2d centro(circonferenza &circ){
    punto2d punto;
    double xC=0,yC=0;

    punto.a= - circ.a/2;
    punto.b= -circ.b/2;

    return punto ;
}

int main(){

    circonferenza circ;
    punto2d p;
    
    while(1){
        cout<<"inserisci a: "<<endl;
        cin>>circ.a;
                cout<<"inserisci b: "<<endl;
        cin>>circ.b;
                cout<<"inserisci c: "<<endl;
        cin>>circ.c;


    p=centro(circ);

    cout<<"Il centro della circonferenza è "<<p.a<<";"<<p.b<<endl;

    }

    return 0;
}