#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


#define MAX_NUM_LEN     15
#define MAX_NAME_LEN    100
#define MAX_NUM_NAMES   2 

typedef struct Student{
    char name[MAX_NAME_LEN];
    int grade; 
}Student;


int main(int argc,char *argv[]){

    //Verifying if we have all the necessary function arguments
    if(argc != 2){
        printf("The function call was not executed correctly\n");
        return 1;
    }
    //Opening the file 
    int f= open(argv[1],O_WRONLY|O_TRUNC);

    if (f ==-1){
        printf("Something went wrong when trying to open the file\n");
        return 2; 
    }

    //Reading the names and grades
    Student students[MAX_NUM_NAMES];
    Student s;  

    printf("Enter %d the student's names and their grades.\n",MAX_NUM_NAMES);

    for(int i=0; i<MAX_NUM_NAMES;i++){
        printf("\nName: "); 
        fgets(s.name,MAX_NAME_LEN,stdin);
        printf("Grade: ");//cannot use fgets because it stores into strings and not integers
        scanf("%d",&s.grade);
        getchar();//to ignore the newline character 
        students[i]=s;//stores the student
    }


    //Writing to the file 
    for(int i=0; i<MAX_NUM_NAMES;i++){
        write(f,&students[i],sizeof(Student));
    }

    //Closing the file
    close(f);

    return 0;

}   