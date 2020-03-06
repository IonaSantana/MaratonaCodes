#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,j,s,k = 1,soma,n1,i;
	while (scanf("%d",&n), n)
	{
		printf("Case %d: ",k);
		k++;
		if(n > 1)
		{	
			j = n;
			soma = 0;
			n1 = n-1;
			s = sqrt(n1);
			for (i = 2; i <= s && n1%i; i++);
			
			if (i > s && n1 > 1)
			{
				soma = n;
				j = n1-1;
			}
			while (j >= 2 && soma!=n)
			{
				s = sqrt(j);
				soma = 1 + j;
				for (i = 2; i <= s; i++)
				{
					if(j%i == 0)
					{
						if(j/i != i)
							soma += j/i;
						soma += i;
					}
				}
				j--;						
			}
			if(soma == n)
				printf("%d\n",j+1);
			else
				puts("-1");
		}else
		{
			puts("1");
		}	
	}
}
