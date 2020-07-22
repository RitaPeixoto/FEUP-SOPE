#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_FILE_LEN 512

int main(int argc, char * argv[]){ //o primeiro elemento do argv é o nome do programa

    int f1,nr,nw;

    unsigned char buffer[MAX_FILE_LEN];
    

    if(argc!=2){//numero de argumentos na chamada da funçao insuficientes
        printf("The function call was not executed correctly\n");
        return 1;
    }

    f1= open(argv[1],O_RDONLY);
    if(f1 == -1){//erro a abrir o ficheiro source
        perror(argv[1]);
        exit(2);

    }
        

    while((nr=read(f1,buffer,MAX_FILE_LEN))>0){
        if((nw =write(STDOUT_FILENO,buffer,nr))<=0 ||nw!=nr){
            perror(argv[1]);
            close(f1);
            return 3;
        }
        
    }
    close(f1);
    return 0;
}