#include <stdio.h>
#include <stdlib.h>
//Exercicio 4
//alinea b
int main(int argc , char * argv[]){
    for(int i =0; i<atoi(argv[2]);i++){
        printf("Hello %s!\n", argv[1]);
    }

    return 0;

}


//alinea a 
/*int main(int argc , char * argv[]){
    printf("Hello %s!\n", argv[argc-1]);
    return 0;
}*/