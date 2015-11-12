#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cidade{
	char *nome;
	int posicao[2];
	int recursoNecessario;
	int recursoGasto;
	
	Cidade *proximo;
	
}Cidade;


/**
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
*	Inicia um ponteiro que sera para Cidade
*
*	@return null
*
**/
Cidade* criaListaCidade()


/**
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
*	Imprime detodas as celulas de lista de cidade
* as respequitivas caracteristica:
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
*	Desaloca a memoria reservada para 
* toda celula pertecente a lista de cidades
*
*	@param listaAlvo
*		lista a ser desalocada
**/
void liberaListaCidade(Cidade *listaAlvo);