#include "../header/Geradores.h"
#include <assert.h>

/**
*	Funcao: criaListaGerador
*
*	AssertivaSaida:
*		NULL;
**/
Gerador* criaListaGerador(){
	return NULL;
}

/**
*	Funcao: criaListaCidade
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO;
**/
Vazio geradorVazio(Gerador *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIO;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIO;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereGerador
*
*	AssertivaEntrada:
*		registro != NULL;
**/
Gerador* insereGerador(char *registro, Gerador *listaAlvo){
	assert(registro != NULL);

	Gerador *novo = (Gerador *)malloc(sizeof(Gerador)); //!< Alocacao de um novo gerador
	char *numChar = (char*) malloc (strlen(registro)*sizeof(char)); //!< Alocacao de um vetor do tamanho do registro
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

	for(i=2;j<=4;i++){
	//! AE: o valor da variavel auxiliar j deve ser menor ou igual ao numero total de atributos lidos do gerador

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
				else if(j == 3)
					novo->recursoProduzido = atoi(numChar);
				else if(j == 4)
					novo->custo = atoi(numChar);
			}
			//! AS: o valor de j eh maior que 5

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
				*	 (posicao corrente-k) do nome do gerador
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
	//! AS: o valor da variavel auxiliar j ultrapassou o numero total de atributos lidos do gerador

	//! Comentarios de argumentacao
		/**
		*	Os atributos nao lidos do gerador inserido recebem o valor nulo, e o proximo gerador
		* da lista que contem o novo gerador inserido na cabeca recebe a lista de geradores atual
		**/

	novo->proximo = listaAlvo;
	novo->saida = NULL;
	listaAlvo = novo;

	return listaAlvo;
}

/**
*	Funcao: imprimeListaGerador
*
*	AssertivaEntrada:
*		geradorVazio(listaAlvo) == NAO_VAZIO;
*
**/
void imprimeListaGerador(Gerador *listaAlvo){
	assert(geradorVazio(listaAlvo) == NAO_VAZIO);

	Gerador *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos do gerador corrente
		**/
		printf("nome: %s pos_x: %d pos_y: %d recurso recebido%d quantidade de saidas%d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoProduzido
				,aux->custo);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaGerador
*
*	AssertivaEntrada:
*		geradorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		geradorVazio(listaAlvo) == VAZIO;
*
**/
void liberaListaGerador(Gerador *listaAlvo){
	assert(geradorVazio(listaAlvo) == NAO_VAZIO);

	Gerador *aux1 = NULL;
	Gerador *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Gerador corrente
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(geradorVazio(aux1) == VAZIO);
}
