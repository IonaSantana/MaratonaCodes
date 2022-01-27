#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
#define inf -1
vi g[30];
bool visitado[30];
int valores[30],dist[30];
stack<int>topological;
void dfs(int u)
{
	visitado[u] = 1;
	
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			dfs(v);
		}
	}
	topological.push(u);
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int T,maior,entrada[30];
	string frase;
	scanf("%d",&T);
	getchar();
	for (int j = 0; j < T; j++)
	{
		if(j>0)
		{
			puts("");
		}
		else					
			getchar();
		for (int i = 0; i < 30; i++)
		{
			visitado[i] = 0;
			dist[i] = inf;
			g[i].clear();
			entrada[i] = 0;
		}
		
		maior = 0;
		while (getline(cin,frase), frase!="")
		{	
			char vertice,lig;
			stringstream f(frase);
			f>>vertice;
			f>>valores[vertice-'A'];
			maior++;
			while(f>>lig)
			{
				g[lig-'A'].push_back(vertice-'A');
				entrada[vertice-'A']++;
			}
		}
		
		for (int i = 0; i < 26; i++)
		{
			if (!visitado[i])
			{
				dfs(i);
			}
		}
		for (int i = 0; i < maior; i++)
		{
			if(!entrada[i])
				dist[i] = valores[i];
		}		
		
		while (!topological.empty())
		{
			int a = topological.top();
			topological.pop();
			if (dist[a] != inf)
			{
				for (int i = 0; i < (int)g[a].size(); i++)
				{
					int v = g[a][i];
					if (dist[v] < dist[a] + valores[v])
					{
						dist[v] = dist[a] + valores[v];
					}
				}
			}
		}
		int maior1 = 0;
		for (int i = 0; i < maior; i++)
		{
			maior1 = max(maior1,(dist[i]));
		}
		printf("%d\n",maior1);
	}
	
}
