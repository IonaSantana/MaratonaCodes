#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef pair<int,int>ii;
int dist[1010][1010],x[] = {1,0,-1,0},y[] = {0,1,0,-1},l,c, li,ci,lf,cf;
char mat[1010][1010];
int bfs(int k, int a)
{
	for (int i = 0; i <= l; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			dist[i][j] = inf;
		}
	}
	queue<ii>q;
	q.push(ii(k,a));
	dist[k][a] = 0;
	while (!q.empty())
	{
		ii v = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int x1 = v.first + x[i];
			int y1 = v.second + y[i];
			if (x1 >= 0 && x1 < l && y1 >= 0 && y1 < c && mat[x1][y1] == '.' && dist[x1][y1] == inf)
			{
				dist[x1][y1] = dist[v.first][v.second] + 1;
				q.push(ii(x1,y1));
			}
		}	
	}
	
	return dist[lf][cf];
}

int main()
{
	int N,l1,qt,col;
	while (scanf("%d%d",&l,&c), l || c)
	{
		scanf("%d",&N);
		for (int i = 0; i <= l; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				mat[i][j] = '.';
			}	
		}
		
		for (int j = 0; j < N; j++)
		{
			scanf("%d%d",&l1,&qt);
			for (int i = 0; i < qt; i++)
			{
				scanf("%d",&col);
				mat[l1][col] = '*';
			}	
		}
		scanf("%d%d%d%d",&li,&ci,&lf,&cf);
		printf("%d\n",bfs(li,ci));
	}
}
