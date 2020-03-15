//Programa p2.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) {   
    printf("Entering SIGINT handler ...\n");   
    sleep(10);   
    printf("Exiting SIGINT handler ...\n");  
}


int main(void) {  
    struct sigaction action;  
    action.sa_handler = sigint_handler;  
    sigemptyset(&action.sa_mask);  
    action.sa_flags = 0;  
    if (sigaction(SIGINT,&action,NULL) < 0)  {        
        fprintf(stderr,"Unable to install SIGINT handler\n");        
        exit(1);  
    }  
    printf("Try me with CTRL-C ...\n");  
    while(1) 
        pause();  //it will only pause if a signal that has not been ignored  has a handler 
    exit(0); 
} 

/*
a) This program receives a signal and starts executing its handler, if during the time the handler is being executed
more signals are being produced these will be ignored and it will only compute the same signal once  

b) The process terminates
ps-u 
kill <process id>

*/