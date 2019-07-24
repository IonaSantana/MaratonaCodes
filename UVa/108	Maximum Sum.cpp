#include <bits/stdc++.h>

using namespace std;
int mat[350][350];

int main()
{
	int N;
	long long soma,ans=0;
	scanf("%d",&N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d",&mat[i][j]);
			if(i > 0) mat[i][j] += mat[i-1][j];
			if(j > 0) mat[i][j] += mat[i][j-1];
			if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
			
		}
		
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = i; k < N; k++)
			{
				for (int l = j; l < N; l++)
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
	
	printf("%lld\n",ans);	
	
}
