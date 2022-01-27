#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int n,a=0;
	while (scanf("%d",&n), n)
	{
		if(a==0)
			printf("PERFECTION OUTPUT\n");
		a++;
		int s = sqrt(n), soma = 1;
		for (int i = 2; i <= s ; i++)
		{
			if(n%i == 0)
				soma += n/i + i;
		}
		if(s*s == n)
			soma-=s;
		printf("%5d  ",n);
		if(soma == n)
			printf("PERFECT");
		else if(soma > n)
			printf("ABUNDANT");
		else
			printf("DEFICIENT");
		puts("");
	}
	printf("END OF OUTPUT\n");
}
