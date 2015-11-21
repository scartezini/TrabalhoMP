<<<<<<< HEAD
#include <gtest/gtest.h>
#include "../app/header/Interconexoes.h"

//! Testando a funcao criaListaInterconexao
TEST(criaListaInterconexao, vazia){

	Interconexao *interconexao = criaListaInterconexao();
	ASSERT_TRUE(interconexao == NULL);
}

//! Testando a funcao interconexaoVazia
	//! Caso vazia
TEST(interconexaoVazia, vazia){
	Interconexao *interconexao = criaListaInterconexao();
	ASSERT_TRUE(interconexaoVazia(interconexao) == VAZIA);
}
	//! Caso naoVazia
TEST(interconexaoVazia, naoVazia){
	Interconexao *interconexao = criaListaInterconexao();
	interconexao = (Interconexao *) malloc (sizeof(Interconexao));
	ASSERT_TRUE(interconexaoVazia(interconexao) == NAO_VAZIA);
}

//! Testando a funcao insereInterconexao
	//! Caso vazia
TEST(insereInterconexao, Vazia){
	Interconexao *interconexao = criaListaInterconexao();

	char *entrada = (char *) malloc(sizeof(char) * strlen("I inter_1 5 5 10 5 100 0.1 15 20"));
	char *nome = (char *) malloc(sizeof(char) * strlen("inter_1"));

	strcpy(entrada,"I inter_1 5 5 10 5 100 0.1 15 20");
	strcpy(nome, "inter_1");

	interconexao = insereInterconexao(entrada,interconexao);
	ASSERT_TRUE(strcmp(nome,interconexao->nome) == 0);
	EXPECT_EQ(interconexao->posicaoInicial[0], 5);
	EXPECT_EQ(interconexao->posicaoInicial[1], 5);
	EXPECT_EQ(interconexao->posicaoFinal[0], 10);
	EXPECT_EQ(interconexao->posicaoFinal[1], 5);
	EXPECT_EQ(interconexao->capacidadeMaxima, 100);
	EXPECT_DOUBLE_EQ(interconexao->chanceFalha, 0.1f);
	EXPECT_EQ(interconexao->tempoConserto, 15);
	EXPECT_EQ(interconexao->custoConserto, 20);
}
	//! Caso naoVazia
TEST(insereInterconexao, naoVazia){
	Interconexao *interconexao = criaListaInterconexao();
	Interconexao *aux = criaListaInterconexao();

	char *entrada = (char *) malloc(sizeof(char) * strlen("I inter_1 5 5 10 5 100 0.1 15 20"));
	char *nome = (char *) malloc(sizeof(char) * strlen("inter_1"));

	strcpy(entrada,"I inter_1 5 5 10 5 100 0.1 15 20");
	strcpy(nome, "inter_1");

	interconexao = insereInterconexao(entrada,interconexao);
	ASSERT_TRUE(strcmp(nome,interconexao->nome) == 0);
	EXPECT_EQ(interconexao->posicaoInicial[0], 5);
	EXPECT_EQ(interconexao->posicaoInicial[1], 5);
	EXPECT_EQ(interconexao->posicaoFinal[0], 10);
	EXPECT_EQ(interconexao->posicaoFinal[1], 5);
	EXPECT_EQ(interconexao->capacidadeMaxima, 100);
	EXPECT_DOUBLE_EQ(interconexao->chanceFalha, 0.1f);
	EXPECT_EQ(interconexao->tempoConserto, 15);
	EXPECT_EQ(interconexao->custoConserto, 20);

	//! Inicio do teste em si
	strcpy(entrada,"I inter_2 5 15 10 10 200 0.2 17 25");
	strcpy(nome, "inter_2");

	interconexao = insereInterconexao(entrada,interconexao);
	aux = interconexao->proximo;
	ASSERT_TRUE(strcmp(nome,aux->nome) == 0);
	EXPECT_EQ(aux->posicaoInicial[0], 5);
	EXPECT_EQ(aux->posicaoInicial[1], 15);
	EXPECT_EQ(aux->posicaoFinal[0], 10);
	EXPECT_EQ(aux->posicaoFinal[1], 10);
	EXPECT_EQ(aux->capacidadeMaxima, 200);
	EXPECT_DOUBLE_EQ(aux->chanceFalha, 0.2f);
	EXPECT_EQ(aux->tempoConserto, 17);
	EXPECT_EQ(aux->custoConserto, 25);

	strcpy(entrada,"I inter_1 5 5 10 5 100 0.1 15 20");
	strcpy(nome, "inter_1");

	ASSERT_TRUE(strcmp(nome,interconexao->nome) == 0);
	EXPECT_EQ(interconexao->posicaoInicial[0], 5);
	EXPECT_EQ(interconexao->posicaoInicial[1], 5);
	EXPECT_EQ(interconexao->posicaoFinal[0], 10);
	EXPECT_EQ(interconexao->posicaoFinal[1], 5);
	EXPECT_EQ(interconexao->capacidadeMaxima, 100);
	EXPECT_DOUBLE_EQ(interconexao->chanceFalha, 0.1f);
	EXPECT_EQ(interconexao->tempoConserto, 15);
	EXPECT_EQ(interconexao->custoConserto, 20);
}
=======
#include "../app/header/Interconexoes.h"
>>>>>>> af17af09d23ef9c3866b6375e4617464b08eaf12
