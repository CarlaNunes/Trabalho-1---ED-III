#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include "funcoes.h"

typedef int tipoChave;
typedef int rrn;
typedef char* string;

int le_arquivo(FILE *arquivo){
    int i = 0;
    Metro metro[200];

    int bufSize = 30;
    char cabecalho[bufSize];

    if ((arquivo = fopen("estacoes.csv", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
#if 1 
        const char separador[2] = ",";
        char buffer[bufSize];
        
        fgets (cabecalho, bufSize, arquivo); 
        while( fgets (buffer, bufSize, arquivo)!=NULL ) {
          
            //printf("=============================\n");
            //puts(buffer);
            
            //É bom verificar se token != NULL
            char *token = strtok(buffer, separador);
            
                metro[i].codEstacao = atoi(token);

                metro[i].nomeEstacao = (char*)malloc(sizeof(char));
                token = strtok(NULL, separador);
                strcpy(metro[i].nomeEstacao,token);

                token = strtok(NULL, separador);
                metro[i].codLinha = atoi(token);

                metro[i].nomeLinha = (char*)malloc(sizeof(char));
                token = strtok(NULL, separador);
                strcpy(metro[i].nomeLinha,token);
                
               token = strtok(NULL, separador);
          
               //int tam = strlen(token);
               if(token == NULL){
                  //char lixo[] = "$";
                  
                  metro[i].codProxEst= 0;//-1 depois mudar. 
                  //Nesse caso teremos valores nulos nessa coluna
                                                        
               }
               else{
                 metro[i].codProxEst = atoi(token);
                                  
               }
                token = strtok(NULL, separador);
                
                if(token == NULL){
                  //char lixo[] = "$";
                  
                  metro[i].distanciaProxEst= 0;//-1 depois mudar
                                                        
               }
               else{
                 metro[i].distanciaProxEst = atoi(token);

                                  
               }
                token = strtok(NULL, separador);
                
                if(token == NULL){
                  //char lixo[] = "$";
                  
                  metro[i].codLinhaInteg= 0;//-1 depois mudar
                                                        
               }
               else{
                 metro[i].codLinhaInteg = atoi(token);
                 
                                  
               }

                 token = strtok(NULL, separador);
                
                if(token == NULL){
                  //char lixo[] = "$";
                  
                  metro[i].codEstacaoInteg= 0;//-1 depois mudar
                                                        
               }
               else{
                 metro[i].codEstacaoInteg= atoi(token);
                                                   
               }

             
            
            
             
            i += 1;
             
        }
        //Testando
        /*
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
        */
#endif
        fclose(arquivo);
        free(metro[i].nomeEstacao);
        free(metro[i].nomeLinha);
    }
    
    return i;
}

