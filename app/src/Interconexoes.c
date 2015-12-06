#include "../header/Interconexoes.h"
#include <assert.h>

/**
*	Funcao: criaListaInterconexao (Iterador)
*
*	AssertivaSaida:
*		NULL;
*
*	Requisitos:
*		criacao de uma nova lista do tipo Interconexao
*
*	Interfaces explicitas:
*		Interconexao*, criaListaInterconexao
**/
Interconexao* criaListaInterconexao(){
	return NULL;
}

/**
*	Funcao: interconexaoVazia (Iterador)
*
*	AssertivaSaida:
*		VAZIA || NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		checar se a lista está vazia
*
*	Interfaces explicitas:
*		Vazia, interconexaoVazia, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		Vazia - tipo de dado, indicando se a lista eh vazia ou nao
*		listaAlvo - lista de interconexoes
**/
Vazia interconexaoVazia(Interconexao *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIA;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIA;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereInterconexao
*
*	AssertivaEntrada:
*		registro != NULL;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*		registro - string, nao vazia, contendo uma linha do arquivo txt de entrada
*
*	Requisitos:
*		inserir um novo gerador na lista de interconexoes
*
*	Interfaces explicitas:
*		Interconexao*, insereInterconexao, char *registro, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		registro - representa uma linha do arquivo de entrada
*		listaAlvo - lista de interconexoes
**/
Interconexao* insereInterconexao(char *registro, Interconexao *listaAlvo){
	assert(registro != NULL);

	Interconexao *novo = (Interconexao *)calloc(sizeof(Interconexao), 1); //!< Alocacao da nova Interconexao
	Interconexao *aux = NULL; //!< Variavel auxiliar para percorrer a lista e inserir o elemento no final
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

	//! Asseriva estrutural: o nome da nova interconexao possui tamanho i-1
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<=8;i++){
	//! AE: o valor da variavel auxiliar j deve ser menor ou igual ao numero total de atributos lidos da interconexao

		if(registro[i] == ' ' || registro[i] == '\0'){
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
					novo->posicaoInicial[0] = atoi(numChar);
				else if(j == 2)
					novo->posicaoInicial[1] = atoi(numChar);
				else if(j == 3)
					novo->posicaoFinal[0] = atoi(numChar);
				else if(j == 4)
					novo->posicaoFinal[1] = atoi(numChar);
				else if(j == 5)
					novo->capacidadeMaxima = atoi(numChar);
				else if(j == 6)
					novo->chanceFalha = atof(numChar);
				else if(j == 7)
					novo->tempoConserto = atoi(numChar);
				else if(j == 8)
					novo->custoConserto = atoi(numChar);
			}
			//! AS: o valor de j eh maior que 8

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
				*	 (posicao corrente-k) do nome da interconexao
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
	//! AS: o valor da variavel auxiliar j ultrapassou o numero total de atributos lidos da interconexao

	//! Comentarios de argumentacao
		/**
		*	Os atributos nao lidos da inteconexao inserida recebem o valor nulo, e a proxima interconexao
		* da lista que contem a nova inteconexao inserido na cabeca recebe a lista de interconexoes atual
		**/
	novo->tagFalha = SEM_FALHA;
	novo->numeroFalha = 0;
	novo->recursoTransportado = 0;

	novo->entradaAdaptador = NULL;
	novo->saidaAdaptador = NULL;

	novo->entradaInterconexao = NULL;
	novo->saidaInterconexao = NULL;

	novo->proximoEntradaAdaptador = NULL;
	novo->proximoSaidaAdaptador = NULL;

	novo->proximoEntradaCidade = NULL;

	novo->entradaGerador = NULL;

	novo->saidaCidade = NULL;

	novo->proximo = NULL;

	if(interconexaoVazia(listaAlvo) == NAO_VAZIA){
	//! AE: se a listaAlvo nao for vazia

		for(aux=listaAlvo;aux->proximo!=NULL;aux=aux->proximo);
		//! AE: o aux nao chegou ao final da lista de interconexoes

		aux->proximo = novo;
	}
	else{
	//! AE: se a listaAlvo for vazia

		listaAlvo = novo;
	}

	free(numChar);
	return listaAlvo;
}

/**
*	Funcao: imprimeListaInterconexao (Iterador)
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		impressao da lista de interconexoes
*
*	Interfaces explicitas:
*		void, imprimeListaInterconexao, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
void imprimeListaInterconexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	Interconexao *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos da interconexao corrente
		**/
		printf(" - nome: %s | posI_x: %d | posI_y: %d | posF_x: %d | posF_y: %d | tag destino: %d | chance falha: %.2f | tempo conserto: %d | custo conserto: %d | número falha: %d | tag falha: %d | capacidade máxima: %d | recurso transportado: %d\n"
				,aux->nome,aux->posicaoInicial[0],aux->posicaoInicial[1],aux->posicaoFinal[0],aux->posicaoFinal[1]
				,aux->tagDestino, aux->chanceFalha, aux->tempoConserto, aux->custoConserto, aux->numeroFalha
				,aux->tagFalha, aux->capacidadeMaxima, aux->recursoTransportado);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaInterconexao (Iterador)
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		interconexaoVazia(listaAlvo) == VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		liberacao da lista de interconexoes
*
*	Interfaces explicitas:
*		void, liberaListaInterconexao, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
void liberaListaInterconexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	Interconexao *aux1 = NULL;
	Interconexao *aux2 = NULL;

	//! Assertiva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim
	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Interconexao corrente
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(interconexaoVazia(aux1) == VAZIA);
}

