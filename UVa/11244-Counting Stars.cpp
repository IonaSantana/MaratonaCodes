#include <bits/stdc++.h>

using namespace std;
bool visitados[110][110];
int x[] = {-1,0,1,0,-1,-1,1,1}, y[] = {0,1,0,-1,-1,1,-1,1},N,M,objeto;
char mat[110][110];
void dfs(int l, int c)
{
	objeto++;
	visitados[l][c] = 1;
	
	for (int i = 0; i < 8; i++)
	{
		int a = l + x[i];
		int b = c + y[i];
		
		if (a >= 0 && a < N && b >= 0 && b < M && mat[a][b] == '*' && !visitados[a][b])
		{
			dfs(a,b);
		}
	}
	
}
int main()
{
	int cont;
	while (scanf("%d%d",&N,&M), N || M)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf(" %c",&mat[i][j]);
				visitados[i][j] = 0;
			}
		}
		cont = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if(mat[i][j] == '*' && !visitados[i][j])
				{	
					objeto = 0;
					dfs(i,j);
					if(objeto == 1)
						cont++;
				}
			}
		}
		printf("%d\n",cont);
	}
}
