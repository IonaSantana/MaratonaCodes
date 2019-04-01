#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,freq,amp;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{	if(i > 0)puts("");
		scanf("%d %d",&amp,&freq);
		for (int j = 0; j < freq; j++)
		{
			if(j>0)printf("\n");
			for (int k = 1; k <= amp; k++)
			{
				for (int l = 0; l < k; l++)
				{
					printf("%d",k);
				}
				printf("\n");
			}
			for (int k = amp-1; k >=1; k--)
			{
				for (int l = 0; l < k; l++)
				{
					printf("%d",k);
				}
				printf("\n");			
			}
			
		}
		
	}	
}
