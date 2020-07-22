#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h> 
#define MAX_FILE_LEN 512

int main(int argc, char * argv[]){ //o primeiro elemento do argv é o nome do programa

    int f1,f2,nr,nw;

    unsigned char buffer[MAX_FILE_LEN];

    f1= open(argv[1],O_RDONLY);
    if(f1 == -1){//erro a abrir o ficheiro source
        perror(argv[1]);
        exit(2);

    }
        
    if(argc==3){
        f2=open(argv[2],O_WRONLY|O_CREAT,0644);
        if(f2 == -1){//erro a abrir o ficheiro source
            perror(argv[2]);
            exit(2);
        }
    
        dup2(f2,STDOUT_FILENO);
    }
    while((nr=read(f1,buffer,MAX_FILE_LEN))>0){
        if((nw =write(STDOUT_FILENO,buffer,nr))<=0 ||nw!=nr){
            perror(argv[1]);
            close(f1);
            return 3;
        }    
    }
    if(argc ==3){
        close(f2);
    }
    close(f1);
    return 0;
}