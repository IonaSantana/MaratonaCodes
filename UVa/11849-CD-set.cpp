#include <bits/stdc++.h>
using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int cd,n,m,cont;
	set<int> j;
	while (scanf("%d %d",&n,&m), n || m)
	{
		cont = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&cd);
			j.insert(cd);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d",&cd);
			if(j.find(cd) != j.end())
				cont++;
		}
		printf("%d\n",cont);	
		j.clear();	
	}	
}	


