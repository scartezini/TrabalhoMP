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
* 	representando tambem a posicao do adaptador na interface
*
* 	recursoNecessario:
* 		quantidade de recurso que a cidade precisa por segundo
*
* 	recursoGasto:
*		quantidade de recurso que a cidade usou
*
* 	proximo:
* 		representa a proxima cidade da rede de cidades
*
*	recursoRecebido:
*		quanto de recurso que a cidade recebeu naquele turno
*
**/

typedef struct cidade{
	char *nome;
	int posicao[2];

	int recursoNecessario;
	int recursoRecebido;
	int recursoGasto;

	Cidade *proximo;
	
}Cidade;

/**
*	Enumeracao para detectar se a lista esta vazia ou nao 
*
**/
enum Vazia{vazia, naoVazia};

/**
*	Funcao: criaListaCidade
*
*	Inicia um ponteiro que sera para Cidade
*
*	@return null
*
*	Assertiva de saida:
*		estrutura do tipo Cidade nula
*
**/
Cidade* criaListaCidade();

/**
*	Funcao: cidadeVazia
*
*	Verifica se a lista de cidades esta vazia	
*
*	@param cidade
*		ponteiro para o inicio da lista de cidades
*
*	@return 
*		variavel do tipo Vazia, indicando se a lista esta vazia
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
*
*	Assertiva de saida:
*		condicao da Cidade sendo vazia ou nao vazia
*
**/
Vazia cidadeVazia(Cidade *cidade);

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
*
*	Assertiva de entrada:
*		
*
*	Assertiva de saida:
*
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
*	@return listaAlvo
*		variavel do tipo Vazia, indicando se a lista esta vazia
*		 
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		Se a lista de cidades a ser imprimida nao eh vazia
*		Entao
*			ela eh imprimida
*		Senao
*			a lista de cidades nao eh imprimida
*		FimSe
**/
Vazia imprimeListaCidade(Cidade *listaAlvo);

/**
*	Funcao: liberaListaCidade
*
*	Desaloca a memoria reservada para 
* toda celula pertecente a lista de cidades
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
void liberaListaCidade(Cidade *listaAlvo);

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
*
*	Assertiva de entrada:
*
*	Assertiva de saida:
*
**/
int recursoGastoTotal(Cidade *cidade);