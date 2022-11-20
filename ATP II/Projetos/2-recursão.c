#include <stdio.h>

void decompor(int K, int *conjunto, int M, int curr, int quant, int *maior){
	//K � o n�mero a ser decomposto
	//"conjunto" � o vetor de tamanho M que cont�m os n�mero que decompor�o
	//curr � �ndice de "conjunto" sendo utilizado agora
	//quant � a quantidade de decomposi��es poss�veis
	//"maior" armazena a maior combina��o dentro de "conjunto" que decop�e K
	
	int i = 0;

	
		//impress�o da quantidade de decomposi��es
		printf("%d ", quant);
	
		//impress�o da maior combina��o que decomp�e K
		while(maior[i] != 0)
		{
			printf("%d ", maior[i]);
			i++;
		}		

}



int main(){
	int N, M;
	int *conjunto; //endere�o do vetor dos n�meros que ser�o usados na combina��o
	int *inteiros; //endere�o do vetor dos n�meros que ser�o decompostos 
	int i;
	
	scanf("%d %d", &N, &M);
	
	//aloca��o din�mica dos vetores de acordo com a entrada
	conjunto = malloc(M*sizeof(int));
	inteiros = malloc(N*sizeof(int));
	
	//leitura dos valores usados na combina��o
	for(i = 0; i<M; i++)
		scanf("%d", conjunto[i]);
	
	//leitura dos valores a serem descompostos
	for(i = 0; i<N; i++)
		scanf("%d", inteiros[i]);
	
	
	//decomposi��o de cada valor de "inteiros"
	for(i = 0; i<N; i++)
	{
		int maior[M] = {0}; //vetor que armazenar� a maior combina�ao poss�vel
		decompor(inteiros[i], conjunto, M, 0, 0, maior);
		printf("\n");
	}
		

	//libera��o da mem�ria alocada
	free(conjunto);
	free(inteiros);
	
	return 0;
}
