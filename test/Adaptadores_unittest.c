#include <gtest/gtest.h>
#include "../app/header/Adaptadores.h"


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

	entrada = "A adapta_1 2 3";
	nome = "adapta_1";

	adaptador = insereAdaptador(entrada,adaptador);
	ASSERT_TRUE(strcmp(nome,adaptador->nome) == 0);
	ASSERT_TRUE(adaptador->posicao[0] == 2);
	ASSERT_TRUE(adaptador->posicao[1] == 3);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
   	return RUN_ALL_TESTS();
}