/*
	created by Vanessa Braganholo
	updated by Raphael Oliveira (nov/2020)
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define NOME_ARQUIVO_HASH "tabHash.dat"
#define NOME_ARQUIVO_DADOS "clientes.dat"

#include <stdlib.h>

#include "lista_clientes.h"
#include "cliente.h"
#include "lista_compartimentos.h"
#include "compartimento_hash.h"
#include "encadeamento_exterior.h"


void teste01(){
	//TEST("Cria Tabela Vazia. Testa o caso de tabela hash com compartimentos vazios");
	// Estamos usando tabela hash de tamanho 7	
	// Adicionar 7 compartimentos que nao apontam para ninguem (prox = -1)
	ListaCompartimentos *tab_hash;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1));

	cria_hash(NOME_ARQUIVO_HASH, 7);

	imprime_compartimentos(tab_hash);

	libera_compartimentos(tab_hash);
}

void teste02(){
	//TEST("Busca chave que eh encontrada na primeira tentativa");
	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(-1),
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(1,
		cliente(50, "Carlos", -1, OCUPADO));	
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = busca(50, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);

	printf("\n O endereço retornado é: %d\n",end); //endereco retornado deve ser igual a 0
	
	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);
}

void teste03(){
	//TEST("Busca chave que existia mas foi removida");
	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(-1),
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(1,
		cliente(50, "Carlos", -1, LIBERADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = busca(50, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);

	printf("\n O endereço retornado é: %d\n",end); //endereco retornado deve ser igual a -1

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);	
}

void teste04(){
	//TEST("Busca chave que eh encontrada na segunda tentativa");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(4),
		compartimento_hash(1),
		compartimento_hash(-1),
		compartimento_hash(2),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(6,
		cliente(49, "Joao", -1, OCUPADO),
		cliente(59, "Maria", 3, OCUPADO),
		cliente(103, "Pedro", -1, OCUPADO),
		cliente(10, "Janio", 5, OCUPADO),
		cliente(51, "Ana", -1, OCUPADO),
		cliente(87, "Mauricio", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = busca(10, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);

	printf("\n O endereço retornado é: %d\n",end);//endereco retornado deve ser igual a 3

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);
}

void teste05(){
	//TEST("Busca chave inexistente");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(4),
		compartimento_hash(1),
		compartimento_hash(-1),
		compartimento_hash(2),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(6,
		cliente(49, "Joao", -1, OCUPADO),
		cliente(59, "Maria", 3, OCUPADO),
		cliente(103, "Pedro", -1, OCUPADO),
		cliente(3, "Janio", 5, OCUPADO),
		cliente(51, "Ana", -1, OCUPADO),
		cliente(87, "Mauricio", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = busca(10, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);

	printf("\n O endereço retornado é: %d\n",end);	//endereco retornado deve ser igual a -1

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);
}

void teste06(){
	//TEST("Busca chave que havia sido removida, mas foi reinserida mais adiante no arquivo");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(4),
		compartimento_hash(1),
		compartimento_hash(-1),
		compartimento_hash(2),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(7,
		cliente(49, "Joao", -1, OCUPADO),
		cliente(59, "Maria", 3, OCUPADO),
		cliente(103, "Pedro", -1, OCUPADO),
		cliente(10, "Janio", 5, LIBERADO),
		cliente(51, "Ana", -1, OCUPADO),
		cliente(87, "Mauricio", 6, OCUPADO),
		cliente(10, "Janio S.", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = busca(10, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);

	printf("\n O endereço retornado é: %d\n",end);	//endereco retornado deve ser igual a 6

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);
}

void teste07(){
	//TEST("Insercao na 1 tentativa. Existe compartimento vazio na tabela para receber o registro");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(1,
		cliente(49, "Joao", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = insere(50, "Mariana", NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS, 1);

	printf("\n O endereço retornado é: %d\n",end);	//endereco retornado deve ser igual a 1

	tab_hash->lista[1]->prox = 1;

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);	
}

void teste08(){
	//TEST("Exclusao de chave inexistente");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(4),
		compartimento_hash(1),
		compartimento_hash(-1),
		compartimento_hash(2),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(6,
		cliente(49, "Joao", -1, OCUPADO),
		cliente(59, "Maria", 3, OCUPADO),
		cliente(103, "Pedro", -1, OCUPADO),
		cliente(3, "Janio", 5, LIBERADO),
		cliente(51, "Ana", -1, OCUPADO),
		cliente(87, "Mauricio", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = exclui(10, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);
	
	printf("\n O endereço retornado é: %d\n",end);	//endereco retornado deve ser igual a -1

	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);	
}

void teste09(){
	//TEST("Exclusao do primeiro noh da lista encadeada de um determinado compartimento");

	ListaCompartimentos *tab_hash;
	ListaClientes *tab_cliente;

	tab_hash = cria_compartimentos(7,
		compartimento_hash(0),
		compartimento_hash(-1),
		compartimento_hash(4),
		compartimento_hash(1),
		compartimento_hash(-1),
		compartimento_hash(2),
		compartimento_hash(-1));
	salva_compartimentos(NOME_ARQUIVO_HASH, tab_hash);

	tab_cliente = cria_clientes(6,
		cliente(49, "Joao", -1, OCUPADO),
		cliente(59, "Maria", 3, OCUPADO),
		cliente(103, "Pedro", -1, OCUPADO),
		cliente(3, "Janio", 5, LIBERADO),
		cliente(51, "Ana", -1, OCUPADO),
		cliente(87, "Mauricio", -1, OCUPADO));
	salva_clientes(NOME_ARQUIVO_DADOS, tab_cliente);

	int end = exclui(59, NOME_ARQUIVO_HASH, NOME_ARQUIVO_DADOS);
	printf("\n O endereço retornado é: %d\n",end);	//endereco retornado deve ser igual a 1

	tab_cliente->lista[1]->status = LIBERADO;
	
	libera_compartimentos(tab_hash);
	libera_clientes(tab_cliente);	
}


int main(){
	////TEST("Cria Tabela Vazia. Testa o caso de tabela hash com compartimentos vazios");
	teste01();

	//TEST("Busca chave que eh encontrada na primeira tentativa");
	teste02();

	//TEST("Busca chave que existia mas foi removida");
	teste03();

	//TEST("Busca chave que eh encontrada na segunda tentativa");
	teste04();

	//TEST("Busca chave inexistente");
	teste05();

	//TEST("Busca chave que havia sido removida, mas foi reinserida mais adiante no arquivo");
	teste06();

	//TEST("Insercao na 1 tentativa. Existe compartimento vazio na tabela para receber o registro");
	teste07();

	//TEST("Exclusao de chave inexistente");
	teste08();

	//TEST("Exclusao do primeiro noh da lista encadeada de um determinado compartimento");
	teste09();

	return 0;
}

