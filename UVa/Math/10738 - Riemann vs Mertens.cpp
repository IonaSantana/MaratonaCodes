#include <bits/stdc++.h>

using namespace std;
int limite = 1000000;
bitset<1000001>bs;
vector<int>primo;
void crivo()
{
	bs.set();
	bs[0] = bs[1] = 0;
	
	for (long long i = 2; i <= limite; i++)
	{
		if(bs[i])
		{
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
	int n,n1,contprimo,k,free,respf;
	pair<int,int> vetM[1000010];
	long long fp;
	crivo();
	vetM[1].first = vetM[1].second = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		k = contprimo = free = 0;
		respf = -1;
		n1 = i;
		fp = primo[k];
		while (fp*fp <= n1)
		{
			free = 0;
			while (n1%fp == 0)
			{
				n1/=fp;
				contprimo++;
				free++;
			}
			fp = primo[++k];
			if (free > 1)
				respf = 0;
		}
		
		if(respf)
		{
			if(contprimo%2)
				respf *= -1; 
		}
		vetM[i].first = respf;
		vetM[i].second = respf + vetM[i-1].second;
	}
	
	while (scanf("%d",&n), n)
	{
		printf("%8d%8d%8d\n",n,vetM[n].first,vetM[n].second);
	}
}
