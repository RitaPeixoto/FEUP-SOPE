#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <string.h>


int main(int argc, char * argv[]){
    int fd;

    if(argc!=2){
        printf("Function call was not executed correctly, Usage: %s <username>\n",argv[0]);
        exit(1);
    }

    do{
        printf("Waiting for server ...\n");
        fd = open("/tmp/fifo_chg ",O_WRONLY);
        sleep(1);
    }while( fd == -1);

    write(fd, argv[1], strlen(argv[1]+1));
    close(fd);

    return 0;
}