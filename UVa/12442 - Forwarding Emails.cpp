#include <bits/stdc++.h>

using namespace std;

int cont,g[50010], dist[50010];
bool visitados[50010];

void dfs(int u)
{
	cont++;
	visitados[u] = 1;
	int v = g[u];
	if (v!=-1 && !visitados[v])
	{
		dfs(v);
	}
	if(dist[u]==-1)
		dist[u] = cont;
	visitados[u] = 0;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int T,V,lig1,lig2;
	scanf("%d",&T);
	for (int j = 0; j < T; j++)
	{
		scanf("%d",&V);
		for (int i = 1; i <= V; i++)
		{
			visitados[i] = 0;
			dist[i] = -1;
			g[i] = -1;
		}
		
		for (int i = 0; i < V; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			g[lig1] = (lig2);
		}
		
		
		for (int i = 1; i <= V; i++)
		{
			if (dist[i]==-1)
			{
				cont = 0;
				dfs(i);
				visitados[i] = 0;
			}
		}

		int altura = 0,vertice = 1;
		for (int i = 1; i <= V; i++)
		{
			if (dist[i] > altura)
			{
				altura = dist[i];
				vertice = i;
			}	
		}
		
		printf("Case %d: %d\n",j+1,vertice);		
	}
}
