#include <stdio.h>

int main(){
	int prim[10], seg[5];
	int res1[10], res2[10];
	int sumSeg = 0;
	int i, j = 0, k = 0, l;
	
	for(i = 0; i<10; i++)
	{
		scanf("%d", &prim[i]);
	}
	
	printf("\n");
	
	for(i = 0; i<5; i++)
	{
		scanf("%d", &seg[i]);
		sumSeg += seg[i];
	}
		
	for(i = 0; i<10; i++)
	{
		if(prim[i] % 2 == 0)
			{
				res1[j] = prim[i] + sumSeg;
				j++;
			}
		else
			{
				res2[k] = 0;
				
				for(l = 0; l<5; l++)
				{
					if(prim[i] % seg[l] == 0)
						res2[k]++;
				}
				
				k++;
			}	
	}
	
	printf("\n");
	
	if(j != 0)
	{
		for(i = 0; i<j; i++)
		{
			printf("%d ", res1[i]);
		}
		printf("\n");
	}
	
	if(k != 0)
	{
		for(i = 0; i<k; i++)
		{
			printf("%d ", res2[i]);
		}
	}
			
	return 0;
}
