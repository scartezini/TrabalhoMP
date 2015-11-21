#include "../header/Geral.h"

int main()
{
	FILE *fp ;
	Cidade *listaCidades = criaListaCidade();
	Gerador *listaGeradores = criaListaGerador();
	Interconexao *listaInterconexoes = criaListaInterconexao();
	Adaptador *listaAdaptadores = criaListaAdaptador();
	Relatorio relatorio;
	int tempoSimulacao;
	char arquivo[100];

	char str[100]; //!< String auxiliar para obter registros

	printf("Digite o caminho para o arquivo:\n" );
	scanf("%s\n",arquivo);
	getchar();

	printf("Digite o tempo desejado de simulacao\n" );
	scanf("%d\n",&tempoSimulacao);

	fp = fopen(arquivo,"r");//!< Abre arquivo de entrada

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

			}
		}
		//! AS: a linha (registro) obtido do arquivo nao possui conteudo, ou seja, o arquivo chegou ao fim

	} while(!feof(fp));
	//! AS: o arquivo chegou ao fim

	fclose(fp);

	//! Comentarios de argumentacao
		/**
		*	Imprimindo as listas obtidas a partir do arquivo de entrada
		**/
	printf("\nlistaCidades:\n");imprimeListaCidade(listaCidades);
	printf("\nlistaGeradores:\n");imprimeListaGerador(listaGeradores);
	printf("\nlistaInterconexoes:\n");imprimeListaInterconexao(listaInterconexoes);
	printf("\nlistaAdaptadores:\n");imprimeListaAdaptador(listaAdaptadores);

	//! Comentarios de argumentacao
		/**
		*	Conectando e verificando as listas
		**/
	conecta(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);
	printf("\n\n");
	verifica(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);


	int i;
	for(i=0;i<tempoSimulacao;i++){
		gerenciaFalhas(listaInterconexoes);
		mandarRecursoProduzido(listaGeradores);
	}

	//! Comentarios de argumentacao
		/**
		*	Preenchimento do relatorio
		**/
	relatorio.tempoTotalSimulacao = tempoSimulacao;
	relatorio.custoTotalSimulacao = custoGeradores(listaGeradores)*tempoSimulacao + custoGastoComConcerto(listaInterconexoes);
	relatorio.totalGeradores = numeroGeradores(listaGeradores);
	relatorio.energiaTotalGerada = recursoProduzidoTotal(listaGeradores);
	relatorio.totalCidades = numeroCidades(listaCidades);
	relatorio.energiaGastaCidades = recursoGastoTotal(listaCidades);
	relatorio.tamanhoTotalInterconexoes = tamanhoTotalConexao(listaInterconexoes);
	relatorio.numeroFalhaInterconexoes = numeroTotalFalhas(listaInterconexoes);
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
