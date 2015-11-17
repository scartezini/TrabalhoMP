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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
   	return RUN_ALL_TESTS();
}