#include <stdlib.h>
#include <stdio.h>
#define MAXNAMELEN 500 
#define PAGER "sort" 
int main(int argc, char *argv[]) { 
    char names[MAXNAMELEN];   
    FILE *fpin, *fpout; 
    if (argc != 2) { 
        printf("The function call was not executed correctly\n"); 
        exit(1); 
    }   
    fpin = fopen(argv[1], "r");   
    fpout = popen(PAGER, "w"); 
    while (fgets(names, MAXN    AMELEN, fpin) != NULL)     
        if(fputs(names, fpout) == EOF)
            printf("fputs error to pipe\n");   
         
    pclose(fpout);   
    exit(0);    
}