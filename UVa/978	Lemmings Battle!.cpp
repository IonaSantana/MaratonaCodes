#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("in5","r",stdin);
	//~ freopen("out5","w",stdout);
	int n,g,b,battle,valor;
	scanf("%d",&n);
	for (int j = 0; j < n; j++)
	{
		map<int,int>green,blue;
		map<int,int>:: iterator itg,itb;
		scanf(" %d %d %d",&battle,&g,&b);
		for (int i = 0; i < g; i++)
		{
			scanf("%d",&valor);
			green[valor]++;
		}
		for (int i = 0; i < b; i++)
		{
			scanf("%d",&valor);
			blue[valor]++;
		}

		while(blue.size() > 0 && green.size() > 0)
		{
			map<int,int>g1,b1;
			for (int i = 0; i < battle; i++)
			{
				if(green.empty() || blue.empty())
					break;
				itg = green.end();
				itb = blue.end();
				itg--;
				itb--;
				
				if(itb->first > itg->first)
				{
					b1[itb->first - itg->first]++;
				
				}else if(itg->first > itb->first)
				{
					g1[itg->first - itb->first]++;
				
				}				
				if(itg->second == 1)
					green.erase(itg->first);
				else
				  itg->second--;
				
				if(itb->second == 1)		
					blue.erase(itb->first);	
				else
					itb->second--;			
			}
			for (itb = g1.begin(); itb !=g1.end(); itb++)
			{
				green[itb->first]+=itb->second;
			}
			for (itb = b1.begin(); itb !=b1.end(); itb++)
			{
				blue[itb->first]+=itb->second;
			}
		}	
		
		if(green.empty() && blue.empty())
		{
			puts("green and blue died");
		
		}else if(!green.empty())
		{
			puts("green wins");
			itg = green.end();
			itg--;
			for ( ;itg != green.begin(); itg--)
			{
				for(int i = 0; i < itg->second; i++)
				{
					printf("%d\n",itg->first);
				}
			}
			for(int i = 0; i < itg->second; i++)
			{
				printf("%d\n",itg->first);
			}		
				
		}else
		{
			puts("blue wins");
			itb = blue.end();
			itb--;
			for ( ;itb != blue.begin(); itb--)
			{
				for(int i = 0; i < itb->second; i++)
				{
					printf("%d\n",itb->first);
				}
			}
			for(int i = 0; i < itb->second; i++)
			{
				printf("%d\n",itb->first);
			}
		}
		if(j < n-1)
			puts("");
	}
}
