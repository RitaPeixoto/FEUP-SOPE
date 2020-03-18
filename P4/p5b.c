//Programa p5.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>

int status;
void handler(int signo){
    int pid;
    pid= wait(&status);
    printf("PARENT: child with PID=%d terminated               with exit code %d\n",pid,WEXITSTATUS(status));
}


int main(void) {  
    pid_t pid;   
    int i, n;
    struct sigaction action;

    action.sa_handler = handler;//to ignore the signal
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if(sigaction(SIGCHLD, &action, NULL)<0){
        fprintf(stderr,"Error in sigaction\n");        
        exit(1);  
    }

    for (i=1; i<=10; i++) {     
        pid=fork();

        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            sleep(15); // child working ...       
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());        
            exit(0);     
        }   
    }   

    printf("PARENT: working hard (task no. %d) ...\n",i);     
    n=20; 
    while((n=sleep(n))!=0);     



    exit(0); 
}
