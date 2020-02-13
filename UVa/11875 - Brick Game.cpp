#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,k,v[15];
	string s;
	scanf("%d",&t);
	getchar();
	for (int i = 0; i < t; i++)
	{
		getline(cin,s);
		stringstream f(s);
		k=0;
		while (f>>v[k])
		{
			k=k+1;
		}
		sort(v, v+k);
		printf("Case %d: %d\n",i+1,v[k/2]);
	}
	
}
