#include "../header/Geral.h"
#include <assert.h>

/**
*	Funcao: conecta
*
*	AssertivaEntrada:
*
*	AssertivaSaida:
**/
void conecta(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores){
	Cidade *auxC = NULL; //!< Ponteiro auxiliar para cidade
	Gerador *auxG = NULL; //!< Ponteiro auxiliar para gerador
	Interconexao *auxI1 = NULL; //!< Ponteiro auxiliar para interconexao
	Interconexao *auxI2 = NULL; //!< Ponteiro auxiliar para interconexao
	Adaptador *auxA = NULL; //!< Ponteiro auxiliar para adaptador

	for(auxI1 = interconexoes; auxI1 != NULL; auxI1 = auxI1->proximo){
	//! AE: o auxI1 ainda nao chegou ao fim da lista de interconexoes
	
		for(auxA = adaptadores; auxA != NULL; auxA = auxA->proximo){
		//! AE: o auxA ainda nao chegou ao fim da lista de adaptadores
		
			if(auxI1->posicaoInicial[0] == auxA->posicao[0] && auxI1->posicaoInicial[1] == auxA->posicao[1]){
			//! AE: a posicao inicial da interconexao apontada por auxI1 coincide com a posicao do adaptador apontado por auxA
				
				//! Comentarios de argumentacao
					/**
					*	insere-se o adaptador como entrada da interconexao
					*	insere-se a interconexao na lista de saidas do adaptador
					**/
				auxI1->entradaAdaptador = auxA;
				
				auxI1->proximoSaidaAdaptador = auxA->saidas;
				auxA->saidas = auxI1;
			}

			if(auxI1->posicaoFinal[0] == auxA->posicao[0] && auxI1->posicaoFinal[1] == auxA->posicao[1]){
			//! AE: a posicao final da interconexao apontada por auxI1 coincide com a posicao do adaptador apontado por auxA
			
				//! Comentarios de argumentacao
					/**
					*	insere-se o adaptador como saida da interconexao
					*	insere-se a interconexao na lista de entradas do adaptador
					**/
				auxI1->saidaAdaptador = auxA;

				auxI1->proximoEntradaAdaptador = auxA->entradas;
				auxA->entradas = auxI1;
			}
		}
		//! AS: o auxA chegou ao fim da lista de adaptadores
		
		for(auxG = geradores; auxG != NULL; auxG = auxG->proximo){
		//! AE: o auxG ainda nao chegou ao fim da lista de geradores
		
			if(auxI1->posicaoInicial[0] == auxG->posicao[0] && auxI1->posicaoInicial[1] == auxG->posicao[1]){
			//! AE: a posicao inicial da interconexao apontada por auxI1 coincide com a posicao do gerador apontado por auxG

				//! Comentarios de argumentacao
					/**
					*	insere-se a interconexao como saida do gerador
					*	insere-se o gerador como entrada da interconexao
					**/
				auxG->saida = auxI1;

				auxI1->entradaGerador = auxG;
			}
		}
		//! AS: o auxG chegou ao fim da lista de geradores
		
		for(auxC = cidades; auxC != NULL; auxC = auxC->proximo){
		//! AE: o auxC ainda nao chegou ao fim da lista de cidades
		
			if(auxI1->posicaoFinal[0] == auxC->posicao[0] && auxI1->posicaoFinal[1] == auxC->posicao[1]){
			//! AE: a posicao final da interconexao apontada por auxI1 coincide com a posicao da cidade apontado por auxC

				//! Comentarios de argumentacao
					/**
					*	insere-se a cidade como saida da lista de interconexao
					*	insere-se a interconexao na lista de entradas da cidade
					**/
				auxI1->saidaCidade = auxC;
				
				auxI1->proximoEntradaCidade = auxC->entradas;
				auxC->entradas = auxI1;
			}
		}
		//! AS: o auxG chegou ao fim da lista de geradores
		
		for(auxI2 = interconexoes; auxI2 != NULL; auxI2 = auxI2->proximo){
		//! AE: o auxI2 ainda nao chegou ao fim da lista de interconexoes
		
			if(auxI1->entradaGerador == NULL && auxI1->entradaAdaptador == NULL && auxI1->entradaInterconexao == NULL && auxI2->saidaCidade == NULL && auxI2->saidaAdaptador == NULL && auxI2->saidaInterconexao == NULL && auxI1->posicaoInicial[0] == auxI2->posicaoFinal[0] && auxI1->posicaoInicial[1] == auxI2->posicaoFinal[1]){
			//! AE: a posicao inicial da interconexao apontada por auxI1 coincide com a posicao final da interconexao apontada por auxI2
			
				//! Comentarios de argumentacao
					/**
					*	insere-se a interconexao auxI1 como saida da interconexao auxI2
					*	insere-se a interconexao auxI2 como entrada da interconexao auxI1
					**/
				auxI2->saidaInterconexao = auxI1;

				auxI1->entradaInterconexao = auxI2;
			}

			if(auxI2->entradaGerador == NULL && auxI2->entradaAdaptador == NULL && auxI2->entradaInterconexao == NULL && auxI1->saidaCidade == NULL && auxI1->saidaAdaptador == NULL && auxI1->saidaInterconexao == NULL && auxI1->posicaoFinal[0] == auxI2->posicaoInicial[0] && auxI1->posicaoFinal[1] == auxI2->posicaoInicial[1]){
			//! AE: a posicao final da interconexao apontada por auxI1 coincide com a posicao inicial da interconexao apontada por auxI2
			
				//! Comentarios de argumentacao
					/**
					*	insere-se a interconexao auxI2 como saida da interconexao auxI1
					*	insere-se a interconexao auxI1 como entrada da interconexao auxI2
					**/
				auxI1->saidaInterconexao = auxI2;

				auxI2->entradaInterconexao = auxI1;
			}
		}
		//! AS: o auxI2 chegou ao fim da lista de interconexoes
	}
	//! AS: o auxI1 chegou ao fim da lista de interconexoes
}

