#include <iostream>
#include <fstream>
#define t 100000
using namespace std;

int main(){

    fstream file;
    string string ;
    file.open("File.txt",ios::in); 
    
    if(!file){
        cout<<"inesistente il file";
        return 1;
    }
int  a=0,numeri[10];
char array[26]={0},c;


file>>c;
    while(!file.eof()){

        if(isalpha(c)){
            c= tolower(c);
        int indice = c - 'a';

        array[indice]++;

        }
     if(isdigit(c)){

        numeri[c-'0']++;
     }
    file>>c;
    }


    for ( int i=0;i<26;i++){
        char l= 'a'+i;
        cout<<"la lettera "<<  l << " è comparsa "<<array[i]<<endl;
        cout<<array[i];
    }

        for ( int i=0;i<10;i++){
 
        cout<<"il valore " <<i<< " è comparso " <<numeri[i]<<endl;
    }
    
    file.close();

    return 0;


}