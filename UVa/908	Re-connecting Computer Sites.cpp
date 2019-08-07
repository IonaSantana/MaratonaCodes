#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
typedef vector<iii>viii;
#define peso first 
#define a1 second.first
#define a2 second.second
viii G;
int N,pai[1000100],tam[1000100];

void init()
{
	for (int i = 0; i < 1000100; i++)
	{
		tam[i] = 1;
		pai[i] = i;
	}
	
}

int find(int u)
{
	if(u == pai[u])
		return u;
	
	return find(pai[u]);	

}

void UnionSet(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if (tam[a] > tam[b])
	{
		tam[a] += tam[b];
		pai[b] = a;
	}else
	{
		tam[b] += tam[a];
		pai[a] = b;
	}	
}

long long Mst()
{
	long long custo = 0;
	
	sort(G.begin(), G.end());
	
	int t = G.size();
	for (int i = 0; i < t; i++)
	{
		if (find(G[i].a1) != find(G[i].a2))
		{
			custo += G[i].peso;
			UnionSet(G[i].a1,G[i].a2);
		}	
	}
	return custo;
}

int main()
{
	int lig1,lig2,custo,a,K,cont = 0;
	long long soma;
	while (scanf("%d",&N)!=EOF)
	{
		if (cont)
			puts("");
		cont++;		
		init();
		soma = 0;
		for (int i = 0; i < N-1; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&custo);
			soma += custo;
		}
		scanf("%d",&a);
		for (int i = 0; i < a; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&custo);
			G.push_back(iii(custo,ii(lig1,lig2)));
		}
		scanf("%d",&K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&custo);
			G.push_back(iii(custo,ii(lig1,lig2)));
		}
		printf("%lld\n%lld\n",soma,Mst());
		G.clear();
	}
}
