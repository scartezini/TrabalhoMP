#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////
// Funções de Cidade //
///////////////////////

struct cidade
{
	char *nome;
	int posicao[2];
	int recursoNecessario;

	struct interconexao *entradas; //Lista de interconexões de entrada desta cidade

	struct cidade *proximo;
};
typedef struct cidade Cidade;

Cidade* criaListaCidade()
{
	return NULL;
}

Cidade* insereCidade(char *registro, Cidade *listaAlvo)
{
	Cidade *novo = (Cidade *)malloc(sizeof(Cidade)); //Aloca novo elemento da lista de cidades
	char numchar[strlen(registro)]; //String auxiliar para transformar números em caracteres para inteiro usando atoi
	int i,j=0,k=2; //Variáveis de Controle

	for(i=2;registro[i]!=' ';i++); //Calcula o tamanho do campo nome no registro + 2
	novo->nome = (char *)malloc((i-1)*sizeof(char)); //Aloca o tamanho calculado anteriormente -1 para o nome do novo elemento

	for(i=2;j<4;i++) //Percorre o registro caracter por caracter, até todos os 4 campos terem sido percorridos (ATENÇÃO: j!= i)
	{
		if(registro[i] == ' '||registro[i] == '\0') //Caso o caracter encontrado seja separador, ou seja, ' '
		{
			if(j == 0) //Caso o campo recém obtido seja o nome
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1) //Caso o campo recém obtido seja a coordenada x da posição
					novo->posicao[0] = atoi(numchar);
				else if(j == 2) //Caso o campo recém obtido seja a coordenada y da posição
					novo->posicao[1] = atoi(numchar);
				else if(j == 3) //Caso o campo recém obtido seja o recurso Necessario
					novo->recursoNecessario = atoi(numchar);
			}
			k = i+1; //Adapta k  de forma que o campo numérico lido seja inserido na string numchar corretamente
			j++; //Ao incrementar j, significa que leremos o próximo campo do registro
		}
		else //Caso não seja separador
		{
			if(j == 0) //Caso o campo a ser obtido seja um nome
				novo->nome[i-k] = registro[i];
			else //Caso o campo a ser obtido seja algum valor numérico
				numchar[i-k] = registro[i];
		}
	}
	//Insere o novo elemento ao início da lista
	novo->entradas = NULL;
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

int imprimeListaCidade(Cidade *listaAlvo)
{
	Cidade *aux = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux!=NULL;aux=aux->proximo)
			printf("%s %d %d %d\n",aux->nome,aux->posicao[0],aux->posicao[1],aux->recursoNecessario);
		return 1;
	}
	else
		return 0;
}

void liberaListaCidade(Cidade *listaAlvo)
{
	Cidade *aux1 = NULL;
	Cidade *aux2 = NULL;

	if(listaAlvo != NULL)
	{
		for(aux1=listaAlvo;aux1!=NULL;aux1=aux2)
		{
			aux2 = aux1->proximo;
			free(aux1->nome);
			free(aux1);
		}
	}
}

////////////////////////
// Funções de Gerador //
////////////////////////

struct gerador
{
	char *nome;
	int posicao[2];
	int recursoProduzido;
	int custoRecurso;

	struct interconexao *saida; //Aponta para a interconexão cuja entrada é este gerador
	
	struct gerador *proximo;
};
typedef struct gerador Gerador;

Gerador* criaListaGerador()
{
	return NULL;
}

