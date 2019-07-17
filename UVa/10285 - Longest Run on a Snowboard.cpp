#include <bits/stdc++.h>

using namespace std;
int n,m;
int pd[110][110],matriz[110][110],x[] = {1,0,-1,0}, y[] = {0,-1,0,1};
//DAG para grafos sem ciclo e direcionado
int caminho(int l, int c)
{	
	if(pd[l][c] != -1)
		return pd[l][c];
			
	// porque senão soma -1 no retorno		
	pd[l][c] = 0;
	for (int i = 0; i < 4; i++)
	{
		int a = l + x[i];
		int b = c + y[i];
		
		if((a >= 0 && a < n) && (b >= 0 && b < m) && matriz[a][b] < matriz[l][c])
		{
			pd[l][c] = max(pd[l][c], caminho(a,b) + 1);
		}
	}
	
	return pd[l][c];	
}

int main()
{
	int N,maior;
	string nome;
	scanf("%d",&N);
	for (int j = 0; j < N; j++)
	{
		cin>>nome;
		scanf(" %d%d",&n,&m);
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				scanf("%d",&matriz[i][k]);
			}		
		}
		
		maior = -1;
		memset(pd,-1,sizeof pd);
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				maior = max(maior,caminho(i,k));
			}
			
		}		
		cout<<nome<<": "<<maior+1<<"\n";
	}
}

