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
    Metro metro[200];
    
    int bufSize = 300;
    char cabecalho[bufSize];
    char *token;
    char  *str;
    str = strdup(buffer);

    if ((arquivo = fopen("estacoes.csv", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
#if 1 
        const char separador[2] = ",";
        char buffer[bufSize];
        

        str = strdup(buffer);
        fgets (cabecalho, bufSize, arquivo); 
        while( fgets (buffer, bufSize, arquivo)!=NULL ) {
          
              token = strsep(&str,separador);
              metro[i].codEstacao = atoi(token);  

            i += 1;
             
        }
        //Testando
        
        for(i = 0; i < 200; i++){
            printf("----------------------\n");
            printf("codEstação: %d\n", metro[i].codEstacao);
            printf("nomeEstação: %s\n", metro[i].nomeEstacao);
            printf("codLinha: %d \n",metro[i].codLinha);
            printf("NomeLinha: %s\n", metro[i].nomeLinha);
            printf("codProxEst: %d \n",metro[i].codProxEst);
            printf("distanciaProxEst: %d \n",metro[i].distanciaProxEst);
            printf("codLinhainteg: %d \n",metro[i].codEstacaoInteg);
            printf("codEstacaoInteg: %d \n",metro[i].codEstacaoInteg);
            
            
            
            printf("\n");
        }
        
#endif
        fclose(arquivo);
        //free(metro[i].nomeEstacao);
        //free(metro[i].nomeLinha);
        //free(r);
    }
    
    free(str);
    return i;
}

