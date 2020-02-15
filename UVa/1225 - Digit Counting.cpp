#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,num[10];
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d",&n);
		for (int j = 0; j <= 9; j++)
		{
			num[j] = 0;
		}
		for (int j = 1; j <= n; j++)
		{
			int aux = j;
			while (aux)
			{
				num[aux%10]++;
				aux/=10;
			}
		}
		printf("%d",num[0]);
		for (int j = 1; j <= 9; j++)
		{
			printf(" %d",num[j]);
		}
		puts("");		
	}	
}
