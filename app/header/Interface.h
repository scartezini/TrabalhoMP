#include "Geral.h"

/**
*	Funcao: inicializa
*
* Inicializa o ncurse e o mapa inicial da simulacao
* pocicionando as cidades, interconexoes, adaptadores
* e geradores em seus devidos locais
*
*	@param cidade
*		lista de cidades
*	@param gerador
*		lista de geradores
*	@param interconexao
*		lista de interconexoes
*	@param adaptador
*		lista de adaptadores
**/
void inicializa(Gerador *,Interconexao *,Adaptador *,Cidade *);

/**
*	Funcao: atualizaInterconexoes (Iterador)
*
* Desenha e atualiza a condicao das interconexoes
*
*	@param interconexao
*		lista de interconexoes
*
*	Assertiva de entrada:
*		estrutura do tipo Interconexao
**/
void atualizaInterconexoes(Interconexao *);

/**
*	Funcao: atualizaCidades (Iterador)
*
* Desenha e atualiza a condicao das cidades
*
*	@param cidade
*		lista de cidades
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
**/
void atualizaCidades(Cidade *);

/**
*	Funcao: atualizaGeradores (Iterador)
*
* Desenha e atualiza a condicao dos geradors
*
*	@param gerador
*		lista de geradores
*
*	Assertiva de entrada:
*		estrutura do tipo Gerador
**/
void atualizaGeradores(Gerador *);

/**
*	Funcao: atualizaAdaptadores (Iterador)
*
* Desenha e atualiza a condicao dos adaptadores
*
*	@param adaptador
*		lista de adaptadores
*
*	Assertiva de entrada:
*		estrutura do tipo Adaptador
**/
void atualizaAdaptadores(Adaptador *);

/**
*	Funcao: desenhaInterconexao (Iterador)
*
* Desenha um elemento da lista de interconexoes na interface
*
*	@param interconexao
*		lista de interconexoes
*
*	Assertiva de entrada:
*		estrutura do tipo Interconexao
**/
void desenhaInterconexao(Interconexao *);

/**
*	Funcao: desenhaCidade (Iterador)
*
* Desenha um elemento da lista de cidades na interface
*
*	@param cidade
*		lista de cidades
*
*	Assertiva de entrada:
*		estrutura do tipo Cidade
**/
void desenhaCidade(Cidade *);

/**
*	Funcao: desenhaGerador (Iterador)
*
* Desenha um elemento da lista de geradores na interface
*
*	@param gerador
*		lista de geradores
*
*	Assertiva de entrada:
*		estrutura do tipo Gerador
**/
void desenhaGerador(Gerador *);

/**
*	Funcao: desenhaAdaptador (Iterador)
*
* Desenha um elemento da lista de adaptadores na interface
*
*	@param adaptador
*		lista de adaptadores
*
*	Assertiva de entrada:
*		estrutura do tipo Adaptador
**/
void desenhaAdaptador(Adaptador *);
