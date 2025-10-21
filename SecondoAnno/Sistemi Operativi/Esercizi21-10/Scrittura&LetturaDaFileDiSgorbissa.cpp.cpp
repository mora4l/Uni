#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(){


/*     const char* filename="output.txt";

    int fd=open(filename,0_RDWR | 0_CREAT, 0644);

    pid_t pid= fork();

    if(pid>0){
        for(int i =0 ; i<10;i++){
            char buffer;
            buffer = '0' +i ; 
            write(fd,&buffer,1) ; 
        }
    }else{
        for(int i = 0 ;i<10;i++){
            char buffer ; 
            int bytesread = read(fd,&buffer,1) ; 
            cout<<buffer<<endl ;
        }
    } */
}