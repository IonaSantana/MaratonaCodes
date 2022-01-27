#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;

vi adjlist[2010];
int pai[2010],res[2010][2010];

bool bfs(int s, int t)
{
	memset(pai,-1,sizeof pai);
	queue<int>q;
	pai[s] = s;
	
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();	
		q.pop();
		
		for (int i = 0; i < (int)adjlist[u].size(); i++)
		{
			int v = adjlist[u][i];
			if (pai[v] == -1 && res[u][v] > 0)
			{
				pai[v] = u;
				q.push(v);
			}	
		}	
	}
	return (pai[t]!= -1);
}

int maxFlow(int s,int t)
{
	int flow = 0, gargalo,vAtual;

	while (bfs(s,t))
	{
		//break;
		gargalo = inf;
		
		vAtual = t;
		while (vAtual != s)
		{
			gargalo = min(gargalo, res[pai[vAtual]][vAtual]);		
			vAtual = pai[vAtual]; 
		}
		
		flow += gargalo;
		
		vAtual = t;
		while (vAtual != s)
		{
			res[pai[vAtual]][vAtual] -= gargalo;
			res[vAtual][pai[vAtual]] += gargalo;		
			vAtual = pai[vAtual]; 
		}
		//break;	
	}
	return flow;
}

int main()
{
	int n,m,cat,i,l,somaCat,j,contE,num[25];
	
	while (scanf("%d%d",&n,&m), n || m)
	{
		somaCat = 0;
		memset(res,0, sizeof res);
		for (i = 1; i <= n; i++)
		{
			scanf("%d",&cat);	
			adjlist[2000].push_back(i);
			adjlist[i].push_back(2000);
			
			res[i][2000] = cat;
			somaCat += cat;
			num[i] = cat;
		}
		
		for (j = i; j < i + m; j++)
		{
			scanf("%d",&l);
			adjlist[j].push_back(0);
			adjlist[0].push_back(j);
			res[0][j] = 1;
			for (int k = 0; k < l; k++)
			{
				scanf("%d",&cat);
				
				adjlist[j].push_back(cat);
				adjlist[cat].push_back(j);
				
				res[j][cat] = 1;	
			}		
		}
		if (maxFlow(0,2000) == somaCat)
		{
			puts("1");
			//reconstrução do grafo, caminho que ele pega
			for (int k = 1; k <= n; k++)
			{	contE = 0;
				for (int z = i; z < j; z++)
				{
					if (res[k][z] == 1)
					{
						printf("%d",z - i + 1);
						contE++;
						if(contE < num[k])	
							printf(" ");				
					}				
				}
				printf("\n");			
			}		
			
		}else
		{
			puts("0");
		}
		for (int i = 0; i < 2010; i++)
		{
			adjlist[i].clear();
		}	
			
	}	
}
