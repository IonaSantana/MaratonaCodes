#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
vi g[210];
bool pinta[210],visitado[210];
bool dfs(int u)
{
	visitado[u] = 1;
	bool aux = 1;
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			pinta[v] = !pinta[u];
			aux &= dfs(v);
		}else if(pinta[v] == pinta[u])
		{
			return 0;
		}
	}
	return aux;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int V,A,lig1,lig2;
	while (scanf("%d",&V), V)
	{
		scanf("%d",&A);	
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			g[lig1].push_back(lig2);
			g[lig2].push_back(lig1);
		}			
		pinta[0] = 1;
		if(dfs(0))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");	
		for (int i = 0; i < 210; i++)
		{
			g[i].clear();
			visitado[i] = pinta[i] = 0;
		}	
	}
}
