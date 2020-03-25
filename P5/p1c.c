//Program p1c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<sys/types.h> 
#define READ 0 
#define WRITE 1 
struct Numbers{
    int x;
    int y; 
};

int main(void) { 
    int fd[2];   
    pid_t pid;   
    pipe(fd); //creating the pipe  
    pid = fork();//creating the father process  
    if (pid >0){//pai 
        char a[2][5];
        printf("PARENT:\n");     
        printf("x y ? "); 
        scanf("%s %s",a[0],a[1]);    //reads the two integers 
        close(fd[READ]);     //closes the reading descriptor   
        write(fd[WRITE],a,2*sizeof(char*));     // writes the two number in the pipe
        close(fd[WRITE]);   //closes the writing descriptor
     } 
     else{//filho    
        char a[2][5];
        //printf("SON:\n");     
        close(fd[WRITE]); //closes the writing descriptor    
        read(fd[READ],a,2*sizeof(char*));     //reads the two number in the pipe
        printf("SON:\n"); //WHY HERE AND NOT ABOVE ..."?!  
        //Calculating the operations and displaying them    
        printf("x + y = %d\n", atoi(a[0])+atoi(a[1]));   
        printf("x-y = %d \n", atoi(a[0])-atoi(a[1]));
        printf("x*y = %d \n",atoi(a[0])*atoi(a[1]));
        if(atoi(a[1])!=0){
            printf("x/y = %f \n", (float)atoi(a[0])/(float)atoi(a[1]));
        }  
        else{
            printf("It is not possible to divide by zero\n");
        }
        close(fd[READ]);   //closes the reading descriptor
     } 
     return 0; 
} 