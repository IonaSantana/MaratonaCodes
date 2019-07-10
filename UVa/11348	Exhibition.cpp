#include <bits/stdc++.h>

using namespace std;

int main()
{
		
		int stamp,l,n,qt,fixa,diferentes;
		bool tem;
		map<int, set<int> > m;
		set<int>::iterator it;
		scanf("%d",&n);
		
		for (int j = 1; j <= n; j++)
		{
			scanf("%d",&l);
			for (int k = 0; k < l; k++)
			{
				scanf("%d",&qt);
				for (int i = 0; i < qt; i++)
				{
					scanf("%d",&stamp);
					m[k].insert(stamp);
				}
				
			}
			diferentes = 0;
			for (int k = 0; k < l-1; k++)
			{	
				it = m[k].begin();	
				while( it!= m[k].end())
				{
					tem = 0;
					fixa = *it;
					//printf("ele %d\n",fixa);
					for (int ab = k+1; ab < l; ab++)
					{					
						if(m[ab].find(fixa) != m[ab].end())
						{
							//it++;
							//cout<<"ab "<<ab<<endl;
							m[ab].erase(fixa);
							tem = 1;
						}					
					}
					if(tem)
					{
						it++;
						m[k].erase(fixa);
						
					}
					else
					{
						//cout<<"d "<<fixa<<endl;
						diferentes++;									
						it++;
					}
				}			
			}
			diferentes += m[l-1].size();
			//cout<<diferentes<<endl;
			printf("Case %d:",j);
			
			if(diferentes)
			{
				for (int i = 0; i < l; i++)
				{
					printf(" %0.6lf",(m[i].size()/(double)diferentes)*100);
					cout<<"%";
					m[i].clear();
				}
			}	
			puts("");
		}
}
