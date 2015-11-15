#include "../header/Cidades.h"
#include "../header/Geradores.h"
#include "../header/Interconexoes.h"
#include "../header/Adaptadores.h"

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