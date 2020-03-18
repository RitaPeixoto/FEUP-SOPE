//Programa p4.c
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>


int main(void) {  
    pid_t pid;   
    int i, n, status;   
    for (i=1; i<=3; i++) {     
        pid=fork();

        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            sleep(i*7); // child working ...       
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());        
            exit(0);     
        }   
    }   
    for (i=1 ;i<=4; i++ ) {      //only starts after the 3 first exited
        printf("PARENT: working hard (task no. %d) ...\n",i);     
        n=20; while((n=sleep(n))!=0);     
        printf("PARENT: end of task no. %d\n",i);     
        printf("PARENT: waiting for child no. %d ...\n",i);     
        pid=wait(&status);     
        if (pid != -1)       
        printf("PARENT: child with PID=%d terminated               with exit code %d\n",pid,WEXITSTATUS(status));   
    }   
    exit(0); 
}
/*
The output of this program is:
    PARENT: working hard (task no. 1) ...
    CHILD no. 2 (PID=6263) working ... 
    CHILD no. 1 (PID=6262) working ... 
    CHILD no. 3 (PID=6264) working ... 
    CHILD no. 1 (PID=6262) exiting ... 
    CHILD no. 2 (PID=6263) exiting ... 
    PARENT: end of task no. 1
    PARENT: waiting for child no. 1 ...
    PARENT: child with PID=6262 terminated               with exit code 0
    PARENT: working hard (task no. 2) ...
    CHILD no. 3 (PID=6264) exiting ... 
    PARENT: end of task no. 2
    PARENT: waiting for child no. 2 ...
    PARENT: child with PID=6263 terminated               with exit code 0
    PARENT: working hard (task no. 3) ...
    PARENT: end of task no. 3
    PARENT: waiting for child no. 3 ...
    PARENT: child with PID=6264 terminated               with exit code 0
    PARENT: working hard (task no. 4) ...
    PARENT: end of task no. 4
    PARENT: waiting for child no. 4 ...

We can notice something is wrong because:
    The child number 2 starts working before child no 1
    Still they finish at the correct order: child 1 first and child 2 second
    

*/