#include <bits/stdc++.h>

using namespace std;
#define int long long
int cont,M,D,N,Q;
int valor[210];
long long PD[210][15][25];
long long mochila(int item,int Disp, long long numero)
{
	if(Disp==M)
	{			
		if(numero%D==0)
		{
			return 1;
		}
		return 0;
	}
	if(item==N) return 0;
	
	if(PD[item][Disp][numero]!=-1)
	{
		return PD[item][Disp][numero];
	}else
	{
		PD[item][Disp][numero]=0;
	}	
	if(Disp+1 <= M)
	{
		int aux = (numero+valor[item])%D;
		if(aux < 0 ) aux +=D; // porque o valor pode ser negativo
			PD[item][Disp][numero] += mochila(item+1,Disp+1,aux);
	}
	return PD[item][Disp][numero] += mochila(item+1,Disp,numero);
	
}
int32_t main()
{
	//freopen("in","r", stdin);
	//freopen("out","w",stdout);
	int j=1,i;
	while (scanf("%lld%lld",&N,&Q), N || Q)
	{			
		for (i = 0; i < N; i++)
		{
			scanf("%lld",&valor[i]);
		}
		printf("SET %lld:\n",j);
		j++;
		
		for (i = 1; i <= Q; i++)
		{				
			memset(PD,-1,sizeof PD);
			scanf("%lld%lld",&D,&M);
			long long a = mochila(0,0,0);
			printf("QUERY %lld: %lld\n",i,a);
		}			
	}
}
