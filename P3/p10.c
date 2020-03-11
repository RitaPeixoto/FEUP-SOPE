// PROGRAMA p10.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[], char *envp[]) {    
    pid_t pid;
    int status;

    if (argc != 2 && argc!=3) {      
        printf("usage: %s dirname\n",argv[0]);      
        exit(1);    
    }

    pid=fork(); 
    //Checking for errors 
    if(pid<0){
        perror("Something is wrong\n");
        return 2;
    }

    else if (pid > 0) {  //Parent process   
         printf("My child is going to execute command              \"ls -laR %s\"\n", argv[1]); 
         wait(&status);  

    }
    else if (pid == 0){      //Child process
        if(argc==3){
            int p = open(argv[2],O_WRONLY|O_CREAT,0666);
            dup2(p,STDOUT_FILENO);
        }
        execlp("ls","ls","-laR",argv[1],NULL);
        printf("Command not executed !\n");      
        exit(1);    
    }    

    exit(0);
}