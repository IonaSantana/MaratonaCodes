#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in4", "r",stdin);
	//~ freopen("out4","w",stdout);
	int n,tipo,num;
	bool st,qu,pqu;
	while(scanf("%d",&n)!=EOF)
	{
		stack<int>s;
		queue<int>q;
		priority_queue<int>pq;
		st = qu = pqu = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d",&tipo,&num);
			if(tipo == 1)
			{
				s.push(num);
				q.push(num);
				pq.push(num);
			}else
			{
				if(st)
				{
					if(!s.empty() && s.top() == num)
					{
						s.pop();
					}else
					{
						st = 0;
					}
				}
				if(qu)
				{
					if(!q.empty() && q.front() == num)
					{
						q.pop();
						
					}else
					{
						qu = 0;
					}
				}
				if(pqu)
				{
					if(!pq.empty() && pq.top() == num)
					{
						pq.pop();
					}else
					{
						pqu = 0;
					}
				}
			}	
		}		
		if((pqu && st && qu) || (pqu && st) || (pqu && qu) || (st && qu))
		{
			puts("not sure");
			
		}else if(!pqu && !st && !qu)
		{
			puts("impossible");
		
		}else if(st)
		{
			puts("stack");
			
		}else if(qu)
		{
			puts("queue");
		
		}else
		{
			puts("priority queue");
		}	
	}
}
