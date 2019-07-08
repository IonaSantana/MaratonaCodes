#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t,n,c;
	long long result;
	string mat;
	map<int,int>m;
	map<int,int>::iterator it;
	
	while(scanf("%d",&t), t)
	{	
		result = 0;
		for (int j = 0; j < t; j++)
		{
			scanf("%d",&n);
			for (int i = 0; i < n; i++)
			{
				scanf("%d",&c);
				m[c]++;
			}
			it = m.end();
			it--;
			result += it->first - (m.begin()->first);
			if(m.begin()->second == 1)
			{
				m.erase(m.begin()->first);
				
			}else
			{
				(m.begin()->second)--;
			}
			if(it->second == 1)
			{
				m.erase(it);
			}	
			else
			{			
				it->second--;		
			}		
		}
		printf("%lld\n",result);
		m.clear();
	}	
}
