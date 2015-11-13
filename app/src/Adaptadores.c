


Adaptador* criaListaAdaptador(){
	return NULL;
}





Adaptador* insereAdaptador(char *registro, Adaptador *listaAlvo){

	Adaptador *novo = (Adaptador *)malloc(sizeof(Adaptador));
	char numchar[strlen(registro)];
	int i,j=0,k=2;

	for(i=2;registro[i]!=' ';i++);
	novo->nome = (char *)malloc((i-1)*sizeof(char));

	for(i=2;j<3;i++){
		if(registro[i] == ' '||registro[i] == '\0'){
			if(j == 0)
				novo->nome[i-k] = '\0';
			else{
				numchar[i-k] = '\0';
				if(j == 1)
					novo->posicao[0] = atoi(numchar);
				else if(j == 2)
					novo->posicao[1] = atoi(numchar);
			}

			k = i+1;
			j++;
		}

		else{

			if(j == 0)
				novo->nome[i-k] = registro[i];
			else
				numchar[i-k] = registro[i];
		}
	}
	novo->saidas = NULL;
	novo->quatidadeSaidas =0;

	novo->recursoRecebido = 0;
	novo->peso = NULL;

	novo->proximo = listaAlvo;
	listaAlvo = novo;
	
	return listaAlvo;
}



void liberaListaAdaptador(Adaptador *listaAlvo){
	Adaptador *aux1 = NULL;
	Adaptador *aux2 = NULL;

	if(listaAlvo != NULL){
		for(aux1=listaAlvo;aux1!=NULL;aux1=aux2){
			aux2 = aux1->proximo;
			free(aux1->nome);
			free(aux1);
		}
	}
}


void defineDistribuicao(Adaptador *adapatador){

	while(adapatador != NULL){

		if(adapatador->saidas == NULL){
			return;
		}

		if(adapatador->peso == NULL){
			adapatador->peso = (float *) malloc(adapatador->quatidadeSaidas * sizeof(float));
		}


		int i;
		int somatorio = 0;
		for(i=0;i<adapatador->quatidadeSaidas;i++){

			somatorio += adapatador->saidas[i]->capacidadeMaxima;
		}

		for (int i = 0; i < adapatador->quatidadeSaidas; ++i){
			
			adapatador->peso[i] = adapatador->saidas[i]->capacidadeMaxima / somatorio;
		}


		adapatador = adapatador->proximo;
	}
}
