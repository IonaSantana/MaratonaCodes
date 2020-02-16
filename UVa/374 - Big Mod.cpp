#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long B,P,M,resp,pot;

	while(scanf("%lld%lld%lld",&B,&P,&M)!=EOF)
	{
		resp = 1;
		pot = B;
		for (; P > 0; P/=2)
		{
			if(P % 2 == 1)
			{
				resp = (resp%M * pot%M)%M;
			}
			pot = (pot%M * pot%M)%M;
		}
		printf("%lld\n",resp);
	}
}
