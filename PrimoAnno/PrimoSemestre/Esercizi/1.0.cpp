#include <iostream>
#include <fstream>

using namespace std;
void scrivi(fstream &file)
{
    int var = 0, varr = 0;
    for (int i = 0; i < 3; i++)
    {

        cout << "Inserisci due numeri :" << endl;
        cin >> var >> varr;
        file << var << " " << varr << endl;
    }
    cout << endl;
    file.close();
}

int conta(fstream &fileleggi)
{
    int conteggio = 0, numero = 0;
    fileleggi >> numero;
    while (!fileleggi.eof())
    {

        if (numero == 5)
        {
            conteggio++;
        }
        fileleggi >> numero;
    }
    fileleggi.close();
    return conteggio;
}

void punteggio(fstream &fileleggi)
{
    int puntoMax = 0;
    int giocatore1=0,giocatore2=0;
    int numero1 = 0, numero2 = 0;

    fileleggi >> numero1 >> numero2;
    
    while (!fileleggi.eof())
    {

        if(numero1>numero2){
            puntoMax=numero1;
            giocatore1++;
        }else{
            puntoMax=numero2;
            giocatore2++;
        }

        fileleggi >> numero1 >> numero2;
    }

    if(giocatore1>giocatore2){
        cout<<"ha vinto il primo coglione"<<endl;
    }else{
        cout<<"ha vinto il secondo"<<endl;
    }

}

int main()
{

    fstream file;
    fstream fileleggi;

    file.open("File.txt", ios::out);
    fileleggi.open("File.txt", ios::in);
    if (!file || !fileleggi)
    {
        cout << "uno dei due file non esiste";
        return 1;
    }

    scrivi(file);
    /*     int basta=conta(fileleggi);
        cout<<endl<< basta; */

    punteggio(fileleggi);

    return 0;
}