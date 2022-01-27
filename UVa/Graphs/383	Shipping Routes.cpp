#include <bits/stdc++.h>

using namespace std;
#define inf 1e9
typedef vector<int>vi;

vi G[40];

int bfs(int inicio, int fim)
{
	vi dist(40,inf);
	dist[inicio] = 0;
	queue<int>q;
	q.push(inicio);
	
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		
		for (int i = 0; i < (int)G[a].size(); i++)
		{
			int v = G[a][i];
			if (dist[v] == inf)
			{
				dist[v] = dist[a] + 1;
				q.push(v);
			}
		}
	}

	return dist[fim];
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int t,M,N,P,num;
	string ent,ent1;
	puts("SHIPPING ROUTES OUTPUT\n");
	scanf("%d",&t);
	
	for (int j = 0; j < t; j++)
	{
		map<string,int>m;
		printf("DATA SET  %d\n\n",j+1);
		scanf("%d%d%d",&M,&N,&P);
		
		for (int i = 1; i <= M; i++)
		{
			cin>>ent;
			m[ent] = i;
		}
		for (int i = 0; i < N; i++)
		{
			cin>>ent>>ent1;

			G[m[ent]].push_back(m[ent1]);
			G[m[ent1]].push_back(m[ent]);
		}				
		for (int i = 0; i < P; i++)
		{
			scanf(" %d",&num);
			getchar();
			cin>>ent>>ent1;

			if (m.count(ent) && m.count(ent1))
			{
				int res = bfs(m[ent], m[ent1]);
				if(res == inf)
					puts("NO SHIPMENT POSSIBLE");
				else
					printf("$%d\n",num*res*100);	
			}else
			{
				puts("NO SHIPMENT POSSIBLE");
			}
		}
		puts("");
		for (int i = 0; i < 40; i++)
		{
			G[i].clear();
		}
		
	}
	puts("END OF OUTPUT");
}


