#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc , char * argv[]){
    clock_t begin ,end;
    struct tms t;
    long ticks;
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int i=1;
    int aux;

    if(argc!=3){
        printf("Function call not executed correctly\n");
        exit(1);
    }

    srand(time(NULL));
    begin = times(&t);
    ticks = sysconf(_SC_CLK_TCK);

    while(aux != n2){
        aux = rand() % n1;
        printf("%d  %d\n",i,aux);
        i++;
    }
    end = times(&t);

    printf("Clock: %4.2f s\n", (double)(end-begin)/ticks);
    printf("User time: %4.2f s\n", (double)t.tms_utime/ticks);
    printf("System time: %4.2f s\n", (double)t.tms_stime/ticks);
    printf("Children user time: %4.2f s\n", (double)t.tms_cutime/ticks);
    printf("Children system time: %4.2f s\n", (double)t.tms_cstime/ticks);

    return 0;
}