#include <bits/stdc++.h>

using namespace std;
typedef pair<double,pair<int,int> > iii;
typedef pair<int,int> ii;
#define inf 0x3f3f3f3f
#define peso first
#define a1 second.first
#define a2 second.second

typedef vector<iii> viii;
viii EDGE;
int pai[510],tam[510],V;

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

void init()
{
	for (int i = 0; i < V; i++)
	{
		pai[i] = i;
		tam[i] = 1;
	}

}
int main()
{
	int A,T;
	ii vet[510];
	scanf("%d",&T);
	for(int j = 0; j < T; j++)
	{
		scanf("%d%d",&A,&V);
		init();
		for (int i = 0; i < V; i++)
		{
			scanf("%d %d",&vet[i].first,&vet[i].second);
		}
		for (int i = 0; i < V; i++)
		{
			for (int k = i+1; k < V; k++)
			{
				long long x = vet[i].first - vet[k].first;
				long long y = vet[i].second - vet[k].second;
				double conta = sqrt((double)(x*x + y*y));
				EDGE.push_back(iii(conta,ii(i,k)));
				EDGE.push_back(iii(conta,ii(k,i)));
				//cout<<conta<<endl;
			}
		}
		stack<double>s;
		double custo = 0;
		sort(EDGE.begin(), EDGE.end());
		int t = EDGE.size();
		for (int i = 0; i < t; i++)
		{
			if(find(EDGE[i].a1) != find(EDGE[i].a2))
			{
				//~ cout<<EDGE[i].peso<<endl;
				custo += EDGE[i].peso;
				unionSet(EDGE[i].a1,EDGE[i].a2);
				s.push(EDGE[i].peso);
			}
		}
		while (A && !s.empty())
		{
			A--;
			custo = s.top();
			s.pop();
		}
		printf("%.2lf\n",custo);
		EDGE.clear();
	}
}


