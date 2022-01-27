#include <bits/stdc++.h>

using namespace std;

bitset<10000001>bs;
int limite = 10000000;
vector<int>primos;

void crivo()
{
	bs.set();
	bs[0] = bs[1] = 1;
	
	for (long long i = 2; i <= limite ; i++)
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
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	crivo();
	long long numero,n,resp,fp,i,t,vai,cont;
	
	while (scanf("%lld",&numero), numero)
	{
		if(numero < 0)
			numero*=-1;

		resp = 1;
		n = numero;
		i = cont = 0;
		fp = primos[i];
		t = primos.size();
		while (fp*fp <= n)
		{
			bool flg = 0;
			while (n%fp == 0)
			{
				resp = fp;
				n /= fp;
				if(!flg)
					cont++,flg = 1;
			}
			if(i == t)
				break;
			else	
				fp = primos[++i];
		}
		if(i == t)
		{
			int k,s = sqrt(n);
			vai = n;
			for (k = 2; k <= s; k++)
			{
				if(n%k ==0)
				{
					vai/=k;
				}
			}
			
			if (k > s)
			{
				cont++;
				resp = numero;
			}else
			{
				i = 0;
				fp = primos[i];
				t = primos.size();
				while (fp*fp <= vai)
				{
					bool flg = 0;
					while (vai%fp == 0)
					{
						resp = fp;
						vai /= fp;
						if(!flg)
							cont++,flg = 1;
					}					
					fp = primos[++i];
				}
				if(vai > 1)
					resp = vai;
			}					
		}else
		{
			if (n > 1)
			{
				cont++;
				resp = n;
			}
		}	
		if(resp == numero || cont == 1)
			printf("-1\n");
		else
			printf("%lld\n",resp);
		
	}
}
