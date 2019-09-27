#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
int cont,V;
void dfs(int fora,int u, vi g[],bool visitado[])
{
	if(fora == 0)
		visitado[u] = 1;
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			dfs(0,v, g,visitado);
		}
	}
	
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int V,lig1,lig2,q,u;
	while (scanf(" %d",&V), V)
	{	
		vi g[V + 3];
		bool visitado[V + 3];
		while (scanf(" %d",&lig1), lig1)
		{
			while (scanf(" %d",&lig2), lig2)
			{
				g[lig1].push_back(lig2);
			}
		}
		
		scanf("%d",&q);
		for (int i = 0; i < q; i++)
		{
			cont = 0;
			memset(visitado,0,sizeof visitado);
			scanf("%d",&u);
			dfs(1,u, g, visitado);
			for (int j = 1; j <= V; j++)
			{
				if(visitado[j] == 0)
					cont++;
			}	
			printf("%d",cont);
			for (int j = 1; j <= V; j++)
			{
				if(visitado[j] == 0)
					printf(" %d",j);
			}
			puts("");		
		}	
	}
}
