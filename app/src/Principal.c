#include "../header/Geral.h"

int main()
{
	FILE *fp;
	Cidade *listaCidades = criaListaCidade();
	Gerador *listaGeradores = criaListaGerador();
	Interconexao *listaInterconexoes = criaListaInterconexao();
	Adaptador *listaAdaptadores = criaListaAdaptador();
	Relatorio relatorio;
	int i, tempoSimulacao = 2;
	char arquivo[100];

	char str[100]; //!< String auxiliar para obter registros

	printf("Rede de distribuicao\n");

	do{
	//! AE: o nome do arquivo nao eh valido 

		printf("Digite o caminho para o arquivo (a partir de ./app/src):\n");
		scanf("%s",arquivo);
		getchar();

		fp = fopen(arquivo,"r");//!< Abre arquivo de entrada
	
	} while(fp == NULL);
	//! AE: o nome do arquivo eh valido 

	printf("Digite o tempo desejado de simulacao\n");
	scanf("%d",&tempoSimulacao);

	do{
	//! AE: o arquivo nao chegou ao fim
	
		if(fgets(str,100,fp)!=NULL){
		//! AE: a linha (registro) obtido do arquivo possui conteudo

			switch (str[0]) {
				case 'C':
					//! AE: O registro obtido eh do tipo Cidade
					listaCidades = insereCidade(str,listaCidades);
					break;

				case 'G':
				//! AE: O registro obtido eh do tipo Gerador
					listaGeradores = insereGerador(str,listaGeradores);
					break;

				case 'I':
				//! AE: O registro obtido eh do tipo Interconexao
					listaInterconexoes = insereInterconexao(str,listaInterconexoes);
					break;

				case 'A':
				//! AE: O registro obtido eh do tipo Adaptador
					listaAdaptadores = insereAdaptador(str,listaAdaptadores);
					break;

				default:
					break;
			}
		}
		//! AS: a linha (registro) obtido do arquivo nao possui conteudo, ou seja, o arquivo chegou ao fim

	} while(!feof(fp));
	//! AS: o arquivo chegou ao fim

	fclose(fp);

	//! Comentarios de argumentacao
		/**
		*	Conectando e verificando as listas
		**/
	conecta(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);
	printf("\n\n");
	verifica(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);

	for(i=0;i<tempoSimulacao;i++){
		gerenciaFalhas(listaInterconexoes);
		mandarRecursoProduzido(listaGeradores);
	}

	//! Comentarios de argumentacao
		/**
		*	Imprimindo as listas obtidas a partir do arquivo de entrada
		**/
	imprimeListaCidade(listaCidades);
	imprimeListaGerador(listaGeradores);
	imprimeListaInterconexao(listaInterconexoes);
	imprimeListaAdaptador(listaAdaptadores);

	//! Comentarios de argumentacao
		/**
		*	Preenchimento do relatorio
		**/
	relatorio.tempoTotalSimulacao = tempoSimulacao;
	printf("Tempo total da simulação: %d segundos\n", relatorio.tempoTotalSimulacao);
	
	relatorio.custoTotalSimulacao = custoGeradores(listaGeradores)*tempoSimulacao + custoGastoComConserto(listaInterconexoes);
	printf("Custo total na simulação: %d\n", relatorio.custoTotalSimulacao);

	relatorio.totalGeradores = numeroGeradores(listaGeradores);
	printf("Total de geradores: %d\n", relatorio.totalGeradores);
	
	relatorio.energiaTotalGerada = recursoProduzidoTotal(listaGeradores);
	printf("Energia total gerada: %d\n", relatorio.energiaTotalGerada);
	
	relatorio.totalCidades = numeroCidades(listaCidades);
	printf("Total de cidades: %d\n", relatorio.totalCidades);
	
	relatorio.energiaGastaCidades = recursoGastoTotal(listaCidades);
	printf("Energia total gasta pelas cidades: %d\n", relatorio.energiaGastaCidades);
	
	relatorio.tamanhoTotalInterconexoes = tamanhoTotalConexao(listaInterconexoes);
	printf("Tamanho total das interconexões: %f\n", relatorio.tamanhoTotalInterconexoes);
	
	relatorio.numeroFalhaInterconexoes = numeroTotalFalhas(listaInterconexoes);
	printf("Número de falhas nas interconexões: %d\n", relatorio.numeroFalhaInterconexoes);
	//relatorio.numeroCidadesNegativadas =
	//relatorio.tempoSemRecurso =
	//relatorio.numeroCidadesNoVermelho =
	//relatorio.tempoCidadesNoVermelho =

	//! Comentarios de argumentacao
		/**
		*	Desalocando as listas obtidas
		**/
	liberaListaCidade(listaCidades);
	liberaListaGerador(listaGeradores);
	liberaListaInterconexao(listaInterconexoes);
	liberaListaAdaptador(listaAdaptadores);

	getchar();
	return 0;
}
