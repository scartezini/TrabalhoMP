#include "Adaptadores.h"
#include "Cidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
* 	Cabecalho do elemento Gerador
* 	
*	nome:
* 		nome do gerador
*
* 	posicaoInicial:
* 		vetor posicaoInicial, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	posicaoInicial:
* 		vetor posicaoInicial, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adapatador na interface
*
* 	chanceFalha:
* 		chance de falha por segundo
*
* 	tempoConcerto:
*		tempo de concerto em caso de falha em segundos
*
*	capacidadeMaxima:
*		capacidade maxima da conexao
*
*	custoConcerto:
*		custo do concerto em segundos
*
* 	numeroFalha:
* 		total de falhas
*
*	tagFalha:
*		marcador para definir se houve falha ou nao
*
*	recurstoTransportado:
*		quantidade de recurso que esta sendo transportado
*
*	proximo:
*		representa as interconexoes realizadas/apontadas pelos adaptadores
*
* 	adaptador:
*		adaptador utilizado/apontado pela interconexao
*
*	cidade:
*		cidade de destino
*
**/

typedef struct interconexao{
	char *nome;
	int posicaoInical[2];
	int posicaoFinal[2];
	float chanceFalha;
	int tempoConserto;
	int capacidadeMaxima;
	int custoConserto;
	int numeroFalha;
	int tagFalha;
	int recursoTransportado;
	
	Interconexao *proximo;
	Adaptador *adaptador;
	Cidade *cidade;
	
}Interconexao;

/**
*	Enumeracao para detectar uma falha 
*
**/
enum Falha{falha, semFalha};

/**
*	Funcao: tamanhoConexao
*
*	Calcula o tamanho da celula de conexao que
* eh passada para a funcao
*
*	@param interconexao
*		ponteiro para a celula de interconexao
*
*	@return 
*		tamanho da celula de conexao que foi passada
*
*	Assertiva de entrada:
*		interconexao - eh a lista de interconexoes
*
*	Assertiva de saida:
*		tamanho de uma conexao
*
**/
float tamanhoConexao(Interconexao *interconexao);


/**
*	Funcao: tamanhoTotalConexao
*
*	Calcula o tamanho total das conexoes 
* da lista que eh passada
*
*	@param interconexao
*		ponteiro para o inicio da lista de celulas de conexao
*
*	@return
*		retorna o tamanho total das conexoes da lista
*
*	Assertiva de entrada:
*		interconexao - eh a lista de interconexoes
*
*	Assertiva de saida:
*		resultado da soma dos tamanhos de todas as conexoes
*
**/
float tamanhoTotalConexao(Interconexao *interconexao);


/**
*	Funcao: totalGastoConserto
*
*	Calcula o custo total gasto com conserto 
* de todas as celulas de conexao
*
*	@param interconexao
*		ponteiro para o inicio da lista de interconexao
*
*	@return
*		total gasto com conserto de todas as conexoes
*
**/
int totalGastoConserto(Interconexao *interconexao);

/**
*	Funcao: calculaFalha
*
*	Calcula a possibilidade de falha
*
*	@return
*		variavel do tipo Falha, indicando se houve falha
* 
*	Assertiva de saida:
*		Se a chance de falha for maior que 0 e maior que um numero aleatorio
*		Entao
*			ocorre um falha
*		Senao
*			nao ocorre uma falha
*		FimSe
*
**/
Falha calculaFalha();
