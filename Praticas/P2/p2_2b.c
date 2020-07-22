#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_FILE_LEN 512

int main(int argc, char * argv[]){ //o primeiro elemento do argv é o nome do programa

    int f1, f2,nr,nw;

    unsigned char buffer[MAX_FILE_LEN];

    if(argc!=3){//numero de argumentos na chamada da funçao insuficientes
        printf("The function call was not executed correctly\n");
        return 1;
    }

    f1= open(argv[1],O_RDONLY);
    if(f1 == -1){//erro a abrir o ficheiro source
        perror(argv[1]);
        exit(2);

    }











































    
    f2= open(argv[2],O_WRONLY|O_CREAT|O_EXCL,0644);
    if(f2==-1){//erro a abrir o ficheiro destination
        perror(argv[2]);
        close(f1);
        exit(3);
    }


    while((nr=read(f1,buffer,MAX_FILE_LEN))>0){
        if(nw = write(f2, buffer,nr)<=0 ||nw!=nr){
            perror(argv[2]);
            close(f1);
            close(f2);
            return 4;
        }
    }

    close(f1);
    close(f2);
    return 0;
}