#import "Adaptadores.h"
#import "Cidades.h"


typedef struct interconexao{
	char *nome;
	int posicaoInical[2];
	int posicaoFinal[2];
	float chanceFalha;
	int tempoConcerto;
	int custoConcerto;
	
	Adaptador *adaptador;
	Cidade *cidade;
	
}Interconexao;