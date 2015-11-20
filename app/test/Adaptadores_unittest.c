#include <gtest/gtest.h>
#include "../header/Adaptadores.h"

TEST(criaListaAdaptador, vazia){

	Adaptador *adaptador = criaListaAdaptador();
	ASSERT_TRUE(adaptador == NULL);

}

TEST(adaptadorVazio, vazio){
	Adaptador *adaptador = criaListaAdaptador();
	ASSERT_TRUE(adaptadorVazio(adaptador) == VAZIO);

}

TEST(adaptadorVazio, naoVazio){
	Adaptador *adaptador = criaListaAdaptador();
	adaptador = (Adaptador *) malloc (sizeof(Adaptador));
	ASSERT_TRUE(adaptadorVazio(adaptador) == NAO_VAZIO);
}


TEST(insereAdaptador, Vazio){
	Adaptador *adaptador = criaListaAdaptador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("A adapta_1 2 3"));
	char *nome = (char *) malloc(sizeof(char) * strlen("adapta_1"));

	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	ASSERT_TRUE(adaptador->posicao[0] == 2);
	ASSERT_TRUE(adaptador->posicao[1] == 3);
}

TEST(insereAdaptador, naoVazio){
	Adaptador *adaptador = criaListaAdaptador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("A adapta_1 2 3"));
	char *nome = (char *) malloc(sizeof(char) * strlen("adapta_1"));

	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	ASSERT_TRUE(adaptador->posicao[0] == 2);
	ASSERT_TRUE(adaptador->posicao[1] == 3);

	strcpy(entrada,"A adapta_2 4 5");
	strcpy(nome, "adapta_2");

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	ASSERT_TRUE(adaptador->posicao[0] == 4);
	ASSERT_TRUE(adaptador->posicao[1] == 5);


	strcpy(entrada,"A adapta_1 2 3");
	strcpy(nome, "adapta_1");

	adaptador = adaptador->proximo;
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	ASSERT_TRUE(adaptador->posicao[0] == 2);
	ASSERT_TRUE(adaptador->posicao[1] == 3);

}

