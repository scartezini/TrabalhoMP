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
* Atualiza a condicao das interconexoes
*
*	@param interconexao
*		lista de interconexoes
**/
void atualizaInterconexoes(Interconexao *);

/**
*	Funcao: atualizaCidades (Iterador)
*
* Atualiza a condicao das cidades
*
*	@param cidade
*		lista de cidades
**/
void atualizaCidades(Cidade *);

/**
*	Funcao: atualizaGeradores (Iterador)
*
* Atualiza a condicao dos geradors
*
*	@param gerador
*		lista de geradores
**/
void atualizaGeradores(Gerador *);

/**
*	Funcao: atualizaAdaptadores (Iterador)
*
* Atualiza a condicao dos adaptadores
*
*	@param adaptador
*		lista de adaptadores
**/
void atualizaAdaptadores(Adaptador *);

/**
*	Funcao: desenhaInterconexao (Iterador)
*
* Desenha a lista de interconexoes na interface
*
*	@param interconexao
*		lista de interconexoes
**/
void desenhaInterconexao(Interconexao *);

/**
*	Funcao: desenhaCidade (Iterador)
*
* Desenha a lista de cidades na interface
*
*	@param cidade
*		lista de cidades
**/
void desenhaCidade(Cidade *);

/**
*	Funcao: desenhaGerador (Iterador)
*
* Desenha a lista de geradores na interface
*
*	@param gerador
*		lista de geradores
**/
void desenhaGerador(Gerador *);

/**
*	Funcao: desenhaAdaptador (Iterador)
*
* Desenha a lista de adaptadores na interface
*
*	@param adaptador
*		lista de adaptadores
**/
void desenhaAdaptador(Adaptador *);