/**
*	Funcao: tamanhoConexao
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		distancia > 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		calculo da distancia entre a posicao final e inicial
*
*	Interfaces explicitas:
*		float, tamanhoConexao, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		float - valor do tamanho
*		listaAlvo - lista de interconexoes
**/
float tamanhoConexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	int xA; //!< Valor no eixo x da posicao inicial
	int yA; //!< Valor no eixo y da posicao inicial

	int xB; //!< Valor no eixo x da posicao final
	int yB; //!< Valor no eixo y da posicao final

	float distancia;

	xA = listaAlvo->posicaoInicial[0];
	yA = listaAlvo->posicaoInicial[1];

	xB = listaAlvo->posicaoFinal[0];
	yB = listaAlvo->posicaoFinal[1];

	//! Comentarios de argumentacao
		/**
		*	Calculando a distancia utilizando ((xb-xa)^2 + (yb-ya)^2)^(1/2)
		**/

	distancia = sqrt(pow((xB - xA),2) + pow((yB - yA),2));

	assert(distancia > 0);
	return distancia;
}

/**
*	Funcao: tamanhoTotalConexao
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		resultado > 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		calculo da soma dos tamanhos das interconexoes
*
*	Interfaces explicitas:
*		float, tamanhoTotalConexao, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		float - valor da soma dos tamanhos
*		listaAlvo - lista de interconexoes
**/
float tamanhoTotalConexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	float resultado = 0;
	Interconexao *aux;

	//! Asseriva estrutural: aux é a lista nao-nula de interconexoes
	aux = listaAlvo;

	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de inteconexoes

	//! Comentarios de argumentacao
		/**
		*	Enquanto a lista de interconexoes eh percorrida, o tamanho
		* das conexoes sao somados e armazenados na variavel resultado
		**/

		resultado += tamanhoConexao(aux);
		aux = aux->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim

	assert(resultado > 0);
	return resultado;
}

/**
*	Funcao: calculaFalha
*
*	AssertivaEntrada:
*		conexao->chanceFalha >= 0 && conexao->chanceFalha <= 1;
*
*	AssertivaSaida:
*		FALHA || SEM_FALHA;
*
*	Requisitos:
*		calculo da chance de falha
*
*	Interfaces explicitas:
*		Falha, calculaFalha, Interconexao *conexao
*
*	Interfaces implicitas:
*		Falha - tipo de dado, indicando se houve falha ou nao
*		listaAlvo - lista de interconexoes
**/
Falha calculaFalha(Interconexao *listaAlvo){
	assert(listaAlvo->chanceFalha >= 0 && listaAlvo->chanceFalha <= 1);

	float numGerado;
	float num;
	float chance = listaAlvo->chanceFalha;

	//! Asseriva estrutural: num eh um numero gerado aleatoriamente
	numGerado = rand() % 101;
	num = numGerado/100;

	return ( (chance > 0) && (chance <= num) ) ? SEM_FALHA : FALHA ;
}

