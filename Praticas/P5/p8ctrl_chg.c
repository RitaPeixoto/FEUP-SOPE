#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <string.h>

#define MAX_SIZE 256
#define TIME 120000*1000 //2 minute

int main(){
    int fd, i=0, n=0;
    char msg[MAX_SIZE];

    fd = open("/tmp/fifo_chg", O_RDONLY);

    while(i<TIME){
        if(read(fd, &msg, MAX_SIZE)>0) 
            printf("Chegou %s\n",msg);
        usleep(500);
        i += 500;
        n++;
    }
    printf("Recebeu %d mensagens\n", n);
    close(fd);

    return 0;
}