#include <bits/stdc++.h>

using namespace std;
int x[] = {-1,0,1,0}, y[] = {0,1,0,-1},M,N,cont;
char mat[25][25];
bool visitados[25][25];

void dfs(int l, int c,char continente)
{
	cont++;
	visitados[l][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		int a = (l + x[i]);
		int b = (N + c + y[i])%N;
		if (!visitados[a][b] && a>=0 && a< M && mat[a][b] == continente)
		{
			dfs(a,b,continente);
		}
	}
	
}
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int a,b,resp;
	char continent;
	while (scanf("%d%d",&M,&N)!=EOF)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %c",&mat[i][j]);
				visitados[i][j] = 0;
			}
		}
		scanf("%d%d",&a,&b);
		continent = mat[a][b];
		resp = cont = 0;
		dfs(a,b,continent);	
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visitados[i][j] && mat[i][j] == continent)
				{	
					cont = 0;
					dfs(i,j,continent);
					resp = max(resp, cont);
				}
			}
		}
		printf("%d\n",resp);
	}
}
