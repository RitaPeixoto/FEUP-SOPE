#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//a completar 
int main(void) {   
    int fd;   
    char *text1="CCCCC";   
    char *text2="DDDDD";  
    fd = open("f1.txt", O_WRONLY|O_SYNC,0600);   
    if(fd==-1){
        printf("Something went wrong while opening the file\n");
        return 1;
    }
    write(fd,text1,5);      
    write(fd,text2,5);   
    if(close(fd)==-1){
        printf("Something went wrong while closing the file\n");
        return 2;  
    }   
    return 0;      
}