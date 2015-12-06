#include "../header/Interface.h"

#define DESLOCAMENTO_VERTICAL 4
#define DESLOCAMENTO_HORIZONTAL 2

int deslocamento;

void inicializa(Gerador* listaGeradores ,Interconexao* listaInterconexoes,Adaptador* listaAdaptadores ,Cidade* listaCidades){

  Gerador *gerador;
  Interconexao *interconexao;
  Adaptador *adaptador;
  Cidade *cidade;

  system("clear");
  initscr();			/* Start curses mode 		  */

  if(has_colors() == FALSE){
    endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}

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

  refresh();			/* Print it on to the real screen */

}
void desenhaGerador(Gerador* gerador){

  int x = gerador->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = gerador->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  start_color();			/* Start color 			*/
  init_pair(7, COLOR_BLUE, COLOR_BLACK);

  attron(COLOR_PAIR(7));

  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"G");

}


void desenhaCidade(Cidade* cidade){

  int x = cidade->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = cidade->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  start_color();			/* Start color 			*/
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);

  attron(COLOR_PAIR(cidade->tagEstado + 1));

  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"C");

}



void desenhaAdaptador(Adaptador* adaptador){

  int x = adaptador->posicao[0] + DESLOCAMENTO_VERTICAL;
  int y = adaptador->posicao[1] + DESLOCAMENTO_HORIZONTAL;

  int auxX;
  int auxY;

  attron(COLOR_PAIR(7));
  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"A");

}


void desenhaInterconexao(Interconexao* conexao){

  int xIn = conexao->posicaoInicial[0] + DESLOCAMENTO_VERTICAL;
  int yIn = conexao->posicaoInicial[1] + DESLOCAMENTO_HORIZONTAL;

  int xOut = conexao->posicaoFinal[0] + DESLOCAMENTO_VERTICAL;
  int yOut = conexao->posicaoFinal[1] + DESLOCAMENTO_HORIZONTAL;

  start_color();			/* Start color 			*/
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);

  attron(COLOR_PAIR(conexao->tagFalha + 4));


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

void atualizaCidades(Cidade* listaCidades){

  Cidade *cidade;


  for(cidade = listaCidades , deslocamento = 3; cidade != NULL ; cidade = cidade->proximo , deslocamento += 5){
    attron(COLOR_PAIR(cidade->tagEstado + 1));
    mvprintw(deslocamento,100,"%s:\n",cidade->nome);
    mvprintw(deslocamento+1,100,"\trecurso necessario: %d\n",cidade->recursoNecessario);
    mvprintw(deslocamento+2,100,"\trecurso recebido: %d\n",cidade->recursoRecebido);
    mvprintw(deslocamento+3,100,"\trecurso gasto %d\n",cidade->recursoGasto);
    desenhaCidade(cidade);
  }


  refresh();			/* Print it on to the real screen */
}

void atualizaInterconexoes(Interconexao* listaInterconexoes){
  Interconexao* conexao;

  for(conexao = listaInterconexoes; conexao != NULL ; conexao = conexao->proximo, deslocamento+=6){
    attron(COLOR_PAIR(conexao->tagFalha + 4));
    mvprintw(deslocamento,100,"%s:\n",conexao->nome);
    mvprintw(deslocamento+1,100,"\tcapacidade maxima: %d\n",conexao->capacidadeMaxima);
    mvprintw(deslocamento+2,100,"\trecurso transportado: %d\n",conexao->recursoTransportado);
    mvprintw(deslocamento+3,100,"\tchance de falha: %d\n",conexao->chanceFalha);
    mvprintw(deslocamento+4,100,"\tnumero de falhas: %d\n",conexao->numeroFalha);
    desenhaInterconexao(conexao);
  }

  refresh();
}


void atualizaGeradores(Gerador* listaGeradores){
  Gerador* gerador;


  for(gerador = listaGeradores; gerador != NULL ; gerador = gerador->proximo, deslocamento+=4){
    attron(COLOR_PAIR(7));
    mvprintw(deslocamento,100,"%s:\n",gerador->nome);
    mvprintw(deslocamento+1,100,"\tcusto/segundo: %d\n",gerador->custo);
    mvprintw(deslocamento+2,100,"\trecurso produzido/segundo: %d\n",gerador->recursoProduzido);
    desenhaGerador(gerador);
  }

  refresh();
}

void atualizaAdaptadores(Adaptador* listaAdaptadores){
  Adaptador* adaptador;

  for(adaptador = listaAdaptadores; adaptador != NULL ; adaptador = adaptador->proximo, deslocamento+=3){
    attron(COLOR_PAIR(7));
    mvprintw(deslocamento,100,"%s:\n",adaptador->nome);
    mvprintw(deslocamento+1,100,"\trecurso recebido: %d\n",adaptador->recursoRecebido);

    desenhaAdaptador(adaptador);
  }

  refresh();
}
