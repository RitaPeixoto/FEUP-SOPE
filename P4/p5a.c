//Programa p5.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>


int main(void) {  
    pid_t pid;   
    int i, n, status;
    struct sigaction action;

    action.sa_handler = SIG_IGN;//to ignore the signal
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if(sigaction(SIGCHLD, &action, NULL)<0){
        fprintf(stderr,"Error in sigaction\n");        
        exit(1);  
    }

    for (i=1; i<=3; i++) {     
        pid=fork();

        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            sleep(i*7); // child working ...       
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());        
            exit(0);     
        }   
    }   
    for (i=1 ;i<=4; i++ ) {      //only starts after the 3 first exited
        printf("PARENT: working hard (task no. %d) ...\n",i);     
        n=20; 
        while((n=sleep(n))!=0);     
        printf("PARENT: end of task no. %d\n",i);     
        printf("PARENT: waiting for child no. %d ...\n",i);  

        //pid=waitpid(-1,&status,WNOHANG);     
        if (pid != -1)       
        printf("PARENT: child with PID=%d terminated               with exit code %d\n",pid,WEXITSTATUS(status));   
    }   
    exit(0); 
}
