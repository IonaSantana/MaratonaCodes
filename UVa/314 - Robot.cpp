#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
int pega1,pega2,dist[55][55][4],d[55][55][4],N,M,x[] = {-1,0,1,0,-2,0,2,0,-3,0,3,0}, y[] = {0,1,0,-1,0,2,0,-2,0,3,0,-3};
set<ii>obstaculos;
set<ii>::iterator it;
int bfs(int in,int in1, int fimx, int fimy, int direcao)
{
	for (int i = 0; i < 55; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = inf;	
		}
	}
	
	dist[in][in1][direcao] = 0;
	queue<iii>q;
	q.push(iii(ii(in,in1),direcao));
	
	while (!q.empty())
	{
		iii a = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int add = 1;
			if(abs(i - a.second) == 2)
				add = 3;
			else if(i != a.second)
				add = 2;

			for (int j = i; j < 12; j+=4)
			{
				int l = a.first.first + x[j];
				int c = a.first.second + y[j];
				if (obstaculos.count(ii(l,c)))
				{
					break;
				}
				else if((l > 0 && c > 0 && l < N && c < M))
				{
					if(dist[l][c][i] > (dist[a.first.first][a.first.second][a.second] + add))
					{
						dist[l][c][i] = dist[a.first.first][a.first.second][a.second] + add;
						q.push(iii(ii(l,c),i));
					}
				}		
			}	
		}	
	}

	int minimo = min(dist[fimx][fimy][3],min(dist[fimx][fimy][2],min(dist[fimx][fimy][0],dist[fimx][fimy][1])));
	return minimo;
}
int main()
{		
	map<string,int> m;
	m["north"] = 0;
	m["east"] = 1;
	m["south"] = 2;
	m["west"] = 3;
	
	int inx,iny,fimx,fimy,mat[60][60];
	string dir;
	while(scanf(" %d%d",&N,&M), N || M)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d",&mat[i][j]);		
				
			}		
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if(mat[i][j])
				{
					obstaculos.insert(ii(i,j));
					if(j + 1 < M)
					{
						obstaculos.insert(ii(i,j+1));
						if(i+1 < N)
							obstaculos.insert(ii(i+1,j+1));
					}
					if(i+1 < N)
							obstaculos.insert(ii(i+1,j));
				}
			}		
		}
	
		scanf("%d%d%d%d ",&inx,&iny,&fimx,&fimy);
		cin>>dir;
		int res = inf;
		if(obstaculos.count(ii(inx,iny)) == 0)
			res = bfs(inx,iny,fimx,fimy,m[dir]);
		
		if(res!=inf)
			printf("%d\n",res);
		else
			puts("-1");
		obstaculos.clear();
	}
}
