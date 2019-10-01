#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int> > iii;
typedef pair<int,int> ii;
typedef vector<iii> viii;
#define inf 0x3f3f3f3f
#define peso first
#define a1 second.first
#define a2 second.second
#define max_n 110
int pai[max_n],tam[max_n];

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

int main()
{
	int custo,lig1,lig2,A,N,V;
	scanf("%d",&N);
	
	for (int j = 0; j < N; j++)
	{	
		for (int l = 0; l < 110; l++)
		{
			tam[l] = 1;
			pai[l] = l;
		}
		vector<int>distancias;
		viii g;
		set<iii>are;
		set<iii>::iterator it;	
		scanf("%d%d",&V,&A);
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&custo);
			g.push_back(iii(custo,ii(lig1,lig2)));
			g.push_back(iii(custo,ii(lig2,lig1)));
		}
		sort(g.begin(),g.end());
		int tamanho = g.size();
		custo = 0;
		
		for (int i = 0; i < tamanho; i++)
		{
			if (find(g[i].a1) != find(g[i].a2))
			{
				unionSet(g[i].a1,g[i].a2);
				custo += g[i].peso;
				are.insert(iii(g[i].peso,ii(g[i].a1,g[i].a2)));
			}	
		}
		distancias.push_back(custo);
		int custo1 = 0;
		for (it = are.begin(); it!= are.end(); it++)
		{	
			custo1 = 0;
			for (int l = 1; l <= V; l++)
			{
				tam[l] = 1;
				pai[l] = l;
			}
			for (int i = 0; i < tamanho; i++)
			{
				int aresta1 = min(g[i].a1,g[i].a2);
				int aresta2 = max(g[i].a1,g[i].a2);
				int aresta3 = min(it->a1,it->a2);
				int aresta4 = max(it->a1,it->a2);
				if(aresta1 != aresta3 || aresta2!=aresta4 || it->peso!=g[i].peso)
				{ 
					if (find(g[i].a1) != find(g[i].a2))
					{
						unionSet(g[i].a1,g[i].a2);
						custo1 += g[i].peso;
					}	
				}
			}
			int pai1 = find(pai[1]),contando = 1;
			for (int i = 2; i <= V; i++)
			{
				if (find(pai[i])!=pai1)
				{
					contando++;
				}
			}
			if (contando == 1)
			{
				distancias.push_back(custo1);
			}
		}
		sort(distancias.begin(), distancias.end());
		printf("%d %d\n",distancias[0], distancias[1]);
	}
}
