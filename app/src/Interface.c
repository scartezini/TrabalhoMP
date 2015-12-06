#include "../header/Interface.h"

#define DESLOCAMENTO_VERTICAL 4 //!< Definindo o deslocamento vertical padrao
#define DESLOCAMENTO_HORIZONTAL 2 //!< Definindo o deslocamento horizontal padrao

int deslocamento; //!< Variavel global que representa o deslocamento

/**
*	Funcao: inicializa
*
*	Hipóteses:
*		listaGeradores - ponteiro para uma lista do tipo Gerador
*		listaInterconexoes - ponteiro para uma lista do tipo Interconexao
*		listaAdaptadores - ponteiro para uma lista do tipo Adaptador
*		listaCidades - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*	  realizar a inicializacao da interface
*
*	Interfaces explicitas:
*		void, inicializa, Gerador* listaGeradores ,Interconexao* listaInterconexoes,Adaptador* listaAdaptadores ,Cidade* listaCidades
*
*	Interfaces implicitas:
*		listaGeradores - lista de geradores
*		listaInterconexoes - lista de interconexoes
*		listaAdaptadores - lista de adaptadores
*		listaCidades - lista de cidades
**/
void inicializa(Gerador* listaGeradores ,Interconexao* listaInterconexoes,Adaptador* listaAdaptadores ,Cidade* listaCidades){

  Gerador *gerador;
  Interconexao *interconexao;
  Adaptador *adaptador;
  Cidade *cidade;

  //! Assertiva estrutural: limpeza da tela
  system("clear");

  //! Assertiva estrutural: inicializacao da ncurses
  initscr();

  //! Assertiva estrutural: verifica se o terminal suporta cores
  if(has_colors() == FALSE){
    endwin();
		printf("Seu terminal nao suporta cores\n");
		exit(1);
	}

  //! Comentarios de argumentacao
		/**
		*	Desenham-se as listas de cada tipo na interface
		**/
  for(gerador = listaGeradores; gerador != NULL ; gerador = gerador->proximo){
    desenhaGerador(gerador);
  }
  for(adaptador = listaAdaptadores; adaptador != NULL ; adaptador = adaptador->proximo){
    desenhaAdaptador(adaptador);
  }
  for(cidade = listaCidades; cidade != NULL ; cidade = cidade->proximo){
    desenhaCidade(cidade);
  }
  for(interconexao = listaInterconexoes; interconexao != NULL ; interconexao = interconexao->proximo){
    desenhaInterconexao(interconexao);
  }

  refresh();
}

/**
*	Funcao: atualizaInterconexoes
*
*	Hipóteses:
*		listaInterconexoes - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		atualizacao do desenho da lista de interconexoes na interface
*
*	Interfaces explicitas:
*		void, atualizaInterconexoes, Interconexao* listaInterconexoes
*
*	Interfaces implicitas:
*		listaInterconexoes - lista de interconexoes
**/
void atualizaInterconexoes(Interconexao* listaInterconexoes){
  Interconexao* conexao;

  //! Asseriva estrutural: conexao é a listaInterconexoes, porem sendo percorrida
  for(conexao = listaInterconexoes; conexao != NULL ; conexao = conexao->proximo, deslocamento+=6){

    //! Assertiva estrutural: definindo as cores de acordo com a condicao da interconexao
    attron(COLOR_PAIR(conexao->tagFalha + 4));

    //! Comentarios de argumentacao
      /**
      * Imprime as caracteristicas da conexao corrente
      **/
    mvprintw(deslocamento,100,"%s:\n",conexao->nome);
    mvprintw(deslocamento+1,100,"\tcapacidade maxima: %d\n",conexao->capacidadeMaxima);
    mvprintw(deslocamento+2,100,"\trecurso transportado: %d\n",conexao->recursoTransportado);
    mvprintw(deslocamento+3,100,"\tchance de falha: %d\n",conexao->chanceFalha);
    mvprintw(deslocamento+4,100,"\tnumero de falhas: %d\n",conexao->numeroFalha);

    //! Assertiva estrutural: desenha a interconexao corrente
    desenhaInterconexao(conexao);
  }

  refresh();
}

