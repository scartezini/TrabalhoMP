#include "Cidades.h"

/**
*	Funcao: criaListaGerador
*
*	Inicia um ponteiro que sera para Gerador
*
*	@return
*   lista do tipo Gerador vazia
*
*	Assertiva de saida:
*		estrutura do tipo Gerador nula
*
**/
Gerador* criaListaGerador();

/**
*	Funcao: geradorVazio
*
*	Verifica se a lista de geradores esta vazia
*
*	@param listaAlvo
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
Vazio geradorVazio(Gerador *);

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
Gerador* insereGerador(char *, Gerador *);

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
void imprimeListaGerador(Gerador *);

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
void liberaListaGerador(Gerador *);


/**
*	Funcao: recursoProduzidoTotal
*
*	Calcula a soma do total de recursos produzido
* pelas celulas.
*
*	@param listaAlvo
*		inicio da lista de geradores;
*
*	@return
*		soma de todo o recurso produzido pelos geradores
*
*	Assertiva de saida:
*		energia total produzida por todos os geradores
**/
int recursoProduzidoTotal(Gerador *);


/**
*	Funcao: custoGeradores
*
*	Calcula a soma de custo por segundo de todos
* os geradores da lista
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de geradores
*
*	@return
*		Soma do custo por segundo de todos os geradores
*
*	Assertiva de entrada:
*		estrutura do tipo Gerador
*
*	Assertiva de saida:
*		custo total dos geradores
**/
int custoGeradores(Gerador *);


/**
*	Funcao: mandarRecursoProduzido
*
*	Altera os nos de conexão do grafo com o recurso
* enviado
* Altera os adaptadores com o recurso recebido
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de geradores
*
*	Assertiva de entrada:
*		estrutura do tipo Gerador, nao vazia
**/
void mandarRecursoProduzido(Gerador *);

/**
*	Funcao: numeroGeradores
*
*	Calcula o numero total de geradores na lista de geradores
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de geradores
*
*	@return
*		Numero total de geradores
*
**	Assertiva de entrada:
*		estrutura do tipo Gerador
*
*	Assertiva de saida:
*		numero total de geradores na lista de geradores
**/
int numeroGeradores(Gerador *);
