// PROGRAMA p9.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>


/*
kill pid
./hello / --> vai executar um diretorio com muito ficheiros
./hello .. --> vai executar o diretorio anterior

1) exit code = 0
2) exit code = 2
3) exit code = 0

Terminou normalmente = 1) e 2) 
Terminou anormalmente = 3)

*/




int main(int argc, char *argv[], char *envp[]) {    
    pid_t pid;
    int status;


    if (argc != 2) {      
        printf("usage: %s dirname\n",argv[0]);      
        exit(1);    
    }

    pid=fork(); 
    //Checking for errors 
    if(pid<0){
        perror("Something is wrong\n");
        return 2;
    }

    else if (pid > 0) {  //Parent process   
         printf("My child is going to execute command              \"ls -laR %s\"\n", argv[1]);   
         wait(&status);
         printf("My son exited with EXIT CODE = %d\n",WEXITSTATUS(status));
         if(WIFEXITED(status)){// returns true if the child process ended normally 
             printf("The child ended normally! \n");
         }
         else if(WIFSIGNALED(status)){// returns true if the child process ended abnormally 
             printf("The child ended abnormally!\n");
         }
    }
    else if (pid == 0){      //Child process
        char *arg[]={"ls","-laR",argv[1],NULL};
        execve("/bin/ls",arg,envp);      
        printf("Command not executed !\n");      
        exit(1);    
    }    
    exit(0);
}