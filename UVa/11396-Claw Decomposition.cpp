#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
vi g[310];
bool pinta[310],visitado[310];
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
	int V,lig1,lig2;
	while (scanf("%d",&V) && V)
	{
		while(scanf("%d%d",&lig1,&lig2) && (lig1 || lig2))
		{
			g[lig1].push_back(lig2);
			g[lig2].push_back(lig1);
		}			
		pinta[1] = 1;
		if(dfs(1))
			puts("YES");
		else
			puts("NO");	
		for (int i = 0; i < 310; i++)
		{
			g[i].clear();
			visitado[i] = pinta[i] = 0;
		}	
	}
}
