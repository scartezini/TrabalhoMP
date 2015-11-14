#include "Cidades.h"
#include <assert.h>

/**
*	Funcao: recursoGastoTotal
*
**/
int recursoGastoTotal(Cidade *cidade){

}

/**
*	Funcao: criaListaCidade
*
*	AssertivaSaida:
*		NULL; 
**/
Cidade* criaListaCidade(){
	return NULL;
}

/**
*	Funcao: criaListaCidade
*
*	AssertivaSaida:
*		vazia || naoVazia; 
**/
Vazia cidadeVazia(Cidade *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return vazia;
	else
	//! AE: listaAlvo nao eh vazia
		return naoVazia;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereCidade
*
*	AssertivaEntrada:
*		
*
*	AssertivaSaida:
*		
**/
Cidade* insereCidade(char *registro, Cidade *listaAlvo){
	Cidade *novo = (Cidade *)malloc(sizeof(Cidade)); 
	char *numChar = (char) malloc (strlen(registro)*sizeof(char)); 
	int i,j=0,k=2; 

	for(i=2;registro[i]!=' ';i++); 
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<4;i++) 
	{
		if(registro[i] == ' '|| registro[i] == '\0') 
		{
			if(j == 0) 
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1) 
					novo->posicao[0] = atoi(numchar);
				else if(j == 2) 
					novo->posicao[1] = atoi(numchar);
				else if(j == 3) 
					novo->recursoNecessario = atoi(numchar);
			}
			k = i+1; 
			j++; 
		}
		else 
		{
			if(j == 0) 
				novo->nome[i-k] = registro[i];
			else
				numChar[i-k] = registro[i];
		}
	}
	
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

/**
*	Funcao: imprimeListaCidade
*
*	AssertivaEntrada:
*		cidadeVazia(listaAlvo) == naoVazia;
*		
**/
void imprimeListaCidade(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == naoVazia);

	Cidade *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime o nome, as posicoes e o recurso necessario da cidade
		* corrente na lista auxiliar
		**/
		printf("nome: %s pos_x: %d pos_y: %d recurso necessario%d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoNecessario);
	}
	//! AS: listaAlvo chegou ao fim		
}

/**
*	Funcao: imprimeListaCidade
*
*	AssertivaEntrada:
*		cidadeVazia(listaAlvo) == naoVazia;
*
*	AssertivaSaida:
*		listaAlvo == NULL;
*		
**/
void liberaListaCidade(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == naoVazia);

	Cidade *aux1 = NULL;
	Cidade *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Cidade
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(listaAlvo == NULL);
}