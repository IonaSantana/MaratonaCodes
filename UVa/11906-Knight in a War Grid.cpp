#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
#define inf 0x3f3f3f3f

int R,C,M,N;
bool proibido[110][110];
int paridade[2];
void bfs()
{
	int x[] = {M,-M,N,-N};
	int y[] = {N,-N,M,-M};
	
	int dist[110][110];
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			dist[i][j] = inf;
		}
	}
	
	dist[0][0] = 0;	
	queue<ii>q;
	q.push(ii(0,0));
	paridade[0] = paridade[1] = 0;
	while (!q.empty())
	{
		set<ii>coord;
		ii a = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int lin = a.first + x[i];
				int col = a.second + y[j];
				
				if (lin >= 0 && lin < R && col >= 0 && col < C && !proibido[lin][col] && coord.find(ii(lin,col))==coord.end())
				{	
					coord.insert(ii(lin,col));
					if (dist[lin][col] == inf)
					{
						dist[lin][col] = dist[a.first][a.second] + 1;
						q.push(ii(lin,col));	
					}
				}
			}
		}	
		for (int i = 2; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				int lin = a.first + x[i];
				int col = a.second + y[j];
				
				if (lin >= 0 && lin < R && col >= 0 && col < C && !proibido[lin][col] && coord.find(ii(lin,col))==coord.end())
				{	
					coord.insert(ii(lin,col));
					if (dist[lin][col] == inf)
					{
						dist[lin][col] = dist[a.first][a.second] + 1;
						q.push(ii(lin,col));		
					}
				}
			}
		}
		paridade[(coord.size()%2)]++;
	}
}

int main()
{
	int T,W,p1,p2;
	scanf("%d",&T);

	for (int j = 0; j < T; j++)
	{
		for (int i = 0; i < 110; i++)
		{
			for (int k= 0; k < 110; k++)
			{
				proibido[i][k] = 0;
			}
		}	
		scanf("%d%d%d%d%d",&R,&C,&M,&N,&W);
		for (int i = 0; i < W; i++)
		{
			scanf("%d%d",&p1,&p2);
			proibido[p1][p2] = 1;
		}
		bfs();
		printf("Case %d: %d %d\n",j+1,paridade[0],paridade[1]);
	}
}
