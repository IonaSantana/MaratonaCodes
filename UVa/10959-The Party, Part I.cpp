#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;
vi G[1010];
int dist[1010];
void bfs(int u)
{
	for (int i = 0; i < 1010; i++)
	{
		dist[i] = inf;
	}
	dist[u] = 0;
	queue<int>q;
	q.push(u);
	
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		
		for (int i = 0; i < (int)G[a].size(); i++)
		{
			int v = G[a][i];
			if (dist[v] > (dist[a] + 1))
			{
				dist[v] = dist[a] + 1;
				q.push(v);
			}
		}	
	}
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	int N,A,P,lig1,lig2;
	scanf("%d",&N);

	for (int j = 0; j < N; j++)
	{
		if (j)
			puts("");
		scanf("%d%d",&P,&A);
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			G[lig1].push_back(lig2);
			G[lig2].push_back(lig1);
		}
		
		bfs(0);
		
		for (int i = 1; i < P; i++)
		{
			printf("%d\n",dist[i]);
		}
		
		for (int i = 0; i < P; i++)
		{
			G[i].clear();
		}
		
	}	
}
