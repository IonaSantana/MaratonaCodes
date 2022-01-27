#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
int main()
{
	int N,M,lig1,lig2;
	while (scanf("%d%d",&N,&M), N || M)
	{
		vi entrada(110,0),g[110],top_order;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			g[lig1].push_back(lig2);
		}
		
		//Sort Topological
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j <(int)g[i].size(); j++)
			{
				entrada[g[i][j]]++;
			}	
		}
		
		queue<int>q;
		
		for (int i = 1; i <= N; i++)
		{
			if(!entrada[i])
				q.push(i);
		}
		
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			top_order.push_back(u);
			
			for (int i = 0; i < (int)g[u].size(); i++)
			{
				if (--entrada[g[u][i]] == 0)
					q.push(g[u][i]);
			}	
		}
		
		int tam = top_order.size();
		printf("%d",top_order[0]);
		for (int i = 1; i < tam; i++)
		{
			printf(" %d",top_order[i]);
		}
		puts("");		
	}
}
