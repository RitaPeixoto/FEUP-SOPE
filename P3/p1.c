// PROGRAMA p1.c 
#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h>
int global=1; 
int main(void) {   
    int local = 2;   
    if(fork() > 0) {     //caso de ser o processo pai,se fosse processo filho retornava 0
        printf("PID = %d; PPID = %d\n", getpid(), getppid());     
        global++;     
        local--;   
    } 
    else {     //caso de ser o processo filho
        printf("PID = %d; PPID = %d\n", getpid(), getppid());     
        global--;     
        local++;   
    }   
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);   
    return 0; 
}

/*
b) repara-se que o PPID mantém-se porque é sempre o terminal que faz a chamada do processo filho
*/