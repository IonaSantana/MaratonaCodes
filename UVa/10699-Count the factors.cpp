#include <bits/stdc++.h>

using namespace std;
#define MAX_N 1200
typedef pair<int, int> ii;
bool eprimo[MAX_N];

int main()
{
	int k = 0,j = 2,N,cont;
	vector<int>primos;
	primos.push_back(2);
	eprimo[0] = eprimo[1] = 1;
	// algoritmo de crivo
	while (j < MAX_N - 1)
	{
		for (int i = j + primos[k]; i < MAX_N; i+= primos[k])
		{
			eprimo[i] = 1;
		}
		j = primos[k];
		j++;
		while (eprimo[j])
		{			
			j++;
		}	
		primos.push_back(j);
		k++;
	}
	
	while (scanf("%d",&N), N)
	{	
		int aux,s = sqrt(N);
		aux = N;
		cont = 0;
		for (int i = 0; primos[i] <= s; i++)
		{
			if(N%primos[i] == 0)
			{
				cont++;
				while (N%primos[i] == 0)
				{
					N/=primos[i];
				}
			}						
		}
		if (N > 1)
		{
			cont++;
		}
		
		printf("%d : %d\n",aux,cont);						
	}
}
