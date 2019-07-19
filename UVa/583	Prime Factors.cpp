#include <bits/stdc++.h>

using namespace std;
#define MAX_N 80200
typedef pair<int, int> ii;
bool eprimo[MAX_N];

int main()
{
	int k = 0,j = 2,N,flag = 0;
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
		flag = 0;	
		printf("%d = ",N);
		if(N < 0)
		{
			N*=(-1);
			flag = 1;
			printf("-1");
		}	
		
		int s = sqrt(N);
		for (int i = 0; primos[i] <= s; i++)
		{
			while (N%primos[i] == 0)
			{	
				if(flag)
					printf(" x ");
				printf("%d",primos[i]);
				N/=primos[i];
				flag = 1;
			}
			
		}
		if(N > 1)
		{
			if(flag)
				printf(" x ");
			printf("%d",N);	
		}
		puts("");							
	}
}
