#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
typedef vector<ii>vii;
typedef vector<iii>viii;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int M,T,lig1,lig2,peso,N,s,t,p;
	long long dist[10010],dist1[10010];
	bool vis[10010],vis1[10010];
	scanf("%d",&T);
	for (int j = 0; j < T; j++)
	{
		viii edges;
		vii g[10010],g1[10010];
		scanf("%d%d%d%d%d",&N,&M,&s,&t,&p);
		for (int i = 1; i <= N; i++)
		{		
			dist[i] = dist1[i] = inf;	
			vis[i] = vis1[i] = 0;				
		}
		
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&peso);
			g[lig1].push_back(ii(peso,lig2));
			g1[lig2].push_back(ii(peso,lig1));			
		}
				
		priority_queue<ii , vector < ii > , greater <ii> >q;
		dist[s] = 0;
		q.push(ii(0,s));
		
		while (!q.empty())
		{
			ii a = q.top();
			q.pop();
			
			if(!vis[a.second])
			{	
				vis[a.second] = 1;
				for (int i = 0; i < (int)g[a.second].size(); i++)
				{
					ii v = g[a.second][i];
					
					if (dist[v.second] > (a.first + v.first))
					{
						dist[v.second] = a.first + v.first;
						q.push(ii(dist[v.second],v.second));
					}
				}	
			}	
		}
		
		dist1[t] = 0;
		q.push(ii(0,t));
		
		while (!q.empty())
		{
			ii a = q.top();
			q.pop();
			if(!vis1[a.second])
			{
				vis1[a.second] = 1;
				for (int i = 0; i < (int)g1[a.second].size(); i++)
				{
					ii v = g1[a.second][i];
					
					if (dist1[v.second] > (a.first + v.first))
					{
						dist1[v.second] = a.first + v.first;
						q.push(ii(dist1[v.second],v.second));
					}
				}	
			}
		}
		int resp = -1;
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < (int)g[i].size(); j++)
			{
				if (dist[i] + dist1[g[i][j].second] + g[i][j].first <= p)
				{
					resp = max(resp,g[i][j].first);
				}
			}		
		}
		
		printf("%d\n",resp);			
	}
}

