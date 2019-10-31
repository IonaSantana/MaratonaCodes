#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
typedef pair<int,int>ii;
int main()
{
	int m1,m2,p1,p2,x[] = {1,0,-1,0}, y[] = {0,1,0,-1},maiorx,maiory,dist[2010][2010];
	while (scanf("%d",&m1), m1)
	{
		queue<ii>q;
		maiorx = maiory = 0;
		vector<ii>mall2;
		for (int i = 0; i < 2010; i++)
		{
			for (int j = 0; j < 2010; j++)
			{
				dist[i][j] = inf;
			}	
		}
		
		for (int i = 0; i < m1; i++)
		{
			scanf("%d%d",&p1,&p2);
			maiorx = max(maiorx,p1);
			maiory = max(maiory,p2);
			q.push(ii(p1,p2));
			dist[p1][p2] = 0;
		}
		
		scanf("%d",&m2);
		for (int i = 0; i < m2; i++)
		{
			scanf("%d%d",&p1,&p2);
			maiorx = max(maiorx,p1);
			maiory = max(maiory,p2);
			mall2.push_back(ii(p1,p2));	
		}
		
		while (!q.empty())
		{
			ii a = q.front();
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int l = a.first + x[i];
				int c = a.second + y[i];
				if (l >= 0 && l <= maiorx && c >= 0 && c <= maiory && dist[l][c] == inf)
				{
					dist[l][c] = dist[a.first][a.second] + 1;
					q.push(ii(l,c));
				}
			}		
		}
		int tam = mall2.size(),minimo = inf;
		for (int i = 0; i < tam; i++)
		{
			minimo = min(minimo,dist[mall2[i].first][mall2[i].second]);
		}
		if(!minimo)
			minimo++;
		
		printf("%d\n",minimo);
	}
}
