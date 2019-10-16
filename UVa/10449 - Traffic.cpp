#include <bits/stdc++.h>

using namespace std;
typedef pair<int,long long>ii;
typedef vector<ii>vii;
int visitado[210],pai;
long long dist[210],peso;
vii g[210];
set<int>vai;
set<int>::iterator it;

bool dfs(int u)
{
	visitado[u] = 1;
	if(u == pai)
		return 1;
	
	bool ciclo = 0;
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i].first;
		if (!visitado[v])
		{
			if(dfs(v))
				ciclo = 1;
		}
	}
	if(ciclo)
		vai.insert(u);
	
	return ciclo;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	long long V,A,lig1,lig2,aresta[210],cont=1,q,vertice;
	
	while(scanf("%lld",&V)==1)
	{	vai.clear();
		for (int i = 1; i <= V; i++)
		{
			dist[i] = 0x3f3f3f3f;
			visitado[i] = 0;
			g[i].clear();
			scanf("%lld",&aresta[i]);
		}
		
		scanf("%lld",&A);
		for (int i = 0; i < A; i++)
		{
			scanf("%lld%lld",&lig1,&lig2);
			peso = aresta[lig2] - aresta[lig1];
			peso = peso*peso*peso;
			g[lig1].push_back(ii(lig2,peso));
		}
		
		dist[1] = 0;
		
		for (int i = 1; i < V; i++)
		{
			for (int u = 1; u <= V; u++)
			{
				for (int j = 0; j < (int)g[u].size(); j++)
				{
					ii v = g[u][j];
					
					if(dist[u]!=0x3f3f3f3f)
						dist[v.first] = min(dist[v.first],dist[u] + v.second);
				}	
			}
		}
		 
		for (int u = 1; u <= V; u++)
		{
			for (int j = 0; j < (int)g[u].size(); j++)
			{
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
				{
					vai.insert(v.first);
					dist[v.first] = dist[u] + v.second;
				}
			}	
		}
		
		for (it = vai.begin(); it!=vai.end(); it++)
		{
			if (!visitado[*it] && g[*it].size())
			{
				pai = *it;
				dfs(g[*it][0].first);
			}
		}

		scanf("%lld",&q);
		printf("Set #%lld\n",cont);
		cont++;
		for (int i = 0; i < q; i++)
		{
			scanf("%lld",&vertice);
			if (dist[vertice]>=3 && dist[vertice] < 0x3f3f3f3f && vai.find(vertice)==vai.end())
			{
				printf("%lld\n",dist[vertice]);
			}else
			{
				puts("?");
			}
		}	
		
	}
}
