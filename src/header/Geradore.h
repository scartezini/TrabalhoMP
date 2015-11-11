#import "Interconexoes.h"

typedef struct gerador{
	char *nome;
	int posicao[2];
	int taxaProducao; 
	int recursoProduzido; // Total de rocurso produzido por aquele gerador
	int custo;
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