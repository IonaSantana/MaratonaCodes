#include <bits/stdc++.h>

using namespace std;
int mat[350][350];

int main()
{
	int N,M,T,K,area;
	long long soma,ans=0;
	scanf("%d",&T);
	for (int ab = 0; ab < T; ab++)
	{
		scanf("%d%d%d",&N,&M,&K);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d",&mat[i][j]);
				if(i > 0) mat[i][j] += mat[i-1][j];
				if(j > 0) mat[i][j] += mat[i][j-1];
				if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];			
			}	
		}
		area = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				for (int k = i; k < N; k++)
				{
					for (int l = j; l < M; l++)
					{
						soma = mat[k][l];
						if(i > 0) soma -= mat[i-1][l];
						if(j > 0) soma -= mat[k][j-1];
						if(i > 0 && j > 0) soma += mat[i-1][j-1];
						
						if(soma <= K)
						{
							int tamanho = (k-i+1)*(l-j+1);
							if(tamanho > area)
							{
								area = tamanho;
								ans = soma;
							}else if (tamanho == area && ans > soma)
							{
								ans = soma;
							}
						}
					}	
				}	
			}	
		}		
		printf("Case #%d: %d %lld\n",ab+1,area,ans);	
	}
}
