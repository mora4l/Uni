#include <iostream>
#include <unistd.h>   //per la fork
#include <sys/wait.h> //per la wait
#include <fstream>
using namespace std;

/*
aprire un file in lettura-scrittura 
chiama la fork per creare un figlio 
nel padre scrive 10 numeri crescenti sul file 
nel figlio legge 10 numeri e li stampa
*/

int main(){

    fstream file ; 
    fstream filelettura;
//aprire un file in lettura-scrittura 

        file.open("File.txt",ios::out);
        filelettura.open("File.txt",ios::in);

//chiama la fork per creare un figlio 
        pid_t pid =fork();
        
        
        
        if(pid==0){ //figlio
//nel figlio legge 10 numeri e li stampa

int numeri[10]={0};


for(int i= 0 ; i<10;i++){

    filelettura>>numeri[i]; 
}

for(int i= 0 ; i<10;i++){

    cout<<"i numeri nel file sono : "<<numeri[i]<<endl; 
} 
           

            
            
        }else{ //padre
//nel padre scrive 10 numeri crescenti sul file 

            for(int i =0 ; i<10;i++){
             file<<i <<endl;
            }


        }


        file.close();

    return 0 ; 
}