#include <bits/stdc++.h>

using namespace std;
pair<int,int> Peso[20];
int N;
char m[110][110];

void dfs(int i, int j)
{
	m[i][j] = '.';
	if (i+1 < N && (m[i+1][j]=='x' || m[i+1][j]=='@')) dfs(i+1,j);
	if (j+1 < N && (m[i][j+1]=='x' || m[i][j+1]=='@')) dfs(i,j+1);
	if (i-1 >= 0 && (m[i-1][j]=='x' || m[i-1][j]=='@')) dfs(i-1,j);
	if (j-1 >= 0 && (m[i][j-1]=='x' || m[i][j-1]=='@')) dfs(i,j-1);	
	
}
int main() 
{
	int T,cont;
	scanf("%d",&T);
	for (int i = 1; i <= T; i++)
	{   scanf("%d",&N);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf(" %c",&m[j][k]);
			}			
		}
		cont=0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (m[j][k]=='x')
				{
					dfs(j,k);
					cont++;
				}
			}			
		}	
		
		printf("Case %d: %d\n",i,cont);		
	}	
}

