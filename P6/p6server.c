
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#define MAXLEN 20
/*
Implemente um aplicação cliente‐servidor, constituída por um programa servidor, multithreaded, em que o
servidor executa operações aritméticas (!) que lhe são solicitadas através de um FIFO pelos clientes, 
sendo a resposta enviada a cada cliente através de outro FIFO.Os pedidos de execução de uma operação são
recebidos através de um FIFO de nome fifo_req, criado pelo servidor.
O processo‐servidor deve manter‐se em funcionamento até que os números a processar sejam ambos
iguais a zero, situação em que não deve efectuar qualquer cálculo, mas apenas deve destruir o FIFO
fifo_req.
*/
int main(){
    int fd, fdDummy,n, i1, i2;
    char msg[MAXLEN];

    if(mkfifo("./fifo_req",0660) < 0){
        if(errno == EEXIST)
            printf("FIFO './fifo_req' already exists\n");
        else
        {
            printf("Created FIFO './fifo_req'\n");
        }
    }
    if((fd = open("./fifo_req",O_RDONLY))!=-1)
        printf("FIFO './fifo_req' openned in READONLY mode\n");
     if ((fdDummy = open("./fifo_req", O_WRONLY)) != -1)
        printf("FIFO './fifo_req' openned in WRONLY mode\n");



    do{
        n = read(fd, msg, MAXLEN);
        sscanf(msg, "%d %d", &i1, &i2);
        sprintf(msg, "%d\n", i1 + i2);
        n = strlen(msg);
        write(fdDummy, msg, n);
    } while (!(i1 == 0 && i2 == 0));



    close(fd);
    close(fdDummy);


    if (unlink("./fifo_req")<0)
        printf("Error when destroying FIFO './fifo_req'\n");
    else
        printf("FIFO './fifo_req' has been destroyed\n");
    
    exit(0);
    return 0;
}