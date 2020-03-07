#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    char str[90];
    const char aux[2] = " ";
    char *token;

    fgets(str,90,stdin);
    token = strtok(str,aux);
    while(token!=NULL){
        printf("%s",token);
        token = strtok(NULL,aux);
    }


    return 0;
}