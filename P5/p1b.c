#include<stdio.h>
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
        struct Numbers numbers;
        printf("PARENT:\n");     
        printf("x y ? "); 
        scanf("%d %d",&numbers.x,&numbers.y);    //reads the two integers 
        close(fd[READ]);     //closes the reading descriptor   
        write(fd[WRITE],&numbers,sizeof(numbers));     // writes the two number in the pipe
        close(fd[WRITE]);   //closes the writing descriptor
     } 
     else{//filho    
        struct Numbers numbers;
        //printf("SON:\n");     
        close(fd[WRITE]); //closes the writing descriptor    
        read(fd[READ],&numbers,sizeof(numbers));     //reads the two number in the pipe
        printf("SON:\n"); //WHY HERE AND NOT ABOVE ..."?!  
        //Calculating the operations and displaying them    
        printf("x + y = %d\n", numbers.x+numbers.y);   
        printf("x-y = %d \n", numbers.x-numbers.y);
        printf("x*y = %d \n",numbers.x*numbers.y);
        if(numbers.y!=0){
            printf("x/y = %f \n", (float)numbers.x/(float)numbers.y);
        }  
        else{
            printf("It is not possible to divide by zero\n");
        }
        close(fd[READ]);   //closes the reading descriptor
     } 
     return 0; 
} 