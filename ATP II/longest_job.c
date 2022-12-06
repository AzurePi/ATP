#include <stdio.h>
#include <stdlib.h>

int momento = 0; //vari�vel para a linha do tempo

typedef struct processo{
	int instante;
	int carga;
	struct processo *prox;
}P;

P *h = NULL; //vari�vel global do endere�o do come�o da lista

void inserir();
void processar();

int main(){
	int N;
	int i;
	
	scanf("%d", &N);
	
	for(i = 0; i<N; i++)
		inserir();
	
	processar();
	
	return 0;
}

//insere os processos a serem analisados em ordem crescente de carga
void inserir(){
	P *novo, *aux = h, *prev = NULL;
	novo = malloc(sizeof(P));
	
	scanf("%d %d", novo->instante, novo->carga);
	
	if(h == NULL) //se a lista est� vazia
	{
		h = novo;
		h->prox = NULL;
		return;
	}
	
	while(novo->carga < aux->carga && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//se chegou ao fim da lista
	if(aux->prox == NULL) 
	{
		novo->prox = NULL; //garante que o fim � o fim
		aux->prox = novo; //insere no fim da lista
		return;
	}
	
	//se ainda est� no come�o da lista
	if(aux == h)
	{
		novo->prox = h; //o novo tem como pr�ximo o atual come�o
		h = novo; //o come�o passa a ser o novo
		return;
	}
	
	//se encontrou o lugar certo
	if(novo->carga > aux->carga)
	{
		prev->prox = novo; //a anterior aponta para a nova
		novo->prox = aux; //a nova aponta para a atual
		return;
	}
	
	return;
}

void processar(){
	P *cur, *aux = h, *prev = NULL;
	
	
	
	
	return;
}
