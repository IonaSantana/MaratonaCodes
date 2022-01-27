#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	map<string,int>w;
	string a;
	int n = 1;
	for (int i = 0; i < 26; i++)
	{					
		a = ('a' + i);
		w[a] = n;
		n++; 
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = i+1; j < 26; j++)
		{		
			a = ('a' + i);
			a += ('a' + j);
			w[a] = n;
			n++; 
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = i+1; j < 26; j++)
		{	
			for (int k = j+1; k < 26; k++)
			{	
				a = ('a' + i);
				a += ('a' + j);
				a += ('a' + k);								
				w[a] = n;
				n++; 			
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{	
		for (int j = i+1; j < 26; j++)
		{	
			for (int k = j+1; k < 26; k++)
			{	
				for (int l = k+1; l < 26; l++)
				{			
					a = ('a' + i);
					a += ('a' + j);
					a += ('a' + k);
					a += ('a' + l);			
					w[a] = n;
					n++; 				
				}
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{	
		for (int j = i+1; j < 26; j++)
		{	
			for (int k = j+1; k < 26; k++)
			{	
				for (int l = k+1; l < 26; l++)
				{	
					for (int m = l+1; m < 26; m++)
					{
						a = ('a' + i);
						a += ('a' + j);
						a += ('a' + k);
						a += ('a' + l);
						a += ('a' + m);
						w[a] = n;
						n++; 
					}
				}
			}
		}
	}
	while(cin>> a)
	{
		if(w.find(a) != w.end())
			printf("%d\n",w[a]);
		else
			printf("0\n");	
	}
}	


