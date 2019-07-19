#include <bits/stdc++.h>

using namespace std;
#define MAX_N 20000000
typedef pair<int, int> ii;
bool eprimo[MAX_N];

int main()
{
	int T,a,b;
	
	scanf("%d",&T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d",&a,&b);
		if (b%a == 0)
		{
			printf("%d %d\n",a,b);
		}else
		{
			printf("-1\n");
		}	
		
	}
}
