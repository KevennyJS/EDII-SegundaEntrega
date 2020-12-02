#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "compartimento_hash.h"


void imprime_compartimento(CompartimentoHash *compartimento)
{
	printf("%d\n", compartimento->prox);
}

CompartimentoHash *compartimento_hash(int prox)
{
	CompartimentoHash *compartimento = (CompartimentoHash *) malloc(sizeof(CompartimentoHash));
	compartimento->prox = prox;
	return compartimento;
}


void salva_compartimento(CompartimentoHash *compartimento, FILE *out)
{
	fwrite(&compartimento->prox, sizeof(int), 1, out);
}

CompartimentoHash *le_compartimento(FILE *in)
{
	CompartimentoHash *compartimento = (CompartimentoHash *) malloc(sizeof(CompartimentoHash));
	if (0 >= fread(&compartimento->prox, sizeof(int), 1, in)) {
		free(compartimento);
		return NULL;
	}
	return compartimento;
}

int cmp_compartimento(CompartimentoHash *c1, CompartimentoHash *c2)
{
	if (c1 == NULL) {
		return (c2 == NULL);
	}
	if (c1->prox != c2->prox) {
		return 0;
	}
	return 1;
}

int tamanho_compartimento()
{
	return sizeof(int); // prox
}