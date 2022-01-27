#include <bits/stdc++.h>

using namespace std;
typedef pair<int , pair<int,int> > iii;
typedef pair<int,int>ii;
#define a1 second.first
#define a2 second.second
#define peso first
typedef vector<iii>viii;

viii EDGE;
int pai[2100],tam[2100],v;

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
int mst()
{
	int custo = 0;
	sort(EDGE.begin(), EDGE.end());
	
	int t = EDGE.size();
	
	for (int i = 0; i < t; i++)
	{
		if (find(EDGE[i].a1) != find(EDGE[i].a2))
		{
			custo += EDGE[i].peso;
			unionSet(EDGE[i].a1,EDGE[i].a2);
		}
	}	
	return custo;
}

int main()
{
	
	int n,a,c,cont;
	string s1,s2;
	scanf("%d",&n);
	for (int j = 0; j < n; j++)
	{	
		map<string,int>m;
		if(j > 0)
			puts("");
		scanf("%d%d",&v,&a);
		
		for (int i = 0; i < v; i++)
		{
			pai[i] = i;
			tam[i] = 1;
		}
		
		cont = 1;
		for (int i = 0; i < a; i++)
		{
			cin>>s1>>s2;
			scanf(" %d",&c);
			
			if (!m.count(s1))
			{
				m[s1] = cont;
				cont++;
			}
			
			if (!m.count(s2))
			{
				m[s2] = cont;
				cont++;
			}
			
			EDGE.push_back(iii(c,ii(m[s2],m[s1])));
			EDGE.push_back(iii(c,ii(m[s1],m[s2])));
			
		}
		printf("%d\n",mst());
		EDGE.clear();
	}
	
}
