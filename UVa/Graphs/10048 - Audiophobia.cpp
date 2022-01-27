#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int> > iii;
typedef pair<int,int> ii;
#define peso first 
#define a1 second.first
#define a2 second.second
#define inf 0x3f3f3f3f
typedef vector<iii> viii;
viii EDGE;
int pai[110],tam[110],N,dist[110][110];

int find(int u)
{
	if(pai[u] == u)
		return u;

	return find(pai[u]);	
}
void unionSet(int a, int b)
{
	a = find(a);
	b = find(b);

	if (tam[a] > tam[b])
	{
		pai[b] = a;
		tam[a] += tam[b];

	}else
	{
		pai[a] = b;
		tam[b] += tam[a];
	}	
}
void kruskal()
{
	sort(EDGE.begin(), EDGE.end());

	int t = EDGE.size();
	for (int i = 0; i < t; i++)
	{
		if(find(EDGE[i].a1) != find(EDGE[i].a2))
		{
			dist[EDGE[i].a1][EDGE[i].a2] = EDGE[i].peso;
			dist[EDGE[i].a2][EDGE[i].a1] = EDGE[i].peso;
			unionSet(EDGE[i].a1,EDGE[i].a2);
		}
	}

}
void init()
{
	for (int i = 1; i <= N; i++)
	{
		pai[i] = i;
		tam[i] = 1;
		EDGE.clear();
	}
	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			dist[i][j] = inf;
		}	
	}
}
int main()
{
	int lig1,lig2,A,pes,Q,cont = 1;
	while(scanf("%d %d %d",&N,&A,&Q), N || A || Q)
	{
		init();
		if(cont > 1)
			puts("");
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&pes);
			EDGE.push_back(iii(pes,ii(lig1,lig2)));	
			EDGE.push_back(iii(pes,ii(lig2,lig1)));	
		}	

		//~ for (int i = 1; i <=N; i++)
		//~ {
			//~ dist[i][i] = 0;
		//~ }
		kruskal();
		for(int k = 1;  k <= N; k++)
		{
			 for(int i = 1;  i <= N; i++)
			 {
				 for(int j = 1;  j <= N; j++)
				 {
					dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
				 }
			 } 
		}
		printf("Case #%d\n",cont);
		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			if(dist[lig1][lig2] < inf)
			{
				printf("%d\n",dist[lig1][lig2]);
			}else
			{
				puts("no path");
			}
		}
		cont++;	
	}
}
