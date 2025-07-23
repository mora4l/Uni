int M[]={10}; //s0
int A[M][M]; //s1


int i =0 ;  //s2
int j=0 ; //s3

int *puntatore=A; //s4

int byte=0; //s5
int byteintermedio=0; //t0

int indirizzomatrice=0   ; //t1
int *dim= M; //t2


while(i<M){
    j=0;

    while(j<M){

        byteintermedio=i*M;
        byte=byteintermedio+j;


        indirizzomatrice=puntatore+byte; 

        *(indirizzomatrice)=0;



        j++;
    }


i++;
}













for(int i = 0 ;i<M;i++){
    for(int j=0 ; j<M;j++){
        A[i][j]=0;
    }
}




































