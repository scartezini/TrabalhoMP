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
* 	representando tambem a posicao do adaptador na interface
*
* 	posicaoFinal:
* 		vetor posicaoFinal, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adaptador na interface
*
*	tagDestino:
*		tag para indentificar qual é a ligaçao final de cada conexao, 
*		seja cidade ou adaptador
*
* 	chanceFalha:
* 		chance de falha por segundo
*
* 	tempoConcerto:
*		tempo de concerto em caso de falha em segundos
*
*	custoConcerto:
*		custo do concerto em segundos
*
* 	numeroFalha:
* 		total de falhas
*
* 	tagFalha:
* 		indica se houve falha
*
*	capacidadeMaxima:
*		capacidade maxima da interconexao
*
*	recursoTranstortado:
*		quantidade de recuso que esta sendo transportado pela conexao no turno
*
*	proximo:
*		representa as interconexoes realizadas/apontadas pelos adaptadores
*
* 	adaptador:
*		adaptador utilizado/apontado pela interconexao
*
*	cidade:
*		cidade de destino
**/

typedef struct interconexao{
	char *nome;
	int posicaoInical[2];
	int posicaoFinal[2];
	int tagDestino; 

	float chanceFalha;
	int tempoConserto;
	int custoConserto;
	
	int numeroFalha;
	int tagFalha; 

	int capacidadeMaxima;
	int recursoTransportado;
	
	Interconexao *proximo;
	Adaptador *adaptador;
	Cidade *cidade;
	
}Interconexao;

/**
*	Enumeracao para detectar uma falha
*
**/
enum Falha{FALHA, SEM_FALHA};

/**
*	Enumeracao para detectar qual eh o ponto 
* final de ligacao da conexao 
**/
enum Destino{ADAPTADOR, CIDADE}

/**
*	Funcao: criaListaInterconexao
*
*	Inicia um ponteiro que sera para Interconexao
*
*	AssertivaSaida:
*		NULL; 
**/
Interconexao* criaListaInterconexao();

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
*		interconexao - eh uma lista de interconexoes nao vazia
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
*		interconexao - eh uma lista de interconexoes nao vazia
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


/**
*
*	Funcao: mandarRecursoTransportado
*
*	Muda cada referencia seja para adaptador ou 
* para cidade, dependenodo do em qual esta ligada,
* alterando o valor do recurso atual. 
*
*	@param interconexao
*		ponterio de referencia para o inicio da lista
*		de interconexoes 
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		Se o destino da interconexao for um adaptador
*		Entao
*			soma-se o recurso transportado ao Adaptador da lista de interconexoes
*		Senao
*			soma-se o recurso transportado ao Adaptador da lista de interconexoes
*		FimSe
**/
void mandarRecursoTransportado(Interconexao *interconexao);