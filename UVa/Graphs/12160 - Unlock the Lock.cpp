#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
int main()
{
	int cont = 1,soma[10000],R,L,U;
	while (scanf("%d%d%d",&L,&U,&R), L || U || R)
	{
		for (int i = 0; i < R; i++)
		{
			scanf("%d",&soma[i]);
		}
		vector<int>dist(10000,inf);
		dist[L] = 0;
		queue<int>q;
		q.push(L);
		
		while (!q.empty())
		{
			int a  = q.front();
			q.pop();
			
			for (int i = 0; i < R; i++)
			{
				int b = a + soma[i],v = 0;
				int c = 0,d = 1;
				while (c < 4)
				{
					c++;
					v += (b%10 * d);
					b/=10;
					d*=10;
				}
				if (dist[v] == inf)
				{
					dist[v] = dist[a] + 1;
					q.push(v);
				}

			}	
		}
		printf("Case %d: ",cont);
		cont++;
		if (dist[U] == inf)
			puts("Permanently Locked");
		else
			printf("%d\n",dist[U]);	
	}
}
