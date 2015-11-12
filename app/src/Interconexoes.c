#include "Interconexao.h"


float tamanhoConexao(Interconexao *interconexao){
	
	int xA;
	int yA;
	
	int xB;
	int yB;
	
	xA = interconexao->posicaoInical[0];
	yA = interconexao->posicaoInical[1];
	
	xB = interconexao->posicaoFinal[0];
	yB = interconexao->posicaoFinal[1];
	
	return sqrt(pow((xB - xA),2) + pow((yB - yA),2));
	
}

float tamanhoTotalConexao(Interconexao *interconexao){
	
	float resultado;
	resultado = 0;
	
	while(interconexao != null){
		resultado += tamanhoConexao(interconexao);
		interconexao = interconexao->proximo;
	}
	
	return resultado;
}