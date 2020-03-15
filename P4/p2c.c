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

    if(sigaction(SIGTERM, &action, NULL)<0){
        fprintf(stderr,"Unable to install SIGTERM handler\n");        
        exit(2);  
    }

    printf("Try me with CTRL-C ...\n");  
    while(1) 
        pause();  //it will only pause if a signal that has not been ignored  has a handler 
    exit(0); 
} 


/*
We can use the same handler since we want to do the same thing

*/
