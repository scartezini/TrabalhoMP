#include "Interconexoes.h"

/** -----------------------Funcoes Gerais---------------------------- */

/**
*	Funcao: conecta
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
void conecta(Cidade *, Gerador *, Interconexao *, Adaptador *);

/**
*	Funcao: verifica
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
void verifica(Cidade *, Gerador *, Interconexao *, Adaptador *);