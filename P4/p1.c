//Programa p1.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
void sigint_handler(int signo) {   //signal handler, called every time the process receives the signal with which is invoked
    printf("In SIGINT handler ...\n"); 
    //printf("Let's sleep\n");
    sleep(30); // b)
    //printf("Done\n");
    } 
int main(void) {   
    if (signal(SIGINT,sigint_handler) < 0) { //if the process receives a SIGINT signal, sigint_handler is called    
        fprintf(stderr,"Unable to install SIGINT handler\n");//case of error     
        exit(1);   
    }   
    printf("Sleeping for 30 seconds ...\n");   
    sleep(30);  //suspends the process until it passes 30 seconds or it receives a signal and the signal handler returns
    printf("Waking up ...\n");   
    exit(0); 
}

/*
a) In the first situation (using CRTL+C), the return value is 0


*/