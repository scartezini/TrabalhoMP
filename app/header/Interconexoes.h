#include "Geradores.h"

/**
*	Funcao: criaListaInterconexao
*
*	Inicia um ponteiro que sera para Interconexao
*
*	@return
*		lista do tipo Interconexao vazia
*
*	AssertivaSaida:
*		NULL;
**/
Interconexao* criaListaInterconexao();

/**
*	Funcao: interconexaoVazia
*
*	Verifica se a lista de interconexoes esta vazia
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de interconexoes
*
*	@return
*		variavel do tipo Vazia, indicando se a lista esta vazia
*
*	Assertiva de entrada:
*		estrutura do tipo Interconexao
*
*	Assertiva de saida:
*		condicao da Interconexao sendo vazia ou nao vazia
*
**/
Vazia interconexaoVazia(Interconexao *);

/**
*	Funcao: insereInterconexao
*
*	Inserir uma nova celula na lista de interconexoes
* a insercao se da pelo inicio da lista e é retornadado
* o novo ponterio para lista.
*
*	@param registro
*		string que sera lida do arquivo representando Inteconexao
*	@param listaAlvo
*		lista de interconexoes onde a nova celula sera inserida
*
*	@return
*		novo pontero para a o inicio da lista de interconexoes
*
*	Assertiva de entrada:
*		registro - eh um vetor contendo o conteudo do txt, deve ser diferente de NULL
*
*	Assertiva de saida:
*		A lista recebida pela funcao, deve ser a proxima interconexao apontada pela lista retornada
**/
Interconexao* insereInterconexao(char *, Interconexao *);

/**
*	Funcao: imprimeListaInterconexao
*
*	Imprime de todas as celulas de lista de interconexoes
* as respectivas caracteristicas:
*	nome
*	posicao inicial x
*	posicao inicial y
*	posicao final x
*	posicao final y
*	tag de destino
*	chance de falha
*	tempo de concerto
*	custo de concerto
*	numero de falhas
*	tag de falha
*	capacidade maxima
*	recurso transportado
*
*	@param listaAlvo
*		lista que sera impressa
*
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		Se a lista de interconexoes a ser imprimida nao eh vazia
*		Entao
*			ela eh imprimida
*		Senao
*			a lista de interconexoes nao eh imprimida
*		FimSe
**/
void imprimeListaInterconexao(Interconexao *);

/**
*	Funcao: liberaListaInterconexao
*
*	Desaloca a memoria reservada para
* toda celula pertecente a lista de interconexoes
*
*	@param listaAlvo
*		lista a ser desalocada
*
*	AssertivaEntrada:
*		A lista nao deve ser vazia
*
*	AssertivaSaida:
*		A lista deve estar vazia
**/
void liberaListaInterconexao(Interconexao *);

/**
*	Funcao: tamanhoConexao
*
*	Calcula o tamanho da celula de conexao que
* eh passada para a funcao
*
*	@param listaAlvo
*		ponteiro para a celula de interconexao
*
*	@return
*		tamanho da celula de conexao que foi passada
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		tamanho de uma conexao
*
**/
float tamanhoConexao(Interconexao *);


/**
*	Funcao: tamanhoTotalConexao
*
*	Calcula o tamanho total das conexoes
* da lista que eh passada
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de celulas de conexao
*
*	@return
*		retorna o tamanho total das conexoes da lista
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		resultado da soma dos tamanhos de todas as conexoes
*
**/
float tamanhoTotalConexao(Interconexao *);


/**
*	Funcao: totalGastoConserto
*
*	Calcula o custo total gasto com conserto
* de todas as celulas de conexao
*
*	@param listaAlvo
*		ponteiro para o inicio da lista de interconexao
*
*	@return
*		total gasto com conserto de todas as conexoes
*
**/
int totalGastoConserto(Interconexao *);

/**
*	Funcao: calculaFalha
*
*	Calcula a possibilidade de falha
*
* 	@param listaAlvo
		celula a qual vai ser calculada a falha
*
*	@return
*		variavel do tipo Falha, indicando se houve falha
*
*	Assertiva de entrada:
*		a chance de falha deve estar entre 0 e 1
*
*	Assertiva de saida:
*		Se a chance de falha for maior que 0 e maior que um numero aleatorio
*		Entao
*			ocorre um falha
*		Senao
*			nao ocorre uma falha
*		FimSe
**/
Falha calculaFalha(Interconexao *);

/**
*
*	Funcao: mandarRecursoTransportado
*
*	Muda cada referencia seja para adaptador ou
* para cidade, dependenodo do em qual esta ligada,
* alterando o valor do recurso atual.
*
*	@param listaAlvo
*		ponterio de referencia para o inicio da lista de interconexoes
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		Se o destino da interconexao for um adaptador
*		Entao
*			soma-se o recurso transportado ao Adaptador da lista de interconexoes
*		Senao
*			soma-se o recurso transportado ao Adaptador da lista de interconexoes
*		FimSe
**/
void mandarRecursoTransportado(Interconexao *);

/**
* Funcao: custoGastoComConserto
*
*	Calcula o custo que foi gasto com o conserto das
* interconexoes
*
*	@param listaAlvo
*		ponterio de referencia para o inicio da lista
*		de interconexoes
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		valor gasto com os consertos das interconexoes
**/
int custoGastoComConserto(Interconexao *);


/**
* Funcao: numeroTotalFalhas
*
*	Faz a contabilidade de quantas falas teve durante toda a simulaca
*
*	@param listaAlvo
*		ponterio de referencia para o inicio da lista
*		de interconexoes
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		total de falhas
**/
int numeroTotalFalhas(Interconexao *);

/**
* Funcao: gerenciaFalhas
*
*	Marca as celulas que falharam como falhas
* e comtabilizam as celulas que estao no concerto o tempo
* que falta para sairem
*
*	@param listaAlvo
*		ponterio de referencia para o inicio da lista
*		de interconexoes
*
*	Assertiva de entrada:
*		interconexao - eh uma lista de interconexoes nao vazia
*
*	Assertiva de saida:
*		Se a interconexao corrente nao falhou
*		Entao
*			Se a chance desta interconexao falhar der FALHA
*			Entao
*				zera o contador de tempo de conserto
*				numero de falhas + 1
*				tagFalha = falha
*			FimSe
*		Senao
*			contador de tempo de conserto + 1
*			Se contador de tempo de conserto alcançar ou ultrapassar o tempo de conserto
*				zera o contador de tempo de conserto
*				tagFalha = sem falha
*			Fimse
**/
void gerenciaFalhas(Interconexao *);

void zerarInterconexoes(interconexao *);
