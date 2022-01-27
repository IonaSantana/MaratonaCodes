
#include <bits/stdc++.h>

using namespace std;
int pai[50010],tam[50010];

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
	
	if (tam[b] > tam[a])
	{
		pai[a] = b;
		tam[b] += tam[a];
		
	}else
	{
		pai[b] = a;
		tam[a] += tam[b];
	}
	
}

int main()
{
	int a1,a2,m,n,cont=1;

	while(scanf("%d %d",&n,&m), n || m)
	{
		set<int>quantos;
		for (int i = 0; i < n; i++)
		{
			pai[i] = i;
			tam[i] = 1;
		}		

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d",&a1,&a2);
			if(find(a1) != find(a2))
				unionSet(a1,a2);
		}
		
		for (int i = 0; i < n; i++)
		{
			quantos.insert(find(pai[i]));
		}
		printf("Case %d: %d\n",cont,(int)quantos.size());
		cont++;
	}	
}