Gerador* insereGerador(char *registro, Gerador *listaAlvo)
{
	Gerador *novo = (Gerador *)malloc(sizeof(Gerador)); //Aloca novo elemento da lista de geradores
	char numchar[strlen(registro)]; //String auxiliar para transformar números em caracteres para inteiro usando atoi
	int i,j=0,k=2; //Variáveis de Controle

	for(i=2;registro[i]!=' ';i++); //Calcula o tamanho do campo nome no registro + 2
	novo->nome = (char *)malloc((i-1)*sizeof(char)); //Aloca o tamanho calculado anteriormente -1 para o nome do novo elemento

	for(i=2;j<5;i++) //Percorre o registro caracter por caracter, até todos os 5 campos terem sido percorridos (ATENÇÃO: j!= i)
	{
		if(registro[i] == ' '||registro[i] == '\0') //Caso o caracter encontrado seja separador, ou seja, ' '
		{
			if(j == 0) //Caso o campo recém obtido seja o nome
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1) //Caso o campo recém obtido seja a coordenada x da posição
					novo->posicao[0] = atoi(numchar);
				else if(j == 2) //Caso o campo recém obtido seja a coordenada y da posição
					novo->posicao[1] = atoi(numchar);
				else if(j == 3) //Caso o campo recém obtido seja o recurso produzido
					novo->recursoProduzido = atoi(numchar);
				else if(j == 4) //Caso o campo recém obtido seja o custo por recurso produzido
					novo->custoRecurso = atoi(numchar);
			}
			k = i+1; //Adapta k  de forma que o campo numérico lido seja inserido na string numchar corretamente
			j++; //Ao incrementar j, significa que leremos o próximo campo do registro
		}
		else //Caso não seja separador
		{
			if(j == 0) //Caso o campo a ser obtido seja um nome
				novo->nome[i-k] = registro[i];
			else //Caso o campo a ser obtido seja algum valor numérico
				numchar[i-k] = registro[i];
		}
	}
	novo->saida = NULL;
	//Insere o novo elemento ao início da lista
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

int imprimeListaGerador(Gerador *listaAlvo)
{
	Gerador *aux = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux!=NULL;aux=aux->proximo)
			printf("%s %d %d %d %d\n",aux->nome,aux->posicao[0],aux->posicao[1],aux->recursoProduzido,aux->custoRecurso);
		return 1;
	}
	else
		return 0;
}

void liberaListaGerador(Gerador *listaAlvo)
{
	Gerador *aux1 = NULL;
	Gerador *aux2 = NULL;

	if(listaAlvo != NULL)
	{
		for(aux1=listaAlvo;aux1!=NULL;aux1=aux2)
		{
			aux2 = aux1->proximo;
			free(aux1->nome);
			free(aux1);
		}
	}
}

//////////////////////////////
// Funções de Interconexoes //
//////////////////////////////

struct interconexao
{
	char *nome;
	int posicaoInicial[2];
	int posicaoFinal[2];
	int capacidadeMax;
	float chanceFalha;
	int tempoConserto;
	int custoConserto;
	
	struct gerador *entradaGerador; //Aponta, caso a entrada seja um gerador, para o gerador cuja saída é esta interconexão
	struct cidade *saidaCidade; //Aponta, caso a saída seja uma cidade, para a cidade cuja entrada é esta interconexão
	struct adaptador *entradaAdaptador; //Aponta, caso a entrada seja um adaptador, para o adaptador cuja saída é esta interconexão
	struct adaptador *saidaAdaptador; //Aponta, caso a saída seja um adaptador, para o adaptador cuja entrada é esta interconexão
	struct interconexao *entradaInterconexao; //Aponta, caso a entrada seja uma interconexão, para a interconexão cuja saída é esta interconexão
	struct interconexao *saidaInterconexao; //Aponta, caso a saída seja uma interconexão, para a interconexão cuja entrada é esta interconexão

	struct interconexao *proximo; //Próximo da lista de interconexões
	struct interconexao *proximoEntradaAdaptador; //Próximo da lista de entradas do adaptador que tem como entrada esta interconexão
	struct interconexao *proximoSaidaAdaptador; //Próximo da lista de saídas do adaptador que tem como saída esta interconexão
	struct interconexao *proximoEntradaCidade; //Próximo da lista de entradas da cidade que tem como entrada esta interconexão
};
typedef struct interconexao Interconexao;

Interconexao* criaListaInterconexao()
{
	return NULL;
}

