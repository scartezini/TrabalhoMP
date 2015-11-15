#include "Interconexoes.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
 
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
*	//peso:
*		//vetor que guarda a porcentagem que cada conexao vai receber
*
* 	proximo:
* 		representa a proxima Adaptador da lista de Adaptadores
**/

typedef struct adaptador{
	char *nome;
	int posicao[2];
	int recursoRecebido;

	Interconexao **saidas;
	int quantidadeSaidas;
	
	Adaptador *proximo;
	
}Adaptador;

/**
*	Enumeracao para detectar se a lista esta vazia ou nao 
*
**/
enum Vazio{VAZIO, NAO_VAZIO};

/**
*	Funcao: criaListaAdaptador
*
*	Inicia um ponteiro que sera para Adaptador
*
*	AssertivaSaida:
*		NULL; 
**/
Adaptador* criaListaAdaptador();

/**
*	Funcao: adaptadorVazio
*
*	Verifica se a lista de adaptadores esta vazia	
*
*	@param cidade
*		ponteiro para o inicio da lista de adaptadores
*
*	@return 
*		variavel do tipo Vazio, indicando se a lista esta vazia
*
*	Assertiva de entrada:
*		estrutura do tipo Adaptador
*
*	Assertiva de saida:
*		condicao do Adaptador sendo vazio ou nao vazio
*
**/
Vazio adaptadorVazio(Adaptador *adaptador);

/**
*	Insere uma nova celula de adaptador na lista
* dos adaptadores
*
*	@param registro 
*		String que sera decodificada e inserida
*	@param	listaAlvo 
*		lista a qual essa nova celula sera inserida
*
*	@return Adaptador
*		novo ponteiro de referencia para o inico da lista
*
*	Assertiva de entrada:
*
*		
*	Assertiva de saida:
*
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo);

/**
*	Funcao: imprimeListaAdaptador
*
*	Imprime de todas as celulas de lista de adaptador
* as respectivas caracteristicas:
*	nome
*	posicao x
*	posicao y
*	recurso recebido
*	quantidade de saidas
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
*		Se a lista de adaptadores a ser imprimida nao eh vazia
*		Entao
*			ela eh imprimida
*		Senao
*			a lista de adaptadores nao eh imprimida
*		FimSe
**/
void imprimeListaAdaptador(Adaptador *listaAlvo);

/**
*
*	Libera o espaco de memoria alocado para a lista de
* adaptadores
*
*	@param listaAlvo 
*		lista a qual sera desalocada
*
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		A lista deve estar vazia
**/
void liberaListaAdaptador(Adaptador *listaAlvo);

/** 
*	
*	Define como sera a distribuicao entre as conexoes 
* que esta ligada a cada adaptador e manda a quantidade que 
* sera passada para as correspondentes conexoes 
*	
*	interconexao->recursoTransportado = 
*		interconexao->capacidadeMax * adaptador->recursoRecebido /
*		soma de todas as capacidadeMax
*  
*	Essa funcao espera que a lista de interconexoes ja foi previamente 
* estabelecida 
*	//TODO retirar essa dependencia
*
* @param adaptador
* 		ponteiro para o inico da lista de adaptadores;
**/
void defineDistribuicao(Adaptador *adaptador);
