#include <bits/stdc++.h>

using namespace std;

bool chamala(int a, int b)
{
	if(b == 0)
		return 0;
	
	if(a/b > 1)
		return ( !(chamala(b, a - (a/b * b))) || !(chamala(a - ((a/b - 1) * b), b)));
	return (!(chamala(b, a - (a/b * b))));
}

int main()
{
	int s,t;
	while (scanf("%d%d",&s,&t), s || t)
	{
	
		if(chamala(max(s,t),min(s,t)))
			puts("Stan wins");
		else
			puts("Ollie wins");
	}

}
