// PROGRAMA p03c.c 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define NUM_THREADS 10 

void *PrintHello(void *threadnum) {    
    printf("Hello from thread no. %d!\n", *(int *) threadnum);    
    pthread_exit(NULL); 
} 
int main() {    
    pthread_t threads[NUM_THREADS];    
    int t;    
    for(t=0; t< NUM_THREADS; t++){       
        printf("Creating thread %d\n", t);       
        pthread_create(&threads[t], NULL, PrintHello, (void *)&t);  
        pthread_join(threads[t],NULL);  
    }    
    exit(0);
}
/*
Utilizando o pthread_exit() caso os outros nao tenham terminado mantém-se ativos
Aparentemente nao mudou nada :)
*/
