/*Si implementi in linguaggio C++ il template di funzione seleziona che
*/
#include <iostream>
using namespace std;

/*riceva in ingresso (ovvero come parametro) un array valori di oggetti del tipo generico T (che si suppone dotato degli operatori < e =), 
la sua dimensione d, 
un ulteriore oggetto v di tipo generico T 
e, per riferimento, un numero intero n. 
Il template di funzione restituisce come valore di ritorno un puntatore ad un oggetto di tipo T e opera come segue:*/
template <typename T>
T *seleziona(T valori[],int d,T v, int &n){
    //    Scandisce l’array valori e conta il numero di elementi minori di v assegnando a n tale valore,
    for(int i =0 ; i<d;i++){
        cout<<"scandisco l'elemento dell'array "<<valori[i]<<" paragonandolo all'elemento di v:"<<v<<endl;
        if(valori[i]<v){
            cout<<"il valore "<<valori[i]<<" è minore di v"<<endl;
            n++;
        }
    }


    //Se il risultato del conteggio (e quindi il valore di n) è maggiore di zero, 
    //dichiara un puntatore pval ad un oggetto di tipo T, alloca dinamicamente un array di n oggetti di tipo T e ne assegna il puntatore a pval.
    if((n>0)){
        cout<<"n è maggiore di 0, è: "<<n<<endl;
        T *pval=new T[n];
        //    Nel caso in cui l’allocazione abbia avuto successo, scandisce nuovamente l’array valori e copia ciascun elemento minore di v all’interno dell’array puntato da pval.

        int nn=0;
        if(pval!=nullptr){
            cout<<"allocazione andata a buon fine"<<endl;
            for(int i =0;i<d;i++){
                if(valori[i]<v){
                    cout<<"il valore "<<valori[i]<<" è minore di v e lo metto in pval"<<endl;
                    pval[nn]=valori[i];
                    nn++;
                }
            }
        }else{
            cout<<"Il puntatore puntava al vuoto"<<endl;
            return NULL;
        }
        //    Al termine della scansione restituisce il puntatore pval come valore di ritorno. 
        //Nel caso in cui non si siano trovati elementi minori di v (e quindi n valga zero) 
        //oppure l’allocazione dinamica non abbia avuto successo, il template di funzione restituisce NULL.

        return pval;
    }else{
        cout<<"n era nullo "<<endl;
        return NULL;
    }






}


int main(){

    //Esempio: assumendo di istanziare il template di funzione con il tipo int e di avere valori = {1, 2, 3, 4, 5, 2, 3, 0} (d = 8) e v = 2, 
    //allora si otterrà n = 2 (l’array dati contiene, cioè, 2 elementi minori di 2) e l’array puntato da pval sarà pval = {1, 0} 
    //(ovvero vi saranno copiati tutti gli elementi di valori minori di 2).*/

    int valori[8]={1,2,3,4,5,2,3,0};
    int d=8;
    int v=2;
    int n=0 ; 

    int *pvall=seleziona(valori,d,v,n);

        for(int i =0 ;i<v;i++){

            cout<<"risultato:"<<pvall[i];
        }


    return 0; 
}