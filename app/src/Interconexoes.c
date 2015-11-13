#include "Interconexoes.h"
#include <assert.h>

/**
*	Funcao: criaListaInterconexao
*
*	AssertivaSaida:
*		NULL; 
**/
Interconexao* criaListaInterconexao(){
	return NULL;
}

/**
*	Funcao: tamanhoConexao
*
*	AssertivaEntrada:
*		interconexao != NULL; 
*
*	AssertivaSaida:
*		distancia > 0; 
**/
float tamanhoConexao(Interconexao *interconexao){
	assert(interconexao != NULL);

	int xA; //!< Valor no eixo x da posicao inicial 
	int yA; //!< Valor no eixo y da posicao inicial 
	
	int xB; //!< Valor no eixo x da posicao final
	int yB; //!< Valor no eixo y da posicao final

	int distancia;
	
	xA = interconexao->posicaoInical[0];
	yA = interconexao->posicaoInical[1];
	
	xB = interconexao->posicaoFinal[0];
	yB = interconexao->posicaoFinal[1];

	//! Comentarios de argumentacao
		/**
		*	Calculando a distancia utilizando ((xb-xa)^2 + (yb-ya)^2)^(1/2)
		**/

	distancia = sqrt(pow((xB - xA),2) + pow((yB - yA),2));
	
	assert(distancia > 0);
	return distancia;
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

	//! Asseriva estrutural: auxiliar é a lista nao-nula de interconexoes
	auxiliar = interconexao;

	while(auxiliar != NULL){
	//! AE: auxliar nao chegou ao fim da lista de inteconexoes

		//! Comentarios de argumentacao
			/**
			*	Enquanto a lista de interconexoes eh percorrida, o tamanho
			* das conexoes sao somados e armazenados na variavel resultado 
			**/

		resultado += tamanhoConexao(auxiliar);
		auxiliar = auxiliar->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim

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
