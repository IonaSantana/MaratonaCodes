#include <bits/stdc++.h>

using namespace std;
//bug no 1 e -1
int mp[1000001];
int limite = 1000000;
vector<int>primos;

void crivo()
{
	for (long long i = 2; i <= limite; i++)
	{
		if (mp[i] == 0)
		{
			mp[i] = i;
			primos.push_back(i);		
		}
		
		for (long long j = 0; j <(int)primos.size() && primos[j] <= mp[i] && i*primos[j] <= limite; j++)
		{
			mp[i*primos[j]] = primos[j];
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
		long long fp,i;
		i = 0;
		printa = 0;
		printf("%lld =",n);
		if(n < 0)
		{
			printa++;
			printf(" -1");
			n*=-1;
		}
		fp = primos[0];
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
