//Programa p3.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
int aux =1;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("Increasing ...\n");
        aux++;
    }
    else if(signo == SIGUSR2){
        printf("Decreasing ...\n");
        aux--;
    }
}   

int main(){
    struct sigaction action;
    
    sigemptyset (&action.sa_mask);
    action.sa_handler= usr_handler;
    action.sa_flags= 0;
    if (sigaction(SIGUSR1,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");//case of error     
        exit(1);   
    }   
    if (sigaction(SIGUSR2,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");//case of error     
        exit(1);   
    }   
    while(1){                   
        sleep(1);
        printf("v = %d\n",aux);
    }
    exit(0);
}