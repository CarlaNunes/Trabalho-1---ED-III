#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes.h"

int conta_Estacoes(Metro metro,Estacoes estacoes){
	//Estacoes estacoes[200];
	//char *aux = (char*)malloc(sizeof(char));
	int i, c = 0, j;
	for(i=0; i < 200; i++){
		if(strcmp(metro.nomeEstacao,estacoes.nome) == 0){
			c += 1;
			if(c > 1){
				j +=1;
				return j;
			}
			c = 0;
		}

	}
			


return 0;
}