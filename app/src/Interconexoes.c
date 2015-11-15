#include "../header/Interconexoes.h"
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
	Interconexao *aux;

	//! Asseriva estrutural: aux é a lista nao-nula de interconexoes
	aux = interconexao;

	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de inteconexoes

		//! Comentarios de argumentacao
			/**
			*	Enquanto a lista de interconexoes eh percorrida, o tamanho
			* das conexoes sao somados e armazenados na variavel resultado 
			**/

		resultado += tamanhoConexao(aux);
		aux = aux->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim

	assert(resultado > 0);
	return resultado;
}

/**
*	Funcao: calculaFalha
*
*	AssertivaSaida:
*		FALHA || SEM_FALHA; 
**/
Falha calculaFalha(){
	float num;
	float chance = 0.01;

	//! Asseriva estrutural: num eh um numero gerado aleatoriamente
	srand(1); 
	num = ((float)rand())/RAND_MAX;

	if ( (chance > 0) && (chance >= num) ) 
	//! AE: chance deve ser maior que 0 e maior ou igual a num 
		return FALHA;
	else
	//! AE: chance deve ser menor que 0 ou menor que num 
		return SEM_FALHA;
	//! AS: o retorno deve ser uma variavel do tipo Falha 
}

/**
*
*	Funcao: mandarRecursoTransportado
*	
*	AssertivaEntrada:
*		interconexao != NULL;
*
**/
void mandarRecursoTransportado(Interconexao *interconexao){
	assert(interconexao != NULL);
	
	Interconexao *aux;
	int recursoEnviado;

	//! Asseriva estrutural: aux é a lista nao-nula de interconexoes
	aux = interconexao;
	
	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de inteconexoes
	
		if(aux->tagFalha == semFalha){
		//! AE: a interconexao corrente nao possui falha
			recursoEnviado = aux->recursoTransportado;
			
			//! Comentarios de argumentacao
				/**
				*	Enqaunto a lista de interconexoes eh percorrida, dependendo do destino da interconexao, 
				* soma-se o recurso ao respectivo destino
				**/
				
			if(aux->tagDestino == ADAPTADOR){
			//! AE: o destino da interconexao eh um Adaptador
				aux->adaptador->recursoRecebido += recursoEnviado;
			}
			else if(aux->tagDestino == CIDADE){
			//! AE: o destino da interconexao eh uma Cidade
				aux->cidade->recursoRecebido += recursoEnviado;
			}
		}

		aux = aux->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim
}