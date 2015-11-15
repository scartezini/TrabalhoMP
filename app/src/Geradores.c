#include "../header/Geradores.h"
#include <assert.h>

/**
*	Funcao: criaListaGerador
*
*	AssertivaSaida:
*		NULL; 
**/
Gerador* criaListaGerador(){
	return NULL;
}

/**
*	Funcao: criaListaCidade
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO; 
**/
Vazio geradorVazio(Gerador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIO;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIO;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}