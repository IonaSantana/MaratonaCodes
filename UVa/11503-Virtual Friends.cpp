#include <bits/stdc++.h>

using namespace std;
int pai[200010],tam[200010];

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
	int n, t,cont;
	string n1,n2;
	scanf("%d",&n);
	for (int j = 0; j < n; j++)
	{
		map<string,int>m;
		scanf(" %d",&t);
		//getchar();
		
		for (int i = 1; i <= t*2; i++)
		{
			pai[i] = i;
			tam[i] = 1;
		}
		cont = 1;

		for (int i = 0; i < t; i++)
		{
			cin>>n1>>n2;
			
			if(!(m.count(n1)))
			{
				m[n1] = cont;
				cont++;
			}
			if(!(m.count(n2)))
			{
				m[n2] = cont;				
				cont++;
			}
	
			if(find(m[n1]) != find(m[n2]))
			{
				unionSet(m[n1],m[n2]);
			}
	
			printf("%d\n",tam[find(m[n1])]);
		}			
	}		
}
