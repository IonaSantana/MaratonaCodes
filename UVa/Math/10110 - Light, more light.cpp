#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,s;
	
	while(scanf("%lld",&t), t)
	{
		s = sqrt(t);
		if(s*s == t)
			puts("yes");
		else
			puts("no");
	}
}
