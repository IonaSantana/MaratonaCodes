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
	crivo();
	int t,cont,maiordiv;
	long long n1,n2,aux,maiornum;
	scanf("%d",&t);
	
	for (int j = 0; j < t; j++)
	{
		scanf("%lld%lld",&n1,&n2);
		maiornum = n1;
		maiordiv = 1;
		for (int i = n1; i <= n2 ; i++)
		{
			aux = i;
			long long fp;
			int k = 0,div = 1;
			fp = primos[k];
			while (fp*fp <= aux)
			{
				cont = 0;
				while (!(aux%fp))
				{
					cont++;
					aux/=fp;
				}
				k++;
				fp = primos[k];
				div *= (cont+1);
			}
			if (aux > 1)
			{
				div *= 2;
			}
			if (div > maiordiv)
			{
				maiordiv = div;
				maiornum = i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n",n1,n2,maiornum,maiordiv);	
	}	
}
