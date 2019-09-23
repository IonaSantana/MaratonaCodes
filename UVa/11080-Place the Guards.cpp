#include <bits/stdc++.h>

using namespace std;
typedef vector<int>vi;
int zero,um,res;
vi g[210];
bool pinta[210],visitado[210];
bool dfs(int u)
{
	visitado[u] = 1;
	bool aux = 1;
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (!visitado[v])
		{
			if(pinta[u])
				zero++;
			else
				um++;
			pinta[v] = !pinta[u];
			aux &= dfs(v);
		}else if(pinta[v] == pinta[u])
		{
			return 0;
		}
	}
	return aux;
}

int main()
{
	int V,A,lig1,lig2,N;
	bool flag;
	scanf("%d",&V);
	for (int i = 0; i < V; i++)
	{	
		scanf("%d%d",&N,&A);	
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			g[lig1].push_back(lig2);
			g[lig2].push_back(lig1);
		}			
		res = zero = um = 0;		
		flag = 1;
		for (int i = 0; i < N; i++)
		{
			if(!visitado[i])
			{
				pinta[i] = 1;
				um++;
				if(!dfs(i))
				   flag = 0;
				
				if(um > zero)
				{	
					if(zero)
						res += zero;
					else
						res += um;
				}
				else if(um < zero)
				{
					if(um)
						res += um;
					else
						res += zero;
				}else
				{
					res += um;
				}
			}
			zero = um = 0;
		}
		if(flag)
		{		
			printf("%d\n",res);
		}	
		else
			puts("-1");	
		for (int i = 0; i < 210; i++)
		{
			g[i].clear();
			visitado[i] = pinta[i] = 0;
		}	
	}
}