Interconexao* insereInterconexao(char *registro, Interconexao *listaAlvo)
{
	Interconexao *novo = (Interconexao *)malloc(sizeof(Interconexao)); //Aloca novo elemento da lista de interconexoes
	Interconexao *aux = NULL; //Auxiliar para percorrer lista e inserir novo elemento ao final
	char numchar[strlen(registro)]; //String auxiliar para transformar números em caracteres para inteiro usando atoi ou atof
	int i,j=0,k=2; //Variáveis de Controle

	for(i=2;registro[i]!=' ';i++); //Calcula o tamanho do campo nome no registro + 2
	novo->nome = (char *)malloc((i-1)*sizeof(char)); //Aloca o tamanho calculado anteriormente -1 para o nome do novo elemento

	for(i=2;j<9;i++) //Percorre o registro caracter por caracter, até todos os 9 campos terem sido percorridos (ATENÇÃO: j!= i)
	{
		if(registro[i] == ' '||registro[i] == '\0') //Caso o caracter encontrado seja separador, ou seja, ' '
		{
			if(j == 0) //Caso o campo recém obtido seja o nome
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1) //Caso o campo recém obtido seja a coordenada x da posição inicial
					novo->posicaoInicial[0] = atoi(numchar);
				else if(j == 2) //Caso o campo recém obtido seja a coordenada y da posição inicial
					novo->posicaoInicial[1] = atoi(numchar);
				else if(j == 3) //Caso o campo recém obtido seja a coordenada x da posição final
					novo->posicaoFinal[0] = atoi(numchar);
				else if(j == 4) //Caso o campo recém obtido seja a coordenada y da posição final
					novo->posicaoFinal[1] = atoi(numchar);
				else if(j == 5) //Caso o campo recém obtido seja a capacidade maxima de transporte de recurso
					novo->capacidadeMax = atoi(numchar);
				else if(j == 6) //Caso o campo recém obtido seja a chance de falha da interconexao
					novo->chanceFalha = atof(numchar);
				else if(j == 7) //Caso o campo recém obtido seja o tempo de conserto da interconexao caso falhe
					novo->tempoConserto = atoi(numchar);
				else if(j == 8) //Caso o campo recém obtido seja o custo de conserto da interconexao caso falhe
					novo->custoConserto = atoi(numchar);
			}
			k = i+1; //Adapta k  de forma que o campo numérico lido seja inserido na string numchar corretamente
			j++; //Ao incrementar j, significa que leremos o próximo campo do registro
		}
		else //Caso não seja separador
		{
			if(j == 0) //Caso o campo a ser obtido seja um nome
				novo->nome[i-k] = registro[i];
			else //Caso o campo a ser obtido seja algum valor numérico
				numchar[i-k] = registro[i];
		}
	}
	//Insere o novo elemento ao final da lista
	novo->entradaGerador = NULL;
	novo->entradaAdaptador = NULL;
	novo->saidaCidade = NULL;
	novo->saidaAdaptador = NULL;
	novo->proximo = NULL;
	novo->proximoSaidaAdaptador = NULL;
	novo->proximoEntradaAdaptador = NULL;
	novo->proximoEntradaCidade = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux->proximo!=NULL;aux=aux->proximo);
		aux->proximo = novo;
	}
	else
		listaAlvo = novo;
	
	return listaAlvo;
}

int imprimeListaInterconexao(Interconexao *listaAlvo)
{
	Interconexao *aux = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux!=NULL;aux=aux->proximo)
			printf("%s %d %d %d %d %d %f %d %d\n",aux->nome,aux->posicaoInicial[0],aux->posicaoInicial[1],aux->posicaoFinal[0],aux->posicaoFinal[1],aux->capacidadeMax,aux->chanceFalha,aux->tempoConserto,aux->custoConserto);
		return 1;
	}
	else
		return 0;
}

void liberaListaInterconexao(Interconexao *listaAlvo)
{
	Interconexao *aux1 = NULL;
	Interconexao *aux2 = NULL;

	if(listaAlvo != NULL)
	{
		for(aux1=listaAlvo;aux1!=NULL;aux1=aux2)
		{
			aux2 = aux1->proximo;
			free(aux1->nome);
			free(aux1);
		}
	}
}


//////////////////////////
// Funções de Adaptador //
//////////////////////////

