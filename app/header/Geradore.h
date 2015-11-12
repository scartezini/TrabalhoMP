#import "Interconexoes.h"

typedef struct gerador{
	char *nome;
	int posicao[2];
	int taxaProducao; 
	int recursoProduzido; // Total de rocurso produzido por aquele gerador
	int custo; //Custo por segundo
	Gerador *proximo;
	
	Interconexao *interconexao;
	
}Gerador;



/**
*	Calcula a soma do total de recursos produzido
*	pelas celualas.	
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
int custoGeradores(Gerador *gerador);