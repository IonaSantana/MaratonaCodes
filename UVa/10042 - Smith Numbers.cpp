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
	long long n,i,aux,n1;
	int t,flag,cont,somas,soman,somaaux,k;
	scanf("%d",&t);
	for (int j = 0; j < t; j++)
	{
		scanf("%lld",&n);
		flag = somas = 0;
		
		for (i = n+1; !flag; i++)
		{
			soman = 0;
			aux = i;
			while (aux)
			{
				soman+=aux%10;
				aux/=10;
			}
			n1 = i;
			k = somas = 0;
			long long fp = primo[k];
			while (fp*fp <= n1)
			{
				cont = 0;
				while(n1%fp == 0)
				{
					cont++;
					n1/=fp;
				}				
				if(cont)
				{
					somaaux = 0;
					aux = primo[k];
					while (aux)
					{
						somaaux += aux%10;
						aux/=10;
					}
					somas += (cont*somaaux);
				}
				fp = primo[++k];
			}
			if (n1 > 1 && n1!=i)
			{
				while (n1)
				{
					somas += n1%10;
					n1/=10;
				}
			}
			if(somas == soman)
				flag = 1;
		}
		printf("%lld\n",i-1);
	}	
}
