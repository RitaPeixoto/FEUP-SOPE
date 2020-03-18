//Programa p1b.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) {   //signal handler, called every time the process receives the signal with which is invoked
    printf("In SIGINT handler ...\n"); 
} 
int main(void) {   
    if (signal(SIGINT,sigint_handler) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGINT handler\n");//case of error     
        exit(1);   
    }   
    int sleep_left = 30;
    printf("Sleeping for 30 seconds ...\n");  
    
    while(sleep_left>0){
        sleep_left = sleep(sleep_left); //suspends the process until it passes 30 seconds or it receives a signal and the signal handler returns
    } //it will abort the current  action to execute the signal handler 
     
    printf("Waking up ...\n");   
    exit(0); 
}
