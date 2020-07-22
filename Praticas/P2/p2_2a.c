#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_LEN 256

int main(int argc, char * argv[]){ //o primeiro elemento do argv é o nome do programa

    char buffer[MAX_FILE_LEN];
    FILE *source, *destination;

    if((source = fopen(argv[1], "r"))==NULL){
        exit(1);// abrir o ficheiro com as permissoes de apenas ler
    }

    fseek(source, 0L,SEEK_END);//vai para o fim do ficheiro
    int size = ftell(source);// diz onde esta o apontador 
    fseek(source, 0L, SEEK_SET); // voltamos a pôr no inicio do ficheiro 


    if((destination = fopen(argv[2],"w"))==NULL){
        exit(2);//abrir o ficheiro com as permissoes de apenas escrever
    }


    fread(buffer,size ,1,source);

    fwrite (buffer,size,1,destination);

    fclose(source);
    fclose(destination);
    return 0;
}