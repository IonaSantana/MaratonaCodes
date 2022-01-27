#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,c,flag,n1,j;
	while (scanf("%d",&n), n >= 0)
	{
		flag = 0;
		c = ceil((double)cbrt(n));
		for (int i = c; i >= 2; i--)
		{
			if(n%i == 1)
			{		
				n1 = n;		
				for (j = 0; j < i && n1%i == 1; j++)
				{
					n1 -= (n1/i + 1);				 
				}
				if(n1%i == 0 && j == i)
				{
					flag = i;
					break;
				}	
			}
		}
		if (flag)
			printf("%d coconuts, %d people and 1 monkey\n",n,flag);
		else
			printf("%d coconuts, no solution\n",n);
	}
}
