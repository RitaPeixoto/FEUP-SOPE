
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>
#include "p7.h"

int main(){
    double args[2] = {0,0};
    int fd1, fd2;

    do{
        fd1 = open("/tmp/fifo_req",O_WRONLY);
        fd2 = open("/tmp/fifo_ans", O_RDONLY);
        sleep(1);
        printf("Waiting for server to respond...\n");
    }while(fd1 == -1 || fd2 == -1);

    do{
        printf("Insert two numbers(format:num1 num2): ");
        scanf("%lf %lf", &args[0],&args[1]);
        write(fd1, &args,2*sizeof(double));

        if(args[0]==0 && args[1]==0) 
            break;
        
        struct Calculador calc;
		while (read(fd2, &calc, sizeof(calc)) <= 0) { };

		printf("Mul: %lf\n", calc.mult);
		printf("Div: %lf\n", calc.quo);
		printf("Sub: %lf\n", calc.sub);
		printf("Sum: %lf\n", calc.sum);

    }while(args[0]!=0 || args[1]!=0);

    

    close(fd1);
    close(fd2);

    return 0;
}