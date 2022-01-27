#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,n1,cont = 1;
	while (scanf("%d",&n), n >= 0)
	{
		vector<int>altura;
		altura.push_back(n);
		while (scanf("%d",&n1), n1 >= 0)
		{
			altura.push_back(n1);
		}
		reverse(altura.begin(),altura.end());
		int tam = altura.size();
		vector<int>L;
		for (int i = 0; i < tam; i++)
		{
			int pos = (upper_bound(L.begin(),L.end(),altura[i]) - L.begin());
			if(pos == (int)L.size())
				L.push_back(altura[i]);
			else
				L[pos] = altura[i];		
		}
		
		if(cont > 1)
			puts("");
		printf("Test #%d:\n",cont);
		cont++;
		printf("  maximum possible interceptions: %d\n",(int)L.size());
	}
}
