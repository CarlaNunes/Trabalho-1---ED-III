#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

#include "funcoes.h"

int main() {
    Metro metro[200];
    FILE *arquivo;
    int cont = 0; // número de pessoas lidas 

    
    cont = le_arquivo(arquivo); 
    printf("pessoas lidas: %d\n",cont);


}