struct adaptador
{
	char *nome;
	int posicao[2];

	struct interconexao *entradas; //Lista de interconexões de entrada deste adaptador
	struct interconexao *saidas; //Lista de interconexões de saída deste adaptador

	struct adaptador *proximo;
};
typedef struct adaptador Adaptador;

Adaptador* criaListaAdaptador()
{
	return NULL;
}

Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo)
{
	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador)); //Aloca novo elemento da lista de adaptadores
	char numchar[strlen(registro)]; //String auxiliar para transformar números em caracteres para inteiro usando atoi ou atof
	int i,j=0,k=2; //Variáveis de Controle

	for(i=2;registro[i]!=' ';i++); //Calcula o tamanho do campo nome no registro + 2
	novo->nome = (char *)malloc((i-1)*sizeof(char)); //Aloca o tamanho calculado anteriormente -1 para o nome do novo elemento

	for(i=2;j<3;i++) //Percorre o registro caracter por caracter, até todos os 3 campos terem sido percorridos (ATENÇÃO: j!= i)
	{
		if(registro[i] == ' '||registro[i] == '\0') //Caso o caracter encontrado seja separador, ou seja, ' '
		{
			if(j == 0) //Caso o campo recém obtido seja o nome
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1) //Caso o campo recém obtido seja a coordenada x da posição
					novo->posicao[0] = atoi(numchar);
				else if(j == 2) //Caso o campo recém obtido seja a coordenada i da posição
					novo->posicao[1] = atoi(numchar);
			}
			k = i+1; //Adapta k  de forma que o campo numérico lido seja inserido na string numchar corretamente
			j++; //Ao incrementar j, significa que leremos o próximo campo do registro
		}
		else
		{
			if(j == 0) //Caso o campo a ser obtido seja um nome
				novo->nome[i-k] = registro[i];
			else //Caso o campo a ser obtido seja algum valor numérico
				numchar[i-k] = registro[i];
		}
	}
	novo->entradas = NULL;
	novo->saidas = NULL;
	//Insere o novo elemento ao início da lista
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

int imprimeListaAdaptador(Adaptador *listaAlvo)
{
	Adaptador *aux = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux!=NULL;aux=aux->proximo)
			printf("%s %d %d\n",aux->nome,aux->posicao[0],aux->posicao[1]);
		return 1;
	}
	else
		return 0;
}

void liberaListaAdaptador(Adaptador *listaAlvo)
{
	Adaptador *aux1 = NULL;
	Adaptador *aux2 = NULL;

	if(listaAlvo != NULL)
	{
		for(aux1=listaAlvo;aux1!=NULL;aux1=aux2)
		{
			aux2 = aux1->proximo;
			free(aux1->nome);
			free(aux1);
		}
	}
}

////////////////////
// Funções Gerais //
////////////////////

