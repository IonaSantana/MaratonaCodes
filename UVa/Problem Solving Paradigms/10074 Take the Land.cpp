#include <bits/stdc++.h>

using namespace std;
int mat[350][350];

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,M;
	long long soma,ans=0;
	while(scanf("%d%d",&N,&M), N || M)
	{
		soma = ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d",&mat[i][j]);
				mat[i][j] ^= 1;
				if(!mat[i][j])
					mat[i][j] = -1000;
				if(i > 0) mat[i][j] += mat[i-1][j];
				if(j > 0) mat[i][j] += mat[i][j-1];
				if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
				
			}
			
		}
		
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
						
						ans = max(soma,ans);
					}	
				}	
			}	
		}	
		if(ans < 0)
			ans = 0;
		printf("%lld\n",ans);	
	}
	
}	
