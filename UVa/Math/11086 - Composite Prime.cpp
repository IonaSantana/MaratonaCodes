#include <bits/stdc++.h>

using namespace std;

bitset<10000001>bs;
int limite = 10000000;
vector<int>primos;

void crivo()
{
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (long long i = 2; i <= limite; i++)
	{
		if (bs[i])
		{
			primos.push_back(i);
			for (long long j = i*i; j <= limite ; j+=i)
			{
				bs[j] = 0;
			}			
		}
	}	
}

int main()
{
	int cont,resp,t;
	long long n;
	crivo();
	while (scanf("%d",&t)!=EOF)
	{
		resp = 0;
		for (int i = 0; i < t; i++)
		{
			cont = 0;
			scanf("%lld",&n);
			long long fp;
			int j = 0;
			fp = primos[j];
			
			while (fp*fp <= n)
			{
				while (!(n%fp))
				{
					cont++;
					n/=fp;
				}
				fp = primos[++j];
			}
			
			if (n!=1)
			{
				cont++;
			}
			if (cont == 2)
			{
				resp++;
			}
		}
		printf("%d\n",resp);
	}
}
