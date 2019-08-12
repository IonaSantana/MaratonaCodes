#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int t,n,valor,ans,sum,maxi,maxf,in;
	scanf("%d",&t);
	for (int j = 1; j <= t; j++)
	{
		ans = sum = 0;
		maxi = maxf = in = 1;
		scanf("%d",&n);
		for (int i = 2; i <= n; i++)
		{
			scanf("%d",&valor);
			sum += valor;

			if(sum < 0)
			{
				sum = 0;
				in = i;	
			}else if(sum == ans && sum > 0)
			{
				if((maxf - maxi) < (i - in))
				{
					maxf = i;
					maxi = in;
				}
			}else if(sum > ans)
			{					
				maxf = i;
				maxi = in;
				ans = sum;
			}			
		}

		if(ans == 0)
		{
			printf("Route %d has no nice parts\n",j);
			
		}else
		{
			printf("The nicest part of route %d is between stops %d and %d\n",j,maxi,maxf);
		}
		
	}	
}
