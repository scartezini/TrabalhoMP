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

	for(i=2;j<4;i++) //Percorre o registro caracter por caracter, até todos os 4 registros terem sido percorridos (ATENÇÃO: j!= i)
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
	struct interconexao *saida;
	
	struct gerador *proximo;
};
typedef struct gerador Gerador;

Gerador* criaListaGerador()
{
	return NULL;
}

Gerador* insereGerador(char *registro, Gerador *listaAlvo)
{
	Gerador *novo = (Gerador *)malloc(sizeof(Gerador));
	char numchar[strlen(registro)];
	int i,j=0,k=2;

	for(i=2;registro[i]!=' ';i++);
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<5;i++)
	{
		if(registro[i] == ' '||registro[i] == '\0')
		{
			if(j == 0)
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1)
					novo->posicao[0] = atoi(numchar);
				else if(j == 2)
					novo->posicao[1] = atoi(numchar);
				else if(j == 3)
					novo->recursoProduzido = atoi(numchar);
				else if(j == 4)
					novo->custoRecurso = atoi(numchar);
			}
			k = i+1;
			j++;
		}
		else
		{
			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numchar[i-k] = registro[i];
		}
	}
	novo->saida = NULL;
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
	struct cidade *cidadeAlvo;
	struct adaptador *adaptadorAlvo;

	struct interconexao *proximo;
};
typedef struct interconexao Interconexao;

Interconexao* criaListaInterconexao()
{
	return NULL;
}

Interconexao* insereInterconexao(char *registro, Interconexao *listaAlvo)
{
	Interconexao *novo = (Interconexao *)malloc(sizeof(Interconexao));
	Interconexao *aux = NULL;
	char numchar[strlen(registro)];
	int i,j=0,k=2;

	for(i=2;registro[i]!=' ';i++);
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<9;i++)
	{
		if(registro[i] == ' '||registro[i] == '\0')
		{
			if(j == 0)
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1)
					novo->posicaoInicial[0] = atoi(numchar);
				else if(j == 2)
					novo->posicaoInicial[1] = atoi(numchar);
				else if(j == 3)
					novo->posicaoFinal[0] = atoi(numchar);
				else if(j == 4)
					novo->posicaoFinal[1] = atoi(numchar);
				else if(j == 5)
					novo->capacidadeMax = atoi(numchar);
				else if(j == 6)
					novo->chanceFalha = atof(numchar);
				else if(j == 7)
					novo->tempoConserto = atoi(numchar);
				else if(j == 8)
					novo->custoConserto = atoi(numchar);
			}
			k = i+1;
			j++;
		}
		else
		{
			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numchar[i-k] = registro[i];
		}
	}
	novo->cidadeAlvo = NULL;
	novo->adaptadorAlvo = NULL;
	//Insere o novo elemento ao final da lista
	novo->proximo = NULL;
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
	struct interconexoes **saidas;

	struct adaptador *proximo;
};
typedef struct adaptador Adaptador;

Adaptador* criaListaAdaptador()
{
	return NULL;
}

Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo)
{
	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador));
	char numchar[strlen(registro)];
	int i,j=0,k=2;

	for(i=2;registro[i]!=' ';i++);
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<3;i++)
	{
		if(registro[i] == ' '||registro[i] == '\0')
		{
			if(j == 0)
				novo->nome[i-k] = '\0';
			else
			{
				numchar[i-k] = '\0';
				if(j == 1)
					novo->posicao[0] = atoi(numchar);
				else if(j == 2)
					novo->posicao[1] = atoi(numchar);
			}
			k = i+1;
			j++;
		}
		else
		{
			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numchar[i-k] = registro[i];
		}
	}
	novo->saidas = NULL;
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

////////////////////////
// Programa Principal //
////////////////////////

int main()
{
	FILE *fp = fopen("teste.txt","r"); //Abre arquivo de entrada
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

	//Desaloca listas obtidas
	liberaListaCidade(listaCidades);
	liberaListaGerador(listaGeradores);
	liberaListaInterconexao(listaInterconexoes);
	liberaListaAdaptador(listaAdaptadores);

	getchar();
	return 0;
}
