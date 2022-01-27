#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
map<int,string>is;
vi g[2010],S;
int dfs_low[2010],dfs_num[2010],contador,cont;
bool visitado[2010];

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = contador++;
	S.push_back(u);
	visitado[u] = 1;
	
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		
		if (!dfs_num[v])
		{
			dfs(v);
		}
		
		if (visitado[v])
		{
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	
	if (dfs_low[u] == dfs_num[u])
	{	
		cont++;
		while (true)
		{
			int v = S.back();
			S.pop_back();
			visitado[v] = 0;
			if(v == u)
				break;
		}
	}
	
}

int main()
{	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int n,m,a,b,p;
	while (scanf("%d%d",&n,&m), n || m)
	{	
		for (int i = 0; i < m; i++)
		{	
			scanf("%d%d%d",&a,&b,&p);
			g[a].push_back(b);
			if(p==2)
				g[b].push_back(a);
		}		
		contador = cont = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!dfs_num[i])
			{
				dfs(i);
				S.clear();
			}
		}
		
		if(cont == 1)
			puts("1");
		else
			puts("0");
		
		for (int i = 0; i < 2010; i++)
		{
			visitado[i] = false;
			dfs_low[i] = dfs_num[i] = 0;
			g[i].clear();
		}	
		S.clear();
	}

}
