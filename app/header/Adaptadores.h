#include "Principal.h"

/**
*	Funcao: criaListaAdaptador
*
*	Inicia um ponteiro que sera para Adaptador
*
*	@return
*		lista do tipo Adaptador vazia
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
*	@param listaAlvo
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
Vazio adaptadorVazio(Adaptador *);

/**
*	Insere uma nova celula de adaptador na lista
* dos adaptadores
*
*	@param registro
*		String que sera decodificada e inserida
*	@param listaAlvo
*		lista a qual essa nova celula sera inserida
*
*	@return Adaptador
*		novo ponteiro de referencia para o inico da lista
*
*	Assertiva de entrada:
*		registro - eh um vetor contendo o conteudo do txt, deve ser diferente de NULL
*
*	Assertiva de saida:
*		A lista recebida pela funcao, deve ser o proximo adaptador apontado pela lista retornada
**/
Adaptador* insereAdaptador(char *, Adaptador *);

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
*	Assertiva de entrada:
*		A lista nao deve ser vazia
*
*	Assertiva de saida:
*		Se a lista de adaptadores a ser imprimida nao eh vazia
*		Entao
*			ela eh imprimida
*		Senao
*			a lista de adaptadores nao eh imprimida
*		FimSe
**/
void imprimeListaAdaptador(Adaptador *);

/**
*
*	Libera o espaco de memoria alocado para a lista de
* adaptadores
*
*	@param listaAlvo
*		lista a qual sera desalocada
*
*	Assertiva de entrada:
*		A lista nao deve ser vazia
*
*	Assertiva de saida:
*		A lista deve estar vazia
**/
void liberaListaAdaptador(Adaptador *);

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
*
*	@param listaAlvo
*		ponteiro para o inico da lista de adaptadores;
*
*	Assertiva de entrada:
*		A lista nao deve ser vazia
*		A lista de saidas nao deve ser vazia
**/
void defineDistribuicao(Adaptador *);

/**
*
* Faz o recurso chegar ate as cidades ou adaptadores de destino,
* faz isso para toda lista de adaptadores
*
*	Essa funcao espera que a lista de interconexoes ja foi previamente
* estabelecida e que a definicao de como sera a distribuicao ja esteja
* previamente definida
*
*	@param listaAlvo
*		ponteiro para o inico da lista de adaptadores;
**/
void mandarRecursoAdaptado(Adaptador *);


void zerarAdaptadores(Adaptador *);
