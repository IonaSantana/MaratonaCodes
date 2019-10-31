#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
#define inf 0x3f3f3f3f
set<int>vai;
set<int>::iterator it;
bool visitado[110];
int pai;
vi g[110];
void dfs(int u)
{
	visitado[u] = 1;
	
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			vai.insert(v);
			dfs(v);
		}
	}
}
int main()
{
	int n,peso[110],qt,v1,dist[110];
	while (scanf("%d",&n), n!=-1)
	{
		vai.clear();
		for (int i = 1; i <= n; i++)
		{
			dist[i] = -inf;
			visitado[i] = 0;
			g[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d",&peso[i],&qt);
			for (int j = 0; j < qt; j++)
			{
				scanf("%d",&v1);
				g[i].push_back(v1);
			}
		}
		dist[1] = 100;
		for (int i = 1; i < n; i++)
		{
			for (int u = 1; u <= n; u++)
			{
				for (int j = 0; j < (int)g[u].size(); j++)
				{
					int v = g[u][j];
					if(dist[u] + peso[v] > 0 && dist[u] + peso[v] > dist[v])
						dist[v] = dist[u] + peso[v];
				}	
			}
		}
		for (int u = 1; u <= n; u++)
		{
			for (int j = 0; j < (int)g[u].size(); j++)
			{
				int v = g[u][j];
				if (dist[u] + peso[v] > 0 && dist[v] < dist[u] + peso[v])
				{
					vai.insert(v);
					dist[v] = dist[u] + peso[v];
				}
			}	
		}
		for (it = vai.begin(); it!=vai.end(); it++)
		{
			if (!visitado[*it] && g[*it].size())
			{
				dfs(g[*it][0]);
			}
		}

		if (dist[n] > 0 || vai.count(n))
			puts("winnable");
		else
			puts("hopeless");
	}
}
