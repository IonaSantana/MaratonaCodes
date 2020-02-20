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
		}else
		{
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
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	long long t,fp,k,aux,resp,flag,tam;
	bool deumerda;
	
	while(scanf("%lld",&t), t)
	{
		tam = primos.size();
		aux = resp = t;
		k = 0;
		fp = primos[k];
		deumerda = 0;
		while (fp*fp <= aux)
		{
			flag = 0;
			while (aux%fp == 0)
			{
				aux/=fp;
				if(flag == 0)
				{
					resp -= resp/fp;
					flag = 1;
				}
			}
			if(k < tam)
				fp = primos[++k];
			else
			{
				deumerda = 1;
				break;
			}
		}
		if (!deumerda && aux > 1)
		{
			resp -= resp/aux;
		}else if(deumerda)
		{
			 deumerda = 0;
			 int s = sqrt(t);
			 for (int i = 2; i <= s; i++)
			 {
				if(aux%i == 0)
				{
					aux/=i;
					resp -= resp/i;
				}
			 }		 
		}
		printf("%lld\n",resp);
	}
}
