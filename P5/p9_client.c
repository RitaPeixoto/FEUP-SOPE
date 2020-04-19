#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <errno.h>
#include <string.h>

/*O cliente simplesmente cria o FIFO para receber a resposta, envia o seu pid para o
servidor e o comando para este executar, espera pela resposta e, quando esta chegar, mostra‐a no écran e
termina.*/

#define MAX_SIZE  256
#define MAX_BUF_SIZE 4096  
int readlines(int fd, char *str) {
  int n;
  do {
      n = read(fd, str, 1);
  } while (n > 0 && *str++ != '\0');
  return (n > 0);
}


int main(){
    int server, client;
    char fifo_cl [MAX_BUF_SIZE];
    
    do{
        server = open("/tmp/fifo.s", O_WRONLY);
        if(server ==-1){
            printf("Connecting to the server....\n");
            sleep(1);
        }
    }while(server==-1);

    sprintf(fifo_cl,"/tmp/fifo.%d",getpid());
    mkfifo(fifo_cl,0660);
    client  = open(fifo_cl,O_RDONLY|O_NONBLOCK);


    printf("Command: ");
    char command[MAX_SIZE];
    fgets(command, MAX_SIZE, stdin);

    char message[MAX_SIZE];
    sprintf(message, "%d %s", getpid(), command);

    write(server, message, strlen(message));
    close(server);

    char buffer[MAX_BUF_SIZE];
    while (!readlines(client, buffer)) { }
    printf("%s\n", buffer);
    close(client);

    unlink(fifo_cl);



    return 0;
}