#import "Interconexoes.h"

typedef struct gerador{
	char *nome;
	int posicao[2];
	int recursoProduzido;
	int custo;
	
	Interconexao *interconexao;
	
}Gerador;