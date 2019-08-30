#include <bits/stdc++.h>

using namespace std;
#define inf 3000
typedef map<int,set<int> > v;
v G;
int E,dist2;
set<int>::iterator it;
int bfs(int u)
{
	int maxi = 0;
	map<int,int>::iterator itm;
	vector<int>dist(2500,inf);
	map<int,int>maximo;
	dist[u] = 0;
	queue<int>q;
	q.push(u);
	
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (it = G[a].begin(); it!= G[a].end(); it++)
		{
			int v1 = *it;
			//cout<<*it<<endl;
			if (dist[v1] == inf)
			{
				dist[v1] = dist[a] + 1;
				maximo[dist[v1]]++;
				q.push(v1);
			}
		}	
	}
	for (itm = maximo.begin(); itm!= maximo.end(); itm++)
	{
		if(maxi < itm->second)
		{
			maxi = itm->second;
			dist2 = itm->first;
		}	
	}
	return maxi;
}

int main()
{
	//~ freopen("ina123","r",stdin);
	//~ freopen("out123","w",stdout);
	int qt,empregado,T,num;
	scanf("%d",&E);
	for (int i = 0; i < E; i++)
	{
		scanf("%d",&qt);
		for (int j = 0; j < qt; j++)
		{
			scanf("%d",&empregado);
			G[i].insert(empregado);
			//G[empregado].insert(i);
		}
		
	}
	scanf("%d",&T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d",&num);
		if(G[num].size() > 0)
		{
			int resp = bfs(num);
			printf("%d %d\n",resp,dist2);
		}
		else
		{
			puts("0");
		}
	}		
}
