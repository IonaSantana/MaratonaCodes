#include <bits/stdc++.h>

using namespace std;
#define inf 500
typedef vector<int>v;
int V,TTL,no,cont,total,c;
v G[400];

void bfs(int u)
{
	vector<int>dist(c+5,inf);
	
	queue<int>q;
	dist[u] = 0;
	q.push(u);
	
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		
		for (int i = 0; i < (int)G[a].size(); i++)
		{
			int v1 = G[a][i];
			if (dist[v1] > dist[a] + 1)
			{		
				total++;	
				dist[v1] = dist[a] + 1;
				if(dist[v1] > TTL)
				{
					cont++;
				}
				q.push(v1);
			}
		}	
	}
}

int main()
{
	int TTL1,no1,test=1;
	while (scanf("%d",&V) && V)
	{	map<long long,int>m;
		c = 1;
		for (int i = 0; i < V; i++)
		{
			scanf("%d%d",&no,&TTL1);
			if(m.count(no)==0)
			{
				m[no] = c;
				c++;
			}	
			if(m.count(TTL1)==0)
			{
				m[TTL1] = c;
				c++;
			}
			G[m[no]].push_back(m[TTL1]);
			G[m[TTL1]].push_back(m[no]);
			
		}
		
		while (scanf("%d%d",&no1,&TTL) && (no1 || TTL))
		{
			if(m.count(no1) == 0)
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test,c - 1,no1,TTL);
			else
			{
				cont = 0;
				total = 1;
				bfs(m[no1]);
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test,c - 1 - total + cont,no1,TTL);			
			}	
			test++;
		}
		for (int i = 0; i < 400; i++)
		{
			G[i].clear();
		}
	}

}
