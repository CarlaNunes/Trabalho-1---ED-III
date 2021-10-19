#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoes.h"

int main() {
    Metro metro[200];
    FILE *arquivo;
    int cont = 0; 

    
    cont = le_arquivo_novo(arquivo); 
    printf("Estações lidas: %d\n",cont);

 return 0;
}