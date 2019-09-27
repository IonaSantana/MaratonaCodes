#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
typedef pair<int,int>ii;
set<ii>links;
set<ii>::iterator it;
vi g[10010];
int low[10010],pai[10010],discoberto[10010],tempo;
bool visitado[10010];

void dfs(int u)
{
	visitado[u] = 1;
	
	discoberto[u] = low[u] = ++tempo;

	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			pai[v] = u;
			dfs(v);
			low[u] = min(low[u],low[v]);
			
			if(low[v] > discoberto[u])//e ponte
				links.insert(ii(min(u,v),max(u,v)));
		}
		else if(v != pai[u])
		{
			low[u] = min(low[u],discoberto[v]);
		}
	}
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int V,N,lig1,lig2;
	char c1,c2;
	while (scanf(" %d",&V)!=EOF)
	{
		for (int i = 0; i < V; i++)
		{
			scanf(" %d %c %d %c",&lig1,&c1,&N,&c2);
			for (int j = 0; j < N; j++)
			{
				scanf(" %d",&lig2);
				g[lig1].push_back(lig2);
			}	
		}
		
		tempo = 0;
		for (int i = 0; i < V; i++)
		{
			if (!visitado[i])
			{
				dfs(i);
			}
		}
		
		printf("%d critical links\n",(int)links.size());
		for (it = links.begin(); it!= links.end(); it++)
		{
			printf("%d - %d\n",it->first,it->second);
		}
		puts("");
		
		for (int i = 0; i < 10010; i++)
		{
			g[i].clear();
			visitado[i] = 0;
		}
		links.clear();
	}
}
