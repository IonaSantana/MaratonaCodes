#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int> > iii;
typedef pair<int,int> ii;
typedef set<int>vi;
vi s;
vi::iterator it;
#define peso first 
#define a1 second.first
#define a2 second.second
#define inf 0x3f3f3f3f
typedef vector<iii> viii;
viii EDGE;
int pai[1010],tam[1010],N,dist[1010][1010];

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
			unionSet(EDGE[i].a1,EDGE[i].a2);
		}else
		{
			s.insert(EDGE[i].peso);
		}
	}
}
void init()
{
	 for (int i = 0; i < N; i++)
	{
		pai[i] = i;
		tam[i] = 1;
		EDGE.clear();
		s.clear();
	}

}
int main()
{
	int lig1,lig2,A,pes,Q,cont = 1;
	while(scanf("%d %d",&N,&A), N || A)
	{
		init();
		if(cont > 1)
			puts("");
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d%d",&lig1,&lig2,&pes);
			EDGE.push_back(iii(pes,ii(lig1,lig2)));		
		}	
		kruskal();
		
		int tamanho = s.size();
		if(tamanho)
		{
			it = s.begin();
			printf("%d",*it);
			it++;
			for (; it!= s.end(); it++)
			{
				printf(" %d",*it);
			}
			puts("");	
		}
		else
			puts("forest");
		
	}
}
