#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
int main()
{
	int V,A,cont = 1,maximo,contador = 1,mat[60][60];
	bool flag;
	string nome1,nome2;
	
	while (scanf("%d%d",&V,&A), V || A)
	{	
		map<string,int>m;
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				mat[i][j] = inf;
			}
		}
		
		cont = 1;
		for (int i = 0; i < A; i++)
		{
			cin>>nome1>>nome2;
			if (m.count(nome1)==0)
			{
				m[nome1] = cont;
				cont++;
			}
			if (m.count(nome2)==0)
			{
				m[nome2] = cont;
				cont++;
			}
			
			mat[m[nome1]][m[nome2]] = 1;
			mat[m[nome2]][m[nome1]] = 1;
			
		}
		
		for (int i = 1; i <= V; i++)
		{
			mat[i][i] = 0;
		}
		for (int k = 1; k <= V; k++)
		{
			for (int j = 1; j <= V; j++)
			{
				for (int i = 1; i <= V; i++)
				{
					 mat[i][j] = min(mat[i][j], (mat[i][k] + mat[k][j]));
				}
				
			}
			
		}
		flag = 0;
		maximo = 0;
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if(mat[i][j] == inf)
				{
					flag = 1;
					break;
				}
				maximo = max(mat[i][j],maximo);
			}
		}
		printf("Network %d:",contador);
		contador++;
		if(!flag)
			printf(" %d\n",maximo);
		else
			puts(" DISCONNECTED");
		puts("");
	}
}
