#include <stdio.h>
#include <stdlib.h>
//alinea a
// como é possivel perceber as coisas sao executadas de forma inversa 
static void exit_handler_1(){
    printf("Executing exit handler 1\n");
    return;
}

static void exit_handler_2(){
    printf("Executign exit handler 2\n");
}


int main(){

    atexit(exit_handler_1);
    atexit(exit_handler_2);
    atexit(exit_handler_1);
    printf("Main done!\n");

    return 0;
}
//alinea b
/*
Sim é possivel instalar um handler mais do que uma vez 
com abort(), aparece no ecrã     "atexit(exit_handler_1)"
com o exit acontece tudo normal
*/