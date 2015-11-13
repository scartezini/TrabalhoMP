#include "Cidades.h"

<<<<<<< HEAD

/*
*
*
*/

=======
>>>>>>> refs/remotes/origin/lucas
Cidade* criaListaCidade(){
	return NULL;
}

Cidade* insereCidade(char *registro, Cidade *listaAlvo){
	Cidade *novo = (Cidade *)malloc(sizeof(Cidade)); 
	char *numchar = (char) malloc (strlen(registro)*sizeof(char)); 
	int i,j=0,k=2; 

	for(i=2;registro[i]!=' ';i++); 
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<4;i++) 
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
					novo->recursoNecessario = atoi(numchar);
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
	
	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}

int imprimeListaCidade(Cidade *listaAlvo){
	Cidade *aux = NULL;
	if(listaAlvo != NULL)
	{
		for(aux=listaAlvo;aux!=NULL;aux=aux->proximo)
			printf("nome: %s pos_x: %d pos_y: %d recurso necessario%d\n"
					,aux->nome,aux->posicao[0]
					,aux->posicao[1],aux->recursoNecessario);
					
		return 1;
	}
	else
		return 0;
}

void liberaListaCidade(Cidade *listaAlvo){
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