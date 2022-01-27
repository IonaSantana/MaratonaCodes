#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef pair< int, int> ii;
typedef vector< ii > vii;
vii g[20010];
int s,t,n;

int dis()
{
	vector<int>dist(20010,inf);
	
	dist[s] = 0;
	priority_queue <ii,vii, greater<ii> >q;
	q.push(ii(0,s));
	//puts("aan");
	while (!q.empty())
	{
		//puts("aaa");
		ii v = q.top();
		q.pop();
		
		for (int i = 0; i < (int)g[v.second].size(); i++)
		{
			ii a = g[v.second][i];
			if (dist[a.second] > dist[v.second] + a.first)
			{
				dist[a.second] = dist[v.second] + a.first;
				q.push(ii(dist[a.second],a.second));
			}	
		}			
	}
	return dist[t];
}

int main()
{
	int ab,m,a,b,c;
	scanf("%d",&ab);
	for (int j = 1; j <= ab; j++)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
		
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			
			g[a].push_back(ii(c,b));
			g[b].push_back(ii(c,a));
		}
		//printf("sai\n");
		int resp = dis();
		if(resp!=inf)
		{
			printf("Case #%d: %d\n",j,resp);
		}else
		{
			printf("Case #%d: unreachable\n",j);
		}	
		
		for (int i = 0; i < 20010; i++)
		{
			g[i].clear();
		}
	
	}	
}
