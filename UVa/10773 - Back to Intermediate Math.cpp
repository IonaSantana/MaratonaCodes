#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,d,u,v;
	double t1,t2;
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d",&d,&v,&u);
		printf("Case %d: ",i+1);
		if(v > u || v==u || !v || !u)
			printf("can't determine\n");
		else
		{
			t1 = d/(double)u;
			t2 = d/(double)(sqrt(u*u - v*v));
			printf("%.3lf\n",t2-t1);
		}
	}
}