/**
*	Funcao: atualizaCidades
*
*	Hipóteses:
*		listaCidades - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		atualizacao do desenho da lista de cidades na interface
*
*	Interfaces explicitas:
*		void, atualizaCidades, Cidade* listaCidades
*
*	Interfaces implicitas:
*		listaCidades - lista de cidades
**/
void atualizaCidades(Cidade* listaCidades){
  Cidade *cidade;

  //! Asseriva estrutural: conexao é a listaCidades, porem sendo percorrida
  for(cidade = listaCidades , deslocamento = 3; cidade != NULL ; cidade = cidade->proximo , deslocamento += 5){

    //! Assertiva estrutural: definindo as cores de acordo com a condicao da cidade
    attron(COLOR_PAIR(cidade->tagEstado + 1));

    //! Comentarios de argumentacao
      /**
      * Imprime as caracteristicas da cidade corrente
      **/
    mvprintw(deslocamento,100,"%s:\n",cidade->nome);
    mvprintw(deslocamento+1,100,"\trecurso necessario: %d\n",cidade->recursoNecessario);
    mvprintw(deslocamento+2,100,"\trecurso recebido: %d\n",cidade->recursoRecebido);
    mvprintw(deslocamento+3,100,"\trecurso gasto %d\n",cidade->recursoGasto);

    //! Assertiva estrutural: desenha a cidade corrente
    desenhaCidade(cidade);
  }

  refresh();
}

/**
*	Funcao: atualizaGeradores
*
*	Hipóteses:
*		listaGeradores - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		atualizacao do desenho da lista de geradores na interface
*
*	Interfaces explicitas:
*		void, atualizaGeradores, Gerador* listaGeradores
*
*	Interfaces implicitas:
*		listaGeradores - lista de geradores
**/
void atualizaGeradores(Gerador* listaGeradores){
  Gerador* gerador;

  //! Asseriva estrutural: conexao é a listaGeradores, porem sendo percorrida
  for(gerador = listaGeradores; gerador != NULL ; gerador = gerador->proximo, deslocamento+=4){

    //! Assertiva estrutural: definindo as cores
    attron(COLOR_PAIR(7));

    //! Comentarios de argumentacao
      /**
      * Imprime as caracteristicas do gerador corrente
      **/
    mvprintw(deslocamento,100,"%s:\n",gerador->nome);
    mvprintw(deslocamento+1,100,"\tcusto/segundo: %d\n",gerador->custo);
    mvprintw(deslocamento+2,100,"\trecurso produzido/segundo: %d\n",gerador->recursoProduzido);

    //! Assertiva estrutural: desenha o gerador corrente
    desenhaGerador(gerador);
  }

  refresh();
}

/**
*	Funcao: atualizaAdaptadores
*
*	Hipóteses:
*		listaAdaptadores - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		atualizacao do desenho da lista de adaptadores na interface
*
*	Interfaces explicitas:
*		void, atualizaAdaptadores, Adaptador* listaAdaptadores
*
*	Interfaces implicitas:
*		listaAdaptadores - lista de adaptadores
**/
void atualizaAdaptadores(Adaptador* listaAdaptadores){
  Adaptador* adaptador;

  //! Asseriva estrutural: conexao é a listaAdaptadores, porem sendo percorrida
  for(adaptador = listaAdaptadores; adaptador != NULL ; adaptador = adaptador->proximo, deslocamento+=3){

    //! Assertiva estrutural: definindo as cores
    attron(COLOR_PAIR(7));

    //! Comentarios de argumentacao
      /**
      * Imprime as caracteristicas do adaptador corrente
      **/
    mvprintw(deslocamento,100,"%s:\n",adaptador->nome);
    mvprintw(deslocamento+1,100,"\trecurso recebido: %d\n",adaptador->recursoRecebido);

    //! Assertiva estrutural: desenha o adaptador corrente
    desenhaAdaptador(adaptador);
  }

  refresh();
}

