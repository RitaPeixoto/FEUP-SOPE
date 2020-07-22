#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <errno.h>
#include <string.h>
#include <wait.h>
/*
.O servidor deverá criar um FIFO bem conhecido(por exemplo,/tmp/fifo.s) e ficar à espera que os clientes 
lhe enviem comandos.Os comandos são strings representando programas executáveis que podem ter ou não ter 
parâmetros na linha de comando.Quando o servidor lê um destes comandos do FIFO e executa‐o
(criando um novo processo),direccionando a sua saída standard para um ficheiro auxiliar.
Após a execução envia o conteúdo do ficheiro auxiliar produzido(ou uma mensagem de erro,senão conseguiu
executar o comando) para o cliente através de outro FIFO criado pelo cliente(por exemplo,/tmp/fifo.pid,
em que pid é o identificador do cliente,também enviado para o servidor).

PS : Most of the code is from skdGT because I'm lazy 
*/

#define MAX_SIZE    256
#define MAX_CMD_SIZE 256

int readline(int fd, char *str) {
  int n;
  do {
      n = read(fd, str, 1);
  } while (n > 0 && *str++ != '\n');
  *(--str) = '\0';
  return (n > 0);
}

pid_t parse_commands(char string[64], char* arr[MAX_CMD_SIZE]) {
  int i = 0;
  pid_t pid;
  char* token = strtok( string, " " );
  while( token != NULL ) {
    if (i == 0)
      pid = atoi(token);
    else
      arr[i - 1] = token;
    i++;
    token = strtok( NULL, " " );
  }
  arr[i] = NULL;
  return pid;
}




int main(){
    int fd;
   

    mkfifo("/tmp/fifo.s",0660);
    fd = open("/tmp/fifo.s",O_RDONLY);

    while(1){
        char * cmd[MAX_CMD_SIZE];
        char msg[256];
        FILE *f;
        while(readline(fd, msg)==0){}// leitura dos comandos
        printf("Received message: %s\n",msg);

        pid_t client_pid = parse_commands(msg, cmd);
        pid_t pid=fork();
        if(pid <0){
            printf("Error forking\n");
            exit(1);
        }
        else if(pid ==0){//criaçao de um novo processo
            int filefd = 
            close(1);
            dup(filefd);
            execvp(cmd[0],cmd);
            exit(1);
        }
       
        int status;
        waitpid(pid, &status,0);

        f = fopen("/tmp/file.txt","rb");
        fseek(f,0, SEEK_END);
        long fsize = ftell(f);
        fseek(f,0,SEEK_SET); /* same as rewind(f); */

        char * string = (char *) malloc(fsize +1);
        fread(string, 1,fsize, f);
        fclose(f);
          
        string[fsize] = 0;

        char fifo_client[64];
        sprintf(fifo_client, "/tmp/fifo.%d", client_pid);
        int client = open(fifo_client, O_WRONLY);
        write(client, string, strlen(string) + 1);
        close(client);   
    }
    close(fd);
    unlink("/tmp/fifo.s");

    return 0;
}