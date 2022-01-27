#include <bits/stdc++.h>
using namespace std;

#define int long long

int V[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
int PD[11][33000]; 

int troco(int item,int soma,int Oqquero)
{
	if(soma == Oqquero) return 1;
	if (item == 11 || soma > Oqquero) return 0;
	if(PD[item][soma]!=-1) return PD[item][soma];																	
	
	return PD[item][soma] = troco(item+1, soma, Oqquero) + troco(item , soma + V[item], Oqquero);
	
}

int32_t main()
{
	double N;
		
	while(scanf("%lf", &N), N > 1e-6)
	{	memset(PD,-1,sizeof PD);
		printf("%6.2f%17lld\n",N,troco(0,0,N*100+1e-9));				
	}
}


