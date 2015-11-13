#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* 	Cabecalho do elemento Cidade
* 	
*	nome:
* 		nome da cidade
*
* 	posicao:
* 		vetor posicao, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	recursoNecessario:
* 		quantidade de recurso que a cidade precisa por segundo
*
* 	recursoGasto:
*		quantidade de recurso que a cidade usou
*
* 	proximo:
* 		representa a proxima cidade da rede de cidades
**/

typedef struct cidade{
	char *nome;
	int posicao[2];
	int recursoNecessario;
	int recursoGasto;
	Cidade *proximo;
	
}Cidade;


/**
*	Funcao: recursoGastoTotal
*
*	Resultado da soma de todos recursos 
* gasto pelas cidades 
*
*	@param cidade
*		ponteiro para o inicio da lista de cidades
*	
*	@return 
*		total de recursos gasto pelas cidades
**/
int recursoGastoTotal(Cidade *cidade);

/**
*	Funcao: criaListaCidade
*
*	Inicia um ponteiro que sera para Cidade
*
*	@return null
*
**/
Cidade* criaListaCidade()

/**
*	Funcao: insereCidade
*
*	Inserir uma nova celula na lista de cidades
* a insercao se da pelo inicio da lista e é retornadado
* o novo ponterio para lista.
*
*	@param registro
*		string que sera lida do arquivo representando Cidade
*	@param listaAlvo 
*		lista de cidade a qual a nova celula sera inserida
*
*	@return
*		novo pontero para a o inicio da lista de cidade
**/
Cidade* insereCidade(char *registro, Cidade *listaAlvo);


/**
*	Funcao: imprimeListaCidade
*
*	Imprime de todas as celulas de lista de cidade
* as respectivas caracteristicas:
*	nome
*	posicao x
*	posicao y
*	recurso necessario
*
*	@param listaAlvo
*		lista que sera impressa 
*
*	@return listaAlvo != null ? 1:0;
*		 
**/
int imprimeListaCidade(Cidade *listaAlvo);


/**
*	Funcao: liberaListaCidade
*
*	Desaloca a memoria reservada para 
* toda celula pertecente a lista de cidades
*
*	@param listaAlvo
*		lista a ser desalocada
**/
void liberaListaCidade(Cidade *listaAlvo);