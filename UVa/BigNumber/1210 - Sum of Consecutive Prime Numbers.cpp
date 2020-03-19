#include <bits/stdc++.h>

using namespace std;
bitset<100010>bs;
vector<int>primo;
int limite = 100000;
int resp[100010];
void crivo()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= limite ; i++)
	{
		if (bs[i])
		{
			resp[i]++;
			primo.push_back(i);
			for (long long j = i*i; j <= limite; j+=i)
			{
				bs[j] = 0;
			}		
		}
	}
}
int main()
{
	crivo();
	int n,tam,j,soma,k;
	tam = primo.size();
	
	for (int i = 2; i <= 70; i++)
	{
		soma = 0;
		k = 0;
		for (j = 0; j < i; j++)
		{
			soma += primo[j];
		}	
		while (soma <= limite && j < tam)
		{
			resp[soma]++;
			soma -= primo[k++];
			soma += primo[j];
			j++;
		}	
	}
	
	while (scanf("%d",&n), n)
	{
		printf("%d\n",resp[n]);
	}
}
