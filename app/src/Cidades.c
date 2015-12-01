#include "../header/Cidades.h"
#include <assert.h>

/**
*	Funcao: criaListaCidade (Iterador)
*
*	AssertivaSaida:
*		NULL;
*
*	Requisitos:
*		criacao de uma nova lista do tipo Cidade
*
*	Interfaces explicitas:
*		Cidade*, criaListaCidade
**/
Cidade* criaListaCidade(){
	return NULL;
}

/**
*	Funcao: cidadeVazia (Iterador)
*
*	AssertivaSaida:
*		VAZIA || NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		checar se a lista está vazia
*
*	Interfaces explicitas:
*		Vazia, cidadeVazia, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		Vazia - tipo de dado, indicando se a lista eh vazia ou nao
*		listaAlvo - lista de cidades
**/
Vazia cidadeVazia(Cidade *listaAlvo){
	if(listaAlvo == NULL)
	//! AE: listaAlvo eh vazia
		return VAZIA;
	else
	//! AE: listaAlvo nao eh vazia
		return NAO_VAZIA;
	//! AS: o retorno deve ser uma variavel do tipo Vazia
}

/**
*	Funcao: insereCidade
*
*	AssertivaEntrada:
*		registro != NULL;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Cidade
*		registro - string, nao vazia, contendo uma linha do arquivo txt de entrada
*
*	Requisitos:
*		inserir uma nova cidade na lista de cidades
*
*	Interfaces explicitas:
*		Cidade*, insereCidade, char *registro, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		registro - representa uma linha do arquivo de entrada
*		listaAlvo - lista de cidades
**/
Cidade* insereCidade(char *registro, Cidade *listaAlvo){
	assert(registro != NULL);

	Cidade *novo = (Cidade *)malloc(sizeof(Cidade)); //!< Alocacao da nova cidade
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

	//! Asseriva estrutural: o nome da nova cidade possui tamanho i-1
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<=3;i++){
	//! AE: o valor da variavel auxiliar j deve ser menor ou igual ao numero total de atributos lidos da cidade

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
					novo->posicao[0] = atoi(numChar);
				else if(j == 2)
					novo->posicao[1] = atoi(numChar);
				else if(j == 3)
					novo->recursoNecessario = atoi(numChar);
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
				*	 (posicao corrente-k) do nome da cidade
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
	//! AS: o valor da variavel auxiliar j ultrapassou o numero total de atributos lidos da cidade

	//! Comentarios de argumentacao
		/**
		*	Os atributos nao lidos da cidade inserida recebem o valor nulo, e a proxima cidade
		* da lista que contem a nova cidade inserido na cabeca recebe a lista de cidades atual
		**/
	novo->recursoRecebido = 0;
	novo->recursoGasto = 0;
	novo->entradas = NULL;
	novo->tagEstado = VERDE;
	novo->turnosNegativados = 0;
	novo->turnosNoVermelho = 0;

	novo->proximo = listaAlvo;
	listaAlvo = novo;

	free(numChar);
	return listaAlvo;
}

/**
*	Funcao: imprimeListaCidade (Iterador)
*
*	AssertivaEntrada:
*		cidadeVazia(listaAlvo) == NAO_VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		impressao da lista de cidades
*
*	Interfaces explicitas:
*		void, imprimeListaCidade, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
void imprimeListaCidade(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *aux = NULL;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	for(aux=listaAlvo;aux!=NULL;aux=aux->proximo){
	//! AE: listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Imprime os atributos da cidade corrente
		**/
		printf(" - nome: %s | pos_x: %d | pos_y: %d | recurso necessario: %d | recurso recebido: %d | recurso gasto: %d\n"
				,aux->nome,aux->posicao[0]
				,aux->posicao[1],aux->recursoNecessario,aux->recursoRecebido
				,aux->recursoGasto);
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: liberaListaCidade (Iterador)
*
*	AssertivaEntrada:
*		cidadeVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		cidadeVazia(aux1) == VAZIA;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		liberacao da lista de cidades
*
*	Interfaces explicitas:
*		void, liberaListaCidade, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
void liberaListaCidade(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *aux1 = NULL;
	Cidade *aux2 = NULL;

	//! Asseriva estrutural: aux1 é a listaAlvo, porem sendo percorrida
	for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
	//! AE: listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Liberam os atributos alocados dinamicamente do elemento Cidade corrente
		**/
		aux2 = aux1->proximo;
		free(aux1->nome);
		free(aux1);
	}
	//! AS: listaAlvo chegou ao fim

	assert(cidadeVazia(aux1) == VAZIA);
}

/**
*	Funcao: recursoGastoTotal
*
*	AssertivaEntrada:
*		cidadeVazia(listaAlvo) == NAO_VAZIA;
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipotese:
*		cidade - ponteiro para o inicio da lista de cidades
*
*	Requisitos:
*		Somar os recursos gatos por todas as cidades
*
*	Interfaces explicitas:
*		int, recursoGastoTotal, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int recursoGastoTotal(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Cidade *aux = listaAlvo;

	while(aux != NULL){
	//! AE: lista nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Incrementa o somatorio com o valor do recurso gasto pela celula atual
		*	muda a referencia de cidade para a proxima celula
		**/
		total += aux->recursoGasto;
		aux = aux->proximo;
	}
	//! AS: lista chegou ao fim

	assert(total >= 0);

	return total;
}