/**
*
*	Funcao: mandarRecursoTransportado
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Interconexao
*
*	Requisitos:
*		transporte dos recursos
*
*	Interfaces explicitas:
*		void, mandarRecursoTransportado, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
void mandarRecursoTransportado(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	Interconexao *aux;
	int recursoEnviado;

	//! Asseriva estrutural: aux é a lista nao-nula de interconexoes
	aux = listaAlvo;

	while(aux != NULL){
	//! AE: aux nao chegou ao fim da lista de inteconexoes

		if(aux->tagFalha == SEM_FALHA){
		//! AE: a interconexao corrente nao possui falha
			recursoEnviado = aux->recursoTransportado;

			//! Comentarios de argumentacao
				/**
				*	Enqaunto a lista de interconexoes eh percorrida, dependendo do destino da interconexao,
				* soma-se o recurso ao respectivo destino
				**/

			if(aux->tagDestino == ADAPTADOR){
			//! AE: o destino da interconexao eh um Adaptador
				aux->saidaAdaptador->recursoRecebido += recursoEnviado;
			}
			else if(aux->tagDestino == CIDADE){
			//! AE: o destino da interconexao eh uma Cidade
				aux->saidaCidade->recursoRecebido += recursoEnviado;
			}
		}

		aux = aux->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim
}


/**
*
*	Funcao: custoGastoComConserto
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponterio para o inicio da lista do tipo Interconexao
*
*	Requisitos:
*		calcular o quanto foi gasto com concerto das interconexoes
*
*	Interfaces explicitas:
*		int, custoGastoComConcerto, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
int custoGastoComConserto(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Interconexao *aux = listaAlvo;

	while(aux != NULL){
	//! AE : listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Incrementa o total com o resultado da multiplicacao
		* do numero de falhas com o custo gasto com o conserto de
		* cada falha
		**/
		total += aux->numeroFalha * aux->custoConserto;
		aux = aux->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;
}


/**
*
*	Funcao: numeroTotalFalhas
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponterio para o inicio da lista do tipo Interconexao
*
*	Requisitos:
*		contabilizar a quantidade de falhas
*
*	Interfaces explicitas:
*		int, numeroTotalFalhas, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
int numeroTotalFalhas(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Interconexao *aux = listaAlvo;

	while (aux != NULL) {
	//! AE: listaAlvo ainda nao acabou
	//! Comentarios de argumentacao
		/**
		*	Incrementa o somatorio com o numero de falhas da celula atual
		**/
		total += aux->numeroFalha;
		aux = aux->proximo;
	}

	assert(total >= 0);

	return total;
}

/**
*
*	Funcao: gerenciaFalhas
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponterio para o inicio da lista do tipo Interconexao
*
*	Requisitos:
*		marcar as celulas que falharam como falhas e contabilizar o concertos das celulas que estao paradas
*
*	Interfaces explicitas:
*		int, numeroTotalFalhas, Interconexao *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de interconexoes
**/
void gerenciaFalhas(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	while(listaAlvo != NULL){
	//! AE: listaAlvo nao chegou ao fim

		if(listaAlvo->tagFalha == SEM_FALHA){
		//! AE: interconexao corrente nao falhou

			if(calculaFalha(listaAlvo) == FALHA) {
				//! AE: chance falha da interconexao corrente eh FALHA
				listaAlvo->contadorTempoConserto = 0;
				listaAlvo->numeroFalha++;
				listaAlvo->tagFalha = FALHA;
			}else{
				listaAlvo->tagFalha = SEM_FALHA;
			}
		}
		else{
		//! AE: interconexao corrente falhou

			listaAlvo->contadorTempoConserto++;

			if(listaAlvo->contadorTempoConserto >= listaAlvo->tempoConserto){
				//! AE: tempo de conserto foi atingido pelo contador
				listaAlvo->tagFalha = SEM_FALHA;
				listaAlvo->contadorTempoConserto = 0;
			}
		}

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim
}


void zerarInterconexoes(interconexao *listaAlvo){
	Interconexao *conexao;

	for(conexao = listaAlvo ; conexao != NULL ; conexao = conexao->proximo){
		conexao->recursoTransportado = 0;
	}

}
