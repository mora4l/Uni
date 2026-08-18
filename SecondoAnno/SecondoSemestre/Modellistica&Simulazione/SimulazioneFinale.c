#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int main(){

//all'inizio tutti i robot sono disponibili
bool robot_1_disponibile = 0 ; 
bool robot_2_disponibile = 0 ; 
bool robot_3_disponibile = 0 ; 

//all'inizio tutti i robot sono pronti a caricare il massimo dei pacchi che riescono
int capacità_trasporto_robot_1 = 3; 
int capacità_trasporto_robot_2 = 3; 
int capacità_trasporto_robot_3 = 3; 

int pacchi_giornata_intera[47][8]; //Qui dentro ci inserisco i dati della tabella . Per ogni posizione kj so se una palazzina ha un nuovo pacco che deve essere consegnato (1) o no (0)

int pacchi_da_consegnare[8]; //qui mi salvo il numero totale di pacchi che ogni palazzina deve ricevere , in totale

for(int i = 0 ; i<8 ; i++){
pacchi_da_consegnare[i]= 0 ; //all'inizio nel collection point ci sono zero pacchi da consegnare
}

  

for(int k = 0; k<48 ; k++){//iterazione k della giornata


// PUNTO 1 
for(int j = 0 ; j<8 ; j++ ) {//controllo dei nuovi pacchi arrivati alla k-esima iterazione
pacchi_da_consegnare[j] = pacchi_giornata_intera[k][j]; //adesso ho tutti i pacchi che devono essere recapitati alle j palazzine
}



//PUNTO 2
for(int r = 0 ; r<8 ; r++) {//ci sono pacchi da consegnare ? 

if(pacchi_da_consegnare[r]>0){//se la palazzina r-esima ha almeno un pacco da consegnare , allora....

if(robot_1_disponibile == 0){
//assegno il pacco al robot 1
capacità_trasporto_robot_1 -- ; //un pacco è stato assegnato al robot 1

//ora controllo se il robot 1 può partire

if(capacità_trasporto_robot_1 == 3){//meccanismo di partenza del robot

robot_1_disponibile = 1; //il robot è partito , devo ora "smarcarmi" quel pacco dal collection point
pacchi_da_consegnare[r] --; 

}

}else if(robot_2_disponibile == 0 ){ //se l'1 non è disponibile controllo il 2
//assegno il pacco al robot 2
capacità_trasporto_robot_2 -- ; //un pacco è stato assegnato al robot 2

}else if(robot_3_disponibile == 0 ){//se l'1 non è disponibile controllo il 3
//assegno il pacco al robot 3
capacità_trasporto_robot_3 -- ; //un pacco è stato assegnato al robot 3
} 
}//altrimenti controllo la prossima palazzina e quel pacco di quella palazzina rimarrà nel collection point almeno fino alla prossima iterazione


}//ho finito di vedere se alla k-esima iterazione ci sono stati dei pacchi da consegnare

}//fine giornata

    return 0 ; 
}

