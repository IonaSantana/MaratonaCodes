#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
vi adjlist[100];
int pai[70],res[70][70];

bool bfs(int s, int t)
{
	memset(pai,-1,sizeof pai);
	queue<int>q;
	q.push(s);
	pai[s] = s;
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for (int i = 0; i < (int)adjlist[u].size(); i++)
		{
			int v = adjlist[u][i];
			
			if(pai[v] == -1 && res[u][v])
			{
				pai[v] = u;
				q.push(v);
			}		
		}		
	}
	return (pai[t] != -1);	
}
int maxFlow(int s, int t)
{
	int gargalo,flow = 0, vAtual;
	
	while (bfs(s,t))
	{
		gargalo = inf;
		
		vAtual = t;
		while(vAtual != s)
		{
			gargalo = min(gargalo, res[pai[vAtual]][vAtual]);
			vAtual = pai[vAtual];
		}

		flow += gargalo;
		
		vAtual = t;
		while(vAtual != s)
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
	map<string,int>m;
	int V,A,N;
	string b1,b2;
	scanf("%d",&N);
	for (int j = 0; j < N; j++)
	{
		
		scanf("%d %d",&V,&A);
		memset(res,0 ,sizeof res);
		m["XXL"] = 50;
		m["XL"] = 51;
		m["L"] = 52;
		m["M"] = 53;
		m["S"] = 54;
		m["XS"] = 55;
		for (int i = 1; i <= A; i++)
		{
			cin>>b1>>b2;
			
			adjlist[0].push_back(i);
			adjlist[i].push_back(0);
			res[0][i] = 1;
			
			adjlist[i].push_back(m[b1]);
			adjlist[m[b1]].push_back(i);
			
			adjlist[i].push_back(m[b2]);
			adjlist[m[b2]].push_back(i);
			
			res[i][m[b1]] = 1;
			res[i][m[b2]] = 1;

		}
			
		for (int i = 50; i <= 55; i++)
		{
			adjlist[i].push_back(60);
			adjlist[60].push_back(i);
			res[i][60] = V/6; 

		}

		if(maxFlow(0,60) == A)
			puts("YES");
		else
			puts("NO");
	}	
	
}
