#include "Interconexoes.h"
#include <assert.h>

float tamanhoConexao(Interconexao *interconexao){
	
	int xA;
	int yA;
	
	int xB;
	int yB;
	
	xA = interconexao->posicaoInical[0];
	yA = interconexao->posicaoInical[1];
	
	xB = interconexao->posicaoFinal[0];
	yB = interconexao->posicaoFinal[1];
	
	return sqrt(pow((xB - xA),2) + pow((yB - yA),2));
	
}

/**
*	Funcao: tamanhoTotalConexao
*
*	AssertivaEntrada:
*		interconexao != NULL; 
*
*	AssertivaSaida:
*		resultado > 0; 
**/
float tamanhoTotalConexao(Interconexao *interconexao){
	assert(interconexao != NULL);

	float resultado = 0;
	Interconexao auxiliar;

	auxiliar = interconexao;
	//! Asseriva estrutural: 
	while(interconexao != NULL){
		resultado += tamanhoConexao(auxiliar);
		auxiliar = auxiliar->proximo;
	}
	
	assert(resultado > 0);
	return resultado;
}

/**
*	Funcao: calculaFalha
*
*	AssertivaSaida:
*		falha || semFalha; 
**/
Falha calculaFalha(){
	float num;
	float chance = 0.01;

	//! Asseriva estrutural: num eh um numero gerado aleatoriamente
	srand(1); 
	num = ((float)rand())/RAND_MAX;

	if ( (chance > 0) && (chance >= num) ) 
	//! AE: chance deve ser maior que 0 e maior ou igual a num 
		return falha;
	else
	//! AE: chance deve ser menor que 0 ou menor que num 
		return semFalha;
	//! AS: o retorno deve ser uma variavel do tipo Falha 
}
