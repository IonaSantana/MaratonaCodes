#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,z,P,n;
	int m;
	while (scanf("%d",&m) && m)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%lld%lld%lld",&x,&y,&n);
			z = 1;
			P = y;
			for (; P > 0; P/=2)
			{
				if(P % 2 == 1)
				{
					z = (z%n * x%n)%n;
				}
				x = (x%n * x%n)%n;
			}	
			printf("%lld\n",z);
		}	
	}
}
