#include "Geral.h"



/**
* Icializa o ncurse e o mapa inicial da simulacao
* pocicionando as cidades, interconexoes, adaptadores
* e geradores em seus devidos locais
*
* @param listaGeradores
* @param listaInterconexoes
* @param listaAdaptadores
* @param listaCidades
*
**/
void inicializa(Gerador*,Interconexao*,Adaptador*,Cidade*);

void atualizaInterconexoes(Interconexao*);
void atualizaCidades(Cidade*);
void atualizaGeradores(Gerador* );
void atualizaAdaptadores(Adaptador* );


void desenhaCidade(Cidade*);
void desenhaInterconexao(Interconexao*);
void desenhaGerador(Gerador*);
void desenhaAdaptador(Adaptador*);
