#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]){

    if(argc <2){
        printf("The fucntion call was not executed correctly\n");
        exit(1);
    }
    int i=0;
    while(i<30){
        printf("%s",argv[1]);
        i+=5;
        sleep(5);
    }
    exit(0);
}