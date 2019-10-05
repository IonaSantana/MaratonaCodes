#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
#define d first
#define andar second.first
#define elevador second.second
#define inf 0x3f3f3f3f
int T,k,tempo[110],dist[110][5];
bool g[110][5];

int d()
{
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dist[i][j] = inf;
		}	
	}
	priority_queue<iii,vector<iii> , greater<iii> >q;
	for (int i = 0; i < T; i++)
	{
		if (g[0][i])
		{
			dist[0][i] = 0;
			q.push(iii(0,ii(0,i)));
		}
	}

	while (!q.empty())
	{
		iii a = q.top();
		q.pop();
		for (int i = 1; i < 100; i++)
		{
			for (int j = 0; j < T; j++)
			{
				if(j == a.elevador)
				{
					if (g[i][j] && dist[i][j] > (dist[a.andar][a.elevador] + (tempo[j] * abs(i - a.andar))))
					{
						 dist[i][j] = dist[a.andar][a.elevador] + (tempo[j] * abs(i - a.andar));
						 q.push(iii(dist[i][j],ii(i,j)));
					}
				
				}else if(g[i][j] && g[i][a.elevador] && i == a.andar && dist[i][j] > (dist[a.andar][a.elevador] + 60))
				{
					 dist[i][j] = (dist[a.andar][a.elevador] + 60);
					 q.push(iii(dist[i][j],ii(i,j)));
				}
				
			}		
		}	
	}
	int minimo = inf;
	for (int i = 0; i < T; i++)
	{
		minimo = min(dist[k][i],minimo);
	}
	
	return minimo;
}

int main()
{

	string entrada;
	int andares;
	while (scanf("%d%d",&T,&k)!=EOF)
	{
		for (int i = 0; i < T; i++)
		{
			scanf("%d",&tempo[i]);
		}
		getchar();
		for (int i = 0; i < T; i++)
		{
			getline(cin,entrada);
			stringstream f(entrada);
			
			while (f >> andares)
			{
				g[andares][i] = 1;
			}
		}
		int resp = d();
		if (resp == inf)
		{
			puts("IMPOSSIBLE");
		}else
		{
			printf("%d\n",resp);
		}
		for (int i = 0; i < 110; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				g[i][j] = 0;
			}	
		}
	}
}
