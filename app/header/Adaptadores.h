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
*
*	peso:
*		vetor que guarda a porcentagem que cada conexao vai receber
**/

typedef struct adaptador{
	char *nome;
	int posicao[2];
	Interconexao **interconexao;
	
	Adaptador *proximo;
	float *peso;
	
}Adaptador;


/**
*	Define como sera a distribuicao entre as conexoes 
* que esta ligada a cada adaptador e guarda a porcentagem
* a ser distribuida no vetor do peso
*
*	interconexao->capacidadeMax /
*	soma de todas as capacidadeMax
*  
* @param adapatador
* 		ponteiro para o inico da lista de adaptadores
*
**/
void defineDistribuicao(Adaptador *adapatador);