/**
*	Funcao: desenhaInterconexao
*
*	Hipóteses:
*		conexao - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		desenho de uma conexao da lista de interconexoes na interface
*
*	Interfaces explicitas:
*		void, desenhaInterconexao, Interconexao* conexao
*
*	Interfaces implicitas:
*		conexao - lista de interconexoes
**/
void desenhaInterconexao(Interconexao* conexao){

  //! Assertiva estrutural: define os deslocamentos para a conexao passar no meio do bloco 3x3
  int xIn = conexao->posicaoInicial[0] + DESLOCAMENTO_VERTICAL;
  int yIn = conexao->posicaoInicial[1] + DESLOCAMENTO_HORIZONTAL;

  int xOut = conexao->posicaoFinal[0] + DESLOCAMENTO_VERTICAL;
  int yOut = conexao->posicaoFinal[1] + DESLOCAMENTO_HORIZONTAL;

  //! Assertiva estrutural: definindo as cores
  start_color();
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);

  //! Assertiva estrutural: muda a cor da interconexao de acordo com o estado da mesma
  attron(COLOR_PAIR(conexao->tagFalha + 4));

  //! Comentarios de argumentacao
  /**
  * Printando a interconexao (I), somente se a mesma estiver conectada, como pontos na interface
  **/
  while(xIn != xOut || yIn != yOut){

    if(xIn < xOut)
      xIn++;
    else if(xIn > xOut)
      xIn--;

    if(yIn < yOut)
      yIn++;
    else if(yIn > yOut)
      yIn--;

    if(xIn != xOut || yIn != yOut)
      mvprintw(xIn,yIn,".");
  }
}

/**
*	Funcao: desenhaCidade
*
*	Hipóteses:
*		cidade - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		desenho de uma cidade da lista de cidades na interface
*
*	Interfaces explicitas:
*		void, desenhaCidade, Cidade* cidade
*
*	Interfaces implicitas:
*		cidade - lista de cidades
**/
void desenhaCidade(Cidade* cidade){

  //! Assertiva estrutural: definindo o bloco 3x3
  int x = cidade->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = cidade->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  //! Assertiva estrutural: definindo as cores
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);

  //! Assertiva estrutural: muda a cor da cidade de acordo com o estado da mesma
  attron(COLOR_PAIR(cidade->tagEstado + 1));

  //! Assertiva estrutural: printando a cidade (C) em um espaço de 3x3 na interface
  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"C");

}

/**
*	Funcao: desenhaGerador
*
*	Hipóteses:
*		gerador - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		desenho de um gerador da lista de geradores na interface
*
*	Interfaces explicitas:
*		void, desenhaGerador, Gerador* gerador
*
*	Interfaces implicitas:
*		gerador - lista de geradores
**/
void desenhaGerador(Gerador* gerador){

  //! Assertiva estrutural: definindo o bloco 3x3
  int x = gerador->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = gerador->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  //! Assertiva estrutural: definindo as cores
  start_color();
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(7));

  //! Assertiva estrutural: printando o gerador (G) em um espaço de 3x3 na interface
  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"G");

}

/**
*	Funcao: desenhaAdaptador
*
*	Hipóteses:
*		adaptador - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		desenho de um adaptador da lista de adaptadores na interface
*
*	Interfaces explicitas:
*		void, desenhaAdaptador, Adaptador* adaptador
*
*	Interfaces implicitas:
*		adaptador - lista de adaptadores
**/
void desenhaAdaptador(Adaptador* adaptador){

  //! Assertiva estrutural: definindo o bloco 3x3
  int x = adaptador->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = adaptador->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  //! Assertiva estrutural: definindo as cores
  attron(COLOR_PAIR(7));

  //! Assertiva estrutural: printando o adaptador (A) em um espaço de 3x3 na interface
  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"A");

}
