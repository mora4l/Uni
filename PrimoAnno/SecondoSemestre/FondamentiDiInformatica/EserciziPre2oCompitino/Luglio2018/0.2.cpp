/*
Si sviluppino, quindi, le seguenti funzioni in linguaggio C++: 
*/
/*
- La funzione somma che riceva come parametri un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero) e restituisca come valore di ritorno un numero reale. La funzione calcolerà 
la somma degli elementi di v per i quali il corrispondente elemento di m vale 1. 
*/
double somma(double v[],int m[],int dim){

    double somma=0;

    for(int i =0 ; i<dim;i++){
        if(m[i]==1){

            somma+=v[i];
        }
    }

    return somma;
}

/*
- La funzione media che riceva come parametri un array v di numeri reali, un array m di numeri interi e la loro 
dimensione dim (un numero intero) e restituisca come valore di ritorno un numero reale. La funzione calcolerà 
la media degli elementi di v per i quali il corrispondente elemento di m vale 1. 
*/

double media(double v[],int m[],int dim){

    double med=0,somma=0;
    int count=0;

    for(int i =0 ; i<dim;i++){
        if(m[i]==1){
            somma+=v[i];
            count ++;
        }
    }

    med=somma/count;

    return med;
}

/*
- La funzione main che operi come segue: dichiari un oggetto q di tipo ArrayOperations, utilizzando il costruttore 
con parametri cui vengano passati l’array di numeri reali x = {1.0, 2.0, 3.0}, l’array di numeri interi y = {1, 0, 1} 
e la loro dimensione dim = 3; chiami sull’oggetto q il metodo calcola della classe ArrayOperations passando 
come parametro per pf la funzione somma e stampi a video il risultato; chiami sull’oggetto q il metodo calcola 
della classe ArrayOperations passando come parametro per pf la funzione media e stampi a video il risultato. 
*/
int main(){

    return 0; 
}