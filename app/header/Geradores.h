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
* 	recursoProduzido:
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

/** -----------------------Funcoes Basicas---------------------------- */

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
Cidade* criaListaGerador();

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
*	Funcao: insereGerador
*
*	Inserir uma nova celula na lista de geradores
* a insercao se da pelo inicio da lista e é retornadado
* o novo ponterio para lista.
*
*	@param registro
*		string que sera lida do arquivo representando Gerador
*	@param listaAlvo 
*		lista de cidade a qual a nova celula sera inserida
*
*	@return
*		novo pontero para a o inicio da lista de geradores
*
*	Assertiva de entrada:
*		registro - eh um vetor contendo o conteudo do txt, deve ser diferente de NULL
*
*	Assertiva de saida:
*		A lista recebida pela funcao, deve ser o proximo gerador apontado pela lista retornada
**/
Gerador* insereGerador(char *registro, Gerador *listaAlvo);

/**
*	Funcao: imprimeListaGerador
*
*	Imprime de todas as celulas de lista de gerador
* as respectivas caracteristicas:
*	nome
*	posicao x
*	posicao y
*	taxa de producao
*	recurso produzido
*	custo
*
*	@param listaAlvo
*		lista que sera impressa 
*
*	@return listaAlvo
*		variavel do tipo Vazio, indicando se a lista esta vazia
*		 
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		Se a lista de geradores a ser imprimida nao eh vazia
*		Entao
*			ela eh imprimida
*		Senao
*			a lista de geradores nao eh imprimida
*		FimSe
**/
void imprimeListaGerador(Gerador *listaAlvo);

/**
*	Funcao: liberaListaGerador
*
*	Desaloca a memoria reservada para 
* toda celula pertecente a lista de geradores
*
*	@param listaAlvo
*		lista a ser desalocada
*
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		A lista deve estar vazia
**/
void liberaListaGerador(Gerador *listaAlvo);

/** -----------------------Funcoes de Calculo---------------------------- */

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