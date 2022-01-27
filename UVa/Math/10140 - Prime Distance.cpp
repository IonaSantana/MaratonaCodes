#include <bits/stdc++.h>

using namespace std;
vector<long long>primo;
int limite = 10000000;
bitset<10000010>bs;

void crivo()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= limite; i++)
	{
		if (bs[i])
		{
			primo.push_back(i);
			for (long long j = i*i; j <= limite; j+=i)
				bs[j] = 0;
		}
	}	
}

int main()
{
	crivo();
	long long n1,k,n,m,i,tam,tam1,minimo,maximo,p1,p2,p3,p4;
	
	while (scanf("%lld%lld",&n,&m)!=EOF)
	{
		vector<long long>primos;
		tam1 = primo.size();
		for (i = n; i <= m; i++)
		{
			n1 = i;
			k = 0;
			long long fp = primo[k];
			while (fp*fp <= n1)
			{
				if(n1%fp == 0)
				{
					fp = n1;
					n1/=fp;
				}	
				if(k+1 < tam1)
					fp = primo[++k];
				else
					fp=n1;
			}
			if (n1 == i && i!=1)
			{
				primos.push_back(i);
			}
		}
		tam = primos.size();
		minimo = 2200000000;
		maximo = 0;
		for (i = 0; i < tam-1; i++)
		{
			long long dist = primos[i+1] - primos[i];
			if (dist > maximo)
			{
				maximo = dist;
				p3 = primos[i];
				p4 = primos[i+1];
			}
			
			if (dist < minimo)
			{
				minimo = dist;
				p1 = primos[i];
				p2 = primos[i+1];
			}
		}
		
		if(maximo)
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p1,p2,p3,p4);	
		else
			puts("There are no adjacent primes.");				
	}
}
