#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

//Struct com os dados do arquivo separado por campos:
typedef struct metro{
    int codEstacao;
    char *nomeEstacao;
    int codLinha;
    char *nomeLinha;
    int codProxEst;
    int distanciaProxEst;
    int codLinhaInteg;
    int codEstacaoInteg;
}Metro;




//Funções Fornecidas
void binarioNaTela1(char *nomeArquivoBinario, char *nomeArquivoIndice);
void scan_quote_string(char *str);
void trim(char *str);

//Funções dos autores

int le_arquivo(FILE *arquivo);
