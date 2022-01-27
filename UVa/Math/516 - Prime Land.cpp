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
	crivo();
	long long numero,n,aux,cont;
	string leitura;
	
	while (getline(cin,leitura), leitura[0]!='0')
	{
		numero = 1;
		cont = 0;
		map<int,int>frequencia;
		map<int,int>::iterator it;
		stringstream f(leitura);
		
		while (f>>n)
		{
			if(cont%2)
			{
				for (int i = 0; i < n; i++)
				{
					numero*=aux;
					
				}				
			}
			else
			{
				aux = n;
			}
			cont++;
		}	
		numero--;
		
		long long fp;
		int j = 0;
		fp = primos[j];

		while (fp*fp <= numero)
		{	
			while (numero%fp == 0)
			{
				frequencia[fp]++;
				numero/=fp;
			}
			fp = primos[++j];
		}
		
		if (numero > 1)
		{
			frequencia[numero]++;
		}	
		it = frequencia.end();
		it--;
		for ( ; it!= frequencia.begin(); it--)
		{
			printf("%d %d ",it->first, it->second);
		}
		printf("%d %d\n",it->first, it->second);		
	}
}
