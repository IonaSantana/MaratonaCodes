#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
typedef vector<int>vi;

vi adjlist[200];
long long pai[200],res[200][200];

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

long long maxFlow(int s,int t)
{
	long long flow = 0, gargalo,vAtual;

	while (bfs(s,t))
	{
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
	}
	return flow;
}

int main()
{	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int v1,v2,maq,c,V,A;
	while (scanf("%d%d",&V,&A), V || A)
	{
		res[1][1 + V] = inf;
		adjlist[1].push_back(1 + V);
		adjlist[1 + V].push_back(1);
		res[V][2*V] = inf;
		adjlist[V].push_back(2*V);
		adjlist[2*V].push_back(V);
		for (int i = 0; i < V - 2; i++)
		{
			scanf("%d%d",&maq,&c);
			adjlist[maq].push_back(maq + V);
			adjlist[maq + V].push_back(maq);
			res[maq][maq + V] = c;
		}
		
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d%d",&v1,&v2,&c);
									
			if(v1 > v2)
				swap(v1,v2);

            if(v1!=1 && v2!=V)
            {
				res[v1 + V][v2] = c;
				res[v2 + V][v1] = c;
				adjlist[v1 + V].push_back(v2);
				adjlist[v2 + V].push_back(v1);
				adjlist[v2].push_back(v1 + V);
				adjlist[v1].push_back(v2 + V);
            }
            else if(v1==1)
			{
				res[1][v2] = c;
				adjlist[1].push_back(v2);
				adjlist[v2].push_back(1);
			}
            else if(v2==V)
            {
                res[v1 + V][V] = c;
                adjlist[v1 + V].push_back(V);
                adjlist[V].push_back(v1 + V);	
			}	
		}
		
		printf("%lld\n",maxFlow(1,2*V));
		for (int i = 0; i < 200; i++)
		{
			adjlist[i].clear();
			for (int j = 0; j < 200; j++)
			{
				res[i][j] = 0;
			}	
		}	
	}

}
