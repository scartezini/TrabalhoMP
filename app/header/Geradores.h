#include "Interconexoes.h"

/**
* 	Cabecalho do elemento Gerador
 	
*	nome:
* 		nome do gerador
*
* 	posicao:
* 		vetor posicao, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adaptador na interface
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
*	Enumeracao para detectar se a lista esta vazia ou nao 
*
**/
enum Vazio{VAZIO, NAO_VAZIO};

/**
*	Funcao: criaListaGerador
*
*	Inicia um ponteiro que sera para Gerador
*
*	@return null
*
*	Assertiva de saida:
*		estrutura do tipo Gerador nula
*
**/
Cidade* criaListaCidade();

/**
*	Funcao: geradorVazio
*
*	Verifica se a lista de geradores esta vazia	
*
*	@param cidade
*		ponteiro para o inicio da lista de geradores
*
*	@return 
*		variavel do tipo Vazio, indicando se a lista esta vazia
*
*	Assertiva de entrada:
*		estrutura do tipo Gerador
*
*	Assertiva de saida:
*		condicao do Gerador sendo vazio ou nao vazio
*
**/
Vazio geradorVazio(Gerador *gerador);

/**
*	Funcao: recursoProduzidoTotal
*
*	Calcula a soma do total de recursos produzido
* pelas celualas.	
*
*	@param gerador
*		inicio da lista de geradores;
*
*	@return 
*		soma de todo o recurso produzido pelos geradores
*
**/
int recursoProduzidoTotal(Gerador *gerador);


/**
*	Funcao: custoGeradores
*
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


/**
*	Funcao: mandarRecursoProduzido
*	
*	Altera os nos de conexão do grafo com o recurso
* enviado
*
*	@param gerador 
*		ponteiro para o inicio da lista de geradores
*
*
**/
void mandarRecursoProduzido(Gerador *gerador);