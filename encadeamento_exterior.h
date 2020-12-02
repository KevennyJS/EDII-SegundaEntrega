#ifndef ENCADEAMENTO_EXTERIOR_H
#define ENCADEAMENTO_EXTERIOR_H

// Cria uma tabela hash vazia de tamanho tam, e salva no arquivo nome_arquivo_hash
// Compartimento que nao tem lista encadeada associada deve ter valor igual a -1
// nome_arquivo_hash: nome do arquivo hash a ser criado
// tan: tamanho da tabela hash a ser criada
void cria_hash(char *nome_arquivo_hash, int tam);

// Executa busca em Arquivos por Encadeamento Exterior (Hash)
// Assumir que ponteiro para proximo noh eh igual a -1 quando nao houver proximo noh
// cod_cli: chave do cliente que esta sendo buscado
// nome_arquivo_hash: nome do arquivo que contem a tabela hash
// nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
// Retorna o endereco onde o cliente foi encontrado, ou -1 se nao for encontrado
int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados);

// Executa insercao em Arquivos por Encadeamento Exterior (Hash)
// cod_cli: chave do cliente que esta sendo inserido
// nome_cli: nome do cliente a ser inserido
// nome_arquivo_hash: nome do arquivo que contem a tabela hash
// nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
// num_registros: numero de registros que ja existem gravados no arquivo
// Retorna o endereco onde o cliente foi inserido, ou -1 se nao conseguiu inserir
int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros);

// Executa exclusao em Arquivos por Encadeamento Exterior (Hash)
// cod_cli: chave do cliente a ser excluido
// nome_arquivo_hash: nome do arquivo que contem a tabela hash
// nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
// Retorna o endereco do cliente que foi excluido, ou -1 se cliente nao existe
int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados);

#endif