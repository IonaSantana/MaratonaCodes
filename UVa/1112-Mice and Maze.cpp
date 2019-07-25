#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef pair< int, int> ii;
typedef vector< ii > vii;
vii g[110];
int E;

int dis(int s)
{
	vector<int>dist(110,inf);
	
	dist[s] = 0;
	priority_queue <ii,vii, greater<ii> >q;
	q.push(ii(0,s));
	while (!q.empty())
	{
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
	return dist[E];
}

int main()
{
	int ab,resp,M,N,T,c,a,b;
	scanf("%d",&ab);
	for (int j = 1; j <= ab; j++)
	{	
		resp = 0;
		scanf("%d%d%d%d",&N,&E,&T,&M);
		
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a].push_back(ii(c,b));
		}
		
		for (int i = 1; i <= N; i++)
		{
			if(dis(i) <= T)
			{
				resp++;
			}
		}	
		if(j > 1)
			puts("");
		printf("%d\n",resp);
		for (int i = 0; i < 110; i++)
		{
			g[i].clear();
		}
		
	}	
}
