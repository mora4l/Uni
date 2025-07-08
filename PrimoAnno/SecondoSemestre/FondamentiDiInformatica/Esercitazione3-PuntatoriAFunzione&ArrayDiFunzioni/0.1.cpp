/*

• Scrivi un il programma abbia lo scopo di gestire un vettore di 5 interi attraverso tre funzioni:
leggi_vettore, stampa_vettore e somma_vettore:
• leggi_vettore: Chiede all'utente di inserire gli elementi nel vettore,
• stampa_vettore: Stampa gli elementi del vettore,
• somma_vettore: Calcola la somma degli elementi del vettore e stampa il risultato .
• Tutte tre le funzioni non restituiscono alcun risultato.
• Il programma principale utilizza un array di puntatori a funzione per consentire eseguire tutte tre
operazioni attraverso un Il ciclo for nel seguente ordine: leggi, stampa, somma
*/

#include <iostream>
using namespace std;

void leggi_vettore(int *a)
{

    cout << "inserisci gli elementi del vettore" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> *(a + i);
    }
}
void stampa_vettore(int *a)
{
    for (int i = 0; i < 5; i++)
    {
        cout << *(a + i);
        cout << endl;
    }
}
void somma_vettore(int *a)
{
    int somma = 0;
    for (int i = 0; i < 5; i++)
    {
        somma += *(a + i);
    }
    cout << "somma:" << somma;
}
int main()
{

    int a[5] = {0};

    void (*p[3])(int *) = {leggi_vettore, stampa_vettore, somma_vettore};

    for (int i = 0; i < 3; i++)
    {
        (*p[i])(a);
    }

    return 0;
}