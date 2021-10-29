#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Struct com os dados do arquivo separado por campos:
typedef struct metro{
    char removido;
	int tamanhoRegistro;
	long long int proLista;
    int codEstacao;
    char *nomeEstacao;
    int codLinha;
    char *nomeLinha;
    int codProxEst;
    int distanciaProxEst;
    int codLinhaInteg;
    int codEstacaoInteg;
}Metro;

//Estrutura auxiliar para contar as ocorrências das estações, se tiver mais de uma 1, 
//teremos repetição.

typedef struct estacoes{
	char *nome;
	int codEst;
	int codProx; 
}Estacoes;


//Funções dos autores

int le_arquivo_novo(FILE *arquivo);
void escreve_Binario(FILE *arquivo, Metro metro);
int conta_Estacoes(Metro metro,Estacoes estacoes);
