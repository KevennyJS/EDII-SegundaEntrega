#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include "stdio.h"
#include <stdlib.h>

#include "encadeamento_exterior.h"
#include "compartimento_hash.h"

void cria_hash(char *nome_arquivo_hash, int tam)
{
	//TODO: criar a tabela hash
    FILE *out = fopen(nome_arquivo_hash, "wb");
    CompartimentoHash *a =  malloc(sizeof(CompartimentoHash));
    a->prox = -1;
    if (out == NULL){
        printf("So sorry, i can't open this archive");
    }else{
        for(int i =0;i<tam;i++)
            fwrite(&a->prox,sizeof(int),1,out);
    }
    fclose(out);
}

int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo
    return INT_MAX;
}


int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros)
{
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}
