#include "../header/Adaptadores.h"
#include <assert.h>

/**
*	Funcao: criaListaAdaptador (Iterador)
*
*	AssertivaSaida:
*		NULL;
*
*	Requisitos:
*		criacao de uma nova lista do tipo Adaptador
*
*	Interfaces explicitas:
*		Adaptador*, criaListaAdaptador
**/
Adaptador* criaListaAdaptador(){
	return NULL;
}

/**
*	Funcao: adaptadorVazio (Iterador)
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		checar se a lista está vazia
*
*	Interfaces explicitas:
*		Vazio, adaptadorVazio, Adaptador *listaAlvo
*
*	Interfaces implicitas:
*		Vazio - tipo de dado, indicando se a lista eh vazia ou nao
*		listaAlvo - lista de adaptadores
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
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Adaptador
*		registro - string, nao vazia, contendo uma linha do arquivo txt de entrada
*
*	Requisitos:
*		inserir um novo adaptador na lista de adaptadores
*
*	Interfaces explicitas:
*		Adaptador*, insereAdaptador, char *registro, Adaptador *listaAlvo
*
*	Interfaces implicitas:
*		registro - representa uma linha do arquivo de entrada
*		listaAlvo - lista de adaptadores
**/
Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo){
	assert(registro != NULL);

	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador)); //!< Alocacao de um novo adaptador
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
	novo->entradas = NULL;
	novo->quantidadeSaidas = 0;

	novo->proximo = listaAlvo;
	listaAlvo = novo;

	free(numChar);
	return listaAlvo;
}

/**
*	Funcao: imprimeListaAdaptador (Iterador)
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		impressao da lista de adaptadores
*
*	Interfaces explicitas:
*		void, imprimeListaAdaptador, Adaptador *listaAlvo**/
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
		printf(" - nome: %s | pos_x: %d | pos_y: %d | recurso recebido: %d | quantidade de saídas: %d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1]
				,aux->recursoRecebido
				,aux->quantidadeSaidas);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaAdaptador (Iterador)
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		adaptadorVazio(aux1) == VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		liberacao da lista de adaptadores
*
*	Interfaces explicitas:
*		void, liberaListaAdaptador, Adaptador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de adaptadores
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

	assert(adaptadorVazio(aux1) == VAZIO);
}

/**
*
*	Funcao: defineDistribuicao
*
*	AssertivaEntrada:
*		adaptadorVazio(listaAlvo) == NAO_VAZIO;
*		para cada adaptador da lista: adaptador->saidas[i] != null;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Adaptador
*
*	Requisitos:
*		definicao da distribuicao do adaptador
*
*	Interfaces explicitas:
*		void, defineDistribuicao, Adaptador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de adaptadores
**/
void defineDistribuicao(Adaptador *listaAlvo){
	assert(adaptadorVazio(listaAlvo) == NAO_VAZIO);

	Adaptador *aux;
	Interconexao *conexao; //!< conexoes do adaptador

	int somatorio;
	int recursoTransportado; //!< quantidade de recurso transportado

	//! Assertiva estrutural: aux é a lista nao-nula de adaptadores
	aux = listaAlvo;

	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de adaptadores

		//! Assertiva estrutural: somatorio eh a soma das capacidades maximas do adaptador corrente
		somatorio = 0;

		if(aux->saidas != NULL){
		//! AE: o adaptador corrente possui saidas

			//! Assertiva estrutural: conexao eh a lista de saidas do adaptador corrente
			conexao = aux->saidas;

			//! Comentarios de argumentacao
				/**
				*	Enquanto percorre a lista de conexoes que saem do adaptador
				* somam-se a capaxidade maxima de todas as conexoes
				**/

			while (conexao != NULL){
			//! AE: a lista de saidas do adaptador nao chegou ao fim
				somatorio += conexao->capacidadeMaxima;
				conexao = conexao->proximoSaidaAdaptador;
			}
			//! AS: a lista de saidas do adaptador chegou ao fim

			//! Assertiva estrutural: conexao eh a lista de saidas do adaptador corrente
			conexao = aux->saidas;

			while(conexao != NULL){
			//! AE: a lista de saidas do adaptador nao chegou ao fim

				if(conexao->tagFalha == SEM_FALHA){
				//! AE: a saida corrente do adaptador nao possui falha

					//! Assertiva estrutural: recursoTransportado é a quantidade de recurso que cada conexao vai transportar no turno
					recursoTransportado = (conexao->capacidadeMaxima * aux->recursoRecebido) / somatorio;

					//! Comentarios de argumentacao
						/**
						*	Se a a capacidade maxima da saida corrente do adaptador for maior ou igual ao recursoTransportado
						*	Entao
						*		o recursoTransportado da saida corrente do adaptador recebe o recursoTransportado
						*	Senao
						*		recebe a capacidadeMaxima da saida corrente do adaptador
						*	FimSe
						**/
					conexao->recursoTransportado = (conexao->capacidadeMaxima >= recursoTransportado) ?
													recursoTransportado : conexao->capacidadeMaxima;

				}
				//! AS: a saida corrente do adaptador possui falha

				conexao = conexao->proximoSaidaAdaptador;
			}
			//! AS: a lista de saidas do adaptador chegou ao fim
		}

		aux = aux->proximo;
	}
	//! AS: a lista de adaptadores chegou ao fim
}


