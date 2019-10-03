#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,V,A,lig1,lig2,to,vo,dist[110][110];
	scanf("%d",&T);
	for (int l = 0; l < T; l++)
	{
		scanf("%d%d",&V,&A);
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				dist[i][j] = 0x3f3f3f3f;
			}	
		}
		
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			dist[lig1][lig2] = 1;
			dist[lig2][lig1] = 1;
		}
		scanf("%d%d",&to,&vo);
		for (int i = 0; i < V; i++)
		{
			dist[i][i] = 0;
		}
		
		for(int k = 0;  k < V; k++)
		{
			for(int i = 0;  i < V; i++)
			{
				for(int j = 0;  j < V; j++)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);								
				}
			} 
		}	
		int soma = 0;
		for (int i = 0; i < V; i++)
		{
			soma = max(soma, dist[to][i] + dist[i][vo]);
		}
		printf("Case %d: %d\n",l+1,soma);
	}
}
