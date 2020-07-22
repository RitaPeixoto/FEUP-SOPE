// PROGRAMA p07.c
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

/*Escreva um programa que copie,"em paralelo",todos os ficheiros regulares de um directório para outro já 
existente;os sub‐directórios não devem ser considerados.Os directórios devem ser passados como argumentos do 
programa.Por cada ficheiro regular deverá ser criada uma nova thread que o copia do directório original para o directório 
de destino.Sugestão:recorra ao código já desenvolvido anteriormente para determinar os ficheiros comuns de 
um directório e para copiar um ficheiro para outro*/

