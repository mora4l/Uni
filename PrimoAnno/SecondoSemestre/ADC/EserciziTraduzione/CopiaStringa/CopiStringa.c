char *strcpy(char dest[], const char src[]) { 
    //char dest s0
    //char src s1
    int i = 0 ; ///s2

    char *pointerdest=dest; //t0
    char *pointersrc=src; //t1

    char valoredest; //t2
    char valoresrc; //t3
    int condition = 1 ;//t4

    while(condition){
        valoredest=*pointerdest;
        valoresrc=*pointersrc; 

        if(valoresrc=='\0'){
            condition = 0 ; 
        }

        valoredest=valoresrc;

        pointerdest+=1;
        i++;
    }





 return dest; 
 }