#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	map <string,int> job;
	string hab,aux,aux1;
	int n,m,val,j,sal,sizeH;
	scanf("%d %d",&m,&n);
	for (int i = 0; i < m; i++)
	{
		getchar();
		cin>>hab;
		scanf(" %d",&val);		
		job[hab] = val;
	}
	for (int i = 0; i < n; i++)
	{
		sal = 0;				
		while(getline(cin,hab), hab != ".")
		{
			j = 0;
			aux = "";
			sizeH = hab.size();
			while (j < sizeH)
			{		
				if(hab[j] != ' ')
				{
					aux+=hab[j];
				}else
				{			
					if(job.count(aux))
						sal += job[aux];
					aux = "";										
				}				
				j++;	
			}
			if(job.count(aux))
				sal += job[aux];	
		}	
		printf("%d\n",sal);	
	}	
}	


