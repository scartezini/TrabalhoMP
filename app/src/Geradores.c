#include "Geradores.h"
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
*		vazio || naoVazio; 
**/
Vazio geradorVazio(Gerador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return vazia;
	else
	//! AE: listaAlvo nao eh vazia
		return naoVazia;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}