/**
*	Funcao: verfica
*
*	AssertivaEntrada:
*
*	AssertivaSaida:
**/
void verifica(Cidade *cidades, Gerador *geradores, Interconexao *interconexoes, Adaptador *adaptadores)
{
	FILE *fp = fopen("ProblemasDeConsistenciaDosElementos.txt","w");
	Cidade *auxC = NULL; //!< Ponteiro auxiliar para cidade
	Gerador *auxG = NULL; //!< Ponteiro auxiliar para gerador
	Interconexao *auxI = NULL; //!< Ponteiro auxiliar para interconexao
	Adaptador *auxA = NULL; //!< Ponteiro auxiliar para adaptador

	fprintf(fp,"CIDADES:\n");
	if(cidadeVazia(cidades) == NAO_VAZIA){
	//! AE: a lista de cidades nao eh vazia	
		
		for(auxC = cidades; auxC != NULL; auxC = auxC->proximo){
		//! AE: o auxC ainda nao chegou ao fim da lista de cidades
		
			if(auxC->entradas == NULL){
			//! AE: a cidade corrente nao posssui entradas
				fprintf(fp,"# %s está desconectada!\n",auxC->nome);
			}
		}
		//! AS: o auxC chegou ao fim da lista de cidades
	}
	else{
	//! AE: a lista de cidades eh vazia	
		fprintf(fp,"# Não há cidades para serem abastecidas!\n");
	}
		
	fprintf(fp,"\nGERADORES:\n");
	if(geradorVazio(geradores) == NAO_VAZIO){
	//! AE: a lista de geradores nao eh vazia	
	
		for(auxG = geradores; auxG != NULL; auxG = auxG->proximo){
		//! AE: o auxG ainda nao chegou ao fim da lista de geradores
			
			if(auxG->saida == NULL){
			//! AE: o gerador corrente nao posssui saidas
				fprintf(fp,"# %s está desconectado!\n",auxG->nome);
			}
		}
		//! AS: o auxG chegou ao fim da lista de geradores
	}
	else{
	//! AE: a lista de geradores eh vazia	
		fprintf(fp,"# Não há geradores para gerar recursos!\n");
	}

	fprintf(fp,"\nINTERCONEXÕES:\n");
	if(interconexaoVazia(interconexoes) == NAO_VAZIA){
	//! AE: a lista de interconexoes nao eh vazia
		
		for(auxI = interconexoes; auxI != NULL; auxI = auxI->proximo){
		//! AE: o auxI ainda nao chegou ao fim da lista de interconexoes
		
			if(auxI->entradaGerador == NULL && auxI->entradaAdaptador == NULL && auxI->entradaInterconexao == NULL){
			//! AE: a interconexao nao possui entradas em geradores, adaptadores e interconexoes	
				fprintf(fp,"# Entrada de %s está desconectada!\n",auxI->nome);
			}
			
			if(auxI->saidaCidade == NULL && auxI->saidaAdaptador == NULL && auxI->saidaInterconexao == NULL){
			//! AE: a interconexao nao possui saidas em geradores, adaptadores e interconexoes	
				fprintf(fp,"# Saída de %s está desconectada!\n",auxI->nome);
			}
		}
		//! AS: o auxI chegou ao fim da lista de interconexoes
	}
	else{
	//! AE: a lista de interconexoes eh vazia		
		fprintf(fp,"# Não há interconexoes para transportar recursos!\n");
	}
	
	fprintf(fp,"\nADAPTADORES:\n");
	if(adaptadorVazio(adaptadores) == NAO_VAZIO){
	//! AE: a lista de adaptadores nao eh vazia
	
		for(auxA = adaptadores; auxA != NULL; auxA = auxA->proximo){
		//! AE: o auxA ainda nao chegou ao fim da lista de adaptadores
		
			if(auxA->entradas == NULL){
			//! AE: o adaptador corrente nao posssui entradas
				fprintf(fp,"# Não há entrada em %s!\n",auxA->nome);
			}
			
			if(auxA->saidas == NULL){
			//! AE: o adaptador corrente nao posssui saidas
				fprintf(fp,"# Não há saídas em %s!\n",auxA->nome);
			}
		}
		//! AS: o auxA chegou ao fim da lista de adaptadores
	}
	else{
	//! AE: a lista de adaptadores eh vazia
		fprintf(fp,"# Não há adaptadores para distribuir recursos!\n");	
	}

	fclose(fp);
}