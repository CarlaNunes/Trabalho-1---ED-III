#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include"funcoes.h"



/*
* Abaixo seguem funções que fazem a escrita do binário em "stdout" (tela) pra poder ser comparado no run.codes.
*
* Funciona assim: você faz tudo o que tiver que fazer na funcionalidade no arquivo em disco, assim como ensinado nas aulas da disciplina.
* Ao fim da funcionalidade, use a função "binarioNaTela" e a função já cuida de tudo para você. É só chamar a função.
*
* Note que ao usar a binarioNaTela, o fclose no arquivo binário já deve ter sido feito anteriormente! Você passa o nome do arquivo binário pra ela e ela vai lidar com a correção necessária.
*
* Você pode colocar isso num módulo *.h separado, ou incluir as funções no próprio código *.c: como preferir.
* VOCÊ NÃO PRECISA ENTENDER ESSAS FUNÇÕES. É só usar elas da forma certa depois de acabar a funcionalidade.
* NÃO MODIFIQUE ESSAS FUNÇÕES. Da forma como elas estão aqui, já estão funcionando para o propósito delas.
*
* Já está tudo testado e funcionando, mas qualquer dúvida acerca destas funções, falar com o monitor Matheus (mcarvalhor@usp.br).
*/



void binarioNaTela1(char *nomeArquivoBinario, char *nomeArquivoIndice) {

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	FILE *fs, *fi;
	size_t fl;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO NA FUNÇÃO BINARIO NA TELA. Não se esqueça do fclose e verifique se passou o argumento corretamente!\n");
		return;
	}
	if(nomeArquivoIndice == NULL || !(fi = fopen(nomeArquivoIndice, "rb"))) {
		fprintf(stderr, "ERRO NA FUNÇÃO BINARIO NA TELA. Não se esqueça do fclose e verifique se passou o argumento corretamente!\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);
	fclose(fs);
	cs = fl;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	fseek(fi, 0, SEEK_END);
	fl = ftell(fi);
	fseek(fi, 0, SEEK_SET);
	mb = (unsigned char *) realloc(mb, fl);
	fread(mb, 1, fl, fi);
	fclose(fi);
	cs += fl;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
}
