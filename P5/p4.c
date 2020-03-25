//Program p4
#include <stdlib.h>
#include <stdio.h>
#include<sys/types.h>
#include <unistd.h>


#define READ    0
#define WRITE    1

int main(int argc, char * argv[]){
    int fd1[2],fd2[2];
    pid_t pid; 

    pipe(fd1);
    pipe(fd2);

    pid = fork();
    if(pid>0){//pai
        pid_t pid;
        pid = fork();
        if(pid >0){
            close(fd1[WRITE]);
            dup(fd1[WRITE]);
            execlp("ls","ls",argv[1],"-laR",NULL);
        }
        else{
            close(fd1[WRITE]);
            dup(fd1[WRITE]);
            close(fd1[READ]);
            dup(fd2[READ]);
            execlp("grep","grep",argv[2],NULL);

        }
    }
    else{//filho
        close(fd1[READ]);
        dup(fd1[READ]);
        execlp("sort","sort",NULL);
    }
}
