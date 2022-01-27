#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int,int>m;
	vector<int>v;
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		m[N]++;
		if(m[N] == 1)
			v.push_back(N);
	}
	int s = v.size();
	for (int i = 0; i < s; i++)
	{
		printf("%d %d\n",v[i],m[v[i]]);
	}
	
}
