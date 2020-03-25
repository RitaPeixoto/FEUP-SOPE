#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h> 
#define READ 0 
#define WRITE 1 

int main(void) { 
    int fd[2];   
    pid_t pid;   
    pipe(fd); //creating the pipe  
    pid = fork();//creating the father process  
    if (pid >0){//pai   
        int a[2];  //array to store the integers 
        printf("PARENT:\n");     
        printf("x y ? "); 
        scanf("%d %d",&a[0],&a[1]);    //reads the two integers 
        close(fd[READ]);     //closes the reading descriptor   
        write(fd[WRITE],a,2*sizeof(int));     // writes the two number in the pipe
        close(fd[WRITE]);   //closes the writing descriptor
     } 
     else{//filho    
        int a[2]; 
        //printf("SON:\n");     
        close(fd[WRITE]); //closes the writing descriptor    
        read(fd[READ],a,2*sizeof(int));     //reads the two number in the pipe
        printf("SON:\n"); //WHY HERE AND NOT ABOVE ..."?!--> because it's going to write by order and therefore it first  
        //Calculating the operations and displaying them    
        printf("x + y = %d\n", a[0]+a[1]);   
        printf("x-y = %d \n",a[0]-a[1]);
        printf("x*y = %d \n",a[0]*a[1]);
        if(a[1]!=0){
        printf("x/y = %f \n", (float)a[0]/(float)a[1]);
        }  
        else{
            printf("It is not possible to divide by zero\n");
        }
        close(fd[READ]);   //closes the reading descriptor
     } 
     return 0; 
} 