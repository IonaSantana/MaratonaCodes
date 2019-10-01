#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef vector<ii>vii;
int main()
{
	int n,V,A,lig1,lig2,peso;
	scanf("%d",&n);
	
	for (int k = 0; k < n; k++)
	{	
		vii g[1010];
		scanf("%d%d",&V,&A);
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&peso);
			g[lig1].push_back(ii(lig2,peso));
		}
		vector<int>dist(1010,0x3f3f3f3f);
		dist[0] = 0;
		
		for (int i = 0; i < V-1; i++)
		{
			for (int u = 0; u < V; u++)
			{
				for (int j = 0; j < (int)g[u].size(); j++)
				{
					ii v = g[u][j];
					dist[v.first] = min(dist[v.first],dist[u] + v.second);
				}	
			}
		}
		
		bool cicloNegativo = 0;
		for (int u = 0; u < V; u++)
		{
			for (int j = 0; j < (int)g[u].size(); j++)
			{
				ii v = g[u][j];
				if (dist[v.first] > dist[u] + v.second)
				{
					cicloNegativo = 1;
				}
			}	
		}
		
		if (cicloNegativo)
			puts("possible");
		else
			puts("not possible");
	}
	
}