/**
*	Funcao: mandarRecursoAdaptado
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Adaptador
*		A estrategia de distribuicao ja foi previamente definida e as
*	interconxoes ligadas diretamente cada celula do adaptador ja esta
*	 com o recursoTransportado preenchido
*
*	Requisitos:
*		Alterar a interconexao ligada a cada celula da lista de geradores
* 	com o valor que sera transportado
*		Altera o adaptador ou cidade de destino com o recurso que sera recebido
*
*	Interfaces explicitas:
*		void, mandarRecursoAdaptado, Adaptador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de adaptadores
**/
void mandarRecursoAdaptado(Adaptador *listaAlvo){

	Interconexao *conexao;
	Interconexao *atual;
	Interconexao *posterior;

	while(listaAlvo != NULL){
	//! AE: a listaAlvo nao chegou ao fim

		//! Assertiva estrutural: conexao sao as saidas do adaptador corrente
		conexao = listaAlvo->saidas;

		while(conexao != NULL){
		//! AE: a lista de saidas do adaptador nao chegou ao fim

			//! Assertiva estrutural: atual eh a saida atual na lista de saidas do adaptador
			atual = conexao;

			while(atual->saidaInterconexao != NULL){
			//! AE: a lista de interconexoes da saida nao chegou ao fim

				//! Assertiva estrutural: posterior eh a proxima conexao na lista de interconexoes
				posterior = atual->saidaInterconexao;

				//! Comentarios de argumentacao
					/**
					*	Verifica se a proxima Interconexao nao esta falha
					* se nao esta define o recurso que ela ira transportar
					**/
				if(posterior->tagFalha == SEM_FALHA){
				//! AE: posterior nao possui falha

					//! Comentarios de argumentacao
						/**
						*	Definicao de quanto de recurso sera transportado
						**/
					posterior->recursoTransportado = (posterior->capacidadeMaxima >= atual->recursoTransportado)?
																						atual->recursoTransportado : posterior->capacidadeMaxima;
				}
				else{
				//! AE: posterior esta falho
					posterior->recursoTransportado = 0;
				}

				atual = posterior;
			}
			//! AS: a lista de interconexoes da saida chegou ao fim

			if(atual->saidaCidade != NULL){
			//! AE: a saida eh uma cidade
				atual->saidaCidade->recursoRecebido = atual->recursoTransportado;
			}
			else if(atual->saidaAdaptador != NULL){
			//! AE: a saida eh um adaptador
				atual->saidaAdaptador->recursoRecebido = atual->recursoTransportado;
			}

			conexao = conexao->proximoSaidaAdaptador;
		}
		//! AS: a lista de saidas do adaptador chegou ao fim

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: a listaAlvo chegou ao fim
}


void zerarAdaptadores(Adaptador *listaAlvo){
	Adaptador *adaptador;

	for(adaptador = listaAlvo ; adaptador != NULL ; adaptador = adaptador->proximo){
		adaptador->recursoRecebido = 0;
	}

}