void conecta(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores)
{
	Cidade *auxC = NULL;
	Gerador *auxG = NULL;
	Interconexao *auxI1 = NULL;
	Interconexao *auxI2 = NULL;
	Adaptador *auxA = NULL;

	for(auxI1 = interconexoes; auxI1 != NULL; auxI1 = auxI1->proximo) //Percorre a lista de interconexões
	{
		for(auxA = adaptadores; auxA != NULL; auxA = auxA->proximo) //Percorre a lista de adaptadores
		{
			//Caso a posição inicial da interconexão apontada por auxI1 coincida com a posição do adaptador apontado por auxA
			if(auxI1->posicaoInicial[0] == auxA->posicao[0] && auxI1->posicaoInicial[1] == auxA->posicao[1])
			{
				//Insere-se o adaptador como entrada da interconexão
				auxI1->entradaAdaptador = auxA;
				//Insere-se a interconexão na lista de saídas do adaptador
				auxI1->proximoSaidaAdaptador = auxA->saidas;
				auxA->saidas = auxI1;
			}
			//Caso a posição final da interconexão apontada por auxI1 coincida com a posição do adaptador apontado por auxA
			if(auxI1->posicaoFinal[0] == auxA->posicao[0] && auxI1->posicaoFinal[1] == auxA->posicao[1])
			{
				//Insere-se o adaptador como saída da interconexão
				auxI1->saidaAdaptador = auxA;
				//Insere-se a interconexão na lista de entradas do adaptador
				auxI1->proximoEntradaAdaptador = auxA->entradas;
				auxA->entradas = auxI1;
			}
		}
		for(auxG = geradores; auxG != NULL; auxG = auxG->proximo) //Percorre a lista de geradores
		{
			//Caso a posição inicial da interconexão apontada por auxI1 coincida com a posição do gerador apontado por auxG
			if(auxI1->posicaoInicial[0] == auxG->posicao[0] && auxI1->posicaoInicial[1] == auxG->posicao[1])
			{
				//Insere-se a interconexão como saída do gerador
				auxG->saida = auxI1;
				//Insere-se o gerador como entrada da interconexão
				auxI1->entradaGerador = auxG;
			}
		}
		for(auxC = cidades; auxC != NULL; auxC = auxC->proximo) //Percorre a lista de cidades
		{
			//Caso a posição final da interconexão apontada por auxI coincida com a posição da cidade apontado por auxC
			if(auxI1->posicaoFinal[0] == auxC->posicao[0] && auxI1->posicaoFinal[1] == auxC->posicao[1])
			{
				//Insere-se a cidade como saída da interconexão
				auxI1->saidaCidade = auxC;
				//Insere-se a interconexão na lista de entradas da cidade
				auxI1->proximoEntradaCidade = auxC->entradas;
				auxC->entradas = auxI1;
			}
		}
		for(auxI2 = interconexoes; auxI2 != NULL; auxI2 = auxI2->proximo)
		{
			printf("aixI1: %s e auxI2: %s\n",auxI1->nome,auxI2->nome);
			//Caso a posição inicial da interconexão auxI1 coincida com a posição final da interconexão auxI2
			if(auxI1->entradaGerador == NULL && auxI1->entradaAdaptador == NULL && auxI1->entradaInterconexao == NULL && auxI2->saidaCidade == NULL && auxI2->saidaAdaptador == NULL && auxI2->saidaInterconexao == NULL && auxI1->posicaoInicial[0] == auxI2->posicaoFinal[0] && auxI1->posicaoInicial[1] == auxI2->posicaoFinal[1])
			{
				printf("TESTE1.1\n");
				//Insere-se a interconexão auxI1 como saída da interconexão auxI2
				auxI2->saidaInterconexao = auxI1;
				//Insere-se a interconexão auxI2 como entrada da interconexão auxI1
				auxI1->entradaInterconexao = auxI2;
			}
			//Caso a posição final da interconexão auxI1 coincida com a posição inicial da interconexão auxI2
			if(auxI2->entradaGerador == NULL && auxI2->entradaAdaptador == NULL && auxI2->entradaInterconexao == NULL && auxI1->saidaCidade == NULL && auxI1->saidaAdaptador == NULL && auxI1->saidaInterconexao == NULL && auxI1->posicaoFinal[0] == auxI2->posicaoInicial[0] && auxI1->posicaoFinal[1] == auxI2->posicaoInicial[1])
			{
				printf("TESTE1.2\n");
				//Insere-se a interconexão auxI2 como saída da interconexão auxI1
				auxI1->saidaInterconexao = auxI2;
				//Insere-se a interconexão auxI1 como entrada da interconexão auxI2
				auxI2->entradaInterconexao = auxI1;
			}
		}
	}
}

