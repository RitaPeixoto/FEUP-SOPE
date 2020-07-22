#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc , char * argv[]){
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int i=1;
    int aux;

    if(argc!=3){
        printf("Function call not executed correctly\n");
        exit(1);
    }

    srand(time(NULL));

    while(aux != n2){
        aux = rand() % n1;
        printf("%d  %d\n",i,aux);
        i++;
    }

    return 0;
}