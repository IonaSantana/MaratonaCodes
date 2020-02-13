#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,c=1,div,aux;
	while (scanf("%d%d",&n,&m), n || m)
	{
		printf("Case %d: ",c);
		
		div = (n-m);
		aux = div/m;
		if(m > n)
			div = 0;
		else if(div%m)
			aux +=1;
		
		if(aux > 26)
			printf("impossible");
		else
			printf("%d",aux);
		puts("");
		c++;
	}
}
