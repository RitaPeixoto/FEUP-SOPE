#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>
/*
Cada pedido deve conter, para
além dos operandos, o nome de outro FIFO, de nome fifo_ans_XXXXX, criado pelo cliente, em que
XXXXX representa a PID do cliente, através do qual deve ser enviado, ao cliente, o resultado da operação.
 O FIFO fifo_ans_XXXXX deverá ser destruído pelo cliente que o criou, quando não
pretender solicitar a execução de mais operações
*/
int main(int argc, char *argv[])
{
    int fd;
    if (argc != 3)
    {
        printf("Usage: ./client int1 int2\n");
        exit(1);
    }
    fd = open("./fifo_req", O_WRONLY);
    if (fd == -1)
    {
        printf("Oops !!! Server is closed !!!\n");
        exit(1);
    }
    printf("FIFO 'requests' openned in WRITEONLY mode\n");
    char line[500];
    sprintf(line, "%d %d\n", atoi(argv[1]), atoi(argv[2]));
    write(fd, line, strlen(line)+1);
    close(fd);
    int fd2 = open("./fifo_req", O_RDONLY);
    char str[500];
    read(fd2, str, 500);
    int res;
    sscanf(str, "%d", &res);
    printf("result: %d", res);
    close(fd2);
    return 0;
}