#include "../header/Interface.h"



void inicializa(Gerador* listaGeradores ,Interconexao* listaInterconexoes,Adaptador* listaAdaptadores ,Cidade* listaCidades){

  Gerador *gerador;
  Interconexao *interconexao;
  Adaptador *adaptador;
  Cidade *cidade;

  system("clear");
  initscr();			/* Start curses mode 		  */

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

  int x = gerador->posicao[0];
  int y = gerador->posicao[1];

  int auxX;
  int auxY;

  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"G");

}


void desenhaCidade(Cidade* cidade){

  int x = cidade->posicao[0];
  int y = cidade->posicao[1];

  int auxX;
  int auxY;

  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"C");
}

void desenhaAdaptador(Adaptador* adaptador){

  int x = adaptador->posicao[0];
  int y = adaptador->posicao[1];

  int auxX;
  int auxY;

  for(auxX = x-1; auxX <= x+1 ; auxX++)
    for(auxY = y-1; auxY <= y+1; auxY++ )
      mvprintw(auxX,auxY,"A");

}


void desenhaInterconexao(Interconexao* conexao){

  int xIn = conexao->posicaoInicial[0];
  int yIn = conexao->posicaoInicial[1];

  int xOut = conexao->posicaoFinal[0];
  int yOut = conexao->posicaoFinal[1];

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
