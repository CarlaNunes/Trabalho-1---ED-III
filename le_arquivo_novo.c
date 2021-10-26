#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes.h"

typedef int tipoChave;
typedef int rrn;
typedef char* string;




int le_arquivo_novo(FILE *arquivo){
    int i = 0;
    Metro metro;
     int bufSize = 600;
   
    char cabecalho[bufSize];
    char *token;
    char  *str,*ptr;
   
    char buffer[bufSize];

    //str = strdup(buffer);

    //metro.nomeEstacao = (char*)malloc(sizeof(char));
    //metro.nomeLinha = (char*)malloc(sizeof(char));
    if ((arquivo = fopen("estacoes.csv", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
#if 1 
        const char separador[2] = ",";
        
        
        
        fgets (cabecalho, bufSize, arquivo); 
        while( fgets (buffer, bufSize, arquivo)!=NULL ) {
            

              str = strdup(buffer);
              token = strsep(&str,separador);
              
              metro.codEstacao = atoi(token);

              metro.nomeEstacao = (char*)malloc(sizeof(char));
              token = strsep(&str,separador);

              strcpy(metro.nomeEstacao,token);

              token = strsep(&str,separador);
              metro.codLinha = atoi(token);


              metro.nomeLinha = (char*)malloc(sizeof(char));
              token = strsep(&str,separador);
              strcpy(metro.nomeLinha,token);

              token = strsep(&str,separador);
              metro.codProxEst = atoi(token);

              token = strsep(&str,separador);
              metro.distanciaProxEst = atoi(token);

               token = strsep(&str,separador); 
               metro.codLinhaInteg = atoi(token);

               token = strsep(&str,separador); 
               metro.codEstacaoInteg= atoi(token);

            i += 1;
            //free(str);

            //TESTANDO:
            printf("----------------------\n");
            printf("codEstação: %d\n", metro.codEstacao);
            printf("nomeEstação: %s\n", metro.nomeEstacao);
            printf("codLinha: %d \n",metro.codLinha);
            printf("NomeLinha: %s\n", metro.nomeLinha);
            printf("codProxEst: %d \n",metro.codProxEst);
            printf("distanciaProxEst: %d \n",metro.distanciaProxEst);
            printf("codLinhainteg: %d \n",metro.codEstacaoInteg);
            printf("codEstacaoInteg: %d \n",metro.codEstacaoInteg);   
            escreve_Binario(arquivo,metro); 

            free(metro.nomeEstacao);
            free(metro.nomeLinha);
        }
        
        
       
            
            
            
            
          
        

        
       
       
#endif
        //free(metro.nomeEstacao);
        //free(metro.nomeLinha);
        fclose(arquivo);
       
        //free(r);
    }
    
    
    return i;
}

