// PROGRAMA p8.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
int main(int argc, char *argv[], char *envp[]) {    
    pid_t pid;    
    if (argc != 2) {      
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
    }
    else if (pid == 0){      //Child process
        char *arg[]={"/bin/ls","-laR",argv[1],NULL};
        execv("/bin/ls",arg);      
        printf("Command not executed !\n");      
        exit(1);    
    }    
    exit(0);
}