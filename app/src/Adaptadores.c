#include "../header/Adaptadores.h"
#include <assert.h>

/**
*	Funcao: criaListaAdaptador
*
*	AssertivaSaida:
*		NULL; 
**/
Adaptador* criaListaAdaptador(){
	return NULL;
}

/**
*	Funcao: adaptadorVazio
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO; 
**/
Vazio adaptadorVazio(Adaptador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIO;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIO;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereAdaptador
*
*	AssertivaEntrada:
*		
*
*	AssertivaSaida:
*		
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo){

	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador));
	char numchar[strlen(registro)];
	int i,j=0,k=2;

	for(i=2;registro[i]!=' ';i++);
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<3;i++){
		if(registro[i] == ' '||registro[i] == '\0'){
			if(j == 0)
				novo->nome[i-k] = '\0';
			else{
				numchar[i-k] = '\0';
				if(j == 1)
					novo->posicao[0] = atoi(numchar);
				else if(j == 2)
					novo->posicao[1] = atoi(numchar);
			}

			k = i+1;
			j++;
		}

		else{

			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numchar[i-k] = registro[i];
		}
	}
	novo->saidas = NULL;
	novo->quatidadeSaidas =0;

	novo->recursoRecebido = 0;
	novo->peso = NULL;

	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

/**
*	Funcao: imprimeListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		
**/
void imprimeListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Cidade *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos do adaptador corrente
		**/
		printf("nome: %s pos_x: %d pos_y: %d recurso recebido%d quantidade de saidas%d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoRecebido
				,aux->quantidadeSaidas);
	}
	//! AS: listaAlvo chegou ao fim		
}

/**
*	Funcao: liberaListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		adaptadorVazio(listaAlvo) == VAZIO;
*		
**/
void liberaListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux1 = NULL;
	Adaptador *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Adaptador
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(adaptadorVazio(listaAlvo) == VAZIO);
}

/**
*
*	Funcao: defineDistribuicao
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		para cada adaptador da lista: adaptador->saidas[i] != null;
**/
void defineDistribuicao(Adaptador *adaptador){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);
	
	while(adaptador != NULL){

		if(adaptador->saidas == NULL){
			return;
		}

		if(adaptador->peso == NULL){
			adaptador->peso = (float *) malloc(adaptador->quatidadeSaidas * sizeof(float));
		}


		int i;
		int somatorio = 0;
		for(i=0;i<adaptador->quatidadeSaidas;i++){

			if(adaptador->saidas[i]->tagFalha == semFalha){
				somatorio += adaptador->saidas[i]->capacidadeMaxima;
			}
		}


		int recursoTransportado;
		Interconexao *conexao;
		for (int i = 0; i < adaptador->quatidadeSaidas; ++i){

			conexao = adaptador->saidas[i];

			if(conexao->tagFalha == semFalha){

			//! Comentarios de argumentacao
				/**
				*	Recurso transportado é a quantidade de recurso que cada 
				* conexao vai transportar no turno
				*	Somatorio é a soma de capaxidade maxima de todos as conexoes
				* ativas;
				*
				*	RT = recursoTransportado
				*	CM = capacidadeMaxima
				*	RS = recursoRecebido
				*
				*	RT = CM*RS/somatorio
				*
				**/
				recursoTransportado = conexao->capacidadeMaxima 
				 						* adaptador->recursoRecebido 
				 						/ somatorio;

				/**
				*
				*	if(recursoTransportado <= conexao->capacidadeMaxima){
				*		conexao->recursoTransportado = recursoTransportado;
				*	}else{
				*		conexao->recursoTransportado = conexao->capacidadeMaxima;
				*	}
				*
				**/
				recursoTransportado <= conexao->capacidadeMaxima ? 
				 						conexao->recursoTransportado = recursoTransportado :
				 						conexao->recursoTransportado = conexao->capacidadeMaxima;
			}
		}


		adaptador = adaptador->proximo;
	}
}
