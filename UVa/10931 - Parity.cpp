#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,aux,pari;
	stack<int>b;
	while (scanf("%lld",&n), n)
	{
		pari = 0;
		aux = n;
		while (aux)
		{
			pari += aux%2;			
			b.push(aux%2);
			aux /= 2;
		}
		
		printf("The parity of ");
		while (!b.empty())
		{
			printf("%d",b.top());
			b.pop();
		}
		printf(" is %lld (mod 2).\n",pari);
	}
}
