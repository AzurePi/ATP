#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
	char palavra[50];
	struct lista *prox;
}Lista;

Lista *h = NULL; //endere�o do come�o da lista

void inserir(); //insere a palavra lida em ordem alfab�tica
void remover(); //remove a palavra lida
void imprimir(); //imprime a partir de uma palavra lida

int main(){
	int N, M;
	int i, op;
	
	scanf("%d %d", &N, &M);
	
	for (i = 0; i<N; i++)
		inserir();
	
	for(i = 0; i<M; i++)
	{
		scanf("%d", &op);
		
		if(op == 0)
			remover();
		else if(op == 1)
			inserir();
		else //if op == 2
			imprimir();
	}

	return 0;
}

//insere a palavra lida em ordem alfab�tica
void inserir(){
	Lista *novo, *aux = h, *prev = NULL;
	novo = malloc(sizeof(Lista));
	
	scanf(" %s", novo->palavra);
	
	if(h == NULL) //se a lista est� vazia
	{
		novo->prox = NULL;
		h = novo;	
		return;
	}
	//lista n�o vazia
	
	
	while(aux->prox != NULL && strcmp(aux->palavra, novo->palavra) < 0)
	{
		if(strcmp(novo->palavra, aux->palavra) == 0)
			return;
		prev = aux;
		aux = aux->prox;
	}
	
	//se novo est� depois de aux
	if(strcmp(novo->palavra, aux->palavra) > 0)
	{
		if(aux->prox == NULL) //e estamos no final da lista
		{
			aux->prox = novo;
			novo->prox = NULL;
			return;
		}
		//mas n�o estamos no final da lista
		
		novo->prox = aux->prox;
		aux->prox = novo;
		return;
	}
	
	//se novo est� antes de aux
	if(strcmp(novo->palavra, aux->palavra) < 0)
	{
		if(aux == h) //e estamos no come�o da lista
		{
			novo->prox = h;
			h = novo;
			return;
		}
		// mas n�o estamos no come�o da lista
		
		prev->prox = novo;
		novo->prox = aux;
		return;
	}
}

//remove a palavra lida
void remover(){
	Lista *aux = h, *prev = NULL;
	char pal[50];
	
	if(h == NULL) //se a lista est� vazia
	{
		printf("NULL\n");
		return;
	}
	//do contr�rio
	scanf(" %s", pal);
	
	//procura a palavra na lista
	while(strcmp(aux->palavra, pal) != 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}

	if(strcmp(aux->palavra, pal) == 0) //se achou a palavra
	{
		if(aux == h) //se estamos no come�o da lista
		{
			if(aux->prox == NULL) //e no fim da lista
				h = NULL; //a lista agora est� vazia
			else //mas h� elementos depois
				h = aux->prox;
		}else //se n�o est� no come�o
		{
			if(aux->prox == NULL) //e est� no final
				prev->prox = NULL;
			else //estamos no meio da lista
				prev->prox = aux->prox;
		}		
	}	
}

void imprimir(){
	Lista *aux, *prev;
	char pal[50];
	
	//se a lista est� vazia
	if(h == NULL)
	{
		printf("NULL\n");
		return;
	}
	//a lista n�o est� vazia
	
	scanf("%s", pal);

	while(strcmp(aux->palavra, pal) < 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;	
	}
	//sai do la�o quando aux � a palavra seguinte (ou igual) a pal
	//ou quando aux � a �ltima palavra da lista
	
	//se a palavra est� na lista
	if(strcmp(aux->palavra, pal) == 0)
		printf("%s", pal);
	
	//se a pr�xima palavra (possivelmente a �ltima da lista) � de fato
	//posterior a pal
	if(strcmp(aux->palavra, pal) > 0)
	{
		do //imprime as palavras
		{
			printf("%s ", aux->palavra);
			aux = aux->prox;
		}while(aux != NULL);
	}else
		printf("NULL");

	printf("\n");
}
