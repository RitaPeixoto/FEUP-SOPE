// PROGRAMA p7.c 
#include ... 
int main(int argc, char *argv[]){
    char prog[20];    

    //Adds the '.c' extension to the program name
    sprintf(prog,"%s.c",argv[1]); 

    //Executes the gcc -Wall -o "programname.c" command 
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);    

    printf("Done!\n");

    exit(0);
}
/*
This program executes the program sent as argument
*/