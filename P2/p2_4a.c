#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


#define MAX_NUM_LEN     15
#define MAX_NAME_LEN    100

















#define MAX_NUM_NAMES   10  
int main(int argc,char *argv[]){
    char names[MAX_NUM_NAMES][MAX_NAME_LEN];
    char grades[MAX_NUM_NAMES][MAX_NUM_LEN];

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
    printf("Enter %d the student's names and their grades.\n",MAX_NUM_NAMES);

    for(int i=0; i<MAX_NUM_NAMES;i++){
        printf("\nName: "); 
        fgets(names[i],MAX_NAME_LEN,stdin);
        printf("Grade: ");
        fgets(grades[i],MAX_NUM_LEN,stdin);
    }


    //Writing to the file 
    for(int i=0; i<MAX_NUM_NAMES;i++){
        write(f,names[i],strlen(names[i])-1);
        write(f , "\n" , strlen("\n"));
        write(f,grades[i],strlen(grades[i])-1);
        write(f, "\n" , strlen("\n"));
    }

    //Closing the file
    close(f);

    return 0;

}   