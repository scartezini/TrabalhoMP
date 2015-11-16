#include "../header/Adaptadores.h"
#include <assert.h>

/** -----------------------Funcoes Basicas---------------------------- */

/**
*	Funcao: criaListaAdaptador
*
*	AssertivaSaida:
*		NULL; 
**/
Adaptador* criaListaAdaptador(){
	return NULL;
}

/**
*	Funcao: adaptadorVazio
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO; 
**/
Vazio adaptadorVazio(Adaptador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIO;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIO;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereAdaptador
*
*	AssertivaEntrada:
*		registro != NULL;
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo){
	assert(registro != NULL);
	
	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador)); //!< Alocacao de um novo adaptador
	char *numChar = (char) malloc (strlen(registro)*sizeof(char)); //!< Alocacao de um vetor do tamanho do registro
	int i,j=0,k=2; //!< Variaveis de auxilio

	for(i=2;registro[i]!=' ';i++);
	//! AE: a posicao corrente do registro possui um caracter relevante
	
	//! Comentarios de argumentacao
		/**
		*	Comecando de registro[2], enquanto registro[i] for um caracter irrelevante,
		* soma-se 1 a variavel de auxilio i
		**/
		
	//! AS: a posicao corrente do registro possui um caracter irrelevante
	
	//! Asseriva estrutural: o nome do novo adaptador possui tamanho i-1 
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<=2;i++){
	//! AE: o valor da variavel auxiliar j deve ser menor ou igual ao numero total de atributos lidos do adaptador

		if(registro[i] == ' '||registro[i] == '\0'){
		//! AE: a posicao corrente do registro possui um caracter irrelevante, ou um caracter finalizador	

			if(j == 0){
			//! AE: o valor de j eh igual a 0	

				//! Comentarios de argumentacao
					/**
					*	A (posicao corrente-k) recebe um caracter finalizador
					**/
				novo->nome[i-k] = '\0';
			}
			//! AS: o valor de j eh maior que 0	
			
			else{
			//! AE: o valor de j eh maior que 0
			
				//! Comentarios de argumentacao
					/**
					*	A (posicao corrente-k) do vetor numChar recebe um caracter finalizador
					**/	
				numChar[i-k] = '\0';
				
				//! Comentarios de argumentacao
					/**
					*	De acordo com o valor da variavel auxiliar j, armazena-se o vetor numChar 
					* no seu respectivo atributo lido
					**/	
				if(j == 1)
					novo->posicao[0] = atoi(numChar);
				else if(j == 2)
					novo->posicao[1] = atoi(numChar);
			}
			//! AS: o valor de j eh maior que 4
			
			k = i+1;
			j++;
		}
		//! AS: a posicao corrente do registro possui um caracter relevante	
		
		else{
		//! AE: a posicao corrente do registro possui um caracter relevante
			
			//! Comentarios de argumentacao
				/**
				*	Se o valor da variavel de auxilio j for 0
				*	Entao
				*		armazena-se a posicao corrente do registro na 
				*	 (posicao corrente-k) do nome do adaptador
				*	Senao
				*		armazena-se a posicao corrente do registro na 
				*	 (posicao corrente-k) do vetor numChar
				*	FimSe
				**/		
			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numChar[i-k] = registro[i];
		}
		//! AS: a posicao corrente do registro possui um caracter irrelevante, ou um caracter finalizador
	}
	//! AS: o valor da variavel auxiliar j ultrapassou o numero total de atributos lidos da adaptador

	//! Comentarios de argumentacao
		/**
		*	Os atributos nao lidos do adaptador inserido recebem o valor nulo, e o proximo adaptador
		* da lista que contem o novo adaptador inserido na cabeca recebe a lista de adaptadores atual
		**/		
	novo->recursoRecebido = 0;
	novo->saidas = NULL;
	novo->quatidadeSaidas = 0;
	//novo->peso = NULL;

	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

/**
*	Funcao: imprimeListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		
**/
void imprimeListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos do adaptador corrente
		**/
		printf("nome: %s pos_x: %d pos_y: %d recurso recebido%d quantidade de saidas%d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoRecebido
				,aux->quantidadeSaidas);
	}
	//! AS: listaAlvo chegou ao fim		
}

/**
*	Funcao: liberaListaAdaptador
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		adaptadorVazio(listaAlvo) == VAZIO;
*		
**/
void liberaListaAdaptador(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux1 = NULL;
	Adaptador *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Adaptador corrente
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(adaptadorVazio(listaAlvo) == VAZIO);
}

/** -----------------------Funcoes de Calculo---------------------------- */

/**
*
*	Funcao: defineDistribuicao
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		para cada adaptador da lista: adaptador->saidas[i] != null;
**/
void defineDistribuicao(Adaptador *adaptador){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);
	
	while(adaptador != NULL){

		if(adaptador->saidas == NULL){
			return;
		}

		if(adaptador->peso == NULL){
			adaptador->peso = (float *) malloc(adaptador->quatidadeSaidas * sizeof(float));
		}


		int i;
		int somatorio = 0;
		for(i=0;i<adaptador->quatidadeSaidas;i++){

			if(adaptador->saidas[i]->tagFalha == semFalha){
				somatorio += adaptador->saidas[i]->capacidadeMaxima;
			}
		}


		int recursoTransportado;
		Interconexao *conexao;
		for (int i = 0; i < adaptador->quatidadeSaidas; ++i){

			conexao = adaptador->saidas[i];

			if(conexao->tagFalha == semFalha){

			//! Comentarios de argumentacao
				/**
				*	Recurso transportado é a quantidade de recurso que cada 
				* conexao vai transportar no turno
				*	Somatorio é a soma de capaxidade maxima de todos as conexoes
				* ativas;
				*
				*	RT = recursoTransportado
				*	CM = capacidadeMaxima
				*	RS = recursoRecebido
				*
				*	RT = CM*RS/somatorio
				*
				**/
				recursoTransportado = conexao->capacidadeMaxima 
				 						* adaptador->recursoRecebido 
				 						/ somatorio;

				/**
				*
				*	if(recursoTransportado <= conexao->capacidadeMaxima){
				*		conexao->recursoTransportado = recursoTransportado;
				*	}else{
				*		conexao->recursoTransportado = conexao->capacidadeMaxima;
				*	}
				*
				**/
				recursoTransportado <= conexao->capacidadeMaxima ? 
				 						conexao->recursoTransportado = recursoTransportado :
				 						conexao->recursoTransportado = conexao->capacidadeMaxima;
			}
		}


		adaptador = adaptador->proximo;
	}
}
