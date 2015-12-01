#include "../header/Geradores.h"
#include <assert.h>

/**
*	Funcao: criaListaGerador (Iterador)
*
*	AssertivaSaida:
*		NULL;
*
*	Requisitos:
*		criacao de uma nova lista do tipo Gerador
*
*	Interfaces explicitas:
*		Gerador*, criaListaGerador
**/
Gerador* criaListaGerador(){
	return NULL;
}

/**
*	Funcao: geradorVazio (Iterador)
*
*	AssertivaSaida:
*		VAZIO || NAO_VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		checar se a lista está vazia
*
*	Interfaces explicitas:
*		Vazio, geradorVazio, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		Vazio - tipo de dado, indicando se a lista eh vazia ou nao
*		listaAlvo - lista de geradores
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
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*		registro - string, nao vazia, contendo uma linha do arquivo txt de entrada
*
*	Requisitos:
*		inserir um novo gerador na lista de geradores
*
*	Interfaces explicitas:
*		Gerador*, insereGerador, char *registro, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		registro - representa uma linha do arquivo de entrada
*		listaAlvo - lista de geradores
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
	novo->saida = NULL;
	novo->taxaProducao = 0;
	novo->proximo = listaAlvo;
	listaAlvo = novo;

	free(numChar);
	return listaAlvo;
}

/**
*	Funcao: imprimeListaGerador
*
*	AssertivaEntrada:
*		geradorVazio(listaAlvo) == NAO_VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		impressao da lista de geradores
*
*	Interfaces explicitas:
*		void, imprimeListaGerador, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
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
		printf(" - nome: %s | pos_x: %d | pos_y: %d | recurso recebido: %d | custo: %d | taxa de produção: %d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoProduzido
				,aux->custo, aux->taxaProducao);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaGerador (Iterador)
*
*	AssertivaEntrada:
*		geradorVazio(listaAlvo) == NAO_VAZIO;
*
*	AssertivaSaida:
*		geradorVazio(listaAlvo) == VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		liberacao da lista de geradores
*
*	Interfaces explicitas:
*		void, liberaListaGerador, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
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

/**
*	Funcao: numeroGeradores (Iterador)
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		realiza o calculo da energia total gerada
*
*	Interfaces explicitas:
*		int, recursoProduzidoTotal, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
**/
int recursoProduzidoTotal(Gerador *listaAlvo){
	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Gerador *aux = listaAlvo;

	while(aux != NULL){
	//! AE: listaAlvo nao chegou ao fim
	
	//! Comentarios de argumentacao
		/**
		*	Somando os recursos produzidos para obter a energia total gerada
		**/
		total += aux->recursoProduzido;
		aux = aux->proximo;
	}

	assert(total >= 0);

	return total;
}

/**
*	Funcao: custoGeradores
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		realiza a soma dos custos dos geradores
*
*	Interfaces explicitas:
*		int, custoGeradores, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
**/
int custoGeradores(Gerador *listaAlvo){
	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Gerador *aux = listaAlvo;

	while(aux != NULL){
	//! AE: listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Somando os custos de cada gerador da lista de geradores
		**/
		total += aux->custo;
		aux = aux->proximo;
	}

	assert(total >= 0);

	return total;
}

/**
*	Funcao: mandarRecursoProduzido
*
*	AssertivaEntrada:
*		geradorVazio(listaAlvo) == NAO_VAZIO;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		alterar a interconexao ligada a cada celula da lista de geradores
* com o valor que sera transportado
*		Altera o adaptador de destino com o recurso que sera recebido
*
*	Interfaces explicitas:
*		void, mandarRecursoProduzido, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
**/
void mandarRecursoProduzido(Gerador *listaAlvo){
	assert(geradorVazio(listaAlvo) == NAO_VAZIO);

	Interconexao *auxiliar;
	Interconexao *auxProxima;

	while(listaAlvo != NULL){
	//! AE: nao chegou ao final da listaAlvo

		if(listaAlvo->saida != NULL){
		//! AE: o elemento possui saidas

			if(listaAlvo->saida->tagFalha == SEM_FALHA){
			//! AE: interconexao ligada a essa celula nao teve falha

				if(listaAlvo->saida != NULL){
				//! AE: gerador possui uma saida
					listaAlvo->saida->recursoTransportado = (listaAlvo->saida->capacidadeMaxima >= listaAlvo->recursoProduzido)?
																				listaAlvo->recursoProduzido : listaAlvo->saida->capacidadeMaxima;


					auxiliar = listaAlvo->saida;

					//! Comentarios de argumentacao
						/**
						*	laço que cobre os casos de uma interconexao apontar para outra antes
						* de chegar ao adaptdor
						**/
					while(auxiliar->saidaInterconexao != NULL){
					//! AE: uma interconexao aponta para outra;
						auxProxima = auxiliar->saidaInterconexao;

						//! Comentarios de argumentacao
							/**
							*	Verifica se a proxima Interconexao nao esta falha
							* se nao esta define o recurso que ela ira transportar
							**/

						if(auxProxima->tagFalha == SEM_FALHA){
						//! AE: conexao nao falha

							// Assertiva estrutural: define o recursoTransportado
							auxProxima->recursoTransportado = (auxProxima->capacidadeMaxima >= auxiliar->recursoTransportado)?
																								auxiliar->recursoTransportado : auxProxima->capacidadeMaxima;

						}
						else{
						//! AE: conexao falha
							auxProxima->recursoTransportado = 0;
						}

						auxiliar = auxProxima;
					}
					//! AS: chegou na ultima interconexao depois do gerador;

					if(auxiliar->saidaAdaptador != NULL){
					//! AE: a interconexao aponta para o adaptador
						auxiliar->saidaAdaptador->recursoRecebido = auxiliar->recursoTransportado;
					}
				}
				//! AS: gerador nao possui uma saida
			}
			else{
			//! AE: interconexao ligada a essa celula falhou
				auxiliar = listaAlvo->saida;

				if(auxiliar != NULL){
				//! AE: a lista possui saida
					auxiliar->recursoTransportado = 0;
					
					while(auxiliar->saidaInterconexao != NULL){
					//! AE: a lista de inteconexao das saidas nao chegou ao fim
						auxiliar = auxiliar->saidaInterconexao;
						auxiliar->recursoTransportado = 0;
					}
					//! AE: a lista de inteconexao das saidas chegou ao fim

					if(auxiliar->saidaAdaptador != NULL){
					//! AE: a interconexao aponta para o adaptador
						auxiliar->saidaAdaptador->recursoRecebido = auxiliar->recursoTransportado;
					}
				}
			}
		}
		//! AS: o elemento nao possui saidas
		
		listaAlvo = listaAlvo->proximo;
	}
	//! AS: chegou ao final da listaAlvo
}


/**
*	Funcao: numeroGeradores (Iterador)
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Gerador
*
*	Requisitos:
*		conta o numero total de geradores em uma lista de geradores
*
*	Interfaces explicitas:
*		int, numeroGeradores, Gerador *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de geradores
**/
int numeroGeradores(Gerador *listaAlvo){
	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Gerador *aux = listaAlvo;

	while(aux != NULL){
	//! AE: listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Contagem do numero de total de geradores na listaAlvo
		**/
		total++;
		aux = aux->proximo;
	}

	assert(total >= 0);

	return total;
}
