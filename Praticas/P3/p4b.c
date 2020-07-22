// PROGRAMA p4.c 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>


int main(void) {  
    pid_t pid, pidSon;

    pid= fork();

    if(pid > 0) { //pai   
        printf("Hello"); 
        exit(1);     
    } 
    else { //filho
        printf(" world!"); 

    }  
    printf("\n");  
    return 0; 
}

/*
O fork retorna duas vezes, primeiro o pai depois o filho. Ou seja faz print hello , print newline, print world caso nao haja o exit(1)
*/