//Programa p1c.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) {   //signal handler, called every time the process receives the signal with which is invoked
    printf("In SIGINT handler ...\n"); 
    sleep(30);
} 
int main(void) {   
    struct sigaction action;
    action.sa_handler= sigint_handler;
    sigemptyset (&action.sa_mask);
    action.sa_flags = 0:
    if (sigaction(SIGINT,&action,NULL) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGINT handler\n");//case of error     
        exit(1);   
    }  
    int sleep_left = 30; 
    printf("Sleeping for 30 seconds ...\n");   
    while(sleep_left>0){
        sleep_left = sleep(sleep_left); //suspends the process until it passes 30 seconds or it receives a signal and the signal handler returns
    } 
    printf("Waking up ...\n");   
    exit(0); 
}