void verifica(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores)
{
	FILE *fp = fopen("ProblemasDeConsistenciaDosElementos.txt","w");
	Cidade *auxC = NULL;
	Gerador *auxG = NULL;
	Interconexao *auxI = NULL;
	Adaptador *auxA = NULL;

	fprintf(fp,"CIDADAES:\n");
	if(cidades != NULL)
	{
		for(auxC = cidades; auxC != NULL; auxC = auxC->proximo) //Percorre a lista de cidades
		{
			if(auxC->entradas == NULL)
				fprintf(fp,"# %s está desconectada!\n",auxC->nome);
		}
	}
	else
		fprintf(fp,"# Não há cidades para serem abastecidas!\n");
	fprintf(fp,"\nGERADORES:\n");
	if(geradores != NULL)
	{
		for(auxG = geradores; auxG != NULL; auxG = auxG->proximo) //Percorre a lista de geradores
		{
			if(auxG->saida == NULL)
				fprintf(fp,"# %s está desconectado!\n",auxG->nome);
		}
	}
	else
		fprintf(fp,"# Não há geradores para gerar recursos!\n");
	fprintf(fp,"\nINTERCONEXÕES:\n");
	if(interconexoes != NULL)
	{
		for(auxI = interconexoes; auxI != NULL; auxI = auxI->proximo) //Percorre a lista de interconexões
		{
			if(auxI->entradaGerador == NULL && auxI->entradaAdaptador == NULL && auxI->entradaInterconexao == NULL)
				fprintf(fp,"# Entrada de %s está desconectada!\n",auxI->nome);
			if(auxI->saidaCidade == NULL && auxI->saidaAdaptador == NULL && auxI->saidaInterconexao == NULL)
				fprintf(fp,"# Saída de %s está desconectada!\n",auxI->nome);
		}
	}
	else
		fprintf(fp,"# Não há interconexoes para transportar recursos!\n");
	fprintf(fp,"\nADAPTADORES:\n");
	if(adaptadores != NULL)
	{
		for(auxA = adaptadores; auxA != NULL; auxA = auxA->proximo) //Percorre a lista de adaptadores
		{
			if(auxA->entradas == NULL)
				fprintf(fp,"# Não há entrada em %s!\n",auxA->nome);
			if(auxA->saidas == NULL)
				fprintf(fp,"# Não há saídas em %s!\n",auxA->nome);
		}
	}
	else
		fprintf(fp,"# Não há adaptadores para distribuir recursos!\n");

	fclose(fp);
}

////////////////////////
// Programa Principal //
////////////////////////

int main()
{
	FILE *fp = fopen("test/teste.txt","r"); //Abre arquivo de entrada
	Cidade *listaCidades = criaListaCidade();
	Gerador *listaGeradores = criaListaGerador();
	Interconexao *listaInterconexoes = criaListaInterconexao();
	Adaptador *listaAdaptadores = criaListaAdaptador();
	char str[100]; //String auxiliar para obter registros
	
	do //Percorre o arquivo de entrada
	{
		if(fgets(str,100,fp)!=NULL) //Obtem uma linha(um registro) do arquivo de entrada, verificando se o arquivo chegou ao fim
		{
			if(str[0] == 'C') //Caso o registro obtido seja do tipo Cidade
				listaCidades = insereCidade(str,listaCidades);
			else if(str[0] == 'G') //Caso o registro obtido seja do tipo Gerador
				listaGeradores = insereGerador(str,listaGeradores);
			else if(str[0] == 'I') //Caso o registro obtido seja do tipo Interconexão
				listaInterconexoes = insereInterconexao(str,listaInterconexoes);
			else if(str[0] == 'A') //Caso o registro obtido seja do tipo Adaptador
				listaAdaptadores = insereAdaptador(str,listaAdaptadores);
		}
	}
	while(!feof(fp));

	fclose(fp);
	
	//Imprime listas obtidas
	printf("\nlistaCidades:\n");imprimeListaCidade(listaCidades);
	printf("\nlistaGeradores:\n");imprimeListaGerador(listaGeradores);
	printf("\nlistaInterconexoes:\n");imprimeListaInterconexao(listaInterconexoes);
	printf("\nlistaAdaptadores:\n");imprimeListaAdaptador(listaAdaptadores);
	
	conecta(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);
	printf("\n\n");
	verifica(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);

	//Desaloca listas obtidas
	liberaListaCidade(listaCidades);
	liberaListaGerador(listaGeradores);
	liberaListaInterconexao(listaInterconexoes);
	liberaListaAdaptador(listaAdaptadores);

	getchar();
	return 0;
}
