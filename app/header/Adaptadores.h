#include "Interconexoes.h"
 
/**
* 	Cabecalho do elemento Adaptador
* 	
*	nome:
* 		nome do adaptador
*
* 	posicao:
* 		vetor posicao, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	interconexao:
* 		representa as interconexoes realizadas/apontadas pelos adaptadores
**/

typedef struct adaptador{
	char *nome;
	int posicao[2];
	Interconexao *interconexao;
	
}Adaptador;