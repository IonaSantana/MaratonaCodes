#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t,n,dia,D;
	string mat;
	map<string,int>m;
	scanf("%d",&t);
	for (int j = 1; j <= t; j++)
	{
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			cin>>mat>>dia;
			m[mat] = dia;
		}
		scanf(" %d ",&D);
		cin>>mat;
		printf("Case %d: ",j);
		if(m.find(mat) == m.end() || m[mat] > D + 5)
		{
			puts("Do your own homework!");
		}else if(m[mat] <= D)
		{
			puts("Yesss");
		}else
		{
			puts("Late");
		}	
		m.clear();
	}	
}
