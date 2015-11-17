#include "Adaptadores.h"

/** -----------------------Funcoes Basicas---------------------------- */

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
<<<<<<< HEAD

typedef struct cidade{
	char *nome;
	int posicao[2];
	int recursoNecessario;
	int recursoGasto;
	Cidade *proximo;
	
}Cidade;

/**
*	Enumeracao para detectar se a lista esta vazia ou nao 
*
**/
enum Vazia{vazia, naoVazia};
=======
Cidade* criaListaCidade();
>>>>>>> origin/lucas

/**
*	Funcao: cidadeVazia
*
*	Verifica se a lista de cidades esta vazia	
*
*	@param cidade
*		ponteiro para o inicio da lista de cidades
*
*	@return 
<<<<<<< HEAD
*		total de recursos gasto pelas cidades
*
*	Assertiva de entrada:
*
*	Assertiva de saida:
*
**/
int recursoGastoTotal(Cidade *cidade);

/**
*	Funcao: criaListaCidade
=======
*		variavel do tipo Vazia, indicando se a lista esta vazia
>>>>>>> origin/lucas
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
*
*	Assertiva de saida:
*		condicao da Cidade sendo vazia ou nao vazia
*
*	Assertiva de saida:
*		estrutura do tipo Cidade nula
*
**/
Cidade* criaListaCidade();

/**
*	Funcao: criaVazia
*
*	Verifica se a lista de cidades esta vazia	
*
*	@param cidade
*		ponteiro para o inicio da lista de cidades
*
*	@return 
*		variavel do tipo Vazia, indicando se a lista esta vazia
*
*	Assertiva de saida:
*		estrutura do tipo Cidade nula
*
**/
<<<<<<< HEAD
Vazia cidadeVazia(Cidade *cidade);
=======
Vazia cidadeVazia(Cidade *);
>>>>>>> origin/lucas

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
*		lista de cidades onde a nova celula sera inserida
*
*	@return
<<<<<<< HEAD
*		novo pontero para a o inicio da lista de cidade
*
*	Assertiva de entrada:
*		
*	Assertiva de saida:
*
=======
*		novo pontero para a o inicio da lista de cidades
*
*	Assertiva de entrada:
*		registro - eh um vetor contendo o conteudo do txt, deve ser diferente de NULL
*
*	Assertiva de saida:
*		A lista recebida pela funcao, deve ser a proxima cidade apontada pela lista retornada
>>>>>>> origin/lucas
**/
Cidade* insereCidade(char *, Cidade *);

/**
*	Funcao: imprimeListaCidade
*
*	Imprime de todas as celulas de lista de cidade
* as respectivas caracteristicas:
*	nome
*	posicao x
*	posicao y
*	recurso necessario
*	recurso recebido
*	recurso gasto
*
*	@param listaAlvo
*		lista que sera impressa 
*
*	@return listaAlvo
*		variavel do tipo Vazia, indicando se a lista esta vazia
*		 
<<<<<<< HEAD
*	AssertivaSaida:
=======
*	AssertivaEntrada:
>>>>>>> origin/lucas
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
<<<<<<< HEAD
Vazia imprimeListaCidade(Cidade *listaAlvo);

=======
void imprimeListaCidade(Cidade *);
>>>>>>> origin/lucas

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
void liberaListaCidade(Cidade *);

/** -----------------------Funcoes de Calculo---------------------------- */

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
int recursoGastoTotal(Cidade *);
