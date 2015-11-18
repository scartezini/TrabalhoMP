#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** -----------------------Enumeracoes---------------------------- */

/**
*	Enumeracao para detectar se a lista esta vazia ou nao
*
**/
typedef enum vazia{
	VAZIA, NAO_VAZIA

}Vazia;

/**
*	Enumeracao para detectar se a lista esta vazia ou nao
*
**/
typedef enum vazio{
	VAZIO, NAO_VAZIO

}Vazio;

/**
*	Enumeracao para detectar uma falha
*
**/
typedef enum falha{
	FALHA, SEM_FALHA

}Falha;

/**
*	Enumeracao para detectar qual eh o ponto
* final de ligacao da conexao
**/
typedef enum destino{
	ADAPTADOR, CIDADE

}Destino;

/** -----------------------Cidades---------------------------- */

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
*	recursoRecebido:
*		quantidade de recurso recebido por segundo pela Cidade
*
* 	recursoGasto:
*		quantidade de recurso que a cidade usou
*
* 	proximo:
* 		representa a proxima Cidade da rede de Cidades
**/

typedef struct cidade{
	char *nome;
	int posicao[2];

	int recursoNecessario;
	int recursoRecebido;
	int recursoGasto;

	struct cidade *proximo;
	interconexoes *entrada;

}Cidade;

/** -----------------------Adaptadores---------------------------- */

/**
* 	Cabecalho do elemento Adaptador
*
*	nome:
* 		nome do adaptador
*
* 	posicao:
* 		vetor posicao, representando x na posicao[0] e y na posicao[1], ambas em km,
* 	representando tambem a posicao do adaptador na interface
*
*	recursoRecebido:
*		quantidade de recurso recebido por segundo pelo Adaptador
*
* 	saidas:
* 		representa as interconexoes realizadas/apontadas pelos adaptadores
*
*	quantidadeSaidas:
*		quantidade de conexoes que o adaptador possui
*
*	peso:
*		vetor que guarda a porcentagem que cada conexao vai receber
*
* 	proximo:
* 		representa a proxima Adaptador da lista de Adaptadores
**/

typedef struct adaptador{
	char *nome;
	int posicao[2];
	int recursoRecebido;

	struct interconexao *saidas;
	struct interconexao *entradas;

	int quantidadeSaidas;

	struct adaptador *proximo;

}Adaptador;

/** -----------------------Interconexoes---------------------------- */

/**
* 	Cabecalho do elemento Inerconexao
*
*	nome:
* 		nome da interconexao
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
	int posicaoInicial[2];
	int posicaoFinal[2];
	Destino tagDestino;

	float chanceFalha;
	int tempoConserto;
	int custoConserto;

	int numeroFalha;
	Falha tagFalha;

	int capacidadeMaxima;
	int recursoTransportado;

	struct interconexao *proximo;
	Adaptador *entradaAdaptador;
	Gerador *entradaGerador;

	Adaptador *saidaAdaptador;
	Cidade *saidaCidade;

	Interconexao *poximoEntradaAdaptador;
	Interconexao *proximoSaidaAdaptador;

}Interconexao;


/** -----------------------Geradores---------------------------- */

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

	struct gerador *proximo;
	Interconexao *saida;

}Gerador;
