#import "Adaptadores.h"
#import "Cidades.h"


typedef struct interconexao{
	char *nome;
	int posicaoInical[2];
	int posicaoFinal[2];
	float chanceFalha;
	int tempoConcerto;
	int custoConcerto;
	Interconexao *proximo;
	
	Adaptador *adaptador;
	Cidade *cidade;
	
}Interconexao;


/**
*	Calcula o tamanho da celua de conexao que
* eh passada para a funcao
*
*	@param interconexao;
*		ponteiro para a celula de interconexao
*
*	@return 
*		tamanho da celula de conexao que foi passada
*
**/
int tamanhoConexao(Interconexao *interconexao);


/**
*	Calcula o tamanho total das conexoes 
* da lista que eh passada
*
*	@param interconexao
*		ponteiro para o inicio da lista de celulas de conexao
*
*	@return
*		retorna o tamanho total das conexoes da lista
**/
int tamanhoTotalConexao(Interconexao *interconexao);