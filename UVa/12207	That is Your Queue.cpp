#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in5","r",stdin);
	//~ freopen("out5","w",stdout);
	int P,C,n,cont=1,c,f;
	char perg;

	while(cin>>P>>C && (P || C))
	{
		queue<int>q;
		set<int>s;
		printf("Case %d:\n",cont);
		cont++;
		for (int i = 1; i <= C && i<=P; i++)
		{
			q.push(i);
			s.insert(i);
		}
		
		for (int j = 1; j <= C; j++)
		{
			scanf(" %c",&perg);
					
			if(perg == 'E')
			{
				scanf("%d",&n);	
				q.push(n);
			
				if(s.find(n)!=s.end())
				{
					c = 0;		
					while(c < 2)
					{
						f = q.front();					
						if(f == n)
						{
							if(c==0)
								q.pop();
							c++;
						}else
						{
							q.pop();
							q.push(f);
						}					
					}
				}else
				{
					s.insert(n);
					f = q.front();	
					while(f != n)
					{
						q.pop();
						q.push(f);
						f = q.front();					
					}
				}			
			}
			else
			{	
				f = q.front();
				printf("%d\n",f);
				q.pop();
				q.push(f);				
			}		
		}		
	}
}
