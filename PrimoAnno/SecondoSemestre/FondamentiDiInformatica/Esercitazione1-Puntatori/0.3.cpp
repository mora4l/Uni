/*
Puntatori
[Esercizio C004] – Si scriva un programma C++ che operi come segue:
*/

#include <iostream>
using namespace std;

int main()
{
    /*
    • Dichiari due variabili a e b di tipo intero e le inizializzi a zero.
    • Dichiari quattro variabili c1, c2, c3 e c4 di tipo intero e le inizializzi a zero.
    • Dichiari la variabile r di tipo riferimento ad intero e le assegni la variabile a.
    • Dichiari le variabili puntatore pa e pb che puntino alle variabili a e b e la variabile puntatore ppa che punti al puntatore pa.
    • Dichiari il puntatore a costante pca che punti alla variabile a.

    */
    int a = 0, b = 0;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    int &r = a;

    int *pa = &a;
    int *pb = &b;
    int **ppa = &pa;

    const int *pca = &a;
    // • Legga da tastiera i valori di a e b e stampi a video i valori inseriti utilizzando i puntatori pa e pb. (inserisco valori rispettivamente a =1 e b=2)

    cout << "Inserisci a e b: " << endl;
    cin >> a >> b;

    cout << "i valori inseriti, usando i puntatori sono : " << *pa << "," << *pb << endl;
    // • Stampi a video i valori di pa e pb. Che cosa viene stampato? gli indirizzi di memoria di pa e pb

    cout << "i valori di pa e pb sono :" << pa << "," << pb << endl;
    // • Stampi a video il valore puntato da ppa. Che cosa viene stampato? viene stampato il valore puntato da pa che a sua volta è il valore di a , cioe 1

    cout << "il valore puntato da ppa:" << **ppa << endl;
    // • Stampi a video il valore puntato dal puntatore al quale ppa punta. Che cosa viene stampato? sempre 1 cazzo

    cout << "ppa punta a pa e ha il valore:" << *pa << endl;
    // • Stampi a video il valore puntato da pca. Che cosa viene stampato? sempre 1 minchia ,poiche pca punta ad a,che ha valore 1

    cout << "Il puntatore pca ha valore:" << *pca << endl;
    /*
    • Assegni a c1 il valore puntato da pa, a c2 il valore puntato dal puntatore al quale punta ppa, a c3 il valore puntato da
    pca e a c4 il valore di r. Stampi quindi a video i valori di c1, c2, c3 e c4. Che cosa viene stampato? Perché? c1 e c2 stampano la stessa cosa e ok , c3 stampa pca , cioè 1 poiche pca punta ad a ed infine r stampa il valore di a poiche anche lui si aggancia alla cella di memoria di a
    */
    c1 = *pa;
    c2 = *pa;
    c3 = *pca;
    c4 = r;

    cout << "i valori di c1 - c2 - c3 - c4 sono rispettivamente: " << endl
         << c1 << endl
         << c2 << endl
         << c3 << endl
         << c4 << endl;

    // Sommi 3 ad a e stampi a video il valore di a;

    a = a + 3;
    cout << "Il valore di a è : " << a << endl;
    // • Sommi 3 al valore puntato da pa e stampi a video il valore di a;

    *pa += 3;

    cout << "Il valore di a dopo che ho incrementato di 3 il valore del puntatore *pa è : " << a << endl;
    // • Sommi 3 al valore puntato dal puntatore al quale punta ppa e stampi a video il valore di a;

    *pa += 3;

    cout << "Il valore di a dopo che ho incrementato il puntatore *pa è : " << a << endl;
    // • Sommi 3 a r e stampi a video il valore di a.

    r += 3;

    cout << "Il valore di a dopo aver aumentato r di 3 è : " << a << endl;
    /*• Quale è l’effetto di queste operazioni sul valore della variabile a? Perché accade ciò che osserviamo
    nelle stampe dei valori di a dopo ciascuna operazione? l'effetto su di a è che incrementa ad ogni operazione , poiche stiamo aggiungendo numeri , alla fine , alla stessa cella di memoria. la seconda domanda è la prima domanda travestita
     */
    /*
    • Assegni ad a il valore di c1 e a pa il valore di pb e ripeta le operazioni le quattro operazioni svolte al
    punto precedente.
    */
    a = c1;
    *pa = *pb;

    cout << "ho dato ad a il valore di c1 e a pa il valore di pb" << endl;

    a = a + 3;
    cout << "Il valore di a è : " << a << endl;

    *pa += 3;

    cout << "Il valore di a dopo che ho incrementato di 3 il valore del puntatore *pa è : " << a << endl;

    *pa += 3;

    cout << "Il valore di a dopo che ho incrementato il puntatore *pa è : " << a << endl;

    r += 3;

    cout << "Il valore di a dopo aver aumentato r di 3 è : " << a << endl;
    /*
    • Al termine stampi a video anche il valore di b. Che cosa è successo? Perché accade ciò che
    osserviamo nelle stampe dei valori di a dopo ciascuna operazione e nella stampa finale del valore di
    b? non lo so mi sono rotto i coglioni. djiskra ha la botta dei santi a fare sti esercizi
    */

    cout << "Il valore di b è " << b << endl;
    return 0;
}