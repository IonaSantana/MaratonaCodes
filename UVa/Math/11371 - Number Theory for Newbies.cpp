#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,aux,m,maior,menor;
	
	while (scanf("%lld",&n)!=EOF)
	{
		map<int,int>dig;
		map<int,int>::iterator it;
		
		aux = n;
		while (aux)
		{
			dig[aux%10]++;
			aux/=10;
		}
		m = 1;
		maior = 0;
		
		for (it = dig.begin(); it != dig.end(); it++)
		{
			for (int i = 0; i < it->second; i++)
			{
				maior += (m * it->first);
				m*=10;
			}		
		}
		menor = 0;
		m/=10;
		it = dig.begin();
		if(it->first == 0)
		{
			it++;
			it->second--;
			menor += (m*it->first);
			m/=10;		
		}
		for (it = dig.begin(); it != dig.end(); it++)
		{
			for (int i = 0; i < it->second; i++)
			{
				menor += (m * it->first);
				m/=10;
			}		
		}
		printf("%lld - %lld = %lld = 9 * %lld\n",maior, menor, maior-menor,(maior - menor)/9);
	}
}
