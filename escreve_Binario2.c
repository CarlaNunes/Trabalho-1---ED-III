#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes.h"
//Preencher o restante do espaço da string com $
//Colocar o '|' 

//Versão com impressão campo a campo
//Também com preenchimento de campos "pequenos com lixo"
void escreve_Binario2(FILE *arquivo, int cont,char nomeArquivoBinario[20]){
  Metro metro[200];

  char status = '0',removido;//Primeiro item do cabeçalho
  char grau[3],data1[10],data2[10];//Variaveis auxiliares para armazenar os valores da struct para impressão.
  int quantidadeEstacoes = cont;
  char lixo[] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";//Terceiro item do cabeçalho
  char proxLista[8];//Dúvida aqui
  int tamReg = 0;

  if ((arquivo = fopen("estacoes.bin", "wb")) == NULL) {
        printf("\n Falha no carregamento do arquivo.\n");
    }
    
   //------Início escrita em arquivo do cabeçalho--------------
     fwrite("removido",sizeof(char),1,arquivo);
     fwrite("Tamanho Registro",sizeof(char) ,1, arquivo);
     fwrite("cod Estacao",sizeof(char) ,1, arquivo);
     fwrite("cod Linha",sizeof(char) ,1, arquivo);
     fwrite("codProx Estacao",sizeof(char) ,1, arquivo);
     fwrite("distProx Estacao",sizeof(char) ,1, arquivo);
     fwrite("codEst Integra",sizeof(char) ,1, arquivo);
     fwrite("nome Estacao",sizeof(char) ,1, arquivo);
     fwrite("nome Linha",sizeof(char) ,1, arquivo);
           


     //fwrite(&lixo, sizeof(char) ,1, arquivo);
  //------Fim escrita em arquivo do cabeçalho--------------
  else{
       int i;
        for(i = 0; i < quantidadeEstacoes ; i++){
      //------------Início escrita dos valores da struct--------
            removido = '1'; //Ver um mdodo de mudar depois.
            //tamReg = strlen(metro); Dando erro aqui, depois resolver

            fwrite(&removido,1,sizeof(char),arquivo);

            int codE = metro[i].codEstacao;
            fwrite(&codE,1,sizeof(int),arquivo);

            fwrite("|",sizeof(char) ,1, arquivo);
            char nomeEs = strcpy(metro[i].nomeEstacao,nomeEs);
            fwrite(nomEEs,1,sizeof(char),arquivo);
            
           
            int codL = metro[i].codLinha;
            fwrite(&codL,1,sizeof(int),arquivo);

            fwrite("|",sizeof(char) ,1, arquivo);
            char nomeLi = strcpy(metro[i].nomeLinha,nomeLi);
            fwrite(nomeLi,1,sizeof(char),arquivo);
            
            int codPro = metro[i].codProxEst;
            fwrite(&codPro,1,sizeof(int),arquivo);

            int distP = metro[i].distanciaProxEst;
            fwrite(&distP,1,sizeof(int),arquivo);

            int dLin = metro[i].codLinhaInteg;
            fwrite(&dLin,1,sizeof(int),arquivo);

            int codEI = metro[i].codEstacaoInteg;
            fwrite(codEI,1,sizeof(int),arquivo);


              
            //------------Fim escrita dos valores da struct--------
        }
  }
      
       
    


    fclose(arquivo);

}
