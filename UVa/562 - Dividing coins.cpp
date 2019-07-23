#include <bits/stdc++.h>

using namespace std;
int t,moeda[110],pd[110][60100],s;
int troco(int item, int soma)
{
	if (item == t ||soma == 0)
		return 0;
	if(pd[item][soma] != -1)
		return pd[item][soma];
		
	if(soma - moeda[item] >= 0)
		return pd[item][soma] = max(troco(item+1,soma),moeda[item] + troco(item+1,soma - moeda[item]));
	
	return pd[item][soma] = troco(item+1,soma);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int j = 0; j < n; j++)
	{
		memset(pd,-1,sizeof pd);
		s = 0;
		scanf("%d",&t);
		for (int i = 0; i < t; i++)
		{
			scanf("%d",&moeda[i]);
			s += moeda[i];
		}
		
		int aux =  troco(0,s/2);
		
		printf("%d\n",(s - 2*aux));		
	}			
}
