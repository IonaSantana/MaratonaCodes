#include <bits/stdc++.h>

using namespace std;
int path[30][30],V,maxi,cont;

void caminho(int u)
{
	//~ cout<<cont<<endl;
	for (int i = 0; i < V; i++)
	{
		if(path[u][i] == 1)
		{
			path[u][i] = 2;
			path[i][u] = 2;
			cont++;
			maxi = max(maxi,cont); 
			caminho(i);	
			cont--;
			path[u][i] = 1;
			path[i][u] = 1;	
		}
	}
	
}

int main()
{
	int A,lig1,lig2;
	
	while (scanf("%d%d",&V,&A), V || A)
	{
				
		for (int i = 0; i < A; i++)
		{
			scanf("%d%d",&lig1,&lig2);
			path[lig1][lig2] = 1;
			path[lig2][lig1] = 1;
		}		
		maxi = 0;
		for (int i = 0; i < V; i++)
		{
			cont = 0;
			caminho(i);
		}	
		printf("%d\n",maxi);
		
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				path[i][j] = 0;
			}			
		}	
	}	
}

