// PROGRAMA p4.c 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>


int main(void) {  
    pid_t pid, pidSon;
    int status;

    pid= fork();

    if(pid > 0) { //pai 
        pidSon = wait(&status);   
        printf(" world!");     
    } 
    else { //filho
        printf("Hello"); 
        exit(1); 
    }  
    printf("\n");  
    return 0; 
}