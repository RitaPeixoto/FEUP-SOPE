//Programa p2c.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) {   
    printf("Entering  SIGINT handler ...\n");   
    sleep(10);   
    printf("Exiting  SIGINT handler ...\n");  
}
void sigterm_handler(int signo){
    printf("Entering  SIGTERM handler ...\n");   
    sleep(10);   
    printf("Exiting  SIGTERM handler ...\n");  
}


int main(void) {        
    struct sigaction action1,action2; 

    action1.sa_handler = sigint_handler;  
    sigemptyset(&action1.sa_mask);  
    action1.sa_flags = 0;  
    if (sigaction(SIGINT,&action1,NULL) < 0)  {        
        fprintf(stderr,"Unable to install SIGINT handler\n");        
        exit(1);  
    }

    action2.sa_handler = sigterm_handler;
    sigemptyset(&action2.sa_mask);
    action2.sa_flags=0;      

    if(sigaction(SIGTERM, &action2, NULL)<0){
        fprintf(stderr,"Unable to install SIGTERM handler\n");        
        exit(2);  
    }

    printf("Try me with CTRL-C ...\n");  
    while(1) 
        pause();  //it will only pause if a signal that has not been ignored  has a handler 
    exit(0); 
} 


