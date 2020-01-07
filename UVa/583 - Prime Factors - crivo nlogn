#include <bits/stdc++.h>

using namespace std;

bitset<1000001>bs;
int limite = 1000000;
vector<int>primos;

void crivo()
{
	bs.set();
	bs[0] = bs[1] = false;
	
	for (long long i = 2; i <= limite; i++)
	{
		if (bs[i] = true)
		{
			primos.push_back(i);
			for (long long j = i*i; j <= limite ; j+=i)
			{
				bs[j] = false;
			}		
		}
	}	
}
int main()
{
	long long n;
	int printa = 0;
	crivo();
	
	while (scanf("%lld",&n), n)
	{
		long long i,fp;
		printa = 0;
		i = 0;
		fp = primos[i];
		printf("%lld =",n);
		if(n < 0)
		{
			printa++;
			printf(" -1");
			n*=-1;
		}
		while (fp*fp <= n)
		{
			while (n%fp == 0)
			{
				if(printa)
				{
					printf(" x");
				}
				printf(" %lld",fp);
				n /= fp;
				printa++;
			}	
			fp = primos[++i];
		}
		if (n != 1)
		{
			if(printa)
			{
				printf(" x");
			}
			printf(" %lld",n);
		}
		puts("");
	}
	

}
