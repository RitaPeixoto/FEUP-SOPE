// PROGRAMA p2.c 
#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h>


int main(void) {  
    printf("1\n");  
    if(fork() > 0) {    
        printf("2");    
        printf("3");  
    } 
    else {    
        printf("4");    
        printf("5");  
    }  
    printf("\n");  
    return 0; 
}

/*
a) 1,2,4,5

b) Output : 123
            45
    write(STDOUT_FILENO,"1",1);  
    if(fork() > 0) {    
        write(STDOUT_FILENO,"2",1);    
        write(STDOUT_FILENO,"3",1);  
    } 
    else {    
        write(STDOUT_FILENO,"4",1);    
        write(STDOUT_FILENO,"5",1);  
    }  
    write(STDOUT_FILENO,"\n",1);  
    return 0; 


c) printf vs write---> o write é uma chamada direta ao kernell e o printf é uma chamada ao user space, ou seja, utiliza userspace memory
enquanto o write usa o buffer. O printf duplica o output por causa da copia do buffer que é criada
Output: 123
        145

d)Output:   1
            23
            45
*/