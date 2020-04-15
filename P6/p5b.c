// PROGRAMA p05b.c
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
/*Escreva um programa que leia 2 números do teclado e crie 4 threads que façam,respectivamente,a soma,a 
subtracção,o produto e o quociente dos números lidos.Os operandos devem ser passados como parâmetros às
threads(usar duas formas diferentes de o fazer,através de um array e de uma struct).O valor dos operandos
e o resultado de cada operação devem ser apresentados no ecrã pela thread que executou cada operação
Alterar o programa anterior por forma a que os resultados sejam apresentados pela main thread */

void *sum(void *arg) {
    int *aux = (int*)arg;
    void *res = malloc(sizeof(int));
    *(int*)res = aux[0]+aux[1];
    return res;
}
void *sub(void *arg) {
    int *aux = (int*)arg;
    void *res = malloc(sizeof(int));
    *(int*)res = aux[0]+aux[1];
    return res;   
}
void *mult(void *arg) {
    int *aux = (int*)arg;
    void *res = malloc(sizeof(int));
    *(int*)res = aux[0]+aux[1];
    return res;
}
void *quo(void *arg) {
    int *aux = (int*)arg;
    void *res = malloc(sizeof(int));
    *(int*)res = aux[0]+aux[1];
    return res;
}


int main(){
    int args[2];
    void *sum , *sub, *mult, *quo;
    pthread_t tsum, tsub, tmult, tdiv;

    printf("Insert two numbers:");
    scanf("%d %d", &args[0],&args[1]);

    pthread_create(&tsum,NULL, sum, &args);
    pthread_create(&tsub,NULL, sub, &args);
    pthread_create(&tmult,NULL, mult, &args);
    pthread_create(&tdiv,NULL, quo, &args);

    pthread_join(tsum, &sum);
    pthread_join(tsub, &sub);   
    pthread_join(tmult, &mult);
    pthread_join(tdiv, &quo);


    printf("%d + %d = %d\n",args[0],args[1],*(int*)sum);
    printf("%d - %d = %d\n",args[0],args[1],*(int*)sub);
    printf("%d * %d = %d\n",args[0],args[1],*(int*)mult);
    printf("%d / %d = %d\n",args[0],args[1],*(int*)quo);



    pthread_exit(0);
}