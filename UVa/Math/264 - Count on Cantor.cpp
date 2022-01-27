#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,cont,soma,l,c,res;
	while (scanf("%d",&n)!=EOF)
	{
		soma = 0;
		cont = 1;
		while (soma < n)
		{
			soma+=cont;
			cont++;
		}		
		cont--;
		soma -= cont;	
		res = n - soma - 1;	
		c = cont - res;
		l = 1 + res;
		if(cont%2 == 0)
			printf("TERM %d IS %d/%d\n",n,l,c);
		else
			printf("TERM %d IS %d/%d\n",n,c,l);;	
	}
}
