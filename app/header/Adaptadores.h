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
	Interconexao **saidas;
	
	Adaptador *proximo;
	float *peso;
	
}Adaptador;


/**
*	Retorna o tipo adaptador
*
*	@return null
*
**/
Adaptador* criaListaAdaptador();

/**
*	Inseri uma nova celula de adaptador na lista
* dos adaptadores
*
*	@param registro 
*		Registro/celula a ser inserida
*	@param	listaAlvo 
*		lista a qual essa nova celula sera inserida
*
*	@return Adaptador
*		novo ponteiro de referencia para o inico da lista
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo)

/**
*
*	Libera o espaco de memoria alocado para a lista de
* adaptadores
*
*	@param listaAlvo 
*		lista a qual sera desalocada
*
**/
void liberaListaAdaptador(Adaptador *listaAlvo);

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
