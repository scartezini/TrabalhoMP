#include <gtest/gtest.h>
#include "../app/header/Adaptadores.h"

//! Testando a funcao criaListaAdaptador
TEST(criaListaAdaptador, vazia){

	Adaptador *adaptador = criaListaAdaptador();
	ASSERT_TRUE(adaptador == NULL);
}

//! Testando a funcao adaptadorVazio
	//! Caso vazio
TEST(adaptadorVazio, vazio){
	Adaptador *adaptador = criaListaAdaptador();
	ASSERT_TRUE(adaptadorVazio(adaptador) == VAZIO);
}
	//! Caso naoVazio
TEST(adaptadorVazio, naoVazio){
	Adaptador *adaptador = criaListaAdaptador();
	adaptador = (Adaptador *) malloc (sizeof(Adaptador));
	ASSERT_TRUE(adaptadorVazio(adaptador) == NAO_VAZIO);
}

//! Testando a funcao insereAdaptador
	//! Caso vazio
TEST(insereAdaptador, Vazio){
	Adaptador *adaptador = criaListaAdaptador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("A adapta_1 2 3"));
	char *nome = (char *) malloc(sizeof(char) * strlen("adapta_1"));

	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	EXPECT_EQ(adaptador->posicao[0], 2);
	EXPECT_EQ(adaptador->posicao[1], 3);
}
	//! Caso naoVazio
TEST(insereAdaptador, naoVazio){
	Adaptador *adaptador = criaListaAdaptador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("A adapta_1 2 3"));
	char *nome = (char *) malloc(sizeof(char) * strlen("adapta_1"));

	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	EXPECT_EQ(adaptador->posicao[0], 2);
	EXPECT_EQ(adaptador->posicao[1], 3);

	//! Inicio do teste em si
	strcpy(entrada,"A adapta_2 4 5");
	strcpy(nome, "adapta_2");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	EXPECT_EQ(adaptador->posicao[0], 4);
	EXPECT_EQ(adaptador->posicao[1], 5);

	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = adaptador->proximo;
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	EXPECT_EQ(adaptador->posicao[0], 2);
	EXPECT_EQ(adaptador->posicao[1], 3);
}
