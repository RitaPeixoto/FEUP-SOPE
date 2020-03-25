#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h> 
#include<stdbool.h>
#define READ 0 
#define WRITE 1

struct Result{
    int sum;
    int dif;
    int mult;
    int div;
    double divd;
    bool invalid;
};

int main(void) { 
    int fd1[2], fd2[2];   
    pid_t pid;   
    pipe(fd1); //creating the pipe 
    pipe(fd2); 
    pid = fork( );//creating the father process  
    if (pid >0){//pai   
        int a[2];  //array to store the integers 
        struct Result res;
        printf("PARENT:\n");     
        printf("x y ? "); 
        scanf("%d %d",&a[0],&a[1]);    //reads the two integers 
        close(fd1[READ]);     //closes the reading descriptor   
        write(fd1[WRITE],a,2*sizeof(int));     // writes the two number in the pipe
        close(fd1[WRITE]);   //closes the writing descriptor
        read(fd2[READ],&res,sizeof(res));
        printf("x+y = %d\n", res.sum);   
        printf("x-y = %d \n",res.dif);
        printf("x*y = %d \n",res.mult);
        if(res.invalid){
            printf("It is not possible to divide by zero\n");
        }
        else if(res.div!=0){
            printf("x/y = %d \n", res.div);
        }
        else{
            printf("x/y = %f \n", res.divd);
        }
        

     } 
     else{//filho    
        int a[2]; 
        struct Result res;
        //printf("SON:\n");     
        close(fd1[WRITE]); //closes the writing descriptor    
        read(fd1[READ],a,2*sizeof(int));     //reads the two number in the pipe
        printf("SON:\n"); //WHY HERE AND NOT ABOVE ..."?!--> because it's going to write by order and therefore it first  
        //Calculating the operations and displaying them    
        res.sum = a[0]+a[1];
        res.dif = a[0]-a[1];
        res.mult = a[0]*a[1];
        if(a[1]==0){
            res.invalid = true;
        }
        else if((a[0]%a[1])==0){
            res.div = a[0]/a[1];
            res.divd=0;
        }
        else{
            res.divd = (float)a[0] / (float) a[1];
            res.div = 0;
        }

        close(fd1[READ]);   //closes the reading descriptor
        write(fd2[WRITE],&res,sizeof(res));
        close(fd2[WRITE]);
     } 
     return 0; 
} 