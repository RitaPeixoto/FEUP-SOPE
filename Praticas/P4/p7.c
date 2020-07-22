//Programa p7.c
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    pid_t pid;
    int status;
    for (int i = 1; i < argc; i++){
        if ((pid = fork()) == 0)
            execl(argv[i], argv[i], NULL);//ponto 1
    }

    while((pid = wait(&status)) != -1 ){
        if (WEXITSTATUS(status) != 0) kill(0, SIGKILL);//ponto 3
        else{
            printf("Process %d finished\t", pid);
            printf("with exit code %d\n",WEXITSTATUS(status));
        } 
    }
    exit(0);
}

/*
o lance em execução os programas cujos nomes dos ficheiros executáveis lhe sejam passados como argumentos
da linha de comandos, ficheiros estes que devem estar num dos directórios do path;
-fique a aguardar a terminação dos processos criados,apresentando no écran a PID e o código de terminação de cada um desses 
processos,à medida que eles forem terminando; 
-se algum dos processos retornar um código determinação com um valor diferente de zero,envie um sinal a 
todos os processos que ainda não terminaram,forçando a sua terminação.



*/