//Programa p6.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

void alarm_handler(int signo){
    pid_t pid; 
    int status;
    pid = wait(&status);
    

}

int main(int argc, char * argv[]){
    pid_t pid;
    if(argc <3){
        printf("The fucntion call was not executed correctly\n");
        exit(1);
    }

    signal(SIGALARM, alarm_handler);
    pid = fork();


    if(pid ==0){//child process 
        execvp(argv[2],&argv[2]);   
    }
    else if(pid >0){//parent process
        alarm(30);
        waitpid(pid, &status, WUNTRACED);
    }
    else{
        fprintf("Unable to fork\n");
        exit(1);
    }
    exit(0);
}



