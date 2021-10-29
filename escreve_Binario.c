#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes.h"
//Lembrando que temos que escrever o cabeçalho 2 vezes no início e no fim.
//Gerar os valores como nroEstaçoes e nPares;
//Preencher com lixo o tamanho dos campos;
void escreve_Binario(FILE *arquivo, Metro metro){
  char status = '0'; //Pois abrimos o arquivo para escrita;
  long long int topoLista;
  int nroEstacoes = 0;
  int nroParesEstacao;

  char delimitador = '|';

  if ((arquivo = fopen("estacoes.bin", "wb+")) == NULL) {
        printf("\n Falha no carregamento do arquivo.\n");
    }
    
  else{
    //------Início escrita em arquivo do cabeçalho--------------
  

      fwrite(&status,sizeof(char),1,arquivo);
      fwrite(&topoLista,sizeof(long long int) ,1, arquivo);
      fwrite(&nroEstacoes,sizeof(int) ,1, arquivo);
      fwrite(&nroParesEstacao,sizeof(int) ,1, arquivo);
     
     
//------Fim escrita em arquivo do cabeçalho-------------- 
     
      metro.removido = '0';
      //metro.tamanhoRegistro = 1;
      metro.proLista = 1;

      fwrite(&metro.removido, sizeof(char),1,arquivo);
      fwrite(&metro.tamanhoRegistro, sizeof(int),1,arquivo);
      fwrite(&metro.proLista, sizeof(long long int),1,arquivo);
      fwrite(&metro.codEstacao, sizeof(int),1,arquivo);
      fwrite(&metro.codLinha, sizeof(int),1,arquivo);
      fwrite(&metro.codProxEst, sizeof(int),1,arquivo);
      fwrite(&metro.distanciaProxEst, sizeof(int),1,arquivo);
      fwrite(&metro.codLinhaInteg, sizeof(int),1,arquivo);
      fwrite(&metro.codEstacaoInteg, sizeof(int),1,arquivo);
      fwrite(metro.nomeEstacao, sizeof(char),1,arquivo);
      fwrite(&delimitador,sizeof(int),1,arquivo);
      fwrite(metro.nomeLinha, sizeof(char),1,arquivo);
      fwrite(&delimitador,sizeof(int),1,arquivo);
      
      
            
  } 

fclose(arquivo);
}
