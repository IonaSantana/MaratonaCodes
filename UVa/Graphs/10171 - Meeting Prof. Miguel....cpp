#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
int main()
{	
	int N,d,dist[26][26][2];
	char idade,sit,lig1,lig2,aluno,professor;
	while (scanf("%d",&N),N)
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				dist[i][j][0] = dist[i][j][1] = inf;
			}
		}
		
		for (int i = 0; i < N; i++)
		{
			scanf(" %c %c %c %c %d",&idade,&sit,&lig1,&lig2,&d);
			if(sit == 'U')
			{
				if (idade == 'Y')
				{
					dist[lig1 - 'A'][lig2 - 'A'][0] = d;
				}else
				{
					dist[lig1 - 'A'][lig2 - 'A'][1] = d;
				}
			}
			else
			{
				if (idade == 'Y')
				{
					dist[lig1 - 'A'][lig2 - 'A'][0] = d;
					dist[lig2 - 'A'][lig1 - 'A'][0] = d;
				}else
				{
					dist[lig1 - 'A'][lig2 - 'A'][1] = d;
					dist[lig2 - 'A'][lig1 - 'A'][1] = d;
				}
			}
		}
		scanf(" %c %c",&aluno,&professor);
		
		for (int i = 0 ; i < N; i++)
		{
			dist[i][i][0] = dist[i][i][1] = 0;
		}
		
		dist[aluno - 'A'][aluno - 'A'][0] = dist[professor - 'A'][professor - 'A'][1] = 0;
		for(int k = 0;  k < 26; k++)
		{
			for(int i = 0;  i < 26; i++)
			{
				for(int j = 0;  j < 26; j++)
				{
					for (int l = 0; l < 2; l++)
					{
						dist[i][j][l] = min(dist[i][j][l], (dist[i][k][l] + dist[k][j][l]));
					}								
				}
			} 
		}
		int minimo = inf;
		set<char>imprime;

		for (int j = 0; j < 26; j++)
		{
			int soma = dist[aluno - 'A'][j][0] + dist[professor - 'A'][j][1];
			if (soma <= minimo && soma != inf)
			{	
				if(soma < minimo)
				{
					imprime.clear();
					minimo = soma;
				}
				imprime.insert(j + 'A');	
			}
		}		
		
		if (minimo == inf)
		{
			puts("You will never meet.");
		}else
		{
			printf("%d",minimo);
			for (set<char>::iterator it = imprime.begin(); it!=imprime.end();it++)
			{
				printf(" %c",*it);
			}
			puts("");
		}	
	}
}
