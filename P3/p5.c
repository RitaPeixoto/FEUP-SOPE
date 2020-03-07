// PROGRAMA p4.c 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>


int main(void) {  
    pid_t pid,pid2, pidSon, pidSon2;
    int status;

    pid= fork();

    if(pid > 0) { //pai 
        pidSon = wait(&status);   
        printf(" friends!");     
    } 
    else { //filho
        pid2= fork();
        if(pid2 > 0) { //pai, anterior filho
            pidSon2 = wait(&status);   
            printf(" my");     
        } 
        else { //filho do filho
            printf("Hello"); 
            exit(1); 
        }  
        exit(2);
    }  
    printf("\n");  
    return 0; 
}