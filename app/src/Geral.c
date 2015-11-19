#include "../header/Geral.h"
#include <assert.h>

void conecta(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores)
{
	Cidade *auxC = NULL;
	Gerador *auxG = NULL;
	Interconexao *auxI1 = NULL;
	Interconexao *auxI2 = NULL;
	Adaptador *auxA = NULL;

	for(auxI1 = interconexoes; auxI1 != NULL; auxI1 = auxI1->proximo) //Percorre a lista de interconexões
	{
		for(auxI2 = interconexoes; auxI2 != NULL; auxI2 = auxI2->proximo)
		{
			//Caso a posição inicial da interconexão auxI1 coincida com a posição final da interconexão auxI2
			if(auxI1->posicaoInicial[0] == auxI2->posicaoFinal[0] && auxI1->posicaoInicial[1] == auxI2->posicaoFinal[1])
			{
				//Insere-se a interconexão auxI1 como saída da interconexão auxI2
				auxI2->saidaInterconexao = auxI1;
				//Insere-se a interconexão auxI2 como entrada da interconexão auxI1
				auxI1->entradaInterconexao = auxI2;
			}
			//Caso a posição final da interconexão auxI1 coincida com a posição inicial da interconexão auxI2
			if(auxI1->posicaoFinal[0] == auxI2->posicaoInicial[0] && auxI1->posicaoFinal[1] == auxI2->posicaoInicial[1])
			{
				//Insere-se a interconexão auxI2 como saída da interconexão auxI1
				auxI1->saidaInterconexao = auxI2;
				//Insere-se a interconexão auxI1 como entrada da interconexão auxI2
				auxI2->entradaInterconexao = auxI1;
			}
		}
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
	}
}

void verifica(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores)
{
	Cidade *auxC = NULL;
	Gerador *auxG = NULL;
	Interconexao *auxI = NULL;
	Adaptador *auxA = NULL;

	if(cidades != NULL)
	{
		for(auxC = cidades; auxC != NULL; auxC = auxC->proximo) //Percorre a lista de cidades
		{
			if(auxC->entradas == NULL)
				printf("# %s está desconectada!\n",auxC->nome);
		}
	}
	else
		printf("# Não há cidades para serem abastecidas!\n");
	if(geradores != NULL)
	{
		for(auxG = geradores; auxG != NULL; auxG = auxG->proximo) //Percorre a lista de geradores
		{
			if(auxG->saida == NULL)
				printf("# %s está desconectado!\n",auxG->nome);
		}
	}
	else
		printf("# Não há geradores para gerar recursos!\n");
	if(interconexoes != NULL)
	{
		for(auxI = interconexoes; auxI != NULL; auxI = auxI->proximo) //Percorre a lista de
		{
			if(auxI->entradaGerador == NULL && auxI->entradaAdaptador == NULL && auxI->entradaInterconexao)
				printf("# Entrada de %s está desconectada!\n",auxI->nome);
			if(auxI->saidaCidade == NULL && auxI->saidaAdaptador == NULL && auxI->saidaInterconexao)
				printf("# Saída de %s está desconectada!\n",auxI->nome);
		}
	}
	else
		printf("# Não há interconexoes para transportar recursos!\n");
	if(adaptadores != NULL)
	{
		for(auxA = adaptadores; auxA != NULL; auxA = auxA->proximo) //Percorre a lista de
		{
			if(auxA->entradas == NULL)
				printf("# Não há entrada em %s!\n",auxA->nome);
			if(auxA->saidas == NULL)
				printf("# Não há saídas em %s!\n",auxA->nome);
		}
	}
	else
		printf("# Não há interconexoes para transportar recursos!\n");
}