#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
    char str[90]; 
    const char aux[2] = " ";
    int i = 0;
    char *token[10];
    char *p;

    fgets(str, 90, stdin); 
    
    p = strtok(str, aux);
   
    while (p != NULL) {
        token[i++] = p;
        p = strtok(NULL, aux);
    }
  
    for (int j = 0; j < i; j++)
        printf(" %s", token[j]);

    return 0; 
} 