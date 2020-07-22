// PROGRAMA p02.c 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#define STDERR 2 
#define NUMITER 10000 
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;  // mutex p/a sec.critica 
int N;

void * thrfunc(void * arg) {  
    int i = 0;
    void* res = malloc(sizeof(int));
    int value = *(int*) arg;
    char s[5];
    
    sprintf(s, "%d", value);
    fprintf(stderr, "Starting thread %d\n", value);
    while(N > 0) {
        pthread_mutex_lock(&mut);
        i++;
        N--;
        pthread_mutex_unlock(&mut);
        write(STDERR, s, 1);
    }
    
    *(int *) res = i;
    return res; 
} 
int main() {  
    N=5000;  
    pthread_t ta, tb;
    void *t1, *t2; 
    int num[2]={1,2};  

    pthread_create(&ta, NULL, thrfunc, &num[0]);   
    pthread_create(&tb, NULL, thrfunc, &num[1]); 

    pthread_join(ta, &t1);   
    pthread_join(tb, &t2); 

    fprintf(stderr,"\nThread 1 wrote %d characters\n",*(int*)t1);
    fprintf(stderr,"\nThread 2 wrote %d characters\n",*(int*)t2);
    fprintf(stderr,"\nTotal: %d\n",*(int *)t1+*(int *)t2);
    free(t1);
    free(t2);
    return 0; 
}