#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,maior,cont;
	vector <int>ler(5);
	while (scanf("%d",&N), N)
	{
		map<vector<int> , int> m;
		map<vector<int> , int>::iterator it;
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				scanf("%d",&ler[i]);
			    
			}
			sort(ler.begin(),ler.end());
			m[ler]++;
			
		}
		maior = cont = 0;
		for (it = m.begin(); it != m.end(); it++)
		{
			if(it->second > maior)
			{
				maior = it->second;
				cont = it->second;
			}else if(maior == it->second)
			{
				cont+= maior;
			}	
		}	
		printf("%d\n",cont);
	}
}