/**
*	Funcao: numeroCidades (Iterador)
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para uma lista do tipo Cidade
*
*	Requisitos:
*		conta o numero total de cidades em uma lista de cidades
*
*	Interfaces explicitas:
*		int, numeroCidades, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int numeroCidades(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
	int total = 0;

	//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
	Cidade *aux = listaAlvo;

	while(aux != NULL){
	//! AE: listaAlvo nao chegou ao fim

	//! Comentarios de argumentacao
		/**
		*	Contagem do numero de total de cidades na listaAlvo
		**/
		total++;
		aux = aux->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;
}

/**
*	Funcao: gerenciaRecursoRecebido
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Cidade
*
*	Requisitos:
*		gerencia o recurso recebido, aterando o valor do recurso gasto
*
*	Interfaces explicitas:
*		int, gerenciaRecursoRecebido, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
void gerenciaRecursoRecebido(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *cidade;
	float porcentagemRecursoNecessario;
	float acumulador;

	while (listaAlvo != NULL) {
	//! AE: listaAlvo nao chegou ao fim

		//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
		cidade = listaAlvo;

		acumulador = (float) cidade->recursoRecebido;
		cidade->recursoGasto += cidade->recursoRecebido;
		porcentagemRecursoNecessario = (acumulador / cidade->recursoNecessario)*100;


		if(porcentagemRecursoNecessario >= 100){
		//! AE: a porcentagem do recurso Necessario eh positiva
			cidade->tagEstado = VERDE;
		}
		else if(porcentagemRecursoNecessario < 100 && porcentagemRecursoNecessario >= 30){
		//! AE: a porcentagem eh negativa mas nao critica
			cidade->tagEstado = AMARELO;
			cidade->turnosNegativados += 1;
		}
		else{
		//! AE: a porcentagem eh critica
			cidade->tagEstado = VERMELHO;
			cidade->turnosNegativados += 1;
			cidade->turnosNoVermelho += 1;
		}

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim
}

/**
*	Funcao: numeroCidadesNegativadas
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Cidade
*
*	Requisitos:
*		contabilizar quantas cidades tiveram seus recursos abaixo do
* necessario
*
*	Interfaces explicitas:
*		int, numeroCidadesNegativadas, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int numeroCidadesNegativadas(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *cidade;
	int total = 0;

	while (listaAlvo != NULL) {
	//! AE: listaAlvo nao chegou ao fim

		//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
		cidade = listaAlvo;

		if(cidade->turnosNegativados > 0){
		//! AE: teve algum turno negativado
			total++;
		}

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;
}

/**
*	Funcao: tempoSemRecursoNecessario
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Cidade
*
*	Requisitos:
*		contabilizar a soma dos tempos que as cidades ficaram sem
* recurso
*
*	Interfaces explicitas:
*		int, tempoSemRecursoNecessario, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int tempoSemRecursoNecessario(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *cidade;
	int total = 0;

	while(listaAlvo != NULL){
	//! AE: listaAlvo nao chegou ao fim

		//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
		cidade = listaAlvo;

		total += cidade->turnosNegativados;

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;
}

/**
*	Funcao: numeroCidadesNoVermelho
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Cidade
*
*	Requisitos:
*		contabilizar quantas cidades tiveram seus recursos abaixo
* de 30% do necessario
*
*	Interfaces explicitas:
*		int, numeroCidades, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int numeroCidadesNoVermelho(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *cidade;
	int total = 0;

	while (listaAlvo != NULL) {
	//! AE: listaAlvo nao chegou ao fim

		//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
		cidade = listaAlvo;

		if(cidade->turnosNoVermelho > 0){
		//! AE: teve algum turno no vermelho
			total++;
		}

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;

}

/**
*	Funcao: tempoSemRecursoNecessario
*
*	AssertivaEntrada:
*		assert(cidadeVazia(listaAlvo) == NAO_VAZIA);
*
*	AssertivaSaida:
*		total >= 0;
*
*	Hipóteses:
*		listaAlvo - ponteiro para o inicio da lista do tipo Cidade
*
*	Requisitos:
*		contabilizar a soma dos tempos que as cidades ficaram com
* menos de 30% do recurso necessario
*
*	Interfaces explicitas:
*		int, tempoSemRecursoNecessario, Cidade *listaAlvo
*
*	Interfaces implicitas:
*		listaAlvo - lista de cidades
**/
int tempoCidadesNoVermelho(Cidade *listaAlvo){
	assert(cidadeVazia(listaAlvo) == NAO_VAZIA);

	Cidade *cidade;
	int total = 0;

	while(listaAlvo != NULL){
	//! AE: listaAlvo nao chegou ao fim

		//! Asseriva estrutural: aux é a listaAlvo, porem sendo percorrida
		cidade = listaAlvo;

		total += cidade->turnosNoVermelho;

		listaAlvo = listaAlvo->proximo;
	}
	//! AS: listaAlvo chegou ao fim

	assert(total >= 0);

	return total;
}


void zerarCidades(Cidade *listaAlvo){

	Cidade *cidade;

	for(cidade = listaAlvo ; cidade != NULL ; cidade = cidade->proximo){
		cidade->recursoRecebido = 0;
	}

}
