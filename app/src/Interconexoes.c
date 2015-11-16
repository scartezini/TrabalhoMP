#include "../header/Interconexoes.h"
#include <assert.h>

/** -----------------------Funcoes Basicas---------------------------- */

/**
*	Funcao: criaListaInterconexao
*
*	AssertivaSaida:
*		NULL; 
**/
Interconexao* criaListaInterconexao(){
	return NULL;
}

/**
*	Funcao: interconexaoVazia
*
*	AssertivaSaida:
*		VAZIA || NAO_VAZIA; 
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
**/
Interconexao* insereInterconexao(char *registro, Interconexao *listaAlvo){
	assert(registro != NULL);
	
	Interconexao *novo = (Interconexao *)malloc(sizeof(Interconexao)); //!< Alocacao da nova Interconexao
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
					novo->posicaoInicial[0] = atoi(numChar);
				else if(j == 4) 
					novo->posicaoInicial[1] = atoi(numChar);
				else if(j == 5) 
					novo->capacidadeMaxima = atoi(numChar);
				else if(j == 6)
					novo->chanceFalha = atoi(numChar);
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
	novo->numeroFalha = 0;
	novo->tagFalha = SEM_FALHA;
	novo->capacidadeMaxima = 0;
	novo->recursoTransportado = 0;
	
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

/**
*	Funcao: imprimeListaInterconexao
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*		
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
		printf("nome: %s posI_x: %d posI_y: %d posF_x: %d posF_y: %d tag destino%d chance falha%f tempo concerto%d custo concerto%d numero falha%d tag falha: %d capacidade maxima%d recurso transportado%d\n"
				,aux->nome,aux->posicaoInicial[0],aux->posicaoInicial[1],aux->posicaoFinal[0],aux->posicaoFinal[1]
				,aux->tagDestino, aux->chanceFalha, aux->tempoConserto, aux->custoConserto, aux->numeroFalha
				,aux->tagFalha, aux->capacidadeMaxima, aux->recursoTransportado);
	}
	//! AS: listaAlvo chegou ao fim		
}

/**
*	Funcao: liberaListaInterconexao
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		interconexaoVazia(listaAlvo) == VAZIA;
*		
**/
void liberaListaInterconexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	Interconexao *aux1 = NULL;
	Interconexao *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
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

	assert(interconexaoVazia(listaAlvo) == VAZIA);
}

/** -----------------------Funcoes de Calculo---------------------------- */

/**
*	Funcao: tamanhoConexao
*
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA; 
*
*	AssertivaSaida:
*		distancia > 0; 
**/
float tamanhoConexao(Interconexao *listaAlvo){
	assert(interconexaoVazia(listaAlvo) == NAO_VAZIA);

	int xA; //!< Valor no eixo x da posicao inicial 
	int yA; //!< Valor no eixo y da posicao inicial 
	
	int xB; //!< Valor no eixo x da posicao final
	int yB; //!< Valor no eixo y da posicao final

	int distancia;
	
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
*	AssertivaSaida:
*		FALHA || SEM_FALHA; 
**/
Falha calculaFalha(){
	float num;
	float chance = 0.01;

	//! Asseriva estrutural: num eh um numero gerado aleatoriamente
	srand(1); 
	num = ((float)rand())/RAND_MAX;

	if ( (chance > 0) && (chance >= num) ) 
	//! AE: chance deve ser maior que 0 e maior ou igual a num 
		return FALHA;
	else
	//! AE: chance deve ser menor que 0 ou menor que num 
		return SEM_FALHA;
	//! AS: o retorno deve ser uma variavel do tipo Falha 
}

/**
*
*	Funcao: mandarRecursoTransportado
*	
*	AssertivaEntrada:
*		interconexaoVazia(listaAlvo) == NAO_VAZIA;
*
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
				aux->adaptador->recursoRecebido += recursoEnviado;
			}
			else if(aux->tagDestino == CIDADE){
			//! AE: o destino da interconexao eh uma Cidade
				aux->cidade->recursoRecebido += recursoEnviado;
			}
		}

		aux = aux->proximo;
	}
	//! AS: a lista de interconexoes chegou ao fim
}