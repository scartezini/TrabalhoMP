#include "../header/Interface.h"



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

  int x = gerador->posicao[0] + 3;
  int y = gerador->posicao[1] + 3;

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

  int x = cidade->posicao[0] + 3;
  int y = cidade->posicao[1] + 3;

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

  int x = adaptador->posicao[0] + 3;
  int y = adaptador->posicao[1] + 3;

  int auxX;
  int auxY;

  attron(COLOR_PAIR(7));
  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"A");

}


void desenhaInterconexao(Interconexao* conexao){

  int xIn = conexao->posicaoInicial[0] + 3;
  int yIn = conexao->posicaoInicial[1] + 3;

  int xOut = conexao->posicaoFinal[0] + 3;
  int yOut = conexao->posicaoFinal[1] + 3;

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

  for(cidade = listaCidades ; cidade != NULL ; cidade = cidade->proximo)
    desenhaCidade(cidade);


  refresh();			/* Print it on to the real screen */

}

void atualizaInterconexoes(Interconexao* listaInterconexoes){
  Interconexao* conexao;

  for(conexao = listaInterconexoes ; conexao != NULL ; conexao = conexao->proximo)
    desenhaInterconexao(conexao);

  refresh();

}
