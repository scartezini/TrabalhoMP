#include "Interconexoes.h"

/**
* 	Cabecalho do elemento Gerador
 	
*	nome:
* 		nome do gerador
*
* 	posicao:
* 		vetor posicao, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	taxaProducao:
* 		quantidade de recurso que a cidade precisa por segundo
*
* 	recursoProducao:
*		quantidade total de recurso produzido pelo gerador
*
*	custo:
*		custo de geração por segundo
*
* 	proximo:
* 		representa a proxima cidade da rede de cidades
*
*	interconexao:
*		representa as interconexoes realizadas/apontadas pelos adaptadores
*
**/

typedef struct gerador{
	char *nome;
	int posicao[2];
	int taxaProducao; 
	int recursoProduzido; 
	int custo; 
	Gerador *proximo;
	Interconexao *interconexao;
	
}Gerador;



/**
*	Calcula a soma do total de recursos produzido
	pelas celualas.	
*
*	@param gerador
*			Inicio da lista de geradores;
*
*	@return 
*		soma de todo o recurso produzido pelos geradores
*
**/
int recursoProduzidoTotal(Gerador *gerador);


/**
*	Calcula a soma de custo por segundo de todos
* os geradores da lista 
*
*	@param gerador 
*		ponteiro para o inicio da lista de geradores
*	
*	@return 
*		Soma do custo por segundo de todos os geradores
**/
int custoGeradores(Gerador *gerador)