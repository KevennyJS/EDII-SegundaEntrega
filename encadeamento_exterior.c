#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"

#include "encadeamento_exterior.h"
#include "compartimento_hash.h"

int funcHash(int codClient,int tam){ return codClient % tam ;}

void cria_hash(char *nome_arquivo_hash, int tam)
{
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
    FILE *in = fopen(nome_arquivo_hash, "rb");
    FILE *out = fopen(nome_arquivo_dados, "rb+");
    if (in == NULL || out == NULL){
        printf("So sorry, i can't open this archive");
    }else{
        int posClient = -1;
        int hashCod = funcHash(cod_cli,7);
        // busca a posição do cliente na hashtable
        fseek(in, sizeof(int) * hashCod, SEEK_SET);
        fread(&posClient, sizeof(int), 1, in);

        if(posClient == -1){
            return -1;
        }

        fseek(out, tamanho_cliente() * posClient, SEEK_SET);
        Cliente *c = le_cliente(out);
        // verifica se é o cliente se não verifica se tem proximo
        while (c->cod_cliente != cod_cli && c->prox != -1){
            fseek(out, tamanho_cliente() * c->prox, SEEK_SET);
            posClient = c->prox;
            c = le_cliente(out);
        }

        if (c->prox == -1 && c->cod_cliente!= cod_cli){ // cliente não existe
            return -1;
        }

        c->status = LIBERADO;
        fseek(out, sizeof(Cliente) * posClient, SEEK_SET);
        salva_cliente(c,out);

    }
    fclose(out);
    fclose(in);
    return -1;
}
