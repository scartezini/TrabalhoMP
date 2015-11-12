

typedef struct cidade{
	char *nome;
	int posicao[2];
	int recursoNecessario;
	int recursoGasto;
	
	Cidade *proximo;
	
}Cidade;


/**
*	Resultado da soma de todos recursos 
* gasto pelas cidades 
*
*	@param cidade
*		ponteiro para o inicio da lista de cidades
*	
*	@return 
*		total de recursos gasto pelas cidades
**/
int recursoGastoTotal(Cidade *cidade);