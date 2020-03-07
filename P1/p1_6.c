// PROGRAMA p6a.c 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>//alinea e    
#define BUF_LENGTH 256 
/*int main(void) {   
    FILE *src, *dst;   
    char buf[BUF_LENGTH];   
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )    {
        //alinea d
        perror("ERRO");
        //
        exit(1);    
    }   
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )   {     
        //alinea d
        perror("ERRO");
        //
        exit(2);   
    }   
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   {
        fputs( buf, dst );   
    }   
    fclose( src );   
    fclose( dst );      
    exit(0);  // zero é geralmente indicativo de "sucesso" } " 
} 
*/
//alinea b--> nao obtinhamos o resultado pretendido pois os ficheiros infile e outfile nao existiam no diretorio onde estava o programa
//alinea e
/*int main(void) {   
    FILE *src, *dst;   
    char buf[BUF_LENGTH];   
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )    {
        printf("Error number: %d\n",errno);
        exit(1);    
    }   
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL )   {     
        printf("Error number: %d\n",errno);
        exit(2);   
    }   
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   {
        fputs( buf, dst );   
    }   
    fclose( src );   
    fclose( dst );      
    exit(0);  // zero é geralmente indicativo de "sucesso" } " 
} */
//alinea f ja acontece tudo como é suposto  
//alinea g
/*int main(int argc , char * argv[],char* envp[]) {   
    FILE *src, *dst;   
    char buf[BUF_LENGTH]; 
    
    if (argc != 3){
		printf("Invalid number of arguments.\n");
		return 1;
	}  

    //o index do infile e 1 e do outfile e 2
    if ( ( src = fopen(argv[1], "r" ) ) == NULL )    {
        printf("Error number: %d\n",errno);
        exit(1);    
    }   
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL )   {     
        printf("Error number: %d\n",errno);
        exit(2);   
    }  

    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   {
        fputs( buf, dst );   
    }   

    fclose( src );   
    fclose( dst );      
    exit(0);  // zero é geralmente indicativo de "sucesso" } " 
} */


//alinea h 
int main(int argc , char * argv[],char* envp[]) {   
    FILE *src, *dst;   
    char buf[BUF_LENGTH]; 
    
    if (argc != 3){
		printf("usage: p6h file1 file2\n");
		return 1;
	}  

    //o index do infile e 1 e do outfile e 2
    if ( ( src = fopen(argv[1], "r" ) ) == NULL )    {
        printf("Error number: %d\n",errno);
        exit(1);    
    }   
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL )   {     
        printf("Error number: %d\n",errno);
        exit(2);   
    }  

    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )   {
        fputs( buf, dst );   
    }   

    fclose( src );   
    fclose( dst );      
    exit(0);  // zero é geralmente indicativo de "sucesso" } " 
}