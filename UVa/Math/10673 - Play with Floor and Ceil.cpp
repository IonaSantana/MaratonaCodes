#include <bits/stdc++.h>  
using namespace std; 
  
int main()  
{  
    long long n,p,q,c,b,x,k,conta;
    scanf("%lld",&n);
    while (n--)
	{
		scanf("%lld%lld",&x,&k);
		c = ceil((double)x/k);
		b = floor((double)x/k);
		p = 1;
		conta = (x-b*p);
		for (int i = 0; conta%c && conta > 0; i++)
		{
			p++;
			conta = (x-b*p);
		}	
		q = ((x-b*p)/c);
		printf("%lld %lld\n",p,q);
	}  
}
