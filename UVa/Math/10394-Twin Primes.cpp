#include <bits/stdc++.h>

using namespace std;
#define MAX_N 20000000
typedef pair<int, int> ii;
bool eprimo[MAX_N];

int main()
{
	int k = 0,j = 2,N;
	vector<int>primos;
	vector<ii>par;
	primos.push_back(2);
	eprimo[0] = eprimo[1] = 1;
	
	while (j < MAX_N - 1)
	{
		//puts("loop");
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
		//printf("%d",primos[k]);
	}
	
	int tam = primos.size() - 1;
	for (int i = 0; i < tam; i++)
	{
		if (primos[i] + 2 == primos[i+1])
		{
			par.push_back(ii(primos[i],primos[i+1]));
		}
	}
	
	while (scanf("%d",&N)!=EOF)
	{		
		printf("(%d, %d)\n",par[N-1].first,par[N-1].second);				
	}
	
}
