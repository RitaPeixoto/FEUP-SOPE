//Program p3b
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h> 
#define READ 0 
#define WRITE 1 

int main(int argc, char *argv[]) {  
    int fd[2];
    pid_t pid;
  
    
    if(pipe(fd)<0){
        fprintf(stderr, "pipe error \n");
        exit(1);
    }
    pid = fork();
    if(pid>0){
        close(fd[READ]);
        dup2(fd[WRITE],STDOUT_FILENO);
        execlp("cat","cat",argv[1],NULL);   
    } 
    else{
        close(fd[WRITE]);
        dup2(fd[WRITE],STDIN_FILENO);//ligar a standard input à saida do pipe
        execlp("usr/bin/sort","usr/bin/sort",NULL);
    }
   exit(0);   
}