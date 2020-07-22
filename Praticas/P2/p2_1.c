#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASS_LEN    20 
int main(void){
    struct termios term, oldterm;
    int i=0; 
    char pass[MAX_PASS_LEN+1], ch, echo ='*';
    
    write(STDOUT_FILENO,"\nPassword? ",11);

    tcgetattr(STDIN_FILENO,&oldterm);          //preenche uma estrutura termios
    term = oldterm;
    term.c_lflag &= ~(ECHO | ECHOE |ECHOK | ECHONL |ICANON);
    //ICANON, saimos do modo canonico, desativando as funcionalidades default da consola de mostrar o echo
    tcsetattr(STDIN_FILENO,TCSAFLUSH, &term); //modifica as características da componente da consola

    while(i<MAX_PASS_LEN && read(STDIN_FILENO,&ch,1)&& ch != '\n'){//se nao atingiu o tamanho maximo, se esta a conseguir ler da consola e se não recebeu um newline
        pass[i++] = ch;
        write(STDOUT_FILENO,&echo,1);// vai escrevendo cada asterisco 
    }
    write(STDOUT_FILENO,"\n",1);
    pass[i]=0;
    tcsetattr(STDIN_FILENO,TCSANOW,&oldterm); // repoe as caracteristicas 

    return 0;    
}   