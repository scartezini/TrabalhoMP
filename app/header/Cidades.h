#include "Adaptadores.h"

/**
*	Funcao: criaListaCidade
*
*	Inicia um ponteiro que sera para Cidade
*
*	@return
*   lista do tipo Cidade vazia
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
*	@param listaAlvo
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
Vazia cidadeVazia(Cidade *);

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
*		novo pontero para a o inicio da lista de cidades
*
*	Assertiva de entrada:
*		registro - eh um vetor contendo o conteudo do txt, deve ser diferente de NULL
*
*	Assertiva de saida:
*		A lista recebida pela funcao, deve ser a proxima cidade apontada pela lista retornada
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
void imprimeListaCidade(Cidade *);

/**
*	Funcao: liberaListaCidade
*
*	Desaloca a memoria reservada para
* toda celula pertecente a lista de cidades
*
*	@param listaAlvo
*		lista a ser desalocada
*
*	Assertiva de entrada:
*		A lista nao deve ser vazia
*
*	Assertiva de saida:
*		A lista deve estar vazia
**/
void liberaListaCidade(Cidade *);

/**
*	Funcao: recursoGastoTotal
*
*	Resultado da soma de todos recursos
* gasto pelas cidades
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*		total de recursos gasto pelas cidades
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
*
*	Assertiva de saida:
*
**/
int recursoGastoTotal(Cidade *);

/**
*	Funcao: numeroCidades
*
*	Calcula o numero total de cidades na lista de cidades
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*		Numero total de cidades
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
*
*	Assertiva de saida:
*		numero total de cidades na lista de cidades
**/
int numeroCidades(Cidade *);

/**
*	Funcao: gerenciaRecursoRecebido
*
*	Altera os atributos das celulas de cidade de acordo com o recurso
* que foi recebido
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade, nao vazia
*
**/
void gerenciaRecursoRecebido(Cidade *);

/**
*	Funcao: numeroCidadesNegativadas
*
*	Resultado da contagem de quantas cidades ficaram
* sem recurso necessario
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*		total de cidades que ficaram com menos recurso que o necessario
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade, nao vazia
*
*	Assertiva de saida:
*		numero total de cidades negativadas na lista de cidades
**/
int numeroCidadesNegativadas(Cidade *);


/**
*	Funcao: tempoSemRecursoNecessario
*
*	Resultado da soma do tempo de turnos que as Cidades
* ficaram sem recurso necessario
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*		total da soma dos tempos que as cidades ficaram sem recurso necessario
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade, nao vazia
*
*	Assertiva de saida:
*		numero total de cidades turnos negativos na lista de cidades
**/
int tempoSemRecursoNecessario(Cidade *);


/**
*	Funcao: numeroCidadesNoVermelho
*
*	Resultado da contagem de quantas cidades receberam menos de
* 30% do recurso necessario
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*		total de cidades que receberam menos de 30% do recurso necessario
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade, nao vazia
*
*	Assertiva de saida:
*		numero total de cidades no vermelho na lista de cidades
**/
int numeroCidadesNoVermelho(Cidade *);


/**
*	Funcao: tempoCidadesNoVermelho
*
*	Resultado da soma do tempo que as cidades passaram com menos de
* 30% do recurso necessario
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de cidades
*
*	@return
*			total da soma dos tempos que as cidades ficaram com menos
*     de 30% do recurso necessario
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade, nao vazia
*
*	Assertiva de saida:
*		tempo total de cidades no vermelho na lista de cidades
**/
int tempoCidadesNoVermelho(Cidade *);


void zerarCidades(Cidade *);
