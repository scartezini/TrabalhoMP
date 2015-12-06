#include "../header/Interface.h"

int main(){

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
	verifica(listaCidades,listaGeradores,listaInterconexoes,listaAdaptadores);
	inicializa(listaGeradores,listaInterconexoes,listaAdaptadores,listaCidades);

	//! Comentarios de argumentacao
		/**
		*	Iniciando a interface
		**/
	mvprintw(0,0,"Pressione enter para comecar!");
	getch();
	mvprintw(0,0,"                             ");

	srand(1);

	for(i=0;i<tempoSimulacao;i++){
	// AE: tempo de simulacao nao chegou ao fim

		start_color();
	  init_pair(1, COLOR_GREEN, COLOR_BLACK);
		attron(COLOR_PAIR(1));
		mvprintw(1,100,"%d segundos", i);

		zerarCidades(listaCidades);
		zerarAdaptadores(listaAdaptadores);
		zerarInterconexoes(listaInterconexoes);

		gerenciaFalhas(listaInterconexoes);

		mandarRecursoProduzido(listaGeradores);
		defineDistribuicao(listaAdaptadores);
		mandarRecursoAdaptado(listaAdaptadores);
		gerenciaRecursoRecebido(listaCidades);

		atualizaCidades(listaCidades);
		atualizaInterconexoes(listaInterconexoes);
		atualizaGeradores(listaGeradores);
		atualizaAdaptadores(listaAdaptadores);

		getch();
	}
	// AS: tempo de simulacao chegou ao fim

	mvprintw(0,0,"                             ");
	mvprintw(1,0,"                             ");
	mvprintw(0,0,"Pressione enter para finalizar!");
	getch();
	endwin();
	//! Comentarios de argumentacao
		/**
		*	Finalizando a interface
		**/

	//! Comentarios de argumentacao
		/**
		*	Imprimindo as listas obtidas a partir do arquivo de entrada
		**/
	printf("\nLista de cidades:\n");imprimeListaCidade(listaCidades);
	printf("\nLista de geradores:\n");imprimeListaGerador(listaGeradores);
	printf("\nLista de interconexões:\n");imprimeListaInterconexao(listaInterconexoes);
	printf("\nLista de adaptadores:\n");imprimeListaAdaptador(listaAdaptadores);

	//! Comentarios de argumentacao
		/**
		*	Preenchimento do relatorio
		**/
	fp = fopen("../../RELATORIO.txt","w");//!< Abre arquivo de entrada
	fprintf(fp,"Relatório:\n\n");
	printf("Relatório:\n\n");

	relatorio.tempoTotalSimulacao = tempoSimulacao;
	fprintf(fp,"Tempo total da simulação: %d segundos\n", relatorio.tempoTotalSimulacao);
	printf("Tempo total da simulação: %d segundos\n", relatorio.tempoTotalSimulacao);

	relatorio.custoTotalSimulacao = custoGeradores(listaGeradores)*tempoSimulacao + custoGastoComConserto(listaInterconexoes);
	fprintf(fp,"Custo total na simulação: %d\n", relatorio.custoTotalSimulacao);
	printf("Custo total na simulação: %d\n", relatorio.custoTotalSimulacao);

	relatorio.totalGeradores = numeroGeradores(listaGeradores);
	fprintf(fp,"Total de geradores: %d\n", relatorio.totalGeradores);
	printf("Total de geradores: %d\n", relatorio.totalGeradores);

	relatorio.energiaTotalGerada = recursoProduzidoTotal(listaGeradores) * tempoSimulacao;
	fprintf(fp,"Energia total gerada: %d\n", relatorio.energiaTotalGerada);
	printf("Energia total gerada: %d\n", relatorio.energiaTotalGerada);

	relatorio.totalCidades = numeroCidades(listaCidades);
	fprintf(fp,"Total de cidades: %d\n", relatorio.totalCidades);
	printf("Total de cidades: %d\n", relatorio.totalCidades);

	relatorio.energiaGastaCidades = recursoGastoTotal(listaCidades);
	fprintf(fp,"Energia total gasta pelas cidades: %d\n", relatorio.energiaGastaCidades);
	printf("Energia total gasta pelas cidades: %d\n", relatorio.energiaGastaCidades);

	relatorio.tamanhoTotalInterconexoes = tamanhoTotalConexao(listaInterconexoes);
	fprintf(fp,"Tamanho total das interconexões: %.2f\n", relatorio.tamanhoTotalInterconexoes);
	printf("Tamanho total das interconexões: %.2f\n", relatorio.tamanhoTotalInterconexoes);

	relatorio.numeroFalhaInterconexoes = numeroTotalFalhas(listaInterconexoes);
	fprintf(fp,"Número de falhas nas interconexões: %d\n", relatorio.numeroFalhaInterconexoes);
	printf("Número de falhas nas interconexões: %d\n", relatorio.numeroFalhaInterconexoes);

	relatorio.numeroCidadesNegativadas = numeroCidadesNegativadas(listaCidades);
	fprintf(fp,"Número de cidades que ficaram com menos recurso que o necessário: %d\n",relatorio.numeroCidadesNegativadas);
	printf("Número de cidades que ficaram com menos recurso que o necessário: %d\n",relatorio.numeroCidadesNegativadas);

	relatorio.tempoSemRecurso =	tempoSemRecursoNecessario(listaCidades);
	fprintf(fp,"Tempo que ficaram sem recurso: %d\n",relatorio.tempoSemRecurso);
	printf("Tempo que ficaram sem recurso: %d\n",relatorio.tempoSemRecurso);

	relatorio.numeroCidadesNoVermelho = numeroCidadesNoVermelho(listaCidades);
	fprintf(fp,"Número de cidades que ficaram com menos de 30%% dos recursos: %d\n",relatorio.numeroCidadesNoVermelho);
	printf("Número de cidades que ficaram com menos de 30%% dos recursos: %d\n",relatorio.numeroCidadesNoVermelho);

	relatorio.tempoCidadesNoVermelho = tempoCidadesNoVermelho(listaCidades);
	fprintf(fp,"Tempo que ficaram com menos de 30%% dos recurso: %d\n", relatorio.tempoCidadesNoVermelho);
	printf("Tempo que ficaram com menos de 30%% dos recurso: %d\n", relatorio.tempoCidadesNoVermelho);

	fclose(fp);

	printf("\n\nRelatório gerado!\n\n");

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
