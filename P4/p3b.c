//Programa p3b.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <time.h>
int aux =1;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("Increasing ...\n");
        aux = abs(aux);
    }
    else if(signo == SIGUSR2){
        printf("Decreasing ...\n");
        aux = -abs(aux);
    }
}   

int main(){
    pid_t pid;
    struct sigaction action;
    int v =0;
    int counter =0;

    sigemptyset (&action.sa_mask);
    action.sa_handler= usr_handler;
    if (sigaction(SIGUSR1,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");//case of error     
        exit(1);   
    }   
    if (sigaction(SIGUSR2,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");//case of error     
        exit(1);   
    }  

    if((pid = fork())<0){
        int s,signo;
        srand(time(NULL));
        for(int i =0; i<50; i++){
            s = rand() %2 +1; //generates either 1 or 2 randomly
            if(s ==1)
                signo = SIGUSR1;
            else
                signo = SIGUSR2;
            kill(pid, signo);
            sleep(1);
        }
    }
    else{
        for(int i=0; i<50; i++){
            sleep(1);
            printf("v = %d\n",v);
            v += aux;
            counter++;
        }
        exit(0);
    }
    exit(0);
}