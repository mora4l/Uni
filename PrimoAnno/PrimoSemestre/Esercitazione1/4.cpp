/*Realizzare un convertitore Euro -> Lire, utilizzando come fattore di conversione il numero
intero costante 1936.*/

#include <iostream>
using namespace std;
#include <iostream>
#include <math.h>
using namespace std;


int main(){

    float euro=0,lire=0;
    char string [255] ="da definire";
    cout<< "inserisci il valore il euro: ";
    cin>> euro;

    lire = euro*1926;

    cout<< euro << " euro sono "<< lire<< " lire.";
    return 0;
}