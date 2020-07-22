#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Exercicio 5
//alinea a 
/*int main(int argc , char * argv[],char* envp[]){
    for(int i =0; envp[i]!=NULL;i++){
        printf("%s\n",envp[i]);
    }
    return 0;

}*/
//alinea b
/*int main(int argc , char * argv[],char* envp[])  { 
    for(int i=0; envp[i]!=NULL;i++){
        if(strncmp("USER=",envp[i],5)==0){
            printf("Hello %s!\n",envp[i]+5);  
        }  
    }

    return 0; 
} */
//alinea c
/*int main(int argc , char * argv[],char* envp[])  { 
    printf("Hello %s!\n",getenv("USER"));  
    return 0; 
} */

//alinea d
//export USER_NAME=ritaapeixoto
int main(int argc , char * argv[],char* envp[])  { 
    printf("Hello %s!\n",getenv("USER_NAME"));  
    return 0; 
}

