#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;

vi acontecimentos[40];
int pd[40];
int maneiras(int indice)
{
	if(acontecimentos[indice].size() == 0)
		return 1;
	
	if(pd[indice] != -1)
		return pd[indice];
	
	pd[indice] = 0;	
	
	for (int i = 0; i < (int)acontecimentos[indice].size(); i++)
	{
		pd[indice] += maneiras(acontecimentos[indice][i]);
	}
	return pd[indice];
}

int main()
{
	int N,num,n,cont = 0;
	while(scanf("%d",&N)!=EOF)
	{
		if(cont > 0)
			puts("");
		cont++;	
		
		for (int j = 0; j < N; j++)
		{
			scanf("%d",&n);
			for (int i = 0; i < n; i++)
			{
				scanf("%d",&num);
				acontecimentos[j].push_back(num);
			}
		}
		memset(pd,-1,sizeof pd);
		printf("%d\n",maneiras(0));
		
		for (int i = 0; i < 40; i++)
		{
			acontecimentos[i].clear();
		}
		
	}
}
