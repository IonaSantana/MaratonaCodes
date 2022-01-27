#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
vi g[30];
bool visitados[30];
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
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,cont;
	char maior;
	string frase;
	
	scanf("%d",&N);
	for (int j = 0; j < N; j++)
	{
		if(j > 0)
			puts("");
		scanf(" %c",&maior);
		int tam = maior - 'A';
		getchar();
		while(getline(cin,frase) && frase.size() > 0)
		{
			g[frase[0] - 'A'].push_back(frase[1] - 'A');
			g[frase[1] - 'A'].push_back(frase[0] - 'A');
		}
		cont = 0;
		for (int i = 0; i < tam+1; i++)
		{
			if (!visitados[i])
			{
				cont++;
				dfs(i);
			}
		}
		printf("%d\n",cont);
		
		for (int i = 0; i < tam+1; i++)
		{
			g[i].clear();
			visitados[i] = 0;
		}	
	}	
}
