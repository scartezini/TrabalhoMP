#include <gtest/gtest.h>
#include "../app/header/Cidades.h"

//! Testando a funcao criaListaCidade
TEST(criaListaCidade, vazia){

	Cidade *cidade = criaListaCidade();
	ASSERT_TRUE(cidade == NULL);
}

//! Testando a funcao cidadeVazia
	//! Caso vazia
TEST(cidadeVazia, vazia){
	Cidade *cidade = criaListaCidade();
	ASSERT_TRUE(cidadeVazia(cidade) == VAZIA);
}
	//! Caso naoVazia
TEST(cidadeVazia, naoVazia){
	Cidade *cidade = criaListaCidade();
	cidade = (Cidade *) malloc (sizeof(Cidade));
	ASSERT_TRUE(cidadeVazia(cidade) == NAO_VAZIA);
}

//! Testando a funcao insereCidade
	//! Caso vazia
TEST(insereCidade, Vazia){
	Cidade *cidade = criaListaCidade();

	char *entrada = (char *) malloc(sizeof(char) * strlen("C Brasília 1 5 143"));
	char *nome = (char *) malloc(sizeof(char) * strlen("Brasília"));

	strcpy(entrada,"C Brasília 1 5 143");
	strcpy(nome, "Brasília");

	cidade = insereCidade(entrada,cidade);
	ASSERT_TRUE(strcmp(nome,cidade->nome) == 0);
	EXPECT_EQ(cidade->posicao[0], 1);
	EXPECT_EQ(cidade->posicao[1], 5);
	EXPECT_EQ(cidade->recursoNecessario, 143);
}
	//! Caso naoVazia
TEST(insereCidade, naoVazia){
	Cidade *cidade = criaListaCidade();

	char *entrada = (char *) malloc(sizeof(char) * strlen("C Brasília 1 5 143"));
	char *nome = (char *) malloc(sizeof(char) * strlen("Brasília"));

	strcpy(entrada,"C Brasília 1 5 143");
	strcpy(nome, "Brasília");

	cidade = insereCidade(entrada,cidade);
	ASSERT_TRUE(strcmp(nome,cidade->nome) == 0);
	EXPECT_EQ(cidade->posicao[0], 1);
	EXPECT_EQ(cidade->posicao[1], 5);
	EXPECT_EQ(cidade->recursoNecessario, 143);

	//! Inicio do teste em si
	strcpy(entrada,"C Belo_Horizonte 1 10 177");
	strcpy(nome, "Belo_Horizonte");

	cidade = insereCidade(entrada,cidade);
	ASSERT_TRUE(strcmp(nome,cidade->nome) == 0);
	EXPECT_EQ(cidade->posicao[0], 1);
	EXPECT_EQ(cidade->posicao[1], 10);
	EXPECT_EQ(cidade->recursoNecessario, 177);

	strcpy(entrada,"C Brasília 1 5 143");
	strcpy(nome, "Brasília");

	cidade = cidade->proximo;
	ASSERT_TRUE(strcmp(nome,cidade->nome) == 0);
	EXPECT_EQ(cidade->posicao[0], 1);
	EXPECT_EQ(cidade->posicao[1], 5);
	EXPECT_EQ(cidade->recursoNecessario, 143);
}

//! Testando a funcao recursoGastoTotal
TEST(recursoGastoTotal, geral){
	Cidade *cidade = criaListaCidade();

	int soma = 0;

	char *entrada = (char *) malloc(sizeof(char) * strlen("C Belo_Horizonte 1 10 177"));

	strcpy(entrada,"C Belo_Horizonte 1 10 177");

	cidade = insereCidade(entrada,cidade);
	soma++;

	strcpy(entrada,"C Brasília 1 5 143");

	cidade = insereCidade(entrada,cidade);
	soma++;

	ASSERT_TRUE(numeroCidades(cidade) == soma);

	soma++;
	ASSERT_TRUE(numeroCidades(cidade) != soma);
}

//! Testando a funcao numeroCidades
TEST(numeroCidades, geral){
	Cidade *cidade = criaListaCidade();

	int soma = 0;

	char *entrada = (char *) malloc(sizeof(char) * strlen("C Belo_Horizonte 1 10 177"));

	strcpy(entrada,"C Belo_Horizonte 1 10 177");

	cidade = insereCidade(entrada,cidade);
	soma++;

	strcpy(entrada,"C Brasília 1 5 143");

	cidade = insereCidade(entrada,cidade);
	soma++;

	//! Inicio do teste em si
	ASSERT_TRUE(numeroCidades(cidade) == soma);

	soma++;
	ASSERT_TRUE(numeroCidades(cidade) != soma);
}