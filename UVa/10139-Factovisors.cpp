#include <bits/stdc++.h>

using namespace std;
#define MAX_N 80100
typedef pair<int, int> ii;
bool eprimo[MAX_N];

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int k = 0,j = 2,n,m;
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
	
	while (scanf("%d %d",&n,&m)!=EOF)
	{	
		map<int,int> fat,num;
		map<int,int>::iterator it;
		int s = sqrt(m),aux = m,cont = 0;
		for (int i = 0; primos[i] <= s; i++)
		{
			while (aux%primos[i] == 0)
			{
				num[primos[i]]++;
				aux/=primos[i];
			}		
		}
		
		if(aux > 1)
			num[aux]++;

		s = primos.size();
		for (it = num.begin(); it!=num.end(); it++)
		{
			for (long long j = it->first; j <= (long long)n; j*=it->first)
			{
				fat[it->first]+=((long long)n)/j;
			}		
		}
		
		for (it = num.begin(); it!=num.end(); it++)
		{
			//printf("%d ",fat[it->first]);
			if (fat[it->first] >= it->second)
			{
				cont++;
			}else
			{
				break;
			}	
		}
		//puts("");
		if (cont == (int)num.size())
		{
			printf("%d divides %d!\n",m,n);
		
		}else
		{
			printf("%d does not divide %d!\n",m,n);
		}
							
	}
}
