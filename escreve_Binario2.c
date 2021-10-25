#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes.h"
//Preencher o restante do espaço da string com $
//Colocar o '|' 

//Versão com impressão campo a campo
//Também com preenchimento de campos "pequenos com lixo"-> Inserir 
void escreve_Binario2(FILE *arquivo, int cont,char nomeArquivoBinario[20]){
 
  Metro metro[200];

  char status = '0',removido = '1';//Primeiro item do cabeçalho
  char grau[3],data1[10],data2[10];//Variaveis auxiliares para armazenar os valores da struct para impressão.
  int quantidadeEstacoes = cont;
  char lixo[] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";//Terceiro item do cabeçalho
  char proxLista[8];//Dúvida aqui
  int tamReg = 0, topoLista[8];
  char delimitador = '|';
  char *nomeEs,*nomeLi;
  int nroEstacoes = 0, nroParesEstacoes = 0; //Pegar o valores em ler_arquivo.c
  nomeEs = (char*)malloc(sizeof(char));
  nomeLi = (char*)malloc(sizeof(char));

  if ((arquivo = fopen("estacoes.bin", "wb")) == NULL) {
        printf("\n Falha no carregamento do arquivo.\n");
    }
    
  else{

     //------Início escrita em arquivo do cabeçalho--------------
 
      //printf("CHEGUEI AQUI!!!!!!");
      fwrite(&status,sizeof(char),1,arquivo);
      fwrite(&topoLista,sizeof(int),8, arquivo);
      fwrite(&nroEstacoes,sizeof(int),4, arquivo);
      fwrite(&nroParesEstacoes,sizeof(int),4, arquivo);
       //fwrite(&lixo, sizeof(char) ,1, arquivo);
  //------Fim escrita em arquivo do cabeçalho-------------- 

      int i;
        for(i = 0; i < quantidadeEstacoes ; i++){
      //------------Início escrita dos valores da struct--------
           // removido = '1'; //Ver um modo de mudar depois.
            //tamReg = strlen(metro); Dando erro aqui, depois resolver

            fwrite(&removido,sizeof(char),1,arquivo);


            int codE = metro[i].codEstacao;
            fwrite(&codE,sizeof(int),4,arquivo);

            fwrite(&delimitador,sizeof(char),1,arquivo);
            nomeEs = strcpy(metro[i].nomeEstacao,nomeEs);
            fwrite(nomeEs,1,sizeof(char),arquivo);
            //fwrite(&delimitador,sizeof(char) ,1, arquivo);
            
           
            int codL = metro[i].codLinha;
            fwrite(&codL,sizeof(int),1,arquivo);

            fwrite(&delimitador,1,sizeof(char),  arquivo);
            nomeLi = strcpy(metro[i].nomeLinha,nomeLi);
            fwrite(nomeLi,sizeof(char),10,arquivo);
            
            int codPro = metro[i].codProxEst;
            fwrite(&codPro,sizeof(int),1,arquivo);

            int distP = metro[i].distanciaProxEst;
            fwrite(&distP,sizeof(int),1,arquivo);

            int dLin = metro[i].codLinhaInteg;
            fwrite(&dLin,sizeof(int),1,arquivo);

            int codEI = metro[i].codEstacaoInteg;
            fwrite(&codEI,sizeof(int),1,arquivo);


              
            //------------Fim escrita dos valores da struct--------
        }
  }
      
           

    free(nomeEs);
    free(nomeLi);
    
    fclose(arquivo);

}
