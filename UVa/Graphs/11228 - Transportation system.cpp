#include <bits/stdc++.h>

using namespace std;
#define max_n 1010
typedef pair<double,pair<int,int> > iii;
typedef pair<int,int> ii;
typedef vector<iii> viii;
#define inf 0x3f3f3f3f
#define peso first
#define a1 second.first
#define a2 second.second

ii vet[max_n];
int pai[max_n],tam[max_n],V;

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
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int T,n,r,numeroEstados;
	double trem,estados;
	scanf("%d",&T);
	
	for (int j = 0; j < T; j++)
	{	
		viii g;
		set<iii>a;
		set<iii>::iterator it;
				
		scanf("%d%d",&n,&r);
		for (int i = 0; i < n; i++)
		{
			pai[i] = i;
			tam[i] = 1;
		}	
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d",&vet[i].first,&vet[i].second);
		}
		for (int i = 0; i < n-1; i++)
		{
			for (int k = i+1; k < n; k++)
			{
				long long x = vet[i].first - vet[k].first;
				long long y = vet[i].second - vet[k].second;
				double conta = sqrt((double)(x*x + y*y));
				g.push_back(iii(conta,ii(i,k)));
				g.push_back(iii(conta,ii(k,i)));
			}	
		}
		double custo = 0;
		sort(g.begin(),g.end());
		int tamanho = g.size();
		for (int i = 0; i < tamanho; i++)
		{	
			if (find(g[i].a1)!=find(g[i].a2))
			{
				custo += g[i].peso;
				unionSet(g[i].a1,g[i].a2);
				a.insert(iii(g[i].peso,ii(g[i].a1,g[i].a2)));
			}
		}
		for (int i = 0; i < n; i++)
		{
			pai[i] = i;
			tam[i] = 1;
		}
		estados = trem = 0;
		for(it = a.begin();it!=a.end(); it++)
		{
			if (it->first <= r)
			{
				unionSet(it->a1,it->a2);
				estados += it->first;
				
			}else
			{
				trem += it->first;
			}
		}
		numeroEstados = 0;
		for (int i = 0; i < n; i++)
		{
			if (pai[i] == i)
			{
				numeroEstados++;	
			}
		}
		printf("Case #%d: %d %d %d\n",j+1,numeroEstados,(int)round(estados),(int)round(trem));
	}
}
