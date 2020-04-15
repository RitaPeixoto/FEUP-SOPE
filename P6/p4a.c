// PROGRAMA p04a.c 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#define NUM_THREADS 10 
/*
Escreva um programa que crie N novas threads.Cada thread deve "dormir" durante um segundo,escrever a 
sua TID e terminar retornando um número inteiro igual ao seu número de ordem(1..N) que lhe deve ser passado
com parâmetro.
*/
void *PrintHello(void *threadnum) {  
    sleep(1);
    printf("Hello from thread no. %d!\n", *(int *) threadnum);     

    void * res = malloc(sizeof(int));
    *(int *)res =  *(int*)threadnum ;
    return res;   
} 
int main() {    
    pthread_t threads[NUM_THREADS];    
    int t;    
    void *res;

    for(t=1; t<= NUM_THREADS; t++){  
        printf("Creating thread %d\n", t);       
        pthread_create(&threads[t-1], NULL, PrintHello,(void *)&t); 
        pthread_join(threads[t-1],&res);
    }    
    pthread_exit(0); 
}
