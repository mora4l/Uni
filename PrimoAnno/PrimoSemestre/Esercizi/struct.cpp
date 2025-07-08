#include <iostream>
using namespace std;

struct Persona{
string nome ;
string cognome; 
int eta; 
bool gay ; 
};

void riempi (Persona persona[3]){
    for(int i =0 ; i<3;i++){
        cout<<"inserisci il nome della persona "<<i<<endl;
        cin>>persona[i].nome;

                cout<<"inserisci il nome della persona "<<i<<endl;
        cin>>persona[i].cognome;

                cout<<"inserisci eta della persona "<<i<<endl;
        cin>>persona[i].eta;
    }
}

void stampapersona(Persona persona[3]){

    for(int i =0 ; i<3;i++){

        cout<<"nome "<<i<< " "<<persona[i].nome<<endl;
                cout<<"cognome "<<i<< " "<<persona[i].cognome<<endl;
                        cout<<"eta "<<i<< " "<<persona[i].eta<<endl;
    }
}

int main(){

    Persona persona[3];
    riempi(persona);
    stampapersona(persona);
    return 0;
}