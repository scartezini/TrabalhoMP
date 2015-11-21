#include <gtest/gtest.h>
#include "../app/header/Geradores.h"

//! Testando a funcao criaListaGerador
TEST(criaListaGerador, vazia){

	Gerador *gerador = criaListaGerador();
	ASSERT_TRUE(gerador == NULL);
}

//! Testando a funcao geradorVazio
	//! Caso vazio
TEST(geradorVazio, vazio){
	Gerador *gerador = criaListaGerador();
	ASSERT_TRUE(geradorVazio(gerador) == VAZIO);
}
	//! Caso naoVazia
TEST(geradorVazio, naoVazio){
	Gerador *gerador = criaListaGerador();
	gerador = (Gerador *) malloc (sizeof(Gerador));
	ASSERT_TRUE(geradorVazio(gerador) == NAO_VAZIO);
}

//! Testando a funcao insereGerador
	//! Caso vazio
TEST(insereGerador, Vazio){
	Gerador *gerador = criaListaGerador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("G Usina1 5 5 100 1000"));
	char *nome = (char *) malloc(sizeof(char) * strlen("Usina1"));

	strcpy(entrada,"G Usina1 5 5 100 1000");
	strcpy(nome, "Usina1");

	gerador = insereGerador(entrada,gerador);
	ASSERT_TRUE(strcmp(nome,gerador->nome) == 0);
	EXPECT_EQ(gerador->posicao[0], 5);
	EXPECT_EQ(gerador->posicao[1], 5);
	EXPECT_EQ(gerador->recursoProduzido, 100);
	EXPECT_EQ(gerador->custo, 1000);
}
	//! Caso naoVazio
TEST(insereGerador, naoVazio){
	Gerador *gerador = criaListaGerador();

	char *entrada = (char *) malloc(sizeof(char) * strlen("G Usina1 5 5 100 1000"));
	char *nome = (char *) malloc(sizeof(char) * strlen("Usina1"));

	strcpy(entrada,"G Usina1 5 5 100 1000");
	strcpy(nome, "Usina1");

	gerador = insereGerador(entrada,gerador);
	ASSERT_TRUE(strcmp(nome,gerador->nome) == 0);
	EXPECT_EQ(gerador->posicao[0], 5);
	EXPECT_EQ(gerador->posicao[1], 5);
	EXPECT_EQ(gerador->recursoProduzido, 100);
	EXPECT_EQ(gerador->custo, 1000);

	//! Inicio do teste em si
	strcpy(entrada,"G Usina2 5 15 388 788");
	strcpy(nome, "Usina2");

	gerador = insereGerador(entrada,gerador);
	ASSERT_TRUE(strcmp(nome,gerador->nome) == 0);
	EXPECT_EQ(gerador->posicao[0], 5);
	EXPECT_EQ(gerador->posicao[1], 15);
	EXPECT_EQ(gerador->recursoProduzido, 388);
	EXPECT_EQ(gerador->custo, 788);

	strcpy(entrada,"G Usina1 5 5 100 1000");
	strcpy(nome, "Usina1");

	gerador = gerador->proximo;
	ASSERT_TRUE(strcmp(nome,gerador->nome) == 0);
	EXPECT_EQ(gerador->posicao[0], 5);
	EXPECT_EQ(gerador->posicao[1], 5);
	EXPECT_EQ(gerador->recursoProduzido, 100);
	EXPECT_EQ(gerador->custo, 1000);
}