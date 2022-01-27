#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,aux,resp;
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		resp = n + n/m;
		aux = n/m + n%m;
		while (aux/m > 0)
		{
			resp += aux/m;
			aux = aux/m + aux%m;
		}
		printf("%d\n",resp);
	}
}
