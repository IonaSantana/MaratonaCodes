#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
vi g[100100];
stack<int>s;
bool visitados[100100];

void dfs(int u)
{
	visitados[u] = 1;
	
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitados[v])
		{
			dfs(v);
		}
	}
	s.push(u);
}
void dfs2(int u)
{
	visitados[u] = 1;
	
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitados[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,lig1,lig2,V,A,cont;
	scanf("%d",&N);
	
	for (int j = 0; j < N; j++)
	{
		scanf("%d%d",&V,&A);
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			g[lig1].push_back(lig2);
		}
		memset(visitados,0,sizeof visitados);
		for (int i = 1; i <= V; i++)
		{
			if (!visitados[i])
			{
				dfs(i);
			}
		}
		memset(visitados,0,sizeof visitados);
		cont = 0;
		while (!s.empty())
		{
			int a = s.top();
			s.pop();
			if (!visitados[a])
			{
				cont++;
				dfs2(a);	
			}
		}
		printf("%d\n",cont);
		for (int i = 0; i < 100100; i++)
		{
			g[i].clear();
		}
		
	}
	